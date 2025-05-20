//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Define the maximum number of websites to monitor
#define MAX_WEBSITES 100

// Define the maximum length of a website URL
#define MAX_URL_LENGTH 256

// Structure to store information about a website
struct website {
    char url[MAX_URL_LENGTH];
    int status;  // 0 = down, 1 = up
    time_t last_checked;
};

// Array to store the websites to monitor
struct website websites[MAX_WEBSITES];

// Mutex to protect the websites array
pthread_mutex_t websites_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to check the status of a website
int check_website(char *url) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, url, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, url);
    strcat(request, "\r\nConnection: close\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return -1;
    }

    // Receive a response from the server
    char response[4096];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        perror("recv");
        return -1;
    }

    // Check the response code
    char *status_code = strstr(response, "HTTP/1.1 ");
    if (status_code == NULL) {
        return -1;
    }
    status_code += 9;
    int status = atoi(status_code);

    // Close the socket
    close(sockfd);

    // Return the status code
    return status;
}

// Function to monitor a website
void *monitor_website(void *arg) {
    struct website *website = (struct website *) arg;

    while (1) {
        // Check the status of the website
        int status = check_website(website->url);

        // Update the website's status
        pthread_mutex_lock(&websites_mutex);
        website->status = status;
        website->last_checked = time(NULL);
        pthread_mutex_unlock(&websites_mutex);

        // Sleep for 60 seconds
        sleep(60);
    }

    return NULL;
}

// Main function
int main() {
    // Read the list of websites to monitor from a file
    FILE *fp = fopen("websites.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    int i = 0;
    while (fscanf(fp, "%s", websites[i].url) != EOF) {
        i++;
    }

    fclose(fp);

    // Create a thread for each website
    pthread_t threads[MAX_WEBSITES];
    for (i = 0; i < MAX_WEBSITES; i++) {
        if (pthread_create(&threads[i], NULL, monitor_website, &websites[i]) != 0) {
            perror("pthread_create");
            return -1;
        }
    }

    // Join the threads
    for (i = 0; i < MAX_WEBSITES; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return -1;
        }
    }

    return 0;
}