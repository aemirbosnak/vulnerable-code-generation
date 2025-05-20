//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct Entry {
    int day;
    int month;
    int year;
    char text[256];
};

int main() {
    struct Entry entries[MAX_ENTRIES];
    int size = 0;

    while (1) {
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (size == MAX_ENTRIES) {
                printf("Error: diary is full\n");
                continue;
            }

            printf("Enter the date (dd/mm/yyyy): ");
            int day, month, year;
            scanf("%d/%d/%d", &day, &month, &year);

            printf("Enter the text: ");
            char text[256];
            scanf(" %[^\n]s", text);

            struct Entry newEntry = {day, month, year};
            strcpy(newEntry.text, text);

            entries[size++] = newEntry;

            printf("Entry added successfully\n");
        }
        else if (choice == 2) {
            if (size == 0) {
                printf("Diary is empty\n");
                continue;
            }

            printf("All entries:\n");

            for (int i = 0; i < size; i++) {
                struct Entry entry = entries[i];

                printf("%d/%d/%d: %s\n", entry.day, entry.month, entry.year, entry.text);
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice. Try again\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}