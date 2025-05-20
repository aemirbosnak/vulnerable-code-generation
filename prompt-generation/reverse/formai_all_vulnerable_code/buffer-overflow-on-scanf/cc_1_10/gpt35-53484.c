//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 100
#define MAX_TRIES 3

bool check_url(char *url) {
    printf("Checking up on %s\n", url);
    if (system(NULL)) { // Check if shell is available
        char command[MAX_URL_LENGTH + 50];
        int response = 0;
        const char* format = "curl -Is %s | head -n 1 | grep -q 200"; // Checking HTTP response for 200 status code
        sprintf(command, format, url);
        for(int i=0; i<MAX_TRIES; i++) { // Maximum 3 tries for each URL
            response = system(command);
            if(response == 0) {
                printf("%s is up and running!\n", url);
                return true;
            }
        }
        printf("%s is down right now.\n", url);
        return false;
    }
    else {
        printf("Error: Failed to locate shell\n");
        return false;
    }
}

void monitor_urls(char **urls, int count) {
    sleep(10); // Wait for 10 seconds before checking again
    for(int i=0; i<count; i++) {
        check_url(urls[i]);
    }
    monitor_urls(urls, count); //Call the function again to keep on checking
}

int main() {
    int count;
    printf("How many URLs would you like to monitor? ");
    scanf("%d", &count);
    char **urls = malloc(count * sizeof(char*)); // Allocate memory for the list of URLs
    for(int i=0; i<count; i++) {
        urls[i] = malloc(MAX_URL_LENGTH * sizeof(char)); // Allocate memory for each URL
        printf("Enter URL #%d: ", i+1);
        scanf("%s", urls[i]);
    }
    monitor_urls(urls, count);
    return 0;
}