//FormAI DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ENTRY_SIZE 500
#define DATE_SIZE 50
#define DIARY_FILE_NAME "romantic_diary.txt"

void add_entry(char *entry, char *date);
void view_diary();

int main() {
    int choice;
    char entry[ENTRY_SIZE];
    char date[DATE_SIZE];

    while (1) {
        printf("Welcome to romantic diary.\n");
        printf("1. Add a new entry.\n");
        printf("2. View diary.\n");
        printf("3. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Write your entry: ");
                scanf("\n%[^\n]s", entry);
                time_t now = time(NULL);
                strftime(date, DATE_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&now));
                add_entry(entry, date);
                printf("Your entry has been added to the diary!\n");
                break;
            case 2:
                view_diary();
                break;
            case 3:
                printf("\nGoodbye! Come back soon.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_entry(char *entry, char *date) {
    FILE *file = fopen(DIARY_FILE_NAME, "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s - %s\n", date, entry);
    fclose(file);
}

void view_diary() {
    char line[ENTRY_SIZE];
    FILE *file = fopen(DIARY_FILE_NAME, "r");

    if (file == NULL) {
        printf("No entries found.\n");
        return;
    }

    printf("\n\n   Welcome to your Romantic Diary!\n\n");

    while (fgets(line, ENTRY_SIZE, file) != NULL) {
        printf("%s", line);
    }

    printf("\n\nEnd of Diary Entries.\n\n");
    fclose(file);
}