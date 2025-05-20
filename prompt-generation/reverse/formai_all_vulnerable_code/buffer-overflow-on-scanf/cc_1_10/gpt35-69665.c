//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100 // maximum number of emails in the mailing list
#define MAX_EMAIL_LENGTH 50 // maximum length of each email

// structure for email
struct email{
    char address[MAX_EMAIL_LENGTH];
    struct email* next;
};

// function to create a new email node
struct email* createEmail(char address[]){
    struct email* new_email = (struct email*)malloc(sizeof(struct email));
    strcpy(new_email->address, address);
    new_email->next = NULL;
    return new_email;
}

// function to add a new email to the mailing list
void addEmailToList(struct email** head, char address[]){
    struct email* new_email = createEmail(address);
    if(*head == NULL){
        *head = new_email;
    }
    else{
        struct email* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_email;
    }
}

// function to display the mailing list
void displayMailingList(struct email* head){
    printf("\nMailing List:\n");
    struct email* temp = head;
    while(temp != NULL){
        printf("%s\n", temp->address);
        temp = temp->next;
    }
}

// function to delete an email from the mailing list
void deleteEmailFromList(struct email** head, char address[]){
    struct email* temp = *head;
    if(strcmp(temp->address, address) == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->next != NULL){
        if(strcmp(temp->next->address, address) == 0){
            struct email* to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
            return;
        }
        temp = temp->next;
    }
    printf("\n%s not found in mailing list!\n", address);
}

int main(){
    struct email* mailing_list = NULL; // initialize mailing list to empty
    int choice;
    char email[MAX_EMAIL_LENGTH];
    while(1){
        printf("\nMailing List Manager\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter email address: ");
                scanf("%s", email);
                addEmailToList(&mailing_list, email);
                printf("%s added to mailing list!\n", email);
                break;
            case 2:
                printf("\nEnter email address to delete: ");
                scanf("%s", email);
                deleteEmailFromList(&mailing_list, email);
                break;
            case 3:
                displayMailingList(mailing_list);
                break;
            case 4:
                printf("\nExiting Mailing List Manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}