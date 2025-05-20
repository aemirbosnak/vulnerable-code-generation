//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 2048

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *file;
    char filename[50];
    char choice;
    int count = 0;
    Entry entries[MAX_ENTRIES];

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter a filename (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                count++;
                printf("\nDate (dd/mm/yyyy): ");
                scanf("%s", entries[count-1].date);
                printf("Time (hh:mm:ss): ");
                scanf("%s", entries[count-1].time);
                printf("Entry: ");
                fgets(entries[count-1].entry, MAX_ENTRY_LENGTH, stdin);
                fprintf(file, "%s %s\n%s\n", entries[count-1].date, entries[count-1].time, entries[count-1].entry);
                fclose(file);
                file = fopen(filename, "a");
                break;
            case '2':
                rewind(file);
                printf("\n");
                while (fgets(entries[count].entry, MAX_ENTRY_LENGTH, file)!= NULL) {
                    sscanf(entries[count].entry, "%s %s\n%[^\n]", entries[count].date, entries[count].time, entries[count].entry);
                    printf("%s %s\n%s\n", entries[count].date, entries[count].time, entries[count].entry);
                    count++;
                }
                break;
            case '3':
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}