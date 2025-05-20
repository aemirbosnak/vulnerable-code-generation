//FormAI DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

//Defining the structure for the node
struct node{
    int data;
    struct node* next;
};

//Function to create a node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a node at the beginning of the Linked List
struct node* insertAtBeginning(struct node* head, int data){
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

//Function to insert a node at the end of the Linked List
struct node* insertAtEnd(struct node* head, int data){
    if(head == NULL){
        struct node* newNode = createNode(data);
        head = newNode;
    }
    else{
        struct node* ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        struct node* newNode = createNode(data);
        ptr->next = newNode;
    }
    return head;
}

//Function to delete the first node from the Linked List
struct node* deleteFirstNode(struct node* head){
    if(head==NULL){
        printf("Linked List is Empty!");
    }
    else if(head->next==NULL){
        printf("Node Deleted: %d\n", head->data);
        head = NULL;
        free(head);
    }
    else{
        printf("Node Deleted: %d\n", head->data);
        head = head->next;
    }
    return head;
}

//Function to delete the last node from the Linked List
struct node* deleteLastNode(struct node* head){
    if(head==NULL){
        printf("Linked List is Empty!");
    }
    else if(head->next==NULL){
        printf("Node Deleted: %d\n", head->data);
        head = NULL;
        free(head);
    }
    else{
        struct node* ptr = head;
        while(ptr->next->next!=NULL){
            ptr = ptr->next;
        }
        printf("Node Deleted: %d\n", ptr->next->data);
        struct node* temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }
    return head;
}

//Function to display the Linked List
void display(struct node* head){
    if(head == NULL){
        printf("Linked List is Empty!");
    }
    else{
        struct node* ptr = head;
        while(ptr!=NULL){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

//Main Function
int main(){
    struct node* head = NULL;
    int choice, data;
    do{
        printf("\nLinked List Operations\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete first node\n");
        printf("4. Delete last node\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                head = deleteFirstNode(head);
                break;
            case 4:
                head = deleteLastNode(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=6);
    return 0;
}