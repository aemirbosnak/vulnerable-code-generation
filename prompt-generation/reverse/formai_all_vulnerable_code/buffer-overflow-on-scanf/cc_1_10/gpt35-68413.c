//FormAI DATASET v1.0 Category: Digital Diary ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Diary {
    char date[11];
    char content[1000];
};

void addEntry(struct Diary entries[], int *numEntries) {
    struct Diary newEntry;
    
    printf("Please enter the date (in format dd/mm/yyyy): ");
    scanf("%s", newEntry.date);
    
    printf("Please enter your entry content: ");
    scanf("%s", newEntry.content);
    
    entries[*numEntries] = newEntry;
    (*numEntries)++;
    
    printf("Entry added successfully!\n\n");
}

void viewEntries(struct Diary entries[], int numEntries) {
    if (numEntries == 0) {
        printf("There are no entries to view.\n\n");
        return;
    }
    
    printf("Entries:\n");
    
    for (int i = 0; i < numEntries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Content: %s\n\n", entries[i].content);
    }
}

int main() {
    struct Diary entries[100];
    int numEntries = 0;
    int choice;
    
    printf("Welcome to the digital diary!\n");
    
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add new entry\n");
        printf("2. View existing entries\n");
        printf("3. Exit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                viewEntries(entries, numEntries);
                break;
            case 3:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid option, please try again.\n\n");
        }
    }
    
    return 0;
}