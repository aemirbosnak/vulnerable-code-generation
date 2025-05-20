//FormAI DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store diary entries
struct DiaryEntry {
    char date[50];
    char entry[500];
};

int main() {
    int option;

    // Create a file pointer to save the diary entries
    FILE *fp;

    // Open the file in "r+" mode to append new data without overwriting the previous one 
    fp=fopen("diary.txt","r+");
    if(fp==NULL) {
        printf("Error in opening the file!");
        exit(1);
    }

    // Get the current date and time
    time_t current_time;
    struct tm * time_info;
    char timeString[50];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(timeString, sizeof(timeString), "%x - %I:%M%p", time_info);

    // Print the welcome message
    printf("\nWelcome to your Digital Diary!\n\n");

    // Loop through the options until the user wants to exit
    do {
        printf("Select an option:\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter your entry:\n");

                // Create a new DiaryEntry instance
                struct DiaryEntry new_entry;

                // Copy the current time as the date of the entry
                strcpy(new_entry.date, timeString);

                // Read the new entry from the user
                fflush(stdin);
                gets(new_entry.entry);

                // Write the new entry to the file
                fprintf(fp, "%s\n%s\n", new_entry.date, new_entry.entry);

                printf("\nEntry added successfully!\n\n");
                break;

            case 2:
                printf("\nYour previous entries:\n\n");

                // Read the diary entries from the file and print them
                char line[501];
                while(fgets(line, sizeof(line), fp)) {
                    printf("%s", line);
                }

                // Move the file pointer to the beginning of the file
                rewind(fp);
                printf("\n");
                break;

            case 3:
                printf("\nThank you for using your Digital Diary. Goodbye!\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n\n");
                break;
        }
    } while(option != 3);

    // Close the file
    fclose(fp);

    return 0;
}