//FormAI DATASET v1.0 Category: Digital Diary ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Function to display the menu options
void menu() {
    printf("=====================================\n");
    printf("           DIGITAL DIARY             \n");
    printf("=====================================\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
}

// Structure to store diary entries
struct Diary {
    char date[15];
    char entry[100];
};

// Function to add a new entry to the diary
void addEntry() {
    FILE *fp;
    struct Diary d;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[15];
    strftime(date, sizeof(date), "%d-%m-%Y", tm);
    strcpy(d.date, date);
    printf("Enter your diary entry (max 100 characters):\n");
    getchar(); // Clear input buffer
    fgets(d.entry, 100, stdin);
    fp = fopen("diary.txt", "a");
    fprintf(fp, "%s\n%s\n", d.date, d.entry);
    fclose(fp);
    printf("Entry added sucessfully!\n");
}

// Function to view all diary entries
void viewEntries() {
    FILE *fp;
    struct Diary d;
    int count = 0;
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("No entries found in diary.\n");
        return;
    }
    printf("=====================================\n");
    printf("           ALL DIARY ENTRIES         \n");
    printf("=====================================\n");
    while(fscanf(fp, "%s%s", d.date, d.entry) != EOF) {
        printf("%d.\n", ++count);
        printf("Date: %s\n", d.date);
        printf("Entry: %s\n\n", d.entry);
    }
    fclose(fp);
}

// Function to search for an entry given a keyword
void searchEntry() {
    FILE *fp;
    struct Diary d;
    char keyword[20];
    int count = 0, found = 0;
    printf("Enter keyword to search for:\n");
    getchar(); // Clear input buffer
    fgets(keyword, 20, stdin);
    keyword[strlen(keyword)-1] = '\0'; // Remove newline character from keyword
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("No entries found in diary.\n");
        return;
    }
    printf("=====================================\n");
    printf("        SEARCHED DIARY ENTRIES       \n");
    printf("=====================================\n");
    while(fscanf(fp, "%s%s", d.date, d.entry) != EOF) {
        // Check if keyword is present in current entry's text
        if(strstr(d.entry, keyword) != NULL) {
            printf("%d.\n", ++count);
            printf("Date: %s\n", d.date);
            printf("Entry: %s\n\n", d.entry);
            found = 1;
        }
    }
    fclose(fp);
    if(!found) printf("No entries found matching the keyword.\n");
}

// Function to clear the console screen
void clearScreen() {
    system("@cls||clear");
}

int main() {
    int option;
    do {
        clearScreen();
        menu();
        printf("Enter your option:\n");
        scanf("%d", &option);
        switch(option) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: exit(0); break;
            default: printf("Invalid option. Please try again.\n");
        }
        printf("\nPress enter to continue...");
        getchar(); // Clear input buffer
        getchar();
    } while(1);
    return 0;
}