//FormAI DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

/* Struct to hold email information */
typedef struct Email {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

/* Function to read input from user */
void read_input(char *buffer, int max_length) {
    fgets(buffer, max_length, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character
}

int main() {
    Email email;
    char choice;
    char filename[MAX_NAME_LENGTH];
    FILE *file;

    while (1) {
        printf("Choose an option:\n");
        printf("1 - Compose Email\n");
        printf("2 - View Inbox\n");
        printf("3 - Exit\n");

        scanf(" %c", &choice);
        getchar();  // Clear input buffer

        switch(choice) {
            case '1':
                printf("Compose Email\n");

                printf("Sender's Email Address: ");
                read_input(email.sender, MAX_EMAIL_LENGTH);

                printf("Recipient's Email Address: ");
                read_input(email.recipient, MAX_EMAIL_LENGTH);

                printf("Email Subject: ");
                read_input(email.subject, MAX_SUBJECT_LENGTH);

                printf("Email Body: ");
                read_input(email.body, MAX_BODY_LENGTH);

                printf("Save email to file? (y/n): ");
                scanf(" %c", &choice);
                getchar();  // Clear input buffer

                if (tolower(choice) == 'y') {
                    printf("Enter file name: ");
                    read_input(filename, MAX_NAME_LENGTH);

                    file = fopen(filename, "w");

                    if (file == NULL) {
                        printf("Error creating file\n");
                    }
                    else {
                        fprintf(file, "From: %s\n", email.sender);
                        fprintf(file, "To: %s\n", email.recipient);
                        fprintf(file, "Subject: %s\n", email.subject);
                        fprintf(file, "%s\n", email.body);
                        printf("Email saved to file: %s\n", filename);
                        fclose(file);
                    }
                }

                break;
            case '2':
                printf("View Inbox\n");

                printf("Enter file name: ");
                read_input(filename, MAX_NAME_LENGTH);

                file = fopen(filename, "r");

                if (file == NULL) {
                    printf("Error opening file\n");
                }
                else {
                    printf("From\t\tTo\t\tSubject\t\tBody\n");
                    printf("--------------------------------------------------\n");

                    while (fscanf(file, "From: %s\nTo: %s\nSubject: %s\n%[^\n]\n",
                            email.sender, email.recipient, email.subject, email.body) == 4) {
                        printf("%s\t%s\t%s\t\t%s\n", email.sender, email.recipient, email.subject, email.body);
                    }

                    fclose(file);
                }

                break;
            case '3':
                printf("Exiting Program\n");
                return 0;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}