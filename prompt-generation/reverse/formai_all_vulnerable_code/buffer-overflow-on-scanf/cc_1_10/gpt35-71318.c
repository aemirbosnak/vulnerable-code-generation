//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define struct for diary entry
struct Entry {
    int day;
    char month[10];
    char year[5];
    char text[500];
};

// Function prototypes
void displayMenu();
void createEntry();
void viewEntry();
void searchEntry();
void editEntry();
void deleteEntry();
void saveToFile();

// Global variables
struct Entry diary[100];
int numEntries = 0;

int main() {
    int choice;
    do {
        displayMenu();
        printf("Please choose an option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                editEntry();
                break;
            case 5:
                deleteEntry();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 7);
    return 0;
}

// Display the main menu
void displayMenu() {
    printf("My Medieval Digital Diary\n");
    printf("-------------------------\n");
    printf("1 - Create a new entry\n");
    printf("2 - View an existing entry\n");
    printf("3 - Search for an entry\n");
    printf("4 - Edit an existing entry\n");
    printf("5 - Delete an entry\n");
    printf("6 - Save diary to file\n");
    printf("7 - Exit\n");
}

// Create a new diary entry
void createEntry() {
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%d/%s/%s", &diary[numEntries].day, diary[numEntries].month, diary[numEntries].year);
    printf("Enter your text (max 500 characters):\n");
    getchar(); // Clear input buffer
    fgets(diary[numEntries].text, sizeof(diary[numEntries].text), stdin);
    numEntries++;
}

// View an existing diary entry
void viewEntry() {
    if (numEntries == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }
    int index;
    printf("Enter the index of the entry you want to view (1-%d): ", numEntries);
    scanf("%d", &index);
    index--;
    printf("Entry %d:\n", index+1);
    printf("Date: %d/%s/%s\n", diary[index].day, diary[index].month, diary[index].year);
    printf("Text: %s\n", diary[index].text);
}

// Search for an existing diary entry
void searchEntry() {
    if (numEntries == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }
    char term[20];
    printf("Enter search term: ");
    scanf("%s", term);
    int count = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].text, term) != NULL) {
            printf("Entry %d:\n", i+1);
            printf("Date: %d/%s/%s\n", diary[i].day, diary[i].month, diary[i].year);
            printf("Text: %s\n", diary[i].text);
            count++;
        }
    }
    if (count == 0) {
        printf("No matching entries found.\n");
    } else {
        printf("%d matching entries found.\n", count);
    }
}

// Edit an existing diary entry
void editEntry() {
    if (numEntries == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }
    int index;
    printf("Enter the index of the entry you want to edit (1-%d): ", numEntries);
    scanf("%d", &index);
    index--;
    printf("Editing entry %d:\n", index+1);
    printf("Old text: %s\n", diary[index].text);
    printf("Enter new text (max 500 characters):\n");
    getchar(); // Clear input buffer
    fgets(diary[index].text, sizeof(diary[index].text), stdin);
}

// Delete an existing diary entry
void deleteEntry() {
    if (numEntries == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }
    int index;
    printf("Enter the index of the entry you want to delete (1-%d): ", numEntries);
    scanf("%d", &index);
    index--;
    for (int i = index; i < numEntries-1; i++) {
        diary[i] = diary[i+1];
    }
    numEntries--;
    printf("Entry deleted.\n");
}

// Save diary to a text file
void saveToFile() {
    if (numEntries == 0) {
        printf("There are no entries in the diary.\n");
        return;
    }
    FILE *fp;
    char fileName[20];
    printf("Enter file name to save as (max 20 characters): ");
    scanf("%s", fileName);
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error: unable to create file.\n");
        return;
    }
    fprintf(fp, "My Medieval Digital Diary\n");
    fprintf(fp, "-------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        fprintf(fp, "Entry %d:\n", i+1);
        fprintf(fp, "Date: %d/%s/%s\n", diary[i].day, diary[i].month, diary[i].year);
        fprintf(fp, "Text: %s\n", diary[i].text);
    }
    fclose(fp);
    printf("Diary saved to file successfully!\n");
}