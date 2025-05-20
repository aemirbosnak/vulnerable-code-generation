//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *file;
    char filename[50];
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(filename, sizeof(filename), "diary_%Y%m%d.txt", tm_now);

    file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary is full. Please delete some entries.\n");
                } else {
                    printf("Enter date (YYYY-MM-DD): ");
                    scanf("%s", entries[num_entries].date);
                    printf("Enter your entry:\n");
                    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                    entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';
                    num_entries++;
                    fprintf(file, "%s - %s\n", entries[num_entries-1].date, entries[num_entries-1].entry);
                    fclose(file);
                    file = fopen(filename, "a");
                }
                break;
            case 2:
                rewind(file);
                printf("\nDate\tEntry\n");
                while (fscanf(file, "%s - %[^\n]\n", entries[num_entries].date, entries[num_entries].entry)!= EOF) {
                    printf("%s\t%s\n", entries[num_entries].date, entries[num_entries].entry);
                    num_entries++;
                }
                break;
            case 3:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}