//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    char* c_time_string;

    printf("Welcome to your Digital Diary!\n\n");

    while(1) {
        int choice;
        printf("What would you like to do?\n1. Add entry\n2. View entries\n3. Exit\n\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            // Add entry

            // Get current time
            current_time = time(NULL);
            c_time_string = ctime(&current_time);

            // Prompt user for diary entry
            char entry[1000];
            printf("\n%s\nNew Entry:\n", c_time_string);
            scanf(" %[^\n]s", &entry);

            // Open diary file in append mode
            FILE* fptr = fopen("diary.txt", "a");

            // Write entry to file in the format "timestamp : entry"
            fprintf(fptr, "%s : %s\n", c_time_string, entry);

            printf("\nEntry added to diary.\n\n");

            fclose(fptr);

        } else if(choice == 2) {
            // View entries

            // Open diary file in read mode
            FILE* fptr = fopen("diary.txt", "r");

            // Check if file exists
            if(fptr == NULL) {
                printf("\nDiary is empty.\n\n");
                continue;
            }

            // Read file line by line and print each entry to console
            char line[1000];
            printf("\nDiary Entries:\n");
            while(fgets(line, 1000, fptr) != NULL) {
                printf("%s", line);
            }

            printf("\n");

            fclose(fptr);

        } else if(choice == 3) {
            // Exit program
            printf("\nGoodbye!\n");
            break;

        } else {
            // Invalid choice
            printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}