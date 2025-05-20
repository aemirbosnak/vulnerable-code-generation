//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

void addEmail(char email[], char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH], int *numEmails);
void removeEmail(char email[], char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH], int *numEmails);
void printList(char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH], int numEmails);

int main() {
    char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH];
    int numEmails = 0;
    int choice;
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. View List\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(email, emailList, &numEmails);
                printf("Email added!\n");
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(email, emailList, &numEmails);
                printf("Email removed!\n");
                break;
            case 3:
                printf("\nList of Email Addresses\n");
                printList(emailList, numEmails);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addEmail(char email[], char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH], int *numEmails) {
    if (*numEmails < MAX_EMAILS) {
        strcpy(emailList[*numEmails], email);
        (*numEmails)++;
    } else {
        printf("Max number of emails in list reached!\n");
    }
}

void removeEmail(char email[], char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH], int *numEmails) {
    int i, j;
    for (i = 0; i < *numEmails; i++) {
        if (strcmp(emailList[i], email) == 0) {
            for (j = i; j < (*numEmails-1); j++) {
                strcpy(emailList[j], emailList[j+1]);
            }
            (*numEmails)--;
            return;
        }
    }
    printf("Email not found in list!\n");
}

void printList(char emailList[MAX_EMAILS][MAX_EMAIL_LENGTH], int numEmails) {
    int i;
    for (i = 0; i < numEmails; i++) {
        printf("%s\n", emailList[i]);
    }
}