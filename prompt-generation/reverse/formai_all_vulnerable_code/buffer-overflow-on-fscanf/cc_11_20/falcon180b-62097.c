//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE* diary;
    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (fscanf(diary, "%s %s", entries[num_entries].date, entries[num_entries].entry)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Error: maximum number of entries reached.\n");
            exit(1);
        }
    }

    fclose(diary);

    char choice;
    while (1) {
        printf("Digital Diary\n");
        printf("a. Add entry\n");
        printf("b. View entries\n");
        printf("c. Search entries\n");
        printf("d. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Error: maximum number of entries reached.\n");
                    break;
                }
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
                break;
            case 'b':
                printf("Viewing entries...\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s - %s\n", entries[i].date, entries[i].entry);
                }
                break;
            case 'c':
                printf("Enter search term: ");
                scanf("%s", entries[num_entries].entry);
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(entries[i].entry, entries[num_entries].entry) == 0) {
                        printf("%s - %s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;
            case 'd':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}