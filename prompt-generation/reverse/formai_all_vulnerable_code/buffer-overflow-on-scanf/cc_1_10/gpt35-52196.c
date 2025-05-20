//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct email{
    char to[50];
    char from[50];
    char subject[100];
    char message[1000];
};

struct node{
    struct email data;
    struct node *next;
};

struct node *HEAD = NULL;

void print_menu(){
    printf("***** Mailing List Manager *****\n");
    printf("1. Add Email\n");
    printf("2. Delete Email\n");
    printf("3. Display Emails\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void add_email(){
    struct email e;
    printf("Enter Sender's Email ID: ");
    scanf("%s", e.from);
    printf("Enter Receiver's Email ID: ");
    scanf("%s", e.to);
    printf("Enter Email Subject: ");
    scanf("%s", e.subject);
    printf("Enter Email Message: ");
    scanf("%s", e.message);

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = e;
    new_node->next = NULL;

    if(HEAD == NULL){
        HEAD = new_node;
    } else{
        struct node *curr = HEAD;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new_node;
    }
    printf("Email added successfully!\n");
}

void delete_email(){
    if(HEAD == NULL){
        printf("Mailing List is empty!\n");
    } else{
        char email[50];
        printf("Enter Email ID to delete: ");
        scanf("%s", email);

        struct node *curr = HEAD;
        struct node *prev = NULL;
        int deleted = 0;

        while(curr != NULL){
            if(strcmp(curr->data.to, email) == 0){
                if(prev == NULL){
                    HEAD = curr->next;
                } else{
                    prev->next = curr->next;
                }
                free(curr);
                deleted = 1;
                printf("Email deleted successfully!\n");
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if(deleted == 0){
            printf("Email not found!\n");
        }
    }
}

void display_emails(){
    if(HEAD == NULL){
        printf("Mailing List is empty!\n");
    } else{
        struct node *curr = HEAD;
        int count = 1;

        while(curr != NULL){
            printf("Email %d:\n", count);
            printf("Sender's Email ID: %s\n", curr->data.from);
            printf("Receiver's Email ID: %s\n", curr->data.to);
            printf("Email Subject: %s\n", curr->data.subject);
            printf("Email Message: %s\n", curr->data.message);
            printf("\n");
            curr = curr->next;
            count++;
        }
    }
}

int main(){
    int choice;
    do{
        print_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_email(); break;
            case 2:
                delete_email(); break;
            case 3:
                display_emails(); break;
            case 4:
                printf("Thank you for using Mailing List Manager!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }while(choice != 4);

    return 0;
}