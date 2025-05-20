//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the mailing list data
typedef struct {
    char name[50];
    char email[50];
} MailingList;

int main() {
    int num_entries = 0;

    // Allocate memory for the mailing list
    MailingList* list = (MailingList*)malloc(num_entries * sizeof(MailingList));

    // Welcome the user to the program
    printf("Welcome to the Mailing List Manager!\n");

    // Loop through the program menu until the user quits
    int loop = 1;
    while (loop) {
        printf("\nPlease choose an option:\n");
        printf("1. Add to Mailing List\n");
        printf("2. View Mailing List\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Get information from the user and add it to the mailing list
                printf("\nPlease enter a name: ");
                char name[50];
                scanf("%s", name);
                strcpy(list[num_entries].name, name);

                printf("Please enter an email: ");
                char email[50];
                scanf("%s", email);
                strcpy(list[num_entries].email, email);

                num_entries++;

                // Resize the mailing list to fit the new entry
                list = (MailingList*)realloc(list, num_entries * sizeof(MailingList));

                printf("\n%s has been added to the mailing list!\n", name);

                break;
            }
            case 2: {
                // Print out the entire mailing list
                printf("\nMailing List:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s (%s)\n", list[i].name, list[i].email);
                }

                break;
            }
            case 3: {
                // Quit the program
                printf("\nThank you for using the Mailing List Manager!\n");
                loop = 0;

                break;
            }
            default: {
                printf("\nInvalid choice, please try again.\n");
            }
        }
    }

    // Free the memory used by the mailing list
    free(list);

    return 0;
}