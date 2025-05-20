//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[10];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int i;
    time_t now;
    struct tm *tm;

    file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No diary file found.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s %s", entries[num_entries].date, entries[num_entries].time, entries[num_entries].entry) == 3) {
        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            printf("Maximum number of entries reached.\n");
            break;
        }
    }

    fclose(file);

    while (1) {
        printf("Digital Diary\n");
        printf("-----------------\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter the time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter your entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
                if (num_entries == MAX_ENTRIES) {
                    printf("Maximum number of entries reached.\n");
                } else {
                    printf("Entry added successfully.\n");
                }
                break;
            case 2:
                printf("Date\tTime\tEntry\n");
                for (i = 0; i < num_entries; i++) {
                    printf("%s\t%s\t%s\n", entries[i].date, entries[i].time, entries[i].entry);
                }
                break;
            case 3:
                printf("Enter the keyword to search: ");
                scanf("%s", entries[num_entries].entry);
                for (i = 0; i < num_entries; i++) {
                    if (strstr(entries[i].entry, entries[num_entries].entry)!= NULL) {
                        printf("%s\t%s\t%s\n", entries[i].date, entries[i].time, entries[i].entry);
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}