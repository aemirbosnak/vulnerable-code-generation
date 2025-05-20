//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct Entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    int num_entries = 0;
    struct Entry entries[MAX_ENTRIES];
    char filename[50];
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    printf("Enter the name of the diary file: ");
    scanf("%s", filename);

    diary = fopen(filename, "r");

    if (diary == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        diary = fopen(filename, "w");
    }

    while (fscanf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content)!= EOF) {
        num_entries++;
    }

    fclose(diary);

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);

            printf("Enter the time (HH:MM): ");
            scanf("%s", entries[num_entries].time);

            printf("Enter your entry:\n");

            fflush(stdin);
            fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);

            num_entries++;

            diary = fopen(filename, "w");

            for (int i = 0; i < num_entries; i++) {
                fprintf(diary, "%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
            }

            fclose(diary);

            printf("Entry saved!\n");
            break;

        case 2:
            printf("Diary entries:\n");

            for (int i = 0; i < num_entries; i++) {
                printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
            }

            break;

        case 3:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}