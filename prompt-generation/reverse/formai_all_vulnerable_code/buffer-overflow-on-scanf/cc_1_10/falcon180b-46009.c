//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node{
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(!new_node){
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add an element to the rear of the queue
void enqueue(struct node** front_ref, struct node** rear_ref, int data){
    struct node* new_node = create_node(data);
    if(*rear_ref == NULL){
        *front_ref = new_node;
        *rear_ref = new_node;
    }
    else{
        (*rear_ref)->next = new_node;
        *rear_ref = new_node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct node** front_ref, struct node** rear_ref){
    struct node* temp_node = *front_ref;
    int data = temp_node->data;
    if(*front_ref == *rear_ref){
        *front_ref = NULL;
        *rear_ref = NULL;
    }
    else{
        *front_ref = (*front_ref)->next;
    }
    free(temp_node);
    return data;
}

// Function to display the elements of the queue
void display(struct node* front){
    struct node* temp = front;
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main(){
    struct node* front = NULL;
    struct node* rear = NULL;
    int choice, data;

    printf("Enter 1 to enqueue an element\n");
    printf("Enter 2 to dequeue an element\n");
    printf("Enter 3 to display the queue\n");
    printf("Enter 4 to exit\n");

    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;

            case 2:
                data = dequeue(&front, &rear);
                printf("Dequeued element is: %d\n", data);
                break;

            case 3:
                display(front);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 4);

    return 0;
}