//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact{
    char name[50];
    char phone[11];
    char email[50];
    struct contact *next;
}*head=NULL;

void add_contact(){
    struct contact* temp;
    temp=(struct contact*)malloc(sizeof(struct contact));
    printf("\nEnter name: ");
    scanf(" %[^\n]s",temp->name);
    printf("\nEnter phone number: ");
    scanf("%s",temp->phone);
    printf("\nEnter email: ");
    scanf("%s",temp->email);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct contact *p;
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
    printf("\nContact added successfully\n");
}

void display_contacts(){
    if(head==NULL){
        printf("\nNo contacts found\n");
    }
    else{
        struct contact *p;
        p=head;
        printf("\nName\t\tPhone\t\tEmail\n");
        while(p!=NULL){
            printf("%-15s%-15s%-15s\n",p->name,p->phone,p->email);
            p=p->next;
        }
    }
}

void search_contact(){
    if(head==NULL){
        printf("\nNo contacts found\n");
    }
    else{
        char name[50];
        printf("\nEnter name to search: ");
        scanf(" %[^\n]s",name);
        struct contact *p;
        p=head;
        int flag=0;
        while(p!=NULL){
            if(strcmp(p->name,name)==0){
                printf("\nName\t\tPhone\t\tEmail\n");
                printf("%-15s%-15s%-15s\n",p->name,p->phone,p->email);
                flag=1;
                break;
            }
            p=p->next;
        }
        if(flag==0){
            printf("\nContact not found\n");
        }
    }
}

void delete_contact(){
    if(head==NULL){
        printf("\nNo contacts found\n");
    }
    else{
        char name[50];
        printf("\nEnter name to delete: ");
        scanf(" %[^\n]s",name);
        struct contact *p,*prev;
        p=head;
        int flag=0;
        while(p!=NULL){
            if(strcmp(p->name,name)==0){
                if(p==head){
                    head=p->next;
                    free(p);
                }
                else{
                    prev->next=p->next;
                    free(p);
                }
                printf("\nContact deleted successfully\n");
                flag=1;
                break;
            }
            prev=p;
            p=p->next;
        }
        if(flag==0){
            printf("\nContact not found\n");
        }
    }
}

int main(){
    int choice;
    do{
        printf("\nMENU:");
        printf("\n1. Add contact");
        printf("\n2. Display all contacts");
        printf("\n3. Search contact");
        printf("\n4. Delete contact");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_contact();
                    break;
            case 2: display_contacts();
                    break;
            case 3: search_contact();
                    break;
            case 4: delete_contact();
                    break;
            case 5: printf("\nExiting...\n");
                    exit(0);
                    break;
            default: printf("\nInvalid choice\n");
                     break;
        }
    }while(choice!=5);
    return 0;
}