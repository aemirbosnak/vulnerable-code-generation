//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    char filename[100] = "diary.txt";
    diary = fopen(filename, "a+");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        system("clear");
        printf("Welcome to the Digital Diary!\n");
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Search for a specific entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Error: Maximum number of entries reached.\n");
            } else {
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);

                printf("Enter the time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);

                printf("Enter your entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';

                fprintf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry);
                num_entries++;

                printf("Entry saved successfully.\n");
            }
            break;

        case 2:
            rewind(diary);
            while (fgets(filename, sizeof(filename), diary)!= NULL) {
                printf("%s", filename);
            }
            break;

        case 3:
            printf("Enter the date to search for (YYYY-MM-DD): ");
            scanf("%s", filename);

            rewind(diary);
            while (fgets(filename, sizeof(filename), diary)!= NULL) {
                if (strcmp(filename, entries[num_entries - 1].date) == 0) {
                    printf("%s", filename);
                }
            }
            break;

        case 4:
            fclose(diary);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}