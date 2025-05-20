//FormAI DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void addEmail(char* emailList[MAX], int* numOfEmails) {
    char email[50];
    printf("Enter Email: ");
    scanf("%s", email);
    if(*numOfEmails < MAX) {
        emailList[*numOfEmails] = malloc(sizeof(email));
        strcpy(emailList[*numOfEmails], email);
        (*numOfEmails)++;
        printf("Email added successfully!\n");
    } else {
        printf("Email list is full!\n");
    }
}

void removeEmail(char* emailList[MAX], int* numOfEmails) {
    char email[50];
    printf("Enter Email: ");
    scanf("%s", email);
    int index = -1;
    for(int i=0; i<*numOfEmails; i++) {
        if(strcmp(emailList[i], email) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Email not found!\n");
    } else {
        free(emailList[index]);
        for(int i=index; i<*numOfEmails-1; i++) {
            emailList[i] = emailList[i+1];
        }
        (*numOfEmails)--;
        printf("Email removed successfully!\n");
    }
}

void printEmails(char* emailList[MAX], int* numOfEmails) {
    printf("\nEmail List:\n");
    for(int i=0; i<*numOfEmails; i++) {
        printf("%d. %s\n", i+1, emailList[i]);
    }
}

int main() {
    int numOfEmails = 0;
    char* emailList[MAX];

    while(1) {
        printf("\nEmail Management System\n\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Print Emails\n");
        printf("4. Exit\n\n");
        printf("Enter Choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEmail(emailList, &numOfEmails);
                break;
            case 2:
                removeEmail(emailList, &numOfEmails);
                break;
            case 3:
                printEmails(emailList, &numOfEmails);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}