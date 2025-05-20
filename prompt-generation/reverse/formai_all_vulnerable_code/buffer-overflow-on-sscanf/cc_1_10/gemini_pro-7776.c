//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#define MAX_PORTS 65535
#define MAX_HOSTNAME 256
#define MAX_BANNER 1024

struct port_info {
    int port;
    char *name;
    char *banner;
};

struct port_info ports[] = {
    {21, "FTP", "220 Service ready"},
    {22, "SSH", "SSH-2.0-OpenSSH"},
    {23, "Telnet", "Escape character is '^]'"},
    {25, "SMTP", "220 ESMTP Postfix"},
    {53, "DNS", "Server: bind"},
    {80, "HTTP", "HTTP/1.1 200 OK"},
    {110, "POP3", "+OK POP3 server ready"},
    {139, "NetBIOS", "Windows 2000 Server"},
    {143, "IMAP", "* OK IMAP4rev1 Server ready"},
    {443, "HTTPS", "HTTP/1.1 301 Moved Permanently"},
    {3306, "MySQL", "5.7.25-0ubuntu0.20.04.1"},
    {3389, "RDP", "Microsoft Terminal Server"},
    {5432, "PostgreSQL", "PostgreSQL 14.4 on x86_64-unknown-linux-gnu"},
    {8080, "HTTP Proxy", "HTTP/1.1 200 Connection established"},
    {0, NULL, NULL}
};

void print_usage(char *program_name) {
    printf("Usage: %s <hostname> <port range>\n", program_name);
    printf("Example: %s 192.168.1.1 21-80\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
    }

    char *hostname = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        print_usage(argv[0]);
    }

    if (start_port < 0 || start_port > MAX_PORTS || end_port < 0 || end_port > MAX_PORTS) {
        print_usage(argv[0]);
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", hostname);
        exit(1);
    }

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr = *((struct in_addr *)host->h_addr);

    for (int port = start_port; port <= end_port; port++) {
        sockaddr.sin_port = htons(port);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("Error: Could not create socket");
            continue;
        }

        int timeout = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

        if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == 0) {
            printf("Port %d is open\n", port);

            char banner[MAX_BANNER];
            int n = recv(sockfd, banner, MAX_BANNER, 0);
            if (n > 0) {
                banner[n] = '\0';
                printf("Banner: %s\n", banner);
            }

            for (int i = 0; ports[i].port != 0; i++) {
                if (ports[i].port == port) {
                    printf("Service: %s\n", ports[i].name);
                    break;
                }
            }
        }

        close(sockfd);
    }

    return 0;
}