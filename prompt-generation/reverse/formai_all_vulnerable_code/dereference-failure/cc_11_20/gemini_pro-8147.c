//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Define the maximum number of websites to monitor
#define MAX_WEBSITES 10

// Define the maximum length of a website URL
#define MAX_URL_LENGTH 256

// Define the maximum number of seconds to wait for a response from a website
#define TIMEOUT_SECONDS 15

// Define the frequency at which to check the websites (in seconds)
#define CHECK_FREQUENCY_SECONDS 60

// Create a struct to store information about a website
typedef struct website {
    char url[MAX_URL_LENGTH];
    int status;
    time_t last_checked;
} website;

// Create an array of websites to monitor
website websites[MAX_WEBSITES] = {
    {"https://www.example.com", 0, 0},
    {"https://www.google.com", 0, 0},
    {"https://www.yahoo.com", 0, 0},
    {"https://www.bing.com", 0, 0},
    {"https://www.duckduckgo.com", 0, 0},
};

// Define the main function
int main() {
    // Get the current time
    time_t now = time(NULL);

    // Check each website in the array
    for (int i = 0; i < MAX_WEBSITES; i++) {
        // Check if the website has been checked recently
        if (now - websites[i].last_checked < CHECK_FREQUENCY_SECONDS) {
            // Skip the website if it has been checked recently
            continue;
        }

        // Update the last checked time
        websites[i].last_checked = now;

        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            exit(1);
        }

        // Set the socket timeout
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT_SECONDS;
        timeout.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            perror("Error setting socket timeout");
            exit(1);
        }

        // Get the website's IP address
        struct hostent *host = gethostbyname(websites[i].url);
        if (host == NULL) {
            perror("Error getting host by name");
            exit(1);
        }

        // Connect to the website
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to server");
            websites[i].status = -1;
            close(sockfd);
            continue;
        }

        // Send a request to the website
        char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
        if (send(sockfd, request, strlen(request), 0) < 0) {
            perror("Error sending request");
            websites[i].status = -1;
            close(sockfd);
            continue;
        }

        // Receive a response from the website
        char response[1024];
        int bytes_received = recv(sockfd, response, sizeof(response), 0);
        if (bytes_received < 0) {
            perror("Error receiving response");
            websites[i].status = -1;
            close(sockfd);
            continue;
        }

        // Check the response code
        char *status_code = strtok(response, " ");
        if (status_code == NULL || atoi(status_code) != 200) {
            websites[i].status = -1;
            close(sockfd);
            continue;
        }

        // The website is up
        websites[i].status = 1;

        // Close the socket
        close(sockfd);
    }

    // Print the status of each website
    for (int i = 0; i < MAX_WEBSITES; i++) {
        printf("%s: ", websites[i].url);
        if (websites[i].status == 1) {
            printf("Up\n");
        } else {
            printf("Down\n");
        }
    }

    return 0;
}