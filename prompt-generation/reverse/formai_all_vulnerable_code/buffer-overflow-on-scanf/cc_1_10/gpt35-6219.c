//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mind-bending
#include<stdio.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<netdb.h>
#include<ifaddrs.h>

#define MAX_IP_LEN 20

int main()
{
    struct ifaddrs *ifaddr, *ifa;
    struct sockaddr_in *sa;
    char *ip_addr;
    int sock_fd;
    struct hostent *host;
    char hostname[MAX_IP_LEN];

    getifaddrs(&ifaddr);
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            ip_addr = inet_ntoa(sa->sin_addr);
            printf("%s: %s\n", ifa->ifa_name, ip_addr);
        }
    }
    freeifaddrs(ifaddr);

    printf("Enter an IP address to scan: ");
    scanf("%s", hostname);
    host = gethostbyname(hostname);

    if (host == NULL)
    {
        printf("Error: Could not resolve hostname\n");
        return 1;
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0)
    {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Scanning %s...\n", inet_ntoa(*(struct in_addr *) host->h_addr_list[0]));

    close(sock_fd);
    return 0;
}