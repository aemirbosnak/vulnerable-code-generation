//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_URL_LENGTH 2048
#define MAX_HISTORY_LENGTH 100

typedef struct {
    char url[MAX_URL_LENGTH];
    time_t timestamp;
} BrowserHistoryEntry;

typedef struct {
    BrowserHistoryEntry entries[MAX_HISTORY_LENGTH];
    int count;
} BrowserHistory;

void initialize_history(BrowserHistory *history) {
    history->count = 0;
}

void add_history_entry(BrowserHistory *history, const char *url) {
    if (history->count < MAX_HISTORY_LENGTH) {
        strncpy(history->entries[history->count].url, url, MAX_URL_LENGTH);
        history->entries[history->count].timestamp = time(NULL);
        history->count++;
    } else {
        printf("Browser history is full!\n");
    }
}

void display_history(const BrowserHistory *history) {
    printf("\nBrowser History:\n");
    for (int i = 0; i < history->count; i++) {
        printf("%d. %s - %s", i + 1, history->entries[i].url, ctime(&history->entries[i].timestamp));
    }
}

void display_menu() {
    printf("\n===== Simple Browser Menu =====\n");
    printf("1. Visit URL\n");
    printf("2. Show History\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

void visit_url(BrowserHistory *history) {
    char url[MAX_URL_LENGTH];

    printf("Enter URL to visit: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = 0;  // Remove newline character

    if (strlen(url) > 0) {
        printf("Visiting: %s\n", url);
        add_history_entry(history, url);
    } else {
        printf("Invalid URL!\n");
    }
}

int main() {
    BrowserHistory history;
    initialize_history(&history);

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character after choice input

        switch (choice) {
            case 1:
                visit_url(&history);
                break;
            case 2:
                display_history(&history);
                break;
            case 3:
                printf("Exiting the browser...\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }

    return 0;
}