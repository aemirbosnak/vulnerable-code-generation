//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAIL_LEN 50 // Maximum length of an email address
#define MAX_NAME_LEN 20 // Maximum length of a person's name
#define MAX_SUB_LEN 100 // Maximum length of a subject line
#define MAX_BODY_LEN 500 // Maximum length of an email body
#define MAX_LIST_SIZE 100 // Maximum number of people on the list

void addToList(); // function to add an email to the list
void printList(); // function to print the current list of emails
void saveList(); // function to save the current list to a file
void loadList(); // function to load a list from a file

struct Email {
    char senderName[MAX_NAME_LEN];
    char senderEmail[MAX_EMAIL_LEN];
    char recipientName[MAX_NAME_LEN];
    char recipientEmail[MAX_EMAIL_LEN];
    char subject[MAX_SUB_LEN];
    char body[MAX_BODY_LEN];
};

struct Email list[MAX_LIST_SIZE]; // Global array to store the list of emails
int numOfEmails = 0; // Global variable to keep track of the number of emails on the list

int main() {
    printf("Welcome to the Mailing List Manager!\n");
    printf("Commands:\n");
    printf("- add: Add a new email to the list\n");
    printf("- print: View the current list of emails\n");
    printf("- save: Save the current list to a file\n");
    printf("- load: Load a list from a file\n");
    printf("- quit: Exit the program\n");

    char input[10]; // Variable to store user input
    while (1) {
        printf("\nEnter a command: ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            addToList();
        } else if (strcmp(input, "print") == 0) {
            printList();
        } else if (strcmp(input, "save") == 0) {
            saveList();
        } else if (strcmp(input, "load") == 0) {
            loadList();
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}

void addToList() {
    struct Email newEmail; // Create a new email struct
    printf("\nEnter the sender's name: ");
    scanf("%s", newEmail.senderName);
    printf("Enter the sender's email address: ");
    scanf("%s", newEmail.senderEmail);
    printf("Enter the recipient's name: ");
    scanf("%s", newEmail.recipientName);
    printf("Enter the recipient's email address: ");
    scanf("%s", newEmail.recipientEmail);
    printf("Enter the subject of the email: ");
    scanf("%s", newEmail.subject);
    printf("Enter the body of the email: ");
    scanf("%s", newEmail.body);

    if (numOfEmails >= MAX_LIST_SIZE) { // Check if the list is full
        printf("Error: The list is full. Please remove an email before adding a new one.\n");
    } else {
        list[numOfEmails] = newEmail; // Add the new email to the list
        numOfEmails++; // Increment the number of emails on the list
        printf("Email added successfully.\n");
    }
}

void printList() {
    if (numOfEmails == 0) { // Check if the list is empty
        printf("The list is empty.\n");
    } else {
        printf("\nCurrent list of emails:\n");
        for (int i = 0; i < numOfEmails; i++) {
            printf("%d: %s <%s> to %s <%s> - %s: %s\n", i+1, list[i].senderName, list[i].senderEmail, list[i].recipientName, list[i].recipientEmail, list[i].subject, list[i].body);
        }
    }
}

void saveList() {
    if (numOfEmails == 0) { // Check if the list is empty
        printf("Error: The list is empty. Nothing to save.\n");
    } else {
        FILE *filePointer;
        char fileName[20];
        printf("\nEnter a file name to save the list: ");
        scanf("%s", fileName);
        if ((filePointer = fopen(fileName, "w")) == NULL) { // Check if the file can be opened for writing
            printf("Error: Unable to open file for writing.\n");
        } else {
            for (int i = 0; i < numOfEmails; i++) {
                fprintf(filePointer, "%s,%s,%s,%s,%s,%s\n", list[i].senderName, list[i].senderEmail, list[i].recipientName, list[i].recipientEmail, list[i].subject, list[i].body); // Write each email to the file in csv format
            }
            fclose(filePointer);
            printf("List saved to %s successfully.\n", fileName);
        }
    }
}

void loadList() {
    if (numOfEmails > 0) { // Check if the list is not empty
        printf("Warning: Loading a new list will overwrite the current list. Do you want to proceed? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            return;
        }
    }

    FILE *filePointer;
    char fileName[20];
    printf("\nEnter a file name to load the list: ");
    scanf("%s", fileName);
    if ((filePointer = fopen(fileName, "r")) == NULL) { // Check if the file can be opened for reading
        printf("Error: Unable to open file for reading.\n");
    } else {
        char line[MAX_SUB_LEN*2+MAX_BODY_LEN+MAX_NAME_LEN*2+MAX_EMAIL_LEN*2+20]; // Variable to store each line of the file
        numOfEmails = 0;

        while(fgets(line, sizeof(line), filePointer) != NULL) { // Read each line of the file
            char *senderName = strtok(line, ",");
            char *senderEmail = strtok(NULL, ",");
            char *recipientName = strtok(NULL, ",");
            char *recipientEmail = strtok(NULL, ",");
            char *subject = strtok(NULL, ",");
            char *body = strtok(NULL, ",");

            if (senderName != NULL && senderEmail != NULL && recipientName != NULL && recipientEmail != NULL && subject != NULL && body != NULL) { // Check if all fields are present
                strcpy(list[numOfEmails].senderName, senderName);
                strcpy(list[numOfEmails].senderEmail, senderEmail);
                strcpy(list[numOfEmails].recipientName, recipientName);
                strcpy(list[numOfEmails].recipientEmail, recipientEmail);
                strcpy(list[numOfEmails].subject, subject);
                strcpy(list[numOfEmails].body, body);
                numOfEmails++;
            } else {
                printf("Error: Invalid file format. Could not load the list.\n");
                numOfEmails = 0; // Reset the list
                break;
            }

            if (numOfEmails >= MAX_LIST_SIZE) { // Check if the list is full
                break;
            }
        }

        fclose(filePointer);

        if (numOfEmails > 0) {
            printf("List loaded from %s successfully.\n", fileName);
        }
    }
}