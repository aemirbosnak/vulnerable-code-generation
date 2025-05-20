//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_URL_LEN 50
#define MAX_TIME 20 // In seconds

// Declare a struct to represent a URL
typedef struct {
    char url[MAX_URL_LEN];
    time_t last_checked;
    bool is_up;
} url_data;

// Function to check if a URL is up
bool check_url(char* url) {
    // In the post-apocalyptic world, internet may not exist anymore
    // So we will simulate the check by generating a random number
    int random_num = rand() % 10;
    if (random_num < 8) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Declare variables
    url_data urls[MAX_URLS];
    int num_urls = 0;
    char input_url[MAX_URL_LEN];
    time_t current_time;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Program introduction
    printf("Welcome to the website uptime monitor!\n");
    printf("Here you can monitor up to %d websites for their uptime.\n", MAX_URLS);

    // Loop to enter websites to monitor
    while (num_urls < MAX_URLS) {
        printf("Enter a website to monitor: ");
        scanf("%s", input_url);

        // Check if URL already exists in the list
        bool url_exists = false;
        for (int i = 0; i < num_urls; i++) {
            if (strcmp(urls[i].url, input_url) == 0) {
                url_exists = true;
                printf("This URL is already being monitored.\n");
                break;
            }
        }

        // Add URL to list if it doesn't already exist
        if (!url_exists) {
            strcpy(urls[num_urls].url, input_url);
            urls[num_urls].last_checked = time(NULL);
            urls[num_urls].is_up = true;
            num_urls++;

            printf("Website added to monitoring list.\n");
        }

        // Check if user wants to add more URLs
        char choice;
        printf("Do you want to add more websites? (Y/N) ");
        scanf(" %c", &choice);
        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

    // Main program loop to check URLs
    while (true) {
        // Check each URL in the list and update its status
        for (int i = 0; i < num_urls; i++) {
            current_time = time(NULL);

            // Check if enough time has passed since last check
            if (difftime(current_time, urls[i].last_checked) > MAX_TIME) {
                // Check if website is up
                urls[i].is_up = check_url(urls[i].url);

                // Update last check time
                urls[i].last_checked = time(NULL);
            }
        }

        // Display the status of each URL
        for (int i = 0; i < num_urls; i++) {
            printf("Website: %s - Status: %s\n", urls[i].url, urls[i].is_up ? "UP" : "DOWN");
        }

        // Wait for a few seconds before checking again
        printf("Waiting for %d seconds before checking websites again...\n\n", MAX_TIME);
        sleep(MAX_TIME);
    }

    return 0;
}