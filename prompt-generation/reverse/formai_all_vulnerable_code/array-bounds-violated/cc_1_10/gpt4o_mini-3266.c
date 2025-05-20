//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define the herald of our humble HTTP client
#define TARGET_PORT 80
#define BUFFER_SIZE 2048

void herald_of_responses(const char *msg) {
    printf("\n**** Herald of Responses ****\n");
    printf("%s\n", msg);
    printf("****************************\n");
}

void summon_http_client(const char *host, const char *c_path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
   
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
   
    // Gather ye spirits of the server
    host_info = gethostbyname(host);
    if (!host_info) {
        herald_of_responses("Alas! The server could not be found.");
        exit(EXIT_FAILURE);
    }
   
    // Create a mythical stream for communication
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        herald_of_responses("Oh no! The sacred socket could not be created.");
        exit(EXIT_FAILURE);
    }
   
    // Construct the ethereal abode of the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    server_addr.sin_port = htons(TARGET_PORT);

    // Attempt to conjure a connection to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        herald_of_responses("Foul fate! The connection to the server has been severed.");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Formulate the sacred request to the web
    snprintf(request, sizeof(request),
            "GET %s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "Connection: close\r\n\r\n", c_path, host);
   
    // Deliver the sacred request unto the server
    send(sockfd, request, strlen(request), 0);
    herald_of_responses("The request hath been sent to the server!");

    // Receive the divine response from the server
    int received_len;
    while ((received_len = recv(sockfd, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[received_len] = '\0';
        printf("%s", buffer);
    }

    if (received_len < 0) {
        herald_of_responses("A dark cloud hath fallen; the reception hath failed.");
    }

    // With the journey complete, we must close our connection
    close(sockfd);
    herald_of_responses("The sacred connection hath been closed.");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        herald_of_responses("Beseech thee, provide the hostname and path!");
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Embark upon the quest to summon the HTTP Client
    summon_http_client(hostname, path);
    return 0;
}