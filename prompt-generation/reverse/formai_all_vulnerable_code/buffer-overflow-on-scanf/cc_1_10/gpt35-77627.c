//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // maximum number of diary entries
#define MAX_CHARS 1000 // maximum number of characters in each entry

int main()
{
    char diary[MAX_ENTRIES][MAX_CHARS]; // 2D array to store diary entries
    char date[MAX_CHARS];
    char entry[MAX_CHARS];
    int option = 0;
    int index = 0;
    time_t t = time(NULL); // get current time

    printf("Welcome to your Digital Diary! Today is %s", ctime(&t));

    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Add an entry\n");
        printf("2. View previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf("%s", date);

                printf("\nEnter the entry:\n");
                getchar(); // clear input buffer
                fgets(entry, MAX_CHARS, stdin);

                if (index >= MAX_ENTRIES) {
                    printf("\nSorry, you have reached the maximum number of entries.\n");
                } else {
                    strcpy(diary[index], date); // copy date into array
                    strcat(diary[index], " - "); // add separator
                    strcat(diary[index], entry); // add entry to array
                    index++; // increment index
                    printf("\nEntry added successfully!\n");
                }
                break;

            case 2:
                if (index == 0) {
                    printf("\nSorry, there are no entries to display.\n");
                } else {
                    printf("\nPrevious Entries:\n");

                    for (int i = 0; i < index; i++) {
                        printf("%s\n", diary[i]); // print each entry
                    }
                }
                break;

            case 3:
                printf("\nThank you for using Digital Diary. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}