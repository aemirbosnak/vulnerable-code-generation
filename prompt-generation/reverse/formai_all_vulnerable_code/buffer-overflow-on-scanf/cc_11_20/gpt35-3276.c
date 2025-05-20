//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100
#define MAX_NAME 30
#define MAX_EMAIL 50

struct mailing_list {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
};

int main() {
    struct mailing_list list[MAX_EMAILS];
    int choice;
    int count = 0;
    char search[MAX_NAME];
    
    do {
        printf("\n==========================\n");
        printf("Mailing List Manager\n");
        printf("==========================\n");
        printf("1. Add a new email\n");
        printf("2. Remove an email\n");
        printf("3. List all emails\n");
        printf("4. Search by name\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (count < MAX_EMAILS) {
                    printf("\nAdding new email:\n");
                    printf("Enter name: ");
                    scanf("%s", list[count].name);
                    printf("Enter email: ");
                    scanf("%s", list[count].email);
                    count++;
                }
                else {
                    printf("Mailing list is full.\n");
                }
                break;
            case 2:
                if (count > 0) {
                    int i, j;
                    char email[MAX_EMAIL];
                    printf("\nEnter the email to be removed: ");
                    scanf("%s", email);
                    for (i = 0; i < count; i++) {
                        if (strcmp(email, list[i].email) == 0) {
                            for (j = i; j < count - 1; j++) {
                                strcpy(list[j].name, list[j+1].name);
                                strcpy(list[j].email, list[j+1].email);
                            }
                            count--;
                            printf("Email removed.\n");
                            break;
                        }
                    }
                }
                else {
                    printf("Mailing list is empty.\n");
                }
                break;
            case 3:
                if (count > 0) {
                    int i;
                    printf("\nMailing list:\n");
                    for (i = 0; i < count; i++) {
                        printf("%s - %s\n", list[i].name, list[i].email);
                    }
                }
                else {
                    printf("Mailing list is empty.\n");
                }
                break;
            case 4:
                if (count > 0) {
                    int i;
                    printf("\nEnter search term: ");
                    scanf("%s", search);
                    printf("\nSearch results:\n");
                    printf("Name - Email\n");
                    for (i = 0; i < count; i++) {
                        if (strstr(list[i].name, search) != NULL) {
                            printf("%s - %s\n", list[i].name, list[i].email);
                        }
                    }
                }
                else {
                    printf("Mailing list is empty.\n");
                }
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}