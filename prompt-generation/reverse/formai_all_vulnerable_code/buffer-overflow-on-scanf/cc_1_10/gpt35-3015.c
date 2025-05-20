//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LENGTH 200
#define MAX_TIMEOUT 5

typedef struct {
    char url[MAX_URL_LENGTH];
    bool is_up;
    time_t last_checked;
} Website;

void display_menu();
void add_website(Website websites[], int *website_count);
void check_website(Website *website);
void print_websites(Website websites[], int website_count);

int main() {
    Website websites[10];
    int website_count = 0;
    char choice;

    do {
        display_menu();
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                add_website(websites, &website_count);
                break;
            case '2':
                print_websites(websites, website_count);
                break;
            case '3':
                for (int i = 0; i < website_count; i++) {
                    check_website(&websites[i]);
                }
                break;
            case '4':
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

        printf("\n\n");

    } while (choice != '4');

    return 0;
}

void display_menu() {
    printf("==============================\n");
    printf("Website Uptime Monitor Program\n");
    printf("==============================\n");
    printf("1. Add website for monitoring\n");
    printf("2. View all websites being monitored\n");
    printf("3. Check all websites for uptime and downtime\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void add_website(Website websites[], int *website_count) {
    if (*website_count >= 10) {
        printf("\nMaximum number of websites reached!");
        return;
    }

    Website new_website;

    printf("\nEnter website URL: ");
    scanf(" %s", new_website.url);

    new_website.is_up = true;
    new_website.last_checked = time(NULL);

    websites[*website_count] = new_website;
    *website_count += 1;

    printf("\nWebsite added for monitoring.");
}

void check_website(Website *website) {
    srand(time(NULL));
    int random_num = rand() % 10;

    if (random_num < 5) {
        website->is_up = false;
    }
    else {
        website->is_up = true;
    }

    website->last_checked = time(NULL);
}

void print_websites(Website websites[], int website_count) {
    if (website_count == 0) {
        printf("\nNo websites added for monitoring.");
        return;
    }

    printf("\n=== List of Websites Being Monitored ===");

    for (int i = 0; i < website_count; i++) {
        printf("\n%s - Last Checked: %s", websites[i].url, ctime(&websites[i].last_checked));

        if (websites[i].is_up) {
            printf("Website is currently up.");
        }
        else {
            printf("Website is currently down.");
        }
    }
}