//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// defining structure for linked list node that contains the email
struct email_node{
    char email[50];
    struct email_node *next;
}*head = NULL;

// function to add a new email to the mailing list
void addToMailingList(char email[]){
    struct email_node *newNode = (struct email_node*)malloc(sizeof(struct email_node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if(!head){
        head = newNode;
        return;
    }

    struct email_node *temp = head;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
}

// function to remove an email from the mailing list
void removeFromMailingList(char email[]){
    if(!head){
        printf("Mailing list is empty.\n");
        return;
    }

    struct email_node *prev = NULL;
    struct email_node *temp = head;

    while(temp){
        if(strcmp(temp->email, email) == 0){
            if(!prev){
                head = temp->next;
            }else{
                prev->next = temp->next;
            }

            free(temp);
            printf("Email removed successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Email not found in the mailing list.\n");
}

// function to display all the emails in the mailing list
void displayMailingList(){
    if(!head){
        printf("Mailing list is empty.\n");
        return;
    }

    struct email_node *temp = head;

    while(temp){
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int main(){
    int choice;
    char email[50];

    printf("Mailing list manager\n");

    while(1){
        printf("\n\n");
        printf("1. Add email to the mailing list\n");
        printf("2. Remove email from the mailing list\n");
        printf("3. Display all the emails in the mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                addToMailingList(email);
                printf("Email added to the mailing list.\n");
                break;

            case 2:
                printf("Enter email to be removed: ");
                scanf("%s", email);
                removeFromMailingList(email);
                break;

            case 3:
                displayMailingList();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}