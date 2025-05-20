//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    char choice;
    time_t now = time(NULL);

    struct tm *t = localtime(&now);
    strftime(filename, sizeof(filename), "diary-%Y-%m-%d.txt", t);

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("\nEnter your entry:\n");
            fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
            strcpy(entries[num_entries].date, asctime(t));
            strcpy(entries[num_entries].time, ctime(&now));
            num_entries++;
            break;

        case '2':
            printf("\nPrevious Entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s\n%s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
            }
            break;

        case '3':
            printf("\nExiting...\n");
            fclose(file);
            remove(filename);
            exit(0);

        default:
            printf("\nInvalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}