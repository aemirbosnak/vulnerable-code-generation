//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define MAX_HISTORY_LENGTH 10

struct website {
    char url[MAX_URL_LENGTH];
    int success_rate;
    time_t last_checked_time;
};

struct website_history {
    char url[MAX_URL_LENGTH];
    time_t last_failed_time;
    int num_failures;
};

int main(void) {
    struct website websites[MAX_HISTORY_LENGTH];
    int num_websites = 0;
    
    struct website_history website_history[MAX_HISTORY_LENGTH];
    int num_website_history = 0;

    char input;
    do {
        printf("Enter website url to monitor: ");
        char url[MAX_URL_LENGTH];
        scanf("%s", url);

        // check if website is already being monitored
        int website_index = -1;
        for (int i = 0; i < num_websites; i++) {
            if (strcmp(url, websites[i].url) == 0) {
                website_index = i;
            }
        }

        // if website is not being monitored, add to list
        if (website_index == -1) {
            // if number of websites being monitored exceeds max history length,
            // remove the oldest website monitored
            if (num_websites >= MAX_HISTORY_LENGTH) {
                for (int i = 0; i < num_websites - 1; i++) {
                    strcpy(websites[i].url, websites[i+1].url);
                    websites[i].success_rate = websites[i+1].success_rate;
                    websites[i].last_checked_time = websites[i+1].last_checked_time;
                }
                num_websites--;
            }

            // add new website
            strcpy(websites[num_websites].url, url);
            websites[num_websites].success_rate = 0;
            websites[num_websites].last_checked_time = time(NULL);
            num_websites++;
        }

        // check website status and update success rate
        // if success rate goes below 50%, add to website history
        int status = rand() % 2; // 0 for success, 1 for failure
        websites[website_index].success_rate = ((websites[website_index].success_rate * 4) + (status ? 0 : 1)) / 5;
        if (websites[website_index].success_rate < 50) {
            // check if website is already in website history
            int website_history_index = -1;
            for (int i = 0; i < num_website_history; i++) {
                if (strcmp(url, website_history[i].url) == 0) {
                    website_history_index = i;
                    break;
                }
            }

            // if website is not in website history, add to list
            if (website_history_index == -1) {
                // if number of websites in website history exceeds max history length,
                // remove the oldest website monitored
                if (num_website_history >= MAX_HISTORY_LENGTH) {
                    for (int i = 0; i < num_website_history - 1; i++) {
                        strcpy(website_history[i].url, website_history[i+1].url);
                        website_history[i].last_failed_time = website_history[i+1].last_failed_time;
                        website_history[i].num_failures = website_history[i+1].num_failures;
                    }
                    num_website_history--;
                }

                // add new website to website history
                strcpy(website_history[num_website_history].url, url);
                website_history[num_website_history].last_failed_time = time(NULL);
                website_history[num_website_history].num_failures = 1;
                num_website_history++;
            } else {
                // update website history
                website_history[website_history_index].last_failed_time = time(NULL);
                website_history[website_history_index].num_failures++;
            }
        }

        // print summary of website status and website history
        printf("Website status: %s\n", status ? "FAILURE" : "SUCCESS");
        printf("Website success rate: %d%%\n", websites[website_index].success_rate);
        printf("Website history:\n");
        for (int i = 0; i < num_website_history; i++) {
            printf("- %s\n", website_history[i].url);
            printf("    Last failed: %s", ctime(&website_history[i].last_failed_time));
            printf("    Number of failures: %d\n", website_history[i].num_failures);
        }

        // prompt user to continue or exit program
        printf("Press any key to add another website or enter 'q' to quit: ");
        scanf(" %c", &input);
    } while (input != 'q');

    return 0;
}