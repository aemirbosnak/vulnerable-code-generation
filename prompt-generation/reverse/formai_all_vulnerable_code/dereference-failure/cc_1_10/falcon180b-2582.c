//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node{
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the end of the queue
void enqueue(struct node** front_ref, int data){
    struct node* node = newNode(data);
    if(*front_ref == NULL){
        *front_ref = node;
        return;
    }
    struct node* last = *front_ref;
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = node;
}

// Function to remove an element from the front of the queue
int dequeue(struct node** front_ref){
    if(*front_ref == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    struct node* temp = *front_ref;
    *front_ref = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display(struct node* front){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main(){
    struct node* front = NULL;
    int choice, data;

    while(1){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;

            case 2:
                data = dequeue(&front);
                if(data!= -1){
                    printf("Dequeued element is %d\n", data);
                }
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}