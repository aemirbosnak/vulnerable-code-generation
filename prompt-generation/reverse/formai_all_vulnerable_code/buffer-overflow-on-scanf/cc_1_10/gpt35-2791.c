//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>


// Define the maximum buffer size for storing information 
#define MAX_BUFFER_SIZE 1024


/**
 * This function returns the IP address of the given host using
 * the getaddrinfo() function.
 * 
 * @param hostname The hostname to query
 * 
 * @returns The IP address of the given hostname, or NULL on error
 */
char* resolve_hostname(char* hostname) {
    struct addrinfo hints, *res;
    char* ip = NULL;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res) == 0) {
        struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
        ip = malloc(INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &(addr->sin_addr), ip, INET_ADDRSTRLEN);
    }

    return ip;
}


/**
 * This function scans the network for active hosts and returns a list
 * of the IP addresses that are currently online.
 * 
 * @param subnet The subnet of the network to scan (e.g. "192.168.0")
 * @param min The minimum value of the IP address range to scan (e.g. 1)
 * @param max The maximum value of the IP address range to scan (e.g. 255)
 * 
 * @returns An array of online IP addresses, terminated by NULL
 */
char** scan_network(char* subnet, int min, int max) {
    char** online_hosts = malloc(max * sizeof(char*));
    int socket_fd;
    struct sockaddr_in address;
    struct timeval timeout;
    fd_set file_descriptors;
    char buffer[MAX_BUFFER_SIZE];
    int i;
    int num_online_hosts = 0;

    for (i = min; i <= max; i++) {
        char ip[INET_ADDRSTRLEN];
        sprintf(ip, "%s.%d", subnet, i);

        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0) {
            perror("socket()");
            continue;
        }

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_port = htons(80);
        inet_pton(AF_INET, ip, &(address.sin_addr));

        if (connect(socket_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            close(socket_fd);
            continue;
        }

        FD_ZERO(&file_descriptors);
        FD_SET(socket_fd, &file_descriptors);

        if (select(socket_fd + 1, &file_descriptors, NULL, NULL, &timeout) == 1) {
            sprintf(buffer, "HEAD / HTTP/1.1\r\nHOST: %s\r\n\r\n", ip);

            if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
                perror("send()");
                close(socket_fd);
                continue;
            }
            if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) > 0) {
                if (strstr(buffer, "200 OK") != NULL) {
                    online_hosts[num_online_hosts] = malloc(INET_ADDRSTRLEN);
                    strcpy(online_hosts[num_online_hosts++], ip);
                }
            }
        }

        close(socket_fd);
    }

    online_hosts[num_online_hosts] = NULL;

    return online_hosts;
}


/**
 * The main function prompts the user for a network subnet and IP range
 * to scan, and then initiates a network scan. It then prompts the user
 * for a hostname to query and prints out the resolved IP address.
 */
int main() {
    char subnet[40], hostname[MAX_BUFFER_SIZE], *ip;
    int min, max, i;
    char** online_hosts;

    printf("Enter the network subnet to scan (e.g. 192.168.0): ");
    scanf("%s", &subnet);

    printf("Enter the minimum IP address to scan (e.g. 1): ");
    scanf("%d", &min);

    printf("Enter the maximum IP address to scan (e.g. 255): ");
    scanf("%d", &max);

    online_hosts = scan_network(subnet, min, max);

    printf("The following hosts are currently online:\n");
    for (i = 0; online_hosts[i] != NULL; i++) {
        printf("%s\n", online_hosts[i]);
    }

    printf("Enter a hostname to resolve (e.g. google.com): ");
    scanf("%s", &hostname);

    ip = resolve_hostname(hostname);
    if (ip) {
        printf("The IP address of %s is %s\n", hostname, ip);
        free(ip);
    } else {
        printf("Unable to resolve hostname.\n");
    }

    return 0;
}