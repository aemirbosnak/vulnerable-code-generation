//FormAI DATASET v1.0 Category: Email Client ; Style: shape shifting
/*
This program is a shape shifting C email client that allows the user to send emails through the command line interface. The user can choose the type of email they want to send (text or HTML) and can input the recipient, subject, and message content. The program also has the ability to send attachments, such as images or documents. Enjoy!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_RECIPIENTS 5
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000
#define MAX_ATTACHMENT_FILENAME_LENGTH 20

// Define struct for email
typedef struct {
    char recipients[MAX_RECIPIENTS][50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char attachment[MAX_ATTACHMENT_FILENAME_LENGTH];
    int isHTML;
} Email;

// Function prototypes
void clearBuffer();
void printMenu();
void getInput(char* input, int maxLength);
void setRecipient(Email* email, int index);
void setSubject(Email* email);
void setMessage(Email* email);
void setAttachment(Email* email);
void setIsHTML(Email* email);

int main() {
    // Initialize email struct
    Email email;
    strcpy(email.attachment, "");
    email.isHTML = 0;
    
    // Print menu and get user input
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        clearBuffer();
        
        switch(choice) {
            case 1:
                setRecipient(&email, 0);
                break;
            case 2:
                setRecipient(&email, 1);
                break;
            case 3:
                setRecipient(&email, 2);
                break;
            case 4:
                setRecipient(&email, 3);
                break;
            case 5:
                setRecipient(&email, 4);
                break;
            case 6:
                setSubject(&email);
                break;
            case 7:
                setMessage(&email);
                break;
            case 8:
                setAttachment(&email);
                break;
            case 9:
                setIsHTML(&email);
                break;
            case 10:
                // Send email
                printf("Sending email...\n");
                printf("To: %s", email.recipients[0]);
                if (strcmp(email.recipients[1], "") != 0) {
                    printf(", %s", email.recipients[1]);
                }
                if (strcmp(email.recipients[2], "") != 0) {
                    printf(", %s", email.recipients[2]);
                }
                if (strcmp(email.recipients[3], "") != 0) {
                    printf(", %s", email.recipients[3]);
                }
                if (strcmp(email.recipients[4], "") != 0) {
                    printf(", %s", email.recipients[4]);
                }
                printf("\n");
                printf("Subject: %s\n", email.subject);
                printf("Message: %s\n", email.message);
                if (strcmp(email.attachment, "") != 0) {
                    printf("Attachment: %s\n", email.attachment);
                }
                if (email.isHTML == 1) {
                    printf("Type: HTML\n");
                } else {
                    printf("Type: Text\n");
                }
                break;
            case 11:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 11);
    
    return 0;
}

/*
Prints the menu of options for the email client.
*/
void printMenu() {
    printf("\nEmail Client\n");
    printf("1. Set recipient 1\n");
    printf("2. Set recipient 2\n");
    printf("3. Set recipient 3\n");
    printf("4. Set recipient 4\n");
    printf("5. Set recipient 5\n");
    printf("6. Set subject\n");
    printf("7. Set message\n");
    printf("8. Set attachment\n");
    printf("9. Set type (text or HTML)\n");
    printf("10. Send email\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
}

/*
Clears the buffer to prevent buffer overflow.
*/
void clearBuffer() {
    while(getchar() != '\n');
}

/*
Gets user input and stores it in the provided char array.
*/
void getInput(char* input, int maxLength) {
    fgets(input, maxLength, stdin);
    int length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
    } else {
        clearBuffer();
    }
}

/*
Sets the recipient at the specified index.
*/
void setRecipient(Email* email, int index) {
    printf("Enter recipient %d: ", index + 1);
    getInput(email->recipients[index], 50);
}

/*
Sets the subject of the email.
*/
void setSubject(Email* email) {
    printf("Enter subject: ");
    getInput(email->subject, MAX_SUBJECT_LENGTH);
}

/*
Sets the message of the email.
*/
void setMessage(Email* email) {
    printf("Enter message: ");
    getInput(email->message, MAX_MESSAGE_LENGTH);
}

/*
Sets the attachment of the email.
*/
void setAttachment(Email* email) {
    printf("Enter attachment filename: ");
    getInput(email->attachment, MAX_ATTACHMENT_FILENAME_LENGTH);
}

/*
Sets the type of the email (text or HTML).
*/
void setIsHTML(Email* email) {
    printf("Is this email in HTML format? (y/n) ");
    char input;
    scanf("%c", &input);
    clearBuffer();
    if (tolower(input) == 'y') {
        email->isHTML = 1;
    } else {
        email->isHTML = 0;
    }
}