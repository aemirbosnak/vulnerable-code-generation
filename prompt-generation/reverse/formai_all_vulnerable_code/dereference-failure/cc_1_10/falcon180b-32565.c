//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256

// Function to get hostname from IP address
char* get_hostname(const char* ip) {
    struct hostent* hostent = gethostbyaddr((const void*)ip, sizeof(ip), AF_INET);
    if (hostent == NULL) {
        return strdup(ip);
    }
    return strdup(hostent->h_name);
}

// Function to check if website is up
int is_website_up(const char* hostname) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return 0;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        close(sockfd);
        return 0;
    }

    close(sockfd);
    return 1;
}

int main() {
    char ip[INET_ADDRSTRLEN];
    char hostname[MAX_HOSTNAME_LEN];

    // Get user input for website to monitor
    printf("Enter website to monitor (e.g. www.example.com): ");
    scanf("%s", hostname);

    // Get IP address from hostname
    struct hostent* hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        printf("Invalid hostname\n");
        return 1;
    }
    inet_ntop(AF_INET, (void*)&((struct in_addr*)hostent->h_addr)->s_addr, ip, INET_ADDRSTRLEN);

    // Check if website is up
    if (is_website_up(ip)) {
        printf("Website is up\n");
    } else {
        printf("Website is down\n");
    }

    return 0;
}