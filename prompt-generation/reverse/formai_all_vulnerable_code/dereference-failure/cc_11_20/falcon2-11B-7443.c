//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <ssid>\n", argv[0]);
        return 1;
    }
    char *ssid = argv[1];

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(2000);
    if(inet_pton(AF_INET, "192.168.1.1", &serv_addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int data = 0;
    char buf[128];
    int n = 0;

    struct ifaddrs *ifaddr, *ifa;
    int family = AF_INET;
    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa!= NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family!= family)
            continue;

        if (strcmp(ifa->ifa_name, ssid) == 0)
        {
            socklen_t len = sizeof(struct sockaddr_in);
            if (bind(sockfd, (struct sockaddr *)&serv_addr, len) < 0)
            {
                perror("bind");
                exit(EXIT_FAILURE);
            }

            if (listen(sockfd, 1) < 0)
            {
                perror("listen");
                exit(EXIT_FAILURE);
            }

            printf("Listening on %s\n", ssid);

            while(1)
            {
                if (n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&serv_addr, &len))
                {
                    if (n == 0)
                        break;
                    printf("Received %d bytes from %s\n", n, inet_ntoa(serv_addr.sin_addr));
                    if (sscanf(buf, "%d", &data)!= 1)
                        printf("Invalid format: %s\n", buf);
                    if (data > 0)
                        printf("Signal strength: %d%%\n", data);
                }
                else
                    printf("Receive failed\n");
            }
            close(sockfd);
            break;
        }
    }

    freeifaddrs(ifaddr);

    return 0;
}