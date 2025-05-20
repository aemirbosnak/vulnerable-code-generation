//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_SIZE 1000
#define MAX_DIARY_SIZE 10000
#define MAX_DATE_SIZE 20

int main()
{
    char* diary = (char*) malloc(MAX_DIARY_SIZE);
    char* date = (char*) malloc(MAX_DATE_SIZE);
    char* entry = (char*) malloc(MAX_ENTRY_SIZE);
    int choice;
    int i = 0;

    while (1) {
        printf("Digital Diary - Please select an option:\n");
        printf("1. Read diary entries\n");
        printf("2. Add new diary entry\n");
        printf("3. Exit\n");
        printf("> ");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the date of the entry you would like to read (DD/MM/YYYY format):\n> ");
            scanf("%s", date);

            for (i = 0; i < MAX_DIARY_SIZE; i++) {
                if (diary[i] == '\0') {
                    break;
                }

                if (!strcmp(date, diary + i)) {
                    printf("%s\n\n", diary + i + strlen(date));
                    break;
                }
            }

            if (i == MAX_DIARY_SIZE) {
                printf("No entries found for that date.\n\n");
            }
        }

        else if (choice == 2) {
            printf("Enter the date of the entry you would like to add (DD/MM/YYYY format):\n> ");
            scanf("%s", date);
            printf("Enter your diary entry:\n> ");
            fgets(entry, MAX_ENTRY_SIZE, stdin); // absorb stray newline character
            fgets(entry, MAX_ENTRY_SIZE, stdin);

            if ((strlen(date) + strlen(entry) + 1) > (MAX_DIARY_SIZE - strlen(diary))) {
                printf("Diary full!\n\n");
                continue;
            }

            sprintf(diary + strlen(diary), "%s%s\n", date, entry);
            printf("Entry added to diary successfully.\n\n");
        }

        else if (choice == 3) { // Exit program
            break;
        }

        else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    free(diary);
    free(date);
    free(entry);

    return 0;
}