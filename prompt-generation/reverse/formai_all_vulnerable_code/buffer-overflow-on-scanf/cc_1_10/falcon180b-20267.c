//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>

#define SIZE 100

int main() {
    int day;
    char entry[SIZE];

    //initialize with current date
    printf("Today's date: %d/%d/%d\n", 01, 01, 2022);

    //print menu
    printf("\nDigital Diary Menu:\n");
    printf("1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Search entry\n");
    printf("4. Edit entry\n");
    printf("5. Delete entry\n");
    printf("6. Exit\n");

    //loop until user chooses to exit
    while(1) {
        //get user choice
        scanf("%d", &day);

        //switch statement to handle user choice
        switch(day) {
            case 1:
                //add entry
                printf("\nAdd Entry:\n");
                printf("Enter entry: ");
                scanf("%[^\n]", entry);
                printf("Entry added: %s\n", entry);
                break;
            case 2:
                //view entries
                printf("\nView Entries:\n");
                printf("Day 1: %s\n", entry);
                break;
            case 3:
                //search entry
                printf("\nSearch Entry:\n");
                printf("Enter keyword: ");
                scanf("%[^\n]", entry);
                printf("Entry found: %s\n", entry);
                break;
            case 4:
                //edit entry
                printf("\nEdit Entry:\n");
                printf("Enter new entry: ");
                scanf("%[^\n]", entry);
                printf("Entry edited: %s\n", entry);
                break;
            case 5:
                //delete entry
                printf("\nDelete Entry:\n");
                printf("Entry deleted: %s\n", entry);
                break;
            case 6:
                //exit program
                printf("\nExiting program...\n");
                break;
            default:
                //invalid choice
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}