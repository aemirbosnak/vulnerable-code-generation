//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_HOSTS 128
#define MAX_IFACE_NAME 16
#define MAX_IP_ADDR 16

struct host {
    char name[MAX_HOSTS];
    char ip[MAX_IP_ADDR];
};

struct interface {
    char name[MAX_IFACE_NAME];
    char ip[MAX_IP_ADDR];
};

struct host_map {
    struct host h;
    struct interface iface;
};

int main(int argc, char *argv[])
{
    int sock, num_hosts = 0, i, j;
    struct ifaddrs *ifaddr, *ifa;
    struct sockaddr_in *sa;
    struct host_map host_map[MAX_HOSTS];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            strcpy(host_map[num_hosts].iface.name, ifa->ifa_name);
            strcpy(host_map[num_hosts].iface.ip, inet_ntoa(sa->sin_addr));
            num_hosts++;
        }
    }

    freeifaddrs(ifaddr);

    printf("Number of hosts detected: %d\n", num_hosts);

    for (i = 0; i < num_hosts; i++) {
        printf("Host %d:\n", i + 1);
        printf("\tInterface name: %s\n", host_map[i].iface.name);
        printf("\tIP address: %s\n", host_map[i].iface.ip);
        printf("\tResolved name: ");

        struct hostent *he = gethostbyaddr(host_map[i].iface.ip, strlen(host_map[i].iface.ip), AF_INET);
        if (he == NULL) {
            printf("n/a");
        } else {
            printf("%s", he->h_name);
            strcpy(host_map[i].h.name, he->h_name);
        }
        printf("\n");
    }

    /* Open socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("\nPORT\t| HOSTNAME\t| IP ADDRESS\n");
    printf("----------------------------------------------\n");

    for (i = 1; i < argc; i++) {
        struct hostent *hname = gethostbyname(argv[i]);
        if (hname == NULL) {
            fprintf(stderr, "Unknown host %s\n", argv[i]);
            continue;
        }

        for (j = 0; j < num_hosts; j++) {
            if (strcmp(host_map[j].h.name, hname->h_name) == 0 ||
                strcmp(host_map[j].iface.ip, inet_ntoa(*(struct in_addr *)hname->h_addr)) == 0) {
                printf("%d\t| %s\t| %s\n", i, hname->h_name, host_map[j].iface.ip);
                break;
            }
        }
    }

    close(sock);
    exit(EXIT_SUCCESS);
}