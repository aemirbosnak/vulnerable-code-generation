//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Structure for each element in the list
typedef struct{
    char name[50];
    char email[100];
    struct node* next;
}node;

//Linked List
node* head=NULL;

//Function to add a new element to the list
void add(){
    node* new_node=(node*)malloc(sizeof(node));
    printf("Enter the name: ");
    scanf("%s",new_node->name);
    printf("Enter the email: ");
    scanf("%s",new_node->email);
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    printf("\nElement added successfully\n");
}

//Function to display all the elements in the list
void display(){
    if(head==NULL){
        printf("\nList is empty\n");
    }
    else{
        node* temp=head;
        while(temp!=NULL){
            printf("\nName: %s\nEmail: %s\n",temp->name,temp->email);
            temp=temp->next;
        }
    }
}

//Function to search for an element in the list
void search(){
    char search_name[50];
    printf("Enter the name to search: ");
    scanf("%s",search_name);
    node* temp=head;
    while(temp!=NULL){
        if(strcmp(temp->name,search_name)==0){
            printf("\nName: %s\nEmail: %s\n",temp->name,temp->email);
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nElement not found\n");
    }
}

//Function to delete an element from the list
void delete(){
    char delete_name[50];
    printf("Enter the name to delete: ");
    scanf("%s",delete_name);
    node* temp=head;
    node* prev=NULL;
    while(temp!=NULL){
        if(strcmp(temp->name,delete_name)==0){
            if(prev==NULL){
                head=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            free(temp);
            printf("\nElement deleted successfully\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("\nElement not found\n");
}

//Driver code
int main(){
    int choice;
    while(1){
        printf("\n1.Add\n2.Display\n3.Search\n4.Delete\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}