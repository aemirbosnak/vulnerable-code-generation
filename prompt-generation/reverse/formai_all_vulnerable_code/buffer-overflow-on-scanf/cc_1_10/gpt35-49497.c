//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// define the maximum length of an entry
#define ENTRY_LENGTH 1000

// define the maximum number of entries 
#define MAX_ENTRIES 100

// define a function to get the current time as string
void get_time_string(char *time_string) {
    time_t current_time;
    struct tm *time_info;

    // get the current time
    time(&current_time);
    time_info = localtime(&current_time);

    // format the time as a string
    strftime(time_string, 50, "%Y-%m-%d %H:%M:%S", time_info);
}

int main() {

    // create an array of strings to store the entries
    char entries[MAX_ENTRIES][ENTRY_LENGTH];

    // initialize the entry count to 0
    int entry_count = 0;

    // loop until the user chooses to exit
    while (1) {

        // print the menu
        printf("\nDigital Diary\n");
        printf("1) Add Entry\n");
        printf("2) Show Entries\n");
        printf("3) Exit\n");
        printf("Choose an option: ");

        // get the user's choice
        int choice;
        scanf("%d", &choice);

        // process the user's choice
        switch (choice) {

            // add an entry
            case 1: {
                // make sure there is room for a new entry
                if (entry_count == MAX_ENTRIES) {
                    printf("Error: Maximum entry count reached.\n");
                    break;
                }

                // ask the user to enter the new entry
                printf("Enter your entry: ");
                char entry[ENTRY_LENGTH];
                scanf(" %[^\n]s", entry);

                // get the current time as a string
                char time_string[50];
                get_time_string(time_string);

                // add the entry to the list
                sprintf(entries[entry_count], "[%s] %s", time_string, entry);
                entry_count++;
                break;
            }

            // show all entries
            case 2: {
                // make sure there are entries to show
                if (entry_count == 0) {
                    printf("No entries.\n");
                    break;
                }

                // print all entries
                for (int i = 0; i < entry_count; i++) {
                    printf("%s\n", entries[i]);
                }
                break;
            }

            // exit the program
            case 3: {
                printf("Goodbye!\n");
                exit(0);
            }

            // handle invalid choices
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}