//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
// include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum characters for diary entries and file name
#define MAX_ENTRY_SIZE 1000
#define FILE_NAME_SIZE 20

// function to display menu and get user input
int menu() {
    int choice;
    printf("Welcome to my digital diary!\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to add an entry to the diary
void add_entry(FILE* fp) {
    char entry[MAX_ENTRY_SIZE];
    printf("Enter your diary entry (max %d characters): ", MAX_ENTRY_SIZE);
    scanf(" %[^\n]", entry);
    fprintf(fp, "%s\n", entry);
    printf("Entry added successfully!\n");
}

// function to view all entries in the diary
void view_entries(FILE* fp) {
    char entry[MAX_ENTRY_SIZE];
    fseek(fp, 0, SEEK_SET);
    int count = 1;
    while (fgets(entry, MAX_ENTRY_SIZE, fp)) {
        printf("%d. %s\n", count, entry);
        count++;
    }
}

// function to search for an entry in the diary
void search_entry(FILE* fp) {
    char keyword[MAX_ENTRY_SIZE];
    printf("Enter a keyword to search for: ");
    scanf(" %[^\n]", keyword);
    fseek(fp, 0, SEEK_SET);
    char entry[MAX_ENTRY_SIZE];
    int count = 1;
    printf("Entries containing '%s':\n", keyword);
    while (fgets(entry, MAX_ENTRY_SIZE, fp)) {
        if (strstr(entry, keyword)) {
            printf("%d. %s\n", count, entry);
        }
        count++;
    }
}

// main function
int main() {
    char file_name[FILE_NAME_SIZE];
    printf("Enter the name of your diary file: ");
    scanf("%s", file_name);
    strcat(file_name, ".txt");
    FILE* fp = fopen(file_name, "a+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_entry(fp);
                break;
            case 2:
                view_entries(fp);
                break;
            case 3:
                search_entry(fp);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);
    fclose(fp);
    return 0;
}