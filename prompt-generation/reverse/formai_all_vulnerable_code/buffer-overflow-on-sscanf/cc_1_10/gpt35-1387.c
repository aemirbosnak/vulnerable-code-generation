//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_PORTS 65535
#define MAX_HOSTS 256
#define TIMEOUT 2

int open_socket()
{
    int fd;
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }
    return fd;
}

void select_socket(int fd, int time_sec)
{
    fd_set fds;
    struct timeval timeout;
    timeout.tv_sec = time_sec;
    timeout.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(fd, &fds);

    int ret = select(fd + 1, NULL, &fds, NULL, &timeout);
    if (ret < 0 && errno != EINTR)
    {
        perror("Select Error");
        exit(EXIT_FAILURE);
    }
}

void scan_port(int fd, struct sockaddr_in addr, int port)
{
    addr.sin_port = htons(port);
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == 0)
    {
        printf("Port %d\t open\n", port);
    }
}

void scan_host(struct sockaddr_in addr, int start_port, int end_port)
{
    int fd = open_socket();
    int i;
    for (i = start_port; i <= end_port; ++i)
    {
        select_socket(fd, TIMEOUT);
        scan_port(fd, addr, i);
    }
    close(fd);
}

void enumerate_hosts()
{
    struct ifaddrs *ifaddr, *ifa;
    struct sockaddr_in *host_addr, *netmask_addr;
    char *hostip, *netmask;
    int count = 0;

    if (getifaddrs(&ifaddr) == -1)
    {
        perror("GetIfAddrs Error");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
            continue;

        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            host_addr = (struct sockaddr_in *)ifa->ifa_addr;
            hostip = inet_ntoa(host_addr->sin_addr);

            netmask_addr = (struct sockaddr_in *)ifa->ifa_netmask;
            netmask = inet_ntoa(netmask_addr->sin_addr);

            printf("Host %d IP: %s\n", ++count, hostip);
            printf("Netmask: %s\n", netmask);

            int i, lsb, msb;
            unsigned long host_mask, netmask_int = inet_addr(netmask);
            unsigned long host_addr_int = inet_addr(hostip);
            sscanf(netmask, "%d.%d.%d.%d", &msb, &msb, &msb, &lsb);

            host_mask = ((1 << lsb) - 1);
            host_mask = ~host_mask;

            for (i = 1; i < host_mask; ++i)
            {
                unsigned long target_addr_int = (host_addr_int & netmask_int) | i;
                struct sockaddr_in target_addr;
                memset(&target_addr, 0, sizeof(target_addr));
                target_addr.sin_family = AF_INET;
                target_addr.sin_addr.s_addr = target_addr_int;

                printf("Scanning Host: %s\n", inet_ntoa(target_addr.sin_addr));
                scan_host(target_addr, 1, MAX_PORTS);
            }
        }
    }
    freeifaddrs(ifaddr);
}

int main()
{
    enumerate_hosts();
    return 0;
}