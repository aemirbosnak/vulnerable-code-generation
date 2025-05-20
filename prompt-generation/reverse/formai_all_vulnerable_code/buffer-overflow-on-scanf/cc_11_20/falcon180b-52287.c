//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

int main() {
    FILE *fp;
    char filename[50];
    time_t now;
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    srand(time(NULL));
    now = time(NULL);
    strftime(filename, 50, "diary_%Y%m%d%H%M%S.txt", localtime(&now));
    fp = fopen(filename, "w+");

    if (fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    fprintf(fp, "Digital Diary\n\n");

    do {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Maximum number of entries reached.\n");
            } else {
                printf("Enter date (YYYYMMDD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                fprintf(fp, "%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                num_entries++;
            }
            break;

        case 2:
            rewind(fp);
            while (fgets(entries[num_entries].date, 20, fp)!= NULL) {
                printf("%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                num_entries++;
            }
            break;

        case 3:
            printf("Enter keyword to search: ");
            scanf("%s", entries[num_entries].entry);
            rewind(fp);
            while (fgets(entries[num_entries].date, 20, fp)!= NULL) {
                if (strstr(entries[num_entries].entry, entries[num_entries].date)!= NULL) {
                    printf("%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                }
            }
            break;

        case 4:
            fclose(fp);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}