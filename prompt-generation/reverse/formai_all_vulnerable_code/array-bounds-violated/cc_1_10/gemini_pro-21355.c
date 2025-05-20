//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_HOSTNAME_LENGTH 255
#define MAX_URL_LENGTH 255
#define MAX_RESPONSE_LENGTH 1024

struct website {
    char hostname[MAX_HOSTNAME_LENGTH];
    char url[MAX_URL_LENGTH];
    int port;
    int timeout;
    time_t last_checked;
    int status; // 0 = down, 1 = up
};

struct website *create_website(char *hostname, char *url, int port, int timeout) {
    struct website *website = malloc(sizeof(struct website));
    strcpy(website->hostname, hostname);
    strcpy(website->url, url);
    website->port = port;
    website->timeout = timeout;
    website->last_checked = 0;
    website->status = 0;
    return website;
}

void destroy_website(struct website *website) {
    free(website);
}

int check_website(struct website *website) {
    // Get the IP address of the website
    struct hostent *host = gethostbyname(website->hostname);
    if (host == NULL) {
        return 0;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return 0;
    }

    // Connect to the website
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(website->port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        return 0;
    }

    // Send a request to the website
    char request[MAX_URL_LENGTH + 8];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", website->url, website->hostname);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        return 0;
    }

    // Receive the response from the website
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received = recv(sockfd, response, MAX_RESPONSE_LENGTH - 1, 0);
    if (bytes_received == -1) {
        return 0;
    }
    response[bytes_received] = '\0';

    // Check the HTTP status code
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        return 0;
    }

    char *http_version = strtok(status_line, " ");
    if (http_version == NULL) {
        return 0;
    }

    char *status_code = strtok(NULL, " ");
    if (status_code == NULL) {
        return 0;
    }

    int status = atoi(status_code);
    if (status != 200) {
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Update the website's status
    website->status = 1;
    website->last_checked = time(NULL);
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hostname> <url> [port] [timeout]\n", argv[0]);
        return 1;
    }

    // Create the website
    char *hostname = argv[1];
    char *url = argv[2];
    int port = 80;
    if (argc > 3) {
        port = atoi(argv[3]);
    }
    int timeout = 10;
    if (argc > 4) {
        timeout = atoi(argv[4]);
    }
    struct website *website = create_website(hostname, url, port, timeout);

    // Check the website
    int status = check_website(website);

    // Print the results
    if (status) {
        printf("Website %s is up.\n", website->hostname);
    } else {
        printf("Website %s is down.\n", website->hostname);
    }

    // Destroy the website
    destroy_website(website);

    return 0;
}