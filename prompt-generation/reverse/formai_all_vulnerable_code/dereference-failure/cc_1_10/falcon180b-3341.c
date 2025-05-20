//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure for linked list
typedef struct node{
    char name[50];
    int age;
    char gender[10];
    struct node *next;
}Node;

//Function to add a new node at the end of the list
void add_node(Node **head){
    Node *newnode = (Node*)malloc(sizeof(Node));
    printf("Enter the name of the person: ");
    scanf("%s", newnode->name);
    printf("Enter the age of the person: ");
    scanf("%d", &newnode->age);
    printf("Enter the gender of the person: ");
    scanf("%s", newnode->gender);
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    Node *temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

//Function to display the list
void display_list(Node *head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Name\tAge\tGender\n");
    Node *temp = head;
    while(temp!= NULL){
        printf("%s\t%d\t%s\n", temp->name, temp->age, temp->gender);
        temp = temp->next;
    }
}

//Function to search for a node with a specific name
Node* search_node(Node *head, char name[50]){
    Node *temp = head;
    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Function to delete a node with a specific name
void delete_node(Node **head, char name[50]){
    Node *temp = *head;
    Node *prev = NULL;
    if(strcmp(temp->name, name) == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && strcmp(temp->name, name)!= 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

//Main function
int main(){
    Node *head = NULL;
    int choice, flag = 1;
    while(flag){
        printf("1. Add node\n2. Display list\n3. Search node\n4. Delete node\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_node(&head);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                printf("Enter the name of the person you want to search: ");
                char name[50];
                scanf("%s", name);
                Node *result = search_node(head, name);
                if(result!= NULL){
                    printf("Name: %s\nAge: %d\nGender: %s\n", result->name, result->age, result->gender);
                }
                else{
                    printf("Node not found\n");
                }
                break;
            case 4:
                printf("Enter the name of the person you want to delete: ");
                char delname[50];
                scanf("%s", delname);
                delete_node(&head, delname);
                break;
            case 5:
                flag = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}