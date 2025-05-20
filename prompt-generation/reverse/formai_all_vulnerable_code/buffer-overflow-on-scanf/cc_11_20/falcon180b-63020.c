//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];
    char filename[50] = "diary.txt";
    char choice;
    time_t now;

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_entries >= MAX_ENTRIES) {
                printf("Error: Diary is full.\n");
            } else {
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter the time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter your entry:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';
                num_entries++;
                printf("Entry saved.\n");
            }
            break;
        case '2':
            printf("\nAll Entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
            }
            break;
        case '3':
            printf("\nEnter the date to search for (YYYY-MM-DD): ");
            scanf("%s", entries[num_entries].date);
            printf("\nEntry found:\n");
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].date, entries[num_entries].date) == 0) {
                    printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
                }
            }
            break;
        case '4':
            printf("Exiting...\n");
            fclose(diary);
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}