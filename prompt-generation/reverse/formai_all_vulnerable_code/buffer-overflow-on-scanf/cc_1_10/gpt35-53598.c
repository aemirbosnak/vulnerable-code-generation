//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char entry[1000];
    char choice;
    int day, month, year;

    printf("Welcome to your Digital Diary!\n");
    printf("What would you like to do today?\n");
    printf("a) Create a new entry\n");
    printf("b) Read an existing entry\n");
    printf("c) Exit\n");

    scanf("%c", &choice);

    switch(choice) {
        
        case 'a':
            printf("Enter the date of your entry (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &day, &month, &year);
            printf("Write your entry below:\n");
            fgets(entry, 1000, stdin);
            printf("Entry saved successfully!\n");
            break;

        case 'b':
            printf("Enter the date of the entry you want to read (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &day, &month, &year);
            printf("Entry for %d/%d/%d:\n", day, month, year);
            // code to read the entry goes here
            break;

        case 'c':
            printf("Are you sure you want to exit? (Y/N): ");
            scanf("%c", &choice);
            if(choice == 'Y' || choice == 'y') {
                printf("Goodbye!");
                exit(0);
            }
            break;

        default:
            printf("Invalid input. Please choose a valid option.\n");
            break;
    }

    return 0;
}