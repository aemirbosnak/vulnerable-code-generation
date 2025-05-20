//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the maximum number of URLs to monitor
#define MAX_URLS 10

// Define the maximum length of a URL
#define MAX_URL_LENGTH 256

// Define the interval (in seconds) between checks
#define CHECK_INTERVAL 60

// Define the timeout (in seconds) for each check
#define CHECK_TIMEOUT 10

// Define the number of retries for each check
#define CHECK_RETRIES 3

// Define the user agent string for the HTTP requests
#define USER_AGENT "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36"

// Define the HTTP request header
#define HTTP_REQUEST "GET / HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n"

// Define the HTTP response string to look for
#define HTTP_RESPONSE "HTTP/1.1 200 OK"

// Define the structure to store the URL and its status
typedef struct {
    char url[MAX_URL_LENGTH];
    int status;
} url_status;

// Function to check the uptime of a URL
int check_uptime(char *url) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Get the host and port from the URL
    char host[MAX_URL_LENGTH];
    int port = 80;
    if (sscanf(url, "http://%[^/]:%d", host, &port) != 2) {
        perror("sscanf");
        close(sockfd);
        return -1;
    }

    // Resolve the hostname to an IP address
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set the timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = CHECK_TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    // Connect to the host
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *) hostent->h_addr_list[0];
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send the HTTP request
    char request[MAX_URL_LENGTH + strlen(HTTP_REQUEST)];
    snprintf(request, sizeof(request), HTTP_REQUEST, host, USER_AGENT);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the HTTP response
    char response[1024];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Check if the HTTP response is OK
    if (strstr(response, HTTP_RESPONSE) == NULL) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return the status code
    return 0;
}

// Function to monitor the uptime of a list of URLs
void monitor_uptime(url_status *urls, int num_urls) {
    while (1) {
        // Check the uptime of each URL
        for (int i = 0; i < num_urls; i++) {
            int status = check_uptime(urls[i].url);
            if (status == 0) {
                printf("%s is up\n", urls[i].url);
            } else {
                printf("%s is down\n", urls[i].url);
            }
        }

        // Sleep for the specified interval
        sleep(CHECK_INTERVAL);
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the list of URLs from the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    url_status urls[MAX_URLS];
    int num_urls = 0;
    while (fgets(urls[num_urls].url, MAX_URL_LENGTH, file) != NULL) {
        urls[num_urls].url[strlen(urls[num_urls].url) - 1] = '\0'; // Remove the newline character
        num_urls++;
    }
    fclose(file);

    // Monitor the uptime of the URLs
    monitor_uptime(urls, num_urls);

    return 0;
}