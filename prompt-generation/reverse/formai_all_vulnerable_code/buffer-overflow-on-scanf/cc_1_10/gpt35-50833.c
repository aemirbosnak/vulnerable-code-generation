//FormAI DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char email[100];
    struct node *next;
};

struct node *head=NULL, *tail=NULL;

void addEmail(char email[]){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->email,email);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
    printf("Email added successfully!\n");
}

void removeEmail(char email[]){
    struct node *temp=head, *prev=NULL;
    while(temp!=NULL){
        if(strcmp(temp->email,email)==0){
            if(prev!=NULL){
                prev->next=temp->next;
                free(temp);
            }
            else{
                head=temp->next;
                free(temp);
            }
            printf("Email removed successfully!\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Email not found!\n");
}

void displayList(){
    struct node *temp=head;
    printf("Mailing List:\n");
    while(temp!=NULL){
        printf("%s\n",temp->email);
        temp=temp->next;
    }
}

int main(){
    char email[100];
    int choice;
    do{
        printf("\nMailing List Manager\n");
        printf("1) Add email\n");
        printf("2) Remove email\n");
        printf("3) Display list\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter email: ");
                scanf("%s",email);
                addEmail(email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s",email);
                removeEmail(email);
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    while(choice!=4);
    return 0;
}