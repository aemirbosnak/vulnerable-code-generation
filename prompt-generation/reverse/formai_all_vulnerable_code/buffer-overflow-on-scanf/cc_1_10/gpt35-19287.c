//FormAI DATASET v1.0 Category: Mailing list manager ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct email{
    char address[50];
    struct email *next;
} Email;

Email *head = NULL;

void addEmail(char *address){
    Email *newEmail = (Email*)malloc(sizeof(Email));
    strcpy(newEmail->address, address);
    newEmail->next = NULL;

    if (head == NULL){
        head = newEmail;
    }else{
        Email *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newEmail;
    }
    printf("%s added to the mailing list!\n", address);
}

void removeEmail(char *address){
    if (head == NULL){
        printf("The mailing list is empty!\n");
    }else if (strcmp(address, head->address) == 0){
        Email *temp = head;
        head = head->next;
        free(temp);
        printf("%s removed from the mailing list!\n", address);
    }else{
        Email *current = head;
        while(current->next != NULL){
            if (strcmp(address, current->next->address) == 0){
                Email *temp = current->next;
                current->next = current->next->next;
                free(temp);
                printf("%s removed from the mailing list!\n", address);
                return;
            }
            current = current->next;
        }
        printf("%s not found in the mailing list!\n", address);
    }
}

void displayMailingList(){
    if (head == NULL){
        printf("The mailing list is empty!\n");
    }else{
        printf("Mailing List:\n");
        Email *current = head;
        while(current != NULL){
            printf("%s\n", current->address);
            current = current->next;
        }
    }
}

int main(){
    printf("***********Mailing List Manager***********\n");

    while(1){
        printf("\n1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Mailing List\n");
        printf("4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            char address[50];
            printf("Enter email address: ");
            scanf("%s", address);
            addEmail(address);
        }else if (choice == 2){
            char address[50];
            printf("Enter email address: ");
            scanf("%s", address);
            removeEmail(address);
        }else if (choice == 3){
            displayMailingList();
        }else if (choice == 4){
            printf("Exiting mailing list manager...\n");
            break;
        }else{
            printf("Invalid choice!\n");
        }
    }

    return 0;
}