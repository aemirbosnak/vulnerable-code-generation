//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1000

struct DiaryEntry {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct DiaryEntry entry;
    time_t now;
    char filename[50];
    int choice;

    // Get the current date and time
    time(&now);
    strftime(entry.date, 20, "%Y-%m-%d", localtime(&now));
    strftime(entry.time, 20, "%H:%M:%S", localtime(&now));

    // Ask the user for the diary filename
    printf("Enter the diary filename: ");
    scanf("%s", filename);

    // Open the diary file
    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    // Main menu
    do {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Write a new entry
                printf("Enter your entry (maximum %d characters): ", MAX_ENTRY_LENGTH);
                scanf("%[^\n]", entry.entry);
                fprintf(diary, "%s %s: %s\n", entry.date, entry.time, entry.entry);
                printf("Entry saved.\n");
                break;
            case 2:
                // Read entries
                rewind(diary);
                while (fgets(entry.entry, MAX_ENTRY_LENGTH, diary)!= NULL) {
                    printf("%s %s: %s", entry.date, entry.time, entry.entry);
                }
                break;
            case 3:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    // Close the diary file
    fclose(diary);

    return 0;
}