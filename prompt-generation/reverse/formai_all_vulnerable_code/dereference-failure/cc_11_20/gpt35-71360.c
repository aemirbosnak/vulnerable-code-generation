//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int max_list_size = 10;
    char* email_list[max_list_size];
    int list_size = 0;
    printf("Welcome to the Email List Manager\n");

    // Main loop
    while (1) {
        // Print out menu options
        printf("\nMenu options:\n");
        printf("1. Add email\n");
        printf("2. Display list\n");
        printf("3. Remove email\n");
        printf("4. Quit\n");
        printf("Enter option number: ");

        // Get user input and handle
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Add email to list
                if (list_size < max_list_size) {
                    printf("Enter email: ");
                    char email[256];
                    scanf("%s", email);
                    email_list[list_size] = (char*) malloc(strlen(email) + 1);
                    strcpy(email_list[list_size], email);
                    list_size++;
                    printf("Added email: %s\n", email);
                } else {
                    printf("List is full, cannot add email.\n");
                }
                break;
            case 2:
                // Display list
                printf("Email List:\n");
                for (int i = 0; i < list_size; i++) {
                    printf("%d. %s\n", i+1, email_list[i]);
                }
                break;
            case 3:
                // Remove email from list
                if (list_size > 0) {
                    printf("Enter index of email to remove: ");
                    int index;
                    scanf("%d", &index);
                    if (index > 0 && index <= list_size) {
                        char* removed_email = email_list[index-1];
                        for (int i = index-1; i < list_size-1; i++) {
                            email_list[i] = email_list[i+1];
                        }
                        email_list[list_size-1] = NULL;
                        list_size--;
                        printf("Removed email: %s\n", removed_email);
                        free(removed_email);
                    } else {
                        printf("Invalid index.\n");
                    }
                } else {
                    printf("List is empty, cannot remove email.\n");
                }
                break;
            case 4:
                // Quit
                printf("Goodbye!\n");
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}