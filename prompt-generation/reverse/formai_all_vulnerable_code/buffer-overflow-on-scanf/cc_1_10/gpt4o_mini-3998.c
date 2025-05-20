//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256
#define MAX_HISTORY 10

typedef struct {
    char urls[MAX_HISTORY][MAX_URL_LENGTH];
    int count;
} History;

void displayMenu() {
    printf("\n--- Retro Browser Plugin ---\n");
    printf("1. Enter a URL\n");
    printf("2. View History\n");
    printf("3. Exit\n");
    printf("---------------------------\n");
}

void addToHistory(History* history, const char* url) {
    if (history->count < MAX_HISTORY) {
        strncpy(history->urls[history->count], url, MAX_URL_LENGTH);
        history->count++;
    } else {
        // Shift history to make room for new URL
        for (int i = 1; i < MAX_HISTORY; i++) {
            strncpy(history->urls[i - 1], history->urls[i], MAX_URL_LENGTH);
        }
        strncpy(history->urls[MAX_HISTORY - 1], url, MAX_URL_LENGTH);
    }
}

void viewHistory(History* history) {
    printf("\n--- Browsing History ---\n");
    for (int i = 0; i < history->count; i++) {
        printf("%d. %s\n", i + 1, history->urls[i]);
    }
}

void displayPage(const char* url) {
    printf("\n--- Displaying Page: %s ---\n", url);
    printf("This is a simulated web page for URL: %s\n", url);
    printf("Welcome to the retro browsing experience!\n");
    printf("Enjoy exploring and imagine the possibilities of the web!\n");
}

int main() {
    History history;
    history.count = 0;

    int choice;
    char url[MAX_URL_LENGTH];

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clean up newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, MAX_URL_LENGTH, stdin);
                url[strcspn(url, "\n")] = 0; // Remove trailing newline
                
                if (strlen(url) > 0) {
                    addToHistory(&history, url);
                    displayPage(url);
                } else {
                    printf("Invalid URL!\n");
                }
                break;

            case 2:
                viewHistory(&history);
                break;

            case 3:
                printf("Exiting the Retro Browser Plugin. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}