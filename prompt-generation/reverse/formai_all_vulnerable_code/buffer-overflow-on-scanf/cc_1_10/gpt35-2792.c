//FormAI DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Email {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

Email emailList[MAX_EMAILS];
int numEmails = 0;

/*
 * Add email to the list
 */
void addEmail(Email e) {
    if(numEmails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached\n");
        return;
    }
    emailList[numEmails++] = e;
}

/*
 * Remove email from the list
 */
void removeEmail(char* email) {
    for(int i = 0; i < numEmails; i++) {
        if(strcmp(emailList[i].email, email) == 0) {
            for(int j = i; j < numEmails - 1; j++) {
                emailList[j] = emailList[j+1];
            }
            numEmails--;
            return;
        }
    }
    printf("Error: email not found\n");
}

/*
 * Print all emails in the list
 */
void printEmails() {
    for(int i = 0; i < numEmails; i++) {
        printf("%s (%s)\n", emailList[i].name, emailList[i].email);
    }
}

/*
 * Main program loop
 */
int main() {
    int choice;
    while(1) {
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print all emails\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                {
                    char name[MAX_NAME_LENGTH];
                    char email[MAX_EMAIL_LENGTH];
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter email: ");
                    scanf("%s", email);
                    Email e;
                    strcpy(e.name, name);
                    strcpy(e.email, email);
                    addEmail(e);
                    break;
                }
            case 2:
                {
                    char email[MAX_EMAIL_LENGTH];
                    printf("Enter email to remove: ");
                    scanf("%s", email);
                    removeEmail(email);
                    break;
                }
            case 3:
                printEmails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}