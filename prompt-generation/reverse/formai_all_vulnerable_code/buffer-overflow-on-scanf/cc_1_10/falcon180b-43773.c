//Falcon-180B DATASET v1.0 Category: Database querying ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for a node
struct node{
    char name[20];
    int value;
    struct node* next;
};

//function to create a new node
struct node* createNode(char name[],int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name,name);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

//function to add a node to the end of the list
void addNode(struct node** head,char name[],int value){
    struct node* newNode = createNode(name,value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//function to search for a node
struct node* searchNode(struct node* head,char name[]){
    struct node* temp = head;
    while(temp!= NULL){
        if(strcmp(temp->name,name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//function to delete a node
void deleteNode(struct node** head,char name[]){
    struct node* temp = searchNode(*head,name);
    if(temp == NULL){
        printf("Node not found\n");
        return;
    }
    if(temp == *head){
        *head = temp->next;
        free(temp);
        return;
    }
    struct node* prev = *head;
    while(prev->next!= temp){
        prev = prev->next;
    }
    prev->next = temp->next;
    free(temp);
}

//function to display the list
void displayList(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%s %d\n",temp->name,temp->value);
        temp = temp->next;
    }
}

//main function
int main(){
    struct node* head = NULL;
    char choice;
    int value;
    char name[20];
    do{
        printf("\nEnter 1 to add a node\nEnter 2 to delete a node\nEnter 3 to search for a node\nEnter 4 to display the list\nEnter 5 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the name of the node: ");
                scanf("%s",name);
                printf("Enter the value of the node: ");
                scanf("%d",&value);
                addNode(&head,name,value);
                break;
            case 2:
                printf("Enter the name of the node to be deleted: ");
                scanf("%s",name);
                deleteNode(&head,name);
                break;
            case 3:
                printf("Enter the name of the node to be searched: ");
                scanf("%s",name);
                struct node* result = searchNode(head,name);
                if(result!= NULL){
                    printf("Node found\n");
                }
                else{
                    printf("Node not found\n");
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 5);
    return 0;
}