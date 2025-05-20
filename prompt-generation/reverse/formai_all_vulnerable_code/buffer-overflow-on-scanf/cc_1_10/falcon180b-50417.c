//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[11];
    char time[9];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *fp;
    char filename[20];
    int num_entries = 0;
    struct entry entries[MAX_ENTRIES];
    char choice;
    int index;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter the time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter your entry:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
                break;

            case '2':
                printf("You have %d entries:\n", num_entries);
                for (index = 0; index < num_entries; index++) {
                    printf("%s %s - %s\n", entries[index].date, entries[index].time, entries[index].content);
                }
                break;

            case '3':
                printf("Enter the date to search for (YYYY-MM-DD): ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("File not found.\n");
                }
                else {
                    while (fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, fp)!= NULL) {
                        num_entries++;
                    }
                    fclose(fp);
                    printf("You have %d entries for %s:\n", num_entries, filename);
                    for (index = 0; index < num_entries; index++) {
                        printf("%s %s - %s\n", entries[index].date, entries[index].time, entries[index].content);
                    }
                }
                break;

            case '4':
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}