//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char content[MAX_LENGTH];
    time_t timestamp;
} Entry;

Entry diary[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n=====================\n");
    printf("    Retro Digital Diary\n");
    printf("=====================\n");
    printf("1. Add a new entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit\n");
    printf("=====================\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Diary is full, cannot add more entries.\n");
        return;
    }
    printf("Enter your diary entry: ");
    fgets(diary[entryCount].content, sizeof(diary[entryCount].content), stdin);
    diary[entryCount].timestamp = time(NULL);
    entryCount++;
    printf("Entry added successfully!\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("%s", diary[i].content);
        printf("Timestamp: %s", ctime(&diary[i].timestamp));
        printf("-------------------------\n");
    }
}

void searchEntry() {
    char query[MAX_LENGTH];
    printf("Enter a keyword to search for: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline character

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].content, query) != NULL) {
            printf("Found in Entry %d:\n", i + 1);
            printf("%s", diary[i].content);
            printf("Timestamp: %s", ctime(&diary[i].timestamp));
            printf("-------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries found containing the keyword: %s\n", query);
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("Thank you for using the Digital Diary! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}