//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_URLS 10     // Maximum number of URLs to monitor
#define TIMEOUT 30      // Timeout for each URL check in seconds
#define INTERVAL 60     // Interval between monitoring checks in seconds

int main() {
    // Array of URLs to monitor
    char* urls[MAX_URLS] = {"https://google.com", "https://facebook.com", "https://amazon.com"};

    // Get the current time
    time_t current_time;
    time(&current_time);

    // Array to store the last check time for each URL
    time_t last_check[MAX_URLS];
    for (int i = 0; i < MAX_URLS; i++) {
        last_check[i] = current_time;
    }

    // Loop forever
    while(true) {
        // Loop through each URL and check its uptime
        for (int i = 0; i < MAX_URLS; i++) {
            // Get the current time
            time(&current_time);
            // Check if it's time to check this URL again
            if (current_time - last_check[i] >= INTERVAL) {
                // Update the last check time
                last_check[i] = current_time;
                // Start a child process to check the URL
                int pid = fork();
                if (pid == 0) {
                    // Child process, check the URL
                    char command[100];
                    sprintf(command, "curl -s -I -o /dev/null -w \"%%{http_code}\" %s | grep -q 200", urls[i]);
                    int result = system(command);
                    // Print the result
                    if (result == 0) {
                        printf("%s is up\n", urls[i]);
                    } else {
                        printf("%s is down\n", urls[i]);
                    }
                    // Exit the child process
                    exit(0);
                } else {
                    // Parent process, wait for the child process to finish
                    sleep(TIMEOUT);
                }
            }
        }
        // Sleep for the interval before checking again
        sleep(INTERVAL);
    }

    return 0;
}