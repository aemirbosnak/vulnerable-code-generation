//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000    // maximum number of entries

// Structure for storing an entry
typedef struct {
    char date[20];
    char entry[1000];
} Entry;

// Function declarations
void print_menu();
void add_entry(Entry diary[], int *count);
void view_entries(Entry diary[], int count);
int validate_date(char *date);

int main() {
    Entry diary[MAX_ENTRIES];   // array to store diary entries
    int count = 0;              // counter for number of entries
    
    while(1) {
        print_menu();   // display the menu options
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_entry(diary, &count);
                break;
            case 2:
                view_entries(diary, count);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function to print the menu options
void print_menu() {
    printf("\nDigital Diary\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to add an entry to the diary
void add_entry(Entry diary[], int *count) {
    // Get current date and time
    time_t now;
    time(&now);
    char date[20];
    strftime(date, 20, "%d/%m/%Y %H:%M:%S", localtime(&now));
    
    // Validate date and store entry
    printf("Enter your entry:\n");
    char entry[1000];
    getchar();
    fgets(entry, 1000, stdin);
    if(validate_date(date)) {
        strcpy(diary[*count].date, date);
        strcpy(diary[*count].entry, entry);
        (*count)++;
        printf("Entry added successfully.\n");
    }
    else {
        printf("Invalid date. Entry not added.\n");
    }
}

// Function to view all entries in the diary
void view_entries(Entry diary[], int count) {
    if(count == 0) {
        printf("There are no entries in the diary.\n");
    }
    else {
        printf("Displaying all entries:\n");
        for(int i=0; i<count; i++) {
            printf("%s\n%s", diary[i].date, diary[i].entry);
        }
    }
}

// Function to validate the date format
int validate_date(char *date) {
    if(strlen(date) != 19) {
        return 0;
    }
    for(int i=0; i<10; i++) {
        if(!isdigit(date[i])) {
            return 0;
        }
        if((i==2 || i==5) && date[i] != '/') {
            return 0;
        }
    }
    if(!isspace(date[10])) {
        return 0;
    }
    for(int i=11; i<19; i++) {
        if(!isdigit(date[i])) {
            return 0;
        }
        if((i==13 || i==16) && date[i] != ':') {
            return 0;
        }
    }
    return 1;
}