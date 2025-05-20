//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 10
#define RESPONSE_TIME_THRESHOLD 5000 // threshold in milliseconds
#define CHECK_FREQUENCY 60 // check frequency in seconds

typedef struct {
    char url[100];
    time_t last_checked_time;
    int status_code;
    int response_time;
} UrlStatus;

void print_header() {
    printf("\n--------------------------------------------------\n");
    printf("\tWelcome to Website Uptime Monitor\n");
    printf("--------------------------------------------------\n\n");
}

void print_menu() {
    printf("1. Add URL\n");
    printf("2. Remove URL\n");
    printf("3. View Status\n");
    printf("4. Exit\n\n");
}

int get_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int check_url(const char *url) {
    // Simulate checking of website status and response time
    srand(time(NULL));
    int status_code = rand() % 6 + 200;
    int response_time = rand() % 3000 + 1000;
    printf("*** Checking status of %s... ***\n", url);
    printf("Status Code: %d\n", status_code);
    printf("Response Time: %dms\n\n", response_time);
    return response_time;
}

void add_url(UrlStatus *url_statuses, int *num_urls) {
    if (*num_urls == MAX_URLS) {
        printf("You have reached the maximum number of URLs!\n\n");
        return;
    }
    char url[100];
    printf("Enter the URL to monitor: ");
    scanf("%s", url);
    printf("\n");
    strcpy(url_statuses[*num_urls].url, url);
    (*num_urls)++;
    printf("URL '%s' added successfully!\n\n", url);
}

void remove_url(UrlStatus *url_statuses, int *num_urls) {
    if (*num_urls == 0) {
        printf("There are no URLs to remove!\n\n");
        return;
    }
    char url[100];
    printf("Enter the URL to remove: ");
    scanf("%s", url);
    printf("\n");
    int i;
    for (i = 0; i < *num_urls; i++) {
        if (strcmp(url_statuses[i].url, url) == 0) {
            int j;
            for (j = i+1; j < *num_urls; j++) {
                url_statuses[j-1] = url_statuses[j];
            }
            (*num_urls)--;
            printf("URL '%s' removed successfully!\n\n", url);
            return;
        }
    }
    printf("URL '%s' does not exist!\n\n", url);
}

void view_status(UrlStatus *url_statuses, int num_urls) {
    if (num_urls == 0) {
        printf("There are no URLs to view status!\n\n");
        return;
    }
    printf("URL\t\tStatus Code\tResponse Time\tLast Checked Time\n");
    int i;
    for (i = 0; i < num_urls; i++) {
        UrlStatus *url_status = &url_statuses[i];
        time_t current_time = time(NULL);
        if (difftime(current_time, url_status->last_checked_time) >= CHECK_FREQUENCY) {
            url_status->response_time = check_url(url_status->url);
            url_status->last_checked_time = time(NULL);
        }
        printf("%s\t%d\t%dms\t%s", url_status->url, url_status->status_code, url_status->response_time, ctime(&url_status->last_checked_time));
        if (url_status->response_time > RESPONSE_TIME_THRESHOLD) {
            printf("*** ALERT: The response time of %s is too slow! ***\n", url_status->url);
        }
    }
    printf("\n");
}

int main() {
    UrlStatus url_statuses[MAX_URLS];
    int num_urls = 0;

    print_header();
    while (1) {
        print_menu();
        int choice = get_menu_choice();
        switch (choice) {
            case 1:
                add_url(url_statuses, &num_urls);
                break;
            case 2:
                remove_url(url_statuses, &num_urls);
                break;
            case 3:
                view_status(url_statuses, num_urls);
                break;
            case 4:
                printf("Thank you for using Website Uptime Monitor!\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
    return 0;
}