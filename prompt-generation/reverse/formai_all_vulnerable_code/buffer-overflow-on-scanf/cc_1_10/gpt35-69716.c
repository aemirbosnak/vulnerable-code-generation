//FormAI DATASET v1.0 Category: Linked list operations ; Style: systematic
#include<stdio.h>
#include<malloc.h>

// Defining the structure of linked list node
struct LinkedList{
    int data;
    struct LinkedList* next;
};

// Method to create node of linked list
struct LinkedList* createNode(int data){
    struct LinkedList* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    node->data = data;
    node->next = NULL;
    return node;
}

// Method to display the linked list
void displayLinkedList(struct LinkedList* root){
    struct LinkedList* curr = root;
    while(curr != NULL){
        printf("%d->",curr->data);
        curr = curr->next;
    }
}

// Method to insert node at the beginning of linked list
struct LinkedList* insertAtBeginning(struct LinkedList* root, int data){
    struct LinkedList* node = createNode(data);
    node->next = root;
    return node;
}

// Method to insert node at the end of linked list
struct LinkedList* insertAtEnd(struct LinkedList* root, int data){
    struct LinkedList* node = createNode(data);

    // if linked list doesn't have any node, then this node is the root node
    if(root == NULL){
        return node;
    }

    struct LinkedList* curr = root;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = node;
    return root;
}

// Method to insert node at specified position of linked list
struct LinkedList* insertAtPosition(struct LinkedList* root, int data, int position){
    struct LinkedList* node = createNode(data);
    if(position == 1){
        node->next = root;
        return node;
    }

    struct LinkedList* curr = root;
    for(int i = 1; i < position-1 && curr != NULL; i++){
        curr = curr->next;
    }
    if(curr == NULL){
        printf("\n Invalid position \n");
        return root;
    }
    node->next = curr->next;
    curr->next = node;
    return root;
}

// Method to delete node from the beginning of linked list
struct LinkedList* deleteFromBeginning(struct LinkedList* root){
    if(root == NULL){
        printf("Linked List is empty \n");
        return root;
    }
    struct LinkedList* temp = root;
    root = root->next;
    free(temp);
    return root;
}

// Method to delete node from the end of linked list
struct LinkedList* deleteFromEnd(struct LinkedList* root){
    if(root == NULL){
        printf("Linked List is empty \n");
        return root;
    }
    struct LinkedList* curr = root;
    struct LinkedList* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    free(curr);
    prev->next = NULL;
    return root;
}

// Method to delete node from specified position of linked list
struct LinkedList* deleteFromPosition(struct LinkedList* root, int position){
    if(root == NULL){
        printf("Linked List is empty \n");
        return root;
    }
    if(position == 1){
        struct LinkedList* temp = root;
        root = root->next;
        free(temp);
        return root;
    }
    struct LinkedList* curr = root;
    struct LinkedList* prev = NULL;
    for(int i = 1; i < position && curr != NULL; i++){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        printf("Invalid position \n");
        return root;
    }
    prev->next = curr->next;
    free(curr);
    return root;
}

// Main method to show operations on linked list
int main(){
    struct LinkedList* root = NULL;
    int choice;

    while(1){
        printf("\n*********** Linked List Operations ************\n");
        printf("1. Display \n");
        printf("2. Insert at beginning \n");
        printf("3. Insert at end \n");
        printf("4. Insert at position \n");
        printf("5. Delete from beginning \n");
        printf("6. Delete from end \n");
        printf("7. Delete from position \n");
        printf("8. Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\n Linked List : ");
                displayLinkedList(root);
                printf("\n");
                break;
            case 2:
                printf("\n Enter data to insert at beginning : ");
                int data_begin;
                scanf("%d",&data_begin);
                root = insertAtBeginning(root, data_begin);
                printf("Created a node with data %d \n", root->data);
                break;
            case 3:
                printf("\n Enter data to insert at end : ");
                int data_end;
                scanf("%d",&data_end);
                root = insertAtEnd(root, data_end);
                printf("Created a node with data %d \n", root->data);
                break;
            case 4:
                printf("\n Enter data to insert : ");
                int data;
                scanf("%d",&data);
                printf("Enter the position for the data : ");
                int position;
                scanf("%d",&position);
                root = insertAtPosition(root, data, position);
                printf("Created a node with data %d \n", root->data);
                break;
            case 5:
                root = deleteFromBeginning(root);
                printf("Deleted the node from beginning \n");
                break;
            case 6:
                root = deleteFromEnd(root);
                printf("Deleted the node from end \n");
                break;
            case 7:
                printf("\n Enter the position to delete a node : ");
                int pos;
                scanf("%d",&pos);
                root = deleteFromPosition(root, pos);
                printf("Deleted the node from position %d \n",pos);
                break;
            case 8:
                printf("\n Thank You for using the program! \n");
                return 0;
            default:
                printf("\n Invalid choice!");
        }
    }
    return 0;
}