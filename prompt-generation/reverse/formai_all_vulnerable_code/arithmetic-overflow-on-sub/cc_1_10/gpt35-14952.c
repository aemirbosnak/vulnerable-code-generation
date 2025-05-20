//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Define the maximum number of websites to monitor
#define MAX_WEBSITES 5

// Define the maximum length for website URLs
#define MAX_URL_LENGTH 50

// Define the interval at which to check website uptime (in seconds)
#define INTERVAL_SECONDS 60

// Define the maximum length for error messages
#define MAX_ERROR_LENGTH 100

// Define the structure to store website URL and status information
typedef struct {
    char url[MAX_URL_LENGTH];
    int status;
    time_t last_checked;
} Website;

// Declare the function to check the uptime for a single website
int check_website_up(Website* website);

// Declare the function to print the status of all monitored websites
void print_website_status(Website* websites, int num_websites);

int main() {
    // Declare an array of Websites to monitor
    Website websites[MAX_WEBSITES] = {
        {"www.knightscodex.com", 0, 0},
        {"www.dragonslair.com", 0, 0},
        {"www.castlekeep.net", 0, 0},
        {"www.medievalmarketplace.com", 0, 0},
        {"www.actionjousting.com", 0, 0}
    };

    int num_websites = sizeof(websites) / sizeof(Website);

    printf("Starting website uptime monitor...\n");

    while (1) {
        // Loop through each website and check its status
        for (int i = 0; i < num_websites; i++) {
            time_t current_time = time(NULL);

            // Only check the website if the elapsed time since last checked is greater than INTERVAL_SECONDS
            if (current_time - websites[i].last_checked >= INTERVAL_SECONDS) {
                int status = check_website_up(&websites[i]);

                if (status != 0) {
                    char error_message[MAX_ERROR_LENGTH];
                    snprintf(error_message, MAX_ERROR_LENGTH, "Error: %s is down!\n", websites[i].url);
                    printf("%s", error_message);
                } else {
                    printf("%s is up and running!\n", websites[i].url);
                }

                websites[i].status = status;
                websites[i].last_checked = current_time;
            }
        }

        print_website_status(websites, num_websites);

        sleep(INTERVAL_SECONDS);
    }

    return 0;
}

int check_website_up(Website* website) {
    // Pretend to check the website by generating a random number
    int random_number = rand() % 10;

    if (random_number == 0) {
        return 1; // Website is down
    } else {
        return 0; // Website is up
    }
}

void print_website_status(Website* websites, int num_websites) {
    printf("\nWebsite Status:\n");

    for (int i = 0; i < num_websites; i++) {
        if (websites[i].status != 0) {
            printf("%s is down.\n", websites[i].url);
        } else {
            printf("%s is up.\n", websites[i].url);
        }
    }

    printf("--------------------\n");
}