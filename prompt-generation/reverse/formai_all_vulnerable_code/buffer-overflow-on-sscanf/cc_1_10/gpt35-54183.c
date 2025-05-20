//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#define MAX_EMAILS 100

typedef struct email {
    char name[50];
    char address[50];
} Email;

Email mailingList[MAX_EMAILS];
int numEmails = 0;

void addEmail() {
    char buffer[100];
    printf("Enter name: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%[^\n]s", mailingList[numEmails].name);
    printf("Enter address: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%[^\n]s", mailingList[numEmails].address);
    numEmails++;
}

void printMailingList() {
    printf("Mailing List:\n");
    for (int i = 0; i < numEmails; i++) {
        printf("%s - %s\n", mailingList[i].name, mailingList[i].address);
    }
}

int main() {
    printf("Welcome to the Mailing List Manager!\n");
    printf("Please select an option:\n");
    printf("1. Add an email to the mailing list\n");
    printf("2. Print the mailing list\n");
    printf("3. Quit\n");
    int choice;
    char buffer[10];
    do {
        printf("Enter your choice: ");
        fgets(buffer, 10, stdin);
        sscanf(buffer, "%d", &choice);
        switch (choice) {
            case 1:
                addEmail();
                break;
            case 2:
                printMailingList();
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}