//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
/* 
 * CODEMONITOR - A WEBSITE UPTIME MONITOR
 * 
 * In fair cyberspace, where we lay our scene,
 * From ancient code break to new technologies,
 * Where bitwise magic makes the code so clean,
 * There's a tool we use to keep our sites in ease.
 *
 * With CodeMonitor, we check the uptime rate
 * Of websites, pages, and their every link,
 * And when they're down, we do not hesitate,
 * But quickly fix the issue, that's what we think.
 *
 * To create this tool, we start with C,
 * And use a socket to connect and bind,
 * Then send an HTTP request, that's the key,
 * And read the response to see what we find.
 *
 * If we receive a "200 OK" code,
 * That means the website is alive and well,
 * But if it's not, then we must hit the road,
 * And fix the problem, whatever it may dwell.
 *
 * We'll use timers, threads, and even more,
 * To make this program fast and efficient,
 * And when errors arise, we'll not ignore,
 * But handle them gracefully, with no dissent.
 *
 * So let us create a monitor so fine,
 * That Romeo and Juliet would envy,
 * And keep our websites up and running fine,
 * For all the world to see and feel so lively.
 */

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <regex.h>
#include <pthread.h>
#include <sys/time.h>

#define TIMEOUT 5 // Timeout in seconds
#define MAX_URL 100 // Maximum URL length
#define MAX_BUFFER 1024 // Maximum buffer length
#define THREADS 10 // Maximum number of threads

void check_website(char *url);
void *check_thread(void *url);

int main(int argc, char *argv[]) {
    // Check if the user provided a URL to monitor
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    check_website(argv[1]);

    return 0;
}

void check_website(char *url) {
    // Declare variables
    int sockfd, port, bytes, status;
    struct addrinfo hints, *res;
    char request[MAX_BUFFER], response[MAX_BUFFER], *headers_end;
    regex_t regex;
    regmatch_t matches[MAX_BUFFER];
    pthread_t threads[THREADS];
    struct timeval start, end;
    double elapsed_time;
    int i;

    // Set the port to HTTP (80) by default
    port = 80;

    // Use regular expressions to match the URL
    regcomp(&regex, "^http://(.*):?([0-9]*)/(.*)$", REG_EXTENDED);
    status = regexec(&regex, url, MAX_BUFFER, matches, 0);
    if (status != REG_NOMATCH) {
        // Extract the hostname and port from the URL
        char hostname[MAX_URL];
        memset(hostname, 0, MAX_URL);
        memcpy(hostname, &url[matches[1].rm_so], matches[1].rm_eo - matches[1].rm_so);
        if (matches[2].rm_so >= 0 && matches[2].rm_so < matches[2].rm_eo) {
            port = atoi(&url[matches[2].rm_so]);
        }

        // Extract the path from the URL
        char path[MAX_URL];
        memset(path, 0, MAX_URL);
        memcpy(path, &url[matches[3].rm_so], matches[3].rm_eo - matches[3].rm_so);

        // Create the HTTP request
        snprintf(request, MAX_BUFFER, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

        // Initialize the hints structs
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        // Get the address info for the hostname
        getaddrinfo(hostname, "80", &hints, &res);

        // Connect to the hostname
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        connect(sockfd, res->ai_addr, res->ai_addrlen);

        // Start the timer
        gettimeofday(&start, NULL);

        // Send the HTTP request
        send(sockfd, request, strlen(request), 0);

        // Receive the HTTP response
        bytes = recv(sockfd, response, MAX_BUFFER - 1, 0);

        // Stop the timer
        gettimeofday(&end, NULL);
        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 0.000001;

        // Check if the request timed out
        if (elapsed_time >= TIMEOUT) {
            printf("Website is down (timeout)\n");
            return;
        }

        // Check if the response is valid
        if (bytes <= 0) {
            printf("Website is down (no response)\n");
            return;
        }

        // Check if the response contains the string "200 OK"
        response[bytes] = '\0';
        headers_end = strstr(response, "\r\n\r\n");
        if (headers_end == NULL) {
            printf("Website is down (invalid response)\n");
            return;
        }

        if (strstr(response, "200 OK") == NULL) {
            printf("Website is down (error response)\n");
            return;
        }

        // The website is up, now let's check each link on the page
        printf("Website is up\n");

        // Extract all links from the response using regular expressions
        regcomp(&regex, "<a (.*?)href=\"(.*?)\"(.*?)>", REG_EXTENDED);
        char *cur = response;
        while (regexec(&regex, cur, MAX_BUFFER, matches, 0) != REG_NOMATCH) {
            char link[MAX_URL];
            memset(link, 0, MAX_URL);
            memcpy(link, &cur[matches[2].rm_so], matches[2].rm_eo - matches[2].rm_so);
            cur += matches[2].rm_eo;

            // Create a thread to check each link
            pthread_create(&threads[i], NULL, check_thread, link);
            i = (i + 1) % THREADS;
        }

        // Wait for all threads to finish
        for (int j = 0; j < i; j++) {
            pthread_join(threads[j], NULL);
        }

    } else {
        printf("Invalid URL\n");
        return;
    }
}

void *check_thread(void *url) {
    check_website(url);
    pthread_exit(NULL);
}