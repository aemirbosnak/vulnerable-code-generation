//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
/* Puzzle Email Client */

#include <stdio.h>
#include <stdlib.h>

/* Define data structures */

typedef struct {
    char name[20];
    char email[50];
} Contact;

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    int id;
    Contact sender;
    Contact recipients[10];
    char subject[100];
    char body[1000];
    Date date;
} Email;

/* Define functions */

void printMenu();
int getInput(int min, int max);
void viewEmail(Email *email);
void sendEmail(Email *email);

int main() {
    int option;
    Email email = {0};

    while (1) {
        printMenu();
        option = getInput(1, 3);

        switch (option) {
            case 1:
                viewEmail(&email);
                break;
            case 2:
                sendEmail(&email);
                break;
            case 3:
                printf("Exiting Puzzle Email Client. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

/* Display the main menu */
void printMenu() {
    printf("================================\n");
    printf("====== Puzzle Email Client =====\n");
    printf("================================\n");
    printf("1. View Email\n");
    printf("2. Send Email\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

/* Get user input */
int getInput(int min, int max) {
    int input;

    while (1) {
        scanf("%d", &input);
        if (input >= min && input <= max) {
            break;
        } else {
            printf("Invalid input. Please try again: ");
        }
    }

    return input;
}

/* Display the email */
void viewEmail(Email *email) {
    if (email->id == 0) {
        printf("You have no emails to view.\n");
    } else {
        printf("Subject: %s\n", email->subject);
        printf("From: %s <%s>\n", email->sender.name, email->sender.email);
        printf("To: ");
        for (int i = 0; i < 10; i++) {
            if (email->recipients[i].email[0] != '\0') {
                printf("%s, ", email->recipients[i].name);
            }
        }
        printf("\n");
        printf("Date: %d/%d/%d\n", email->date.day, email->date.month, email->date.year);
        printf("Body:\n%s\n", email->body);
    }
}

/* Send an email */
void sendEmail(Email *email) {
    printf("To: ");
    scanf("%s", email->recipients[0].name);
    printf("Subject: ");
    scanf("%s", email->subject);
    printf("Body: ");
    scanf("%s", email->body);
    printf("Email sent!\n");
}