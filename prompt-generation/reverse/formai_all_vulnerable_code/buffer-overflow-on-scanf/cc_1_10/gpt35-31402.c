//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to add an entry to the digital diary
void add_entry(char* filename) {
    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    printf("Enter the date (in YYYY-MM-DD format): ");
    char date[15];
    scanf("%s", date);
    printf("Enter the entry:\n");
    char entry[500];
    fflush(stdin);
    fgets(entry, 500, stdin);
    fprintf(fp, "%s: %s\n", date, entry);
    fclose(fp);
    printf("Entry added successfully!\n");
}

// Function to view entries in the digital diary by date
void view_by_date(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    char date[15];
    printf("Enter the date to view (in YYYY-MM-DD format): ");
    scanf("%s", date);
    char line[520];
    int found = 0;
    while (fgets(line, sizeof(line), fp)) {
        char* ptr = strstr(line, date);
        if (ptr != NULL) {
            printf("%s", line);
            found = 1;
        }  
    }
    if (found == 0) {
        printf("No entries found for the given date.\n");
    }
    fclose(fp);
}

// Function to view all entries in the digital diary
void view_all_entries(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    char line[520];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line); 
    }
    fclose(fp);
}

// Function to clear all entries from the digital diary
void clear_entries(char* filename) {
    FILE* fp = fopen(filename, "w");
    fclose(fp);
    printf("All entries have been cleared.\n");
}

int main() {
    char filename[] = "digital_diary.txt";
    int choice;
    printf("Welcome to your digital diary!\n");
    do {
        printf("Please choose an option:\n");
        printf("1. Add an entry\n");
        printf("2. View entries by date\n");
        printf("3. View all entries\n");
        printf("4. Clear all entries\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(filename);
                break;
            case 2:
                view_by_date(filename);
                break;
            case 3:
                view_all_entries(filename);
                break;
            case 4:
                clear_entries(filename);
                break;
            case 5:
                printf("Thank you for using your digital diary!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}