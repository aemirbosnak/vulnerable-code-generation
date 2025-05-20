//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{ //Defining linked-list structure
    char email[50];
    struct node* next;
}node_t;

node_t* head=NULL;

void add_email(){ //Function to add email to the linked-list
    node_t* temp=(node_t*)malloc(sizeof(node_t));
    printf("Enter the email address: ");
    scanf("%s",temp->email);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        node_t* current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=temp;
    }
    printf("Email Address %s added to the list successfully!!\n", temp->email);
}

void display_list(){ //Function to display the list
    if(head==NULL){
        printf("The list is empty!!\n");
    }
    else{
        node_t* current=head;
        printf("The list contains the following email addresses:\n\n");
        while(current!=NULL){
            printf("%s\n\n", current->email);
            current=current->next;
        }
    }
}

void delete_email(){ //Function to delete email from the list
    char email[50];
    printf("Enter the email address to be deleted: ");
    scanf("%s",email);
    node_t* current=head;
    node_t* previous=NULL;
    while(current!=NULL){
        if(strcmp(current->email,email)==0){
            break;
        }
        previous=current;
        current=current->next;
    }
    if(current==NULL){
        printf("Email address not found!!\n");
        return;
    }
    if(previous==NULL){
        head=current->next;
        printf("Email address %s deleted successfully!!\n", email);
        free(current);
    }
    else{
        previous->next=current->next;
        printf("Email address %s deleted successfully!!\n", email);
        free(current);
    }
}

int main(){
    while(1){
        printf("\nPress 1 to Add Email to the List\nPress 2 to Delete Email from the List\nPress 3 to Display List\nPress 0 to Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 0: printf("Thank you for using Email Mailing List Manager!!\n"); 
                    exit(0);
            case 1: add_email();
                    break;
            case 2: delete_email();
                    break;
            case 3: display_list();
                    break;
            default: printf("Invalid choice!!\n");
        }
    }
    return 0;
}