//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char title[50];
    char content[1000];
    time_t timestamp;
};

struct entry entries[MAX_ENTRIES];

int main() {
    int i;
    char input[100];
    int entry_count = 0;

    // Print greeting
    printf("Welcome to your Digital Diary!\n");

    // Main loop
    while (1) {
        // Print menu
        printf("Menu:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        // Get user input
        scanf("%d", &i);

        // Add entry
        if (i == 1) {
            printf("Enter title: ");
            scanf("%s", entries[entry_count].title);
            printf("Enter content: ");
            scanf("%s", entries[entry_count].content);
            entries[entry_count].timestamp = time(NULL);
            entry_count++;
            printf("Entry added successfully!\n");
        }

        // View entries
        else if (i == 2) {
            printf("Your entries:\n");
            for (int j = 0; j < entry_count; j++) {
                printf("%s - %s\n", entries[j].title, entries[j].content);
            }
        }

        // Exit
        else if (i == 3) {
            break;
        }

        // Invalid input
        else {
            printf("Invalid input!\n");
        }
    }

    return 0;
}