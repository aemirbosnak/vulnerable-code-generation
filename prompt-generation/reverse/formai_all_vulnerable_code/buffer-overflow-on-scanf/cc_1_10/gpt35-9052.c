//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Email;

typedef struct {
    Email list[MAX_EMAILS];
    int count;
} EmailList;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} EmailContent;

void printMenu() {
    printf("1. Add email\n");
    printf("2. Remove email\n");
    printf("3. View all emails\n");
    printf("4. Send email\n");
    printf("5. Quit\n");
}

void printEmailList(EmailList* emailList) {
    int i;
    for (i = 0; i < emailList->count; i++) {
        printf("%s\n", emailList->list[i].email);
    }
}

Email* findEmail(EmailList* emailList, char* email) {
    int i;
    for (i = 0; i < emailList->count; i++) {
        if (strcmp(emailList->list[i].email, email) == 0) {
            return &emailList->list[i];
        }
    }
    return NULL;
}

void addEmail(EmailList* emailList, char* email) {
    if (emailList->count == MAX_EMAILS) {
        printf("List is full!\n");
        return;
    }

    Email* foundEmail = findEmail(emailList, email);
    if (foundEmail != NULL) {
        printf("Email already exists!\n");
        return;
    }

    Email newEmail;
    strcpy(newEmail.email, email);
    emailList->list[emailList->count] = newEmail;
    emailList->count++;
    printf("Email added successfully!\n");
}

void removeEmail(EmailList* emailList, char* email) {
    Email* foundEmail = findEmail(emailList, email);
    if (foundEmail == NULL) {
        printf("Email not found!\n");
        return;
    }

    int i;
    for (i = 0; i < emailList->count; i++) {
        if (strcmp(emailList->list[i].email, email) == 0) {
            int j;
            for (j = i; j < emailList->count - 1; j++) {
                emailList->list[j] = emailList->list[j + 1];
            }
            emailList->count--;
            printf("Email removed successfully!\n");
            return;
        }
    }
}

void sendEmail(EmailList* emailList, EmailContent* emailContent) {
    int i;
    for (i = 0; i < emailList->count; i++) {
        printf("To: %s\nSubject: %s\nMessage: %s\n\n",
            emailList->list[i].email,
            emailContent->subject,
            emailContent->message
        );
    }
}

int main() {
    EmailList emailList;
    emailList.count = 0;

    EmailContent emailContent;

    int option;
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    do {
        printMenu();
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter email: ");
            scanf("%s", email);
            addEmail(&emailList, email);
            break;
        case 2:
            printf("Enter email: ");
            scanf("%s", email);
            removeEmail(&emailList, email);
            break;
        case 3:
            printEmailList(&emailList);
            break;
        case 4:
            printf("Enter subject: ");
            getchar();
            fgets(subject, MAX_SUBJECT_LENGTH, stdin);

            printf("Enter message: ");
            fgets(message, MAX_MESSAGE_LENGTH, stdin);

            strcpy(emailContent.subject, subject);
            strcpy(emailContent.message, message);

            sendEmail(&emailList, &emailContent);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (option != 5);

    return 0;
}