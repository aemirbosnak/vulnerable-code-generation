//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

//defining the structure of node
struct Node{
    int data;
    struct Node *next; //pointer to next node
};

typedef struct Node node;

node* createNode(int data){
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(node** head, int data){
    //creating a new node
    node* new_node = createNode(data);
    node* current_node = *head;

    //checks if the linked list is empty
    if(*head == NULL){
        *head = new_node;
    } else{
        //traversing till end of the linked list
        while(current_node->next){
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    printf("Node with data %d appended\n", data);
}

void display(node* head){
    node* current_node = head;

    if(head == NULL){
        printf("Linked list is empty\n");
    } else{
        printf("Linked list: ");
        while(current_node){
            printf("%d ", current_node->data);
            current_node = current_node->next;
        }
    }
}

void delete(node** head, int data){
    node* prev_node = NULL;
    node* current_node = *head;

    //checks if the node to be deleted is the head node
    if(current_node != NULL && current_node->data == data){
        *head = current_node->next;
        free(current_node);
        printf("Node with data %d deleted\n", data);
        return;
    }

    //traversing till the node to be deleted is found
    while(current_node != NULL && current_node->data != data){
        prev_node = current_node;
        current_node = current_node->next;
    }

    //checks if node to be deleted is found or not
    if(current_node == NULL){
        printf("Node with data %d not found\n", data);
        return;
    }

    //deleting the node
    prev_node->next = current_node->next;
    free(current_node);
    printf("Node with data %d deleted\n", data);
}

int main(){
    node* head = NULL; //initializing the head node
    int choice, data;

    do{
        printf("\nLinked List Operations\n");
        printf("1. Append\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter node data: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 2:
                printf("Enter node data to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0); //terminating the program

            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0; //successfully terminating the program
}