//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFF_SIZE 1024
#define MAX_IFACE_NAME 30

struct iface {
    char name[MAX_IFACE_NAME];
    char ip[16];
};

int main() {
    struct ifaddrs *if_list, *if_iter;
    struct sockaddr_in *addr;
    char interface_name[INET_ADDRSTRLEN];
    char data_buff[MAX_BUFF_SIZE];
    int sock_fd, optval, bytes_read;
    ssize_t sent_bytes;
    socklen_t opt_len = sizeof(optval);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    fd_set fdset;
    int max_fd = -1;
    struct iface local_ifaces[10];
    int iface_count = 0;

    if (getifaddrs(&if_list) < 0) {
        perror("getifaddrs() failed");
        return EXIT_FAILURE;
    }

    for (if_iter = if_list; if_iter != NULL; if_iter = if_iter->ifa_next) {
        if (if_iter->ifa_addr->sa_family != AF_INET) {
            continue; // Skip non-IPv4 interfaces
        }
        if (iface_count >= 10) {
            printf("Ignoring interface %s since limit of 10 configured interfaces reached\n", if_iter->ifa_name);
            continue;
        }
        addr = (struct sockaddr_in *) if_iter->ifa_addr;
        inet_ntop(AF_INET, &addr->sin_addr, local_ifaces[iface_count].ip, INET_ADDRSTRLEN);
        strcpy(local_ifaces[iface_count].name, if_iter->ifa_name);
        iface_count++;
    }

    printf("Found %d local interfaces\n", iface_count);
    for (int i = 0; i < iface_count; i++) {
        printf("Local Interface %d: %s (%s)\n", i + 1, local_ifaces[i].name, local_ifaces[i].ip);
    }

    printf("Enter the IP address to scan: ");
    fflush(stdout);
    fgets(data_buff, MAX_BUFF_SIZE, stdin);
    const char *remote_host = strtok(data_buff, "\n");

    printf("Starting scan of %s...\n", remote_host);
    for (int i = 0; i < iface_count; i++) {
        sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (setsockopt(sock_fd, SOL_SOCKET, SO_BINDTODEVICE, local_ifaces[i].name, strlen(local_ifaces[i].name)) < 0) {
            perror("setsockopt(SO_BINDTODEVICE) failed");
            continue;
        }
        if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEPORT, &optval, opt_len) < 0) {
            perror("setsockopt(SO_REUSEPORT) failed");
            continue;
        }
        if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv)) < 0) {
            perror("setsockopt(SO_RCVTIMEO) failed");
            continue;
        }
        if (setsockopt(sock_fd, SOL_SOCKET, SO_SNDTIMEO, (const char *)&tv, sizeof(tv)) < 0) {
            perror("setsockopt(SO_SNDTIMEO) failed");
            continue;
        }

        struct hostent *hostinfo = gethostbyname(remote_host);
        if (hostinfo == NULL) {
            herror("gethostbyname() failed");
            continue;
        }

        struct sockaddr_in remote_addr;
        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr_list[0];
        remote_addr.sin_port = htons(80);

        if (connect(sock_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) != 0) {
            printf("%s: Failed to connect\n", local_ifaces[i].name);
            continue;
        }

        printf("%s: Connected\n", local_ifaces[i].name);

        sent_bytes = send(sock_fd, "GET / HTTP/1.1\r\n\r\n", 17, 0);
        if (sent_bytes < 0) {
            perror("send() failed");
            continue;
        }

        FD_ZERO(&fdset);
        FD_SET(sock_fd, &fdset);
        max_fd = sock_fd + 1;
        select(max_fd, &fdset, NULL, NULL, &tv);
        if (FD_ISSET(sock_fd, &fdset)) {
            bytes_read = recv(sock_fd, data_buff, sizeof(data_buff), 0);
            if (bytes_read < 0) {
                perror("recv() failed");
                continue;
            }
            printf("%s: Response received (%d bytes received)\n", local_ifaces[i].name, bytes_read);
        } else {
            printf("%s: No response received\n", local_ifaces[i].name);
        }
        close(sock_fd);
    }

    printf("Scan complete\n");
    return EXIT_SUCCESS;
}