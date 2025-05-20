//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 256
#define MAX_NUM_WEBSITES 10

typedef struct {
    char url[MAX_URL_LENGTH];
    bool status;
} website;

int main() {
    website websites[MAX_NUM_WEBSITES];
    int num_websites;
    int i;

    printf("Enter the number of websites to monitor (up to %d): ", MAX_NUM_WEBSITES);
    scanf("%d", &num_websites);

    printf("Enter the URLs of the websites to monitor, one per line:\n");
    for (i = 0; i < num_websites; i++) {
        scanf("%s", websites[i].url);
        websites[i].status = true;
    }

    while (true) {
        printf("Monitoring...\n");

        for (i = 0; i < num_websites; i++) {
            // Ping the website
            // ...

            // If ping fails, mark website as down
            websites[i].status = false;

            // Send notification if website just went down
            if (!websites[i].status) {
                printf("ALERT: %s is down!\n", websites[i].url);
                // Send email, text message, etc.
                // ...
            }

            // Otherwise, mark website as up
            websites[i].status = true;
        }

        // Wait 5 minutes before pinging websites again
        sleep(300);
    }

    return 0;
}