//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <unistd.h>

#define BUFSIZE 1024

struct host 
{
    char name[100];
    char ip[100];
};

int main(int argc, char *argv[]) 
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    int sock, rc, bytes;
    char buf[BUFSIZE];
    struct host hosts[100];
    int num_hosts = 0;

    if (getifaddrs(&ifap) == -1) {
        perror("Error getting ifaddrs");
        return 1;
    }

    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr->sa_family == AF_INET) 
        {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            strcpy(hosts[num_hosts].ip, addr);

            if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), hosts[num_hosts].name, NI_MAXHOST, NULL, 0, 0) != 0) 
            {
                perror("Error getting name info");
                strcpy(hosts[num_hosts].name, "Unable to resolve");
            }

            num_hosts++;
        }
    }

    freeifaddrs(ifap);

    for (int i = 0; i < num_hosts; i++) 
    {
        printf("\nName: %s\t IP Address: %s", hosts[i].name, hosts[i].ip);
    }

    printf("\n\n");

    for (int i = 0; i < num_hosts; i++) 
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock < 0) 
        {
            perror("Error opening socket");
            return 1;
        }

        struct hostent *he;
        he = gethostbyname(hosts[i].name);

        if (he == NULL) 
        {
            herror("Error getting host by name");
            close(sock);
            continue;
        }

        struct sockaddr_in server_addr;
        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        bcopy((char *) he->h_addr, (char *) &server_addr.sin_addr.s_addr, he->h_length);

        rc = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

        if (rc < 0) 
        {
            perror("Error connecting");
            close(sock);
            continue;
        }

        sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hosts[i].name);

        bytes = send(sock, buf, strlen(buf), 0);

        int total = 0;
        while (1) 
        {
            memset(buf, '\0', BUFSIZE);
            int n = recv(sock, buf, BUFSIZE-1, 0);

            if (n < 0) {
                perror("Error receiving message");
                break;
            }
            total += n;
            if (total > BUFSIZE)
                break;
            if (n == 0)
                break;

            printf("%s\n", buf);
        }

        printf("\n\n");

        close(sock);
    }

    return 0;
}