//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

// Entry structure
struct entry {
    char date[20];
    char title[50];
    char content[500];
};

// Function declarations
int add_entry(struct entry[], int);
void view_entry(struct entry[], int);
void view_all_entries(struct entry[], int);

// Main function
int main() {
    struct entry diary[MAX_ENTRIES];
    int count = 0;
    char choice;

    // Loop through menu options
    while(1) {
        printf("\n\tDIGITAL DIARY\n");
        printf("1. Add new entry\n");
        printf("2. View an entry\n");
        printf("3. View all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Switch case for menu options
        switch(choice) {
            case '1':
                count = add_entry(diary, count);
                break;

            case '2':
                view_entry(diary, count);
                break;

            case '3':
                view_all_entries(diary, count);
                break;

            case '4':
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

// Function to add a new entry
int add_entry(struct entry diary[], int count) {
    // Check if diary is full
    if(count == MAX_ENTRIES) {
        printf("Sorry, diary is full!\n");
        return count;
    }

    struct entry new_entry;

    // Get current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(new_entry.date, "%d/%d/%d %02d:%02d:%02d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);

    // Get user input for title and content
    printf("Enter entry title: ");
    scanf(" %[^\n]s", new_entry.title);
    printf("Enter entry content:\n");
    scanf(" %[^\n]s", new_entry.content);

    // Add new entry to diary and return updated count
    diary[count] = new_entry;
    printf("Entry added successfully!\n");
    return ++count;
}

// Function to view a specific entry
void view_entry(struct entry diary[], int count) {
    // Check if diary is empty
    if(count == 0) {
        printf("Diary is empty!\n");
        return;
    }

    int entry_num;

    // Get entry number to view
    printf("Enter entry number: ");
    scanf(" %d", &entry_num);

    // Check if entry number is valid
    if(entry_num <= 0 || entry_num > count) {
        printf("Invalid entry number!\n");
        return;
    }

    // View selected entry
    printf("\n\t%s\n", diary[entry_num-1].title);
    printf("\t%s\n", diary[entry_num-1].date);
    printf("\t%s\n\n", diary[entry_num-1].content);
}

// Function to view all entries
void view_all_entries(struct entry diary[], int count) {
    // Check if diary is empty
    if(count == 0) {
        printf("Diary is empty!\n");
        return;
    }

    printf("\tALL ENTRIES\n");

    // Loop through all entries and display them
    for(int i = 0; i < count; i++) {
        printf("%d. %s\n", i+1, diary[i].title);
        printf("\t%s\n", diary[i].date);
        printf("\t%s\n\n", diary[i].content);
    }
}