//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DiaryEntry {
    char date[11];
    char title[50];
    char content[1000];
};

void addEntry(FILE *file) {
    struct DiaryEntry entry;
    printf("\nEnter date in format DD/MM/YYYY: ");
    scanf("%s", entry.date);
    getchar(); // Clear the newline from the input buffer
    printf("Enter a title for the entry: ");
    fgets(entry.title, sizeof(entry.title), stdin);
    printf("Enter the content for the entry: ");
    fgets(entry.content, sizeof(entry.content), stdin);
    fprintf(file, "%s\n%s\n%s\n", entry.date, entry.title, entry.content);
    printf("\nEntry added successfully!\n");
}

void viewEntries(FILE *file) {
    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
}

int main() {
    FILE *file = fopen("diary.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!");
        return 1;
    }

    printf("Welcome to your digital diary!\n");
    printf("What would you like to do?\n");

    int choice;
    do {
        printf("\n1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(file);
                break;
            case 2:
                printf("\nAll entries:\n");
                viewEntries(file);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, try again.\n");
        }
    } while (choice != 3);

    fclose(file);
    return 0;
}