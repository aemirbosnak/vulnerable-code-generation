//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing email information
typedef struct {
    char *email;
    int subscribed;
} Email;

// Define a function for adding email to the mailing list
void addEmail(Email *mailingList, char *email, int *numEmails) {
    // Check if this email already exists in the list
    for(int i = 0; i < *numEmails; i++) {
        if(strcmp(mailingList[i].email, email) == 0) {
            printf("This email already exists in the mailing list.\n");
            return;
        }
    }

    // Allocate memory for the new email
    mailingList[*numEmails].email = (char*)malloc(strlen(email) + 1);

    if(mailingList[*numEmails].email == NULL) {
        printf("Failed to allocate memory for new email.\n");
        return;
    }

    // Copy the email address to the new memory location
    strcpy(mailingList[*numEmails].email, email);

    // Mark the email as subscribed by default
    mailingList[*numEmails].subscribed = 1;

    *numEmails += 1;

    printf("Email added successfully.\n");
}

// Define a function for deleting email from the mailing list
void deleteEmail(Email *mailingList, char *email, int *numEmails) {
    int found = 0;

    // Check if this email exists in the list and delete it
    for(int i = 0; i < *numEmails; i++) {
        if(strcmp(mailingList[i].email, email) == 0) {
            found = 1;
            free(mailingList[i].email);
            *numEmails -= 1;

            // Shift the remaining elements of the list one index back
            for(int j = i; j < *numEmails; j++) {
                mailingList[j] = mailingList[j+1];
            }

            printf("Email deleted successfully.\n");
            break;
        }
    }

    if(found == 0) {
        printf("This email does not exist in the mailing list.\n");
    }
}

// Define a function for subscribing to the mailing list
void subscribeEmail(Email *mailingList, char *email, int *numEmails) {
    int found = 0;

    // Check if this email exists in the list and subscribe it
    for(int i = 0; i < *numEmails; i++) {
        if(strcmp(mailingList[i].email, email) == 0) {
            found = 1;
            mailingList[i].subscribed = 1;
            printf("Email subscribed successfully.\n");
            break;
        }
    }

    if(found == 0) {
        printf("This email does not exist in the mailing list.\n");
    }
}

// Define a function for unsubscribing from the mailing list
void unsubscribeEmail(Email *mailingList, char *email, int *numEmails) {
    int found = 0;

    // Check if this email exists in the list and unsubscribe it
    for(int i = 0; i < *numEmails; i++) {
        if(strcmp(mailingList[i].email, email) == 0) {
            found = 1;
            mailingList[i].subscribed = 0;
            printf("Email unsubscribed successfully.\n");
            break;
        }
    }

    if(found == 0) {
        printf("This email does not exist in the mailing list.\n");
    }
}

int main() {
    const int MAX_EMAILS = 1000;

    // Allocate memory for the mailing list array
    Email *mailingList = (Email*)malloc(sizeof(Email) * MAX_EMAILS);

    if(mailingList == NULL) {
        printf("Failed to allocate memory for mailing list.\n");
        return 1;
    }

    int numEmails = 0;
    char command[50], email[100];

    printf("Welcome to the mailing list manager!\n");

    while(1) {
        printf("\nEnter a command (add/delete/subscribe/unsubscribe/show/exit): ");
        scanf("%s", command);

        if(strcmp(command, "add") == 0) {
            printf("Enter the email address you would like to add: ");
            scanf("%s", email);

            addEmail(mailingList, email, &numEmails);
        }
        else if(strcmp(command, "delete") == 0) {
            printf("Enter the email address you would like to delete: ");
            scanf("%s", email);

            deleteEmail(mailingList, email, &numEmails);
        }
        else if(strcmp(command, "subscribe") == 0) {
            printf("Enter the email address you would like to subscribe: ");
            scanf("%s", email);

            subscribeEmail(mailingList, email, &numEmails);
        }
        else if(strcmp(command, "unsubscribe") == 0) {
            printf("Enter the email address you would like to unsubscribe: ");
            scanf("%s", email);

            unsubscribeEmail(mailingList, email, &numEmails);
        }
        else if(strcmp(command, "show") == 0) {
            printf("\nMailing List:\n");

            for(int i = 0; i < numEmails; i++) {
                printf("%s - %s\n", mailingList[i].email, mailingList[i].subscribed ? "Subscribed" : "Unsubscribed");
            }
        }
        else if(strcmp(command, "exit") == 0) {
            printf("\nThank you for using the mailing list manager!\n");
            break;
        }
        else {
            printf("\nInvalid command. Please try again.\n");
        }
    }

    // Free the memory allocated for the mailing list
    for(int i = 0; i < numEmails; i++) {
        free(mailingList[i].email);
    }

    free(mailingList);

    return 0;
}