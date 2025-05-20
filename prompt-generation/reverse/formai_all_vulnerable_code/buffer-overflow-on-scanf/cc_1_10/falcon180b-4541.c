//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

/* Function prototypes */
int scan_network(char *ip_range, int port);
int validate_ip(char *ip);
int is_port_open(int sockfd, struct sockaddr_in target);

int main(int argc, char *argv[])
{
    char ip_range[20];
    int port;

    printf("Enter IP range (e.g. 192.168.1.1-192.168.1.255): ");
    scanf("%s", ip_range);

    printf("Enter port number (e.g. 80): ");
    scanf("%d", &port);

    scan_network(ip_range, port);

    return 0;
}

int scan_network(char *ip_range, int port)
{
    char *token = strtok(ip_range, "-");
    struct sockaddr_in target;
    int sockfd;
    int retval;
    fd_set master_fds, read_fds;

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    while (token!= NULL) {
        if (validate_ip(token)) {
            target.sin_family = AF_INET;
            target.sin_port = htons(port);
            target.sin_addr.s_addr = inet_addr(token);

            sockfd = socket(AF_INET, SOCK_STREAM, 0);

            if (sockfd == -1) {
                printf("Error creating socket\n");
                continue;
            }

            retval = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

            if (retval == -1) {
                printf("Connection failed\n");
            } else {
                printf("Connection successful\n");
            }

            close(sockfd);
        }

        token = strtok(NULL, "-");
    }

    return 0;
}

int validate_ip(char *ip)
{
    char *ptr;
    int i = 0;
    int octet_count = 0;

    if (strlen(ip) > 15) {
        return FALSE;
    }

    for (ptr = ip; *ptr!= '\0'; ptr++) {
        if (*ptr == '.') {
            octet_count++;
        } else if (!isdigit(*ptr)) {
            return FALSE;
        }
    }

    if (octet_count!= 3) {
        return FALSE;
    }

    return TRUE;
}

int is_port_open(int sockfd, struct sockaddr_in target)
{
    fd_set read_fds;
    struct timeval timeout;
    int retval;

    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    retval = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        printf("Error with select()\n");
        return FALSE;
    } else if (retval == 0) {
        printf("Connection timed out\n");
        return FALSE;
    } else {
        return TRUE;
    }
}