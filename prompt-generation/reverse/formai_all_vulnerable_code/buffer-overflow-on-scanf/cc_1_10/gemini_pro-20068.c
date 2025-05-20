//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

typedef struct {
    char *text;
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(const char *text) {
    if (numEntries == MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    entries[numEntries].text = malloc(strlen(text) + 1);
    strcpy(entries[numEntries].text, text);
    entries[numEntries].timestamp = time(NULL);
    numEntries++;
}

void printEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n", entries[i].text);
        printf("Timestamp: %s\n\n", ctime(&entries[i].timestamp));
    }
}

void searchEntries(const char *query) {
    for (int i = 0; i < numEntries; i++) {
        if (strstr(entries[i].text, query) != NULL) {
            printf("%s\n", entries[i].text);
            printf("Timestamp: %s\n\n", ctime(&entries[i].timestamp));
        }
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    bool running = true;

    while (running) {
        printf("Enter a command (add, print, search, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter your entry: ");
            scanf(" %[^\n]", input);
            addEntry(input);
        } else if (strcmp(input, "print") == 0) {
            printEntries();
        } else if (strcmp(input, "search") == 0) {
            printf("Enter your search query: ");
            scanf(" %[^\n]", input);
            searchEntries(input);
        } else if (strcmp(input, "quit") == 0) {
            running = false;
        } else {
            printf("Invalid command.\n");
        }

        printf("\n");
    }

    for (int i = 0; i < numEntries; i++) {
        free(entries[i].text);
    }

    return 0;
}