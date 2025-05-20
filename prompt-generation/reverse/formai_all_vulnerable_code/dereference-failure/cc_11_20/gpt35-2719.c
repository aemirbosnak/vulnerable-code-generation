//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/ether.h>
#include <sys/ioctl.h>

#define MAX_THREADS 10
#define MAX_SSID_LEN 32
#define SCAN_INTERVAL 5 // Scan interval in seconds

typedef struct ssid_list_t
{
    char ssid[MAX_SSID_LEN];
    struct ssid_list_t *next;
} ssid_list_t;

typedef struct thread_arg_t
{
    int sock;
    struct sockaddr_in sin;
    ssid_list_t **list;
} thread_arg_t;

void *scan_networks(void *args)
{
    thread_arg_t *targs = (thread_arg_t *)args;
    char buf[4096], ssid[MAX_SSID_LEN];
    int numbytes;
    socklen_t len = sizeof(struct sockaddr_in);

    while (true)
    {
        if ((numbytes = sendto(targs->sock, "SCAN", 4, 0, (struct sockaddr *)&targs->sin, len)) == -1)
        {
            fprintf(stderr, "Error sending SCAN request: %s\n", strerror(errno));
            continue;
        }

        if ((numbytes = recvfrom(targs->sock, buf, sizeof(buf), 0, (struct sockaddr *)&targs->sin, &len)) == -1)
        {
            fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
            continue;
        }

        int offset = 0;
        while (offset < numbytes)
        {
            int len = buf[offset++];

            if (offset + len > numbytes)
            {
                fprintf(stderr, "Invalid response format: %d bytes left but expected %d\n", numbytes - offset, len);
                break;
            }

            memcpy(ssid, buf + offset, len);
            ssid[len] = 0;
            offset += len;

            ssid_list_t *newnode = (ssid_list_t *)malloc(sizeof(ssid_list_t));
            strncpy(newnode->ssid, ssid, MAX_SSID_LEN);
            newnode->ssid[MAX_SSID_LEN - 1] = 0;
            newnode->next = *targs->list;
            *targs->list = newnode;
        }

        sleep(SCAN_INTERVAL);
    }
}

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in sin;
    pthread_t threads[MAX_THREADS];
    ssid_list_t *ssid_list = NULL;
    int num_threads = 1;
    struct ifaddrs *ifaddr, *ifa;
    char *ifname = NULL;

    if (getifaddrs(&ifaddr) == -1)
    {
        fprintf(stderr, "Error getting interface list: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET || (ifa->ifa_flags & IFF_LOOPBACK))
            continue;

        printf("%s: %s\n", ifa->ifa_name, inet_ntoa(((struct sockaddr_in *)ifa->ifa_addr)->sin_addr));

        sprintf(ifname, "%s", ifa->ifa_name);
    }

    freeifaddrs(ifaddr);

    if (ifname == NULL || strlen(ifname) == 0)
    {
        fprintf(stderr, "Error: no suitable network interface found\n");
        exit(EXIT_FAILURE);
    }

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    sin.sin_port = htons(8000);

    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &(int){1}, sizeof(int)) == -1)
    {
        fprintf(stderr, "Error setting socket option: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, ifname, strlen(ifname)) == -1)
    {
        fprintf(stderr, "Error binding socket to %s: %s\n", ifname, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_threads; i++)
    {
        thread_arg_t *targs = (thread_arg_t *)malloc(sizeof(thread_arg_t));
        targs->sock = sock;
        targs->sin = sin;
        targs->list = &ssid_list;

        if (pthread_create(&threads[i], NULL, scan_networks, targs) != 0)
        {
            fprintf(stderr, "Error creating thread %d: %s\n", i, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    while (true)
    {
        system("clear");
        printf("Available networks:\n");

        ssid_list_t *node = ssid_list;
        while (node)
        {
            printf("- %s\n", node->ssid);
            node = node->next;
        }

        sleep(1);
    }

    close(sock);

    return EXIT_SUCCESS;
}