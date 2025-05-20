//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//define the maximum number of entries and the maximum length of each entry
#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

//function to get the current date and time
void getDateTime(char* dateTime) {
    time_t now;
    struct tm* localTime;

    now = time(NULL);
    localTime = localtime(&now);
    strftime(dateTime, 20, "%Y-%m-%d %H:%M:%S", localTime);
}

int main() {
    //declare variables
    char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH];
    char input[MAX_ENTRY_LENGTH];
    char dateTime[20];

    int numEntries = 0;

    printf("*** C Digital Diary ***\n");

    //loop until user chooses to exit
    while(1) {
        printf("\nOptions:\n1. Add entry\n2. View entries\n3. Exit\n");
        printf("Enter option number: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                //get input from user
                printf("\nEnter entry: ");
                scanf(" %[^\n]", input);

                //get current date and time
                getDateTime(dateTime);

                //check if number of entries has reached maximum limit
                if(numEntries == MAX_ENTRIES) {
                    printf("\nMaximum number of entries reached. Cannot add more.\n");
                    break;
                }

                //add entry to array of entries
                sprintf(entries[numEntries], "%s %s", dateTime, input);

                //increment number of entries
                numEntries++;

                printf("\nEntry added successfully.\n");

                break;
            case 2:
                //display all entries
                if(numEntries == 0) {
                    printf("\nNo entries found.\n");
                } else {
                    printf("\n---List of Entries---\n");
                    for(int i = 0; i < numEntries; i++) {
                        printf("%d. %s\n", i+1, entries[i]);
                    }
                }
                break;
            case 3:
                //exit program
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}