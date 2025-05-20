//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Limit of emails that can be added to the mailing list
#define MAX_EMAIL_LENGTH 50 // Limit of characters that an email can have
#define FILENAME "mailing_list.txt" // File to save the mailing list

// Struct to store the emails
typedef struct {
    char email[MAX_EMAIL_LENGTH];
} mailing_list_t;

// Function to print menu options
void print_menu() {
    printf("\n==== MAILING LIST MANAGER ====\n");
    printf("[1] Add email\n");
    printf("[2] Remove email\n");
    printf("[3] Show mailing list\n");
    printf("[4] Save mailing list\n");
    printf("[5] Exit\n");
    printf("Option: ");
}

int main() {
    mailing_list_t mailing_list[MAX_EMAILS]; // Initialize empty mailing list
    int num_emails = 0; // Number of emails in the mailing list
    char option; // User selected option
    int i, j, k; // Loop variables
    char buffer[MAX_EMAIL_LENGTH]; // Auxiliary buffer to read and remove emails

    // Load saved mailing list, if any
    FILE *fp = fopen(FILENAME, "r");
    if (fp != NULL) {
        printf("Loading saved mailing list...\n");
        while(fgets(buffer, MAX_EMAIL_LENGTH, fp) != NULL) {
            // Remove the newline character from the email
            buffer[strcspn(buffer, "\n")] = 0;
            // Add the email to the mailing list
            strncpy(mailing_list[num_emails].email, buffer, MAX_EMAIL_LENGTH);
            num_emails++;
        }
        fclose(fp);
    }

    while(1) {
        print_menu();
        scanf("%c", &option);
        getchar(); // Consume the trailing newline character

        switch(option) {
            case '1': // Adding an email
                if (num_emails >= MAX_EMAILS) { // Check if maximum limit of emails has been reached
                    printf("Mailing list is full.\n");
                } else {
                    printf("Enter email: ");
                    fgets(buffer, MAX_EMAIL_LENGTH, stdin);
                    // Remove the trailing newline character
                    buffer[strcspn(buffer, "\n")] = 0;
                    // Add the email to the mailing list
                    strncpy(mailing_list[num_emails].email, buffer, MAX_EMAIL_LENGTH);
                    num_emails++;
                    printf("Email added to the mailing list.\n");
                }
                break;
            case '2': // Removing an email
                if (num_emails == 0) { // Check if mailing list is empty
                    printf("Mailing list is empty.\n");
                    break;
                }
                printf("Enter email to remove: ");
                fgets(buffer, MAX_EMAIL_LENGTH, stdin);
                // Remove the trailing newline character
                buffer[strcspn(buffer, "\n")] = 0;
                for (i = 0; i < num_emails; i++) {
                    if (strncmp(mailing_list[i].email, buffer, MAX_EMAIL_LENGTH) == 0) { // Email found
                        // Shift all emails to the right of the removed email one position to the left
                        for (j = i; j < num_emails - 1; j++) {
                            strncpy(mailing_list[j].email, mailing_list[j+1].email, MAX_EMAIL_LENGTH);
                        }
                        // Set the last email as empty
                        memset(mailing_list[num_emails-1].email, 0, MAX_EMAIL_LENGTH);
                        num_emails--;
                        printf("Email removed from the mailing list.\n");
                        break;
                    }
                }
                if (i == num_emails) { // Email not found
                    printf("Email not found in the mailing list.\n");
                }
                break;
            case '3': // Showing the mailing list
                if (num_emails == 0) { // Check if mailing list is empty
                    printf("Mailing list is empty.\n");
                    break;
                }
                printf("Mailing list:\n");
                for (i = 0; i < num_emails; i++) {
                    printf("%s\n", mailing_list[i].email);
                }
                break;
            case '4': // Saving the mailing list to file
                fp = fopen(FILENAME, "w");
                if (fp == NULL) {
                    printf("Error saving mailing list to file.\n");
                    break;
                }
                for (i = 0; i < num_emails; i++) {
                    fprintf(fp, "%s\n", mailing_list[i].email);
                }
                fclose(fp);
                printf("Mailing list saved to file.\n");
                break;
            case '5': // Exiting the program
                printf("Exiting program.\n");
                exit(0);
                break;
            default: // Invalid option
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}