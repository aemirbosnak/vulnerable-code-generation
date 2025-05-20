//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

#define BUFF_SIZE 1024

int main()
{
    // Initialize variables
    int sockfd, err;
    struct sockaddr_in servaddr;
    char buffer[BUFF_SIZE];
    struct timeval timeout;
    fd_set readfds;
    int nready;
    time_t start_time, end_time;
    double elapsed_time;

    // Get the website URL from the user
    printf("Enter the website URL: ");
    char url[100];
    scanf("%s", url);

    // Parse the URL to get the hostname and port
    char *hostname = strtok(url, ":");
    char *port = strtok(NULL, ":");
    if (port == NULL)
    {
        port = "80";  // Default port
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address structure
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    // Set the socket timeout
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // Connect to the server
    err = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (err == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a HTTP HEAD request to the server
    char request[] = "HEAD / HTTP/1.1\r\nHost: ";
    strcat(request, hostname);
    strcat(request, "\r\nConnection: close\r\n\r\n");
    send(sockfd, request, strlen(request), 0);

    // Set the read file descriptor set
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    // Wait for the server's response
    nready = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (nready == -1)
    {
        perror("select");
        exit(EXIT_FAILURE);
    }
    else if (nready == 0)
    {
        printf("Timeout: No response from the server\n");
        exit(EXIT_FAILURE);
    }

    // Get the response from the server
    memset(buffer, 0, BUFF_SIZE);
    err = recv(sockfd, buffer, BUFF_SIZE, 0);
    if (err <= 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    // Check the response status code
    char *status_code = strtok(buffer, " ");
    if (strcmp(status_code, "200") != 0)
    {
        printf("Error: Website is not responding properly (status code: %s)\n", status_code);
        exit(EXIT_FAILURE);
    }

    // Get the website title from the response header
    char *title = strstr(buffer, "<title>");
    if (title != NULL)
    {
        title += 7;
        char *end_title = strstr(title, "</title>");
        if (end_title != NULL)
        {
            *end_title = '\0';
            printf("Website title: %s\n", title);
        }
    }

    // Get the website response time
    start_time = time(NULL);
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    printf("Website response time: %.2f seconds\n", elapsed_time);

    return 0;
}