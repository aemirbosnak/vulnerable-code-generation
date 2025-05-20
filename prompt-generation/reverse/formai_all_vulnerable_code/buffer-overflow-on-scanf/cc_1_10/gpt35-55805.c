//FormAI DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>

// struct to store diary entry
typedef struct {
    char date[11];
    char entry[250];
} DiaryEntry;

int main() {
    DiaryEntry diary[100]; // array of 100 diary entries
    int numEntries = 0; // current number of diary entries
    
    printf("Welcome to the Multiplayer Digital Diary!\n");
    printf("Please enter your name: ");
    char playerName[50];
    fgets(playerName, 50, stdin);
    
    // game loop
    while (1) {
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Add a diary entry\n");
        printf("2. Read all diary entries\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter today's date (yyyy-mm-dd): ");
                scanf("%s", diary[numEntries].date);
                printf("Enter your diary entry: ");
                getchar(); // get rid of extra newline
                fgets(diary[numEntries].entry, 250, stdin);
                numEntries++;
                printf("Diary entry added!\n");
                break;
            case 2:
                printf("\n");
                for (int i = 0; i < numEntries; i++) {
                    printf("Date: %s\n", diary[i].date);
                    printf("Entry: %s\n", diary[i].entry);
                    printf("Written by: %s", playerName);
                    printf("\n");
                }
                break;
            case 3:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}