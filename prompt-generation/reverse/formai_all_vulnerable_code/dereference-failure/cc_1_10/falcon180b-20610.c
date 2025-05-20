//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node* next;
};

void enqueue(struct node** front_ref, int new_data);
int dequeue(struct node** front_ref);
int is_empty(struct node* front);
void print_queue(struct node* front);

int main(){
    struct node* front = NULL;
    int choice, new_data;

    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter the data to be enqueued: ");
                scanf("%d", &new_data);
                enqueue(&front, new_data);
                break;
            }
            case 2:{
                new_data = dequeue(&front);
                if(new_data!= -1)
                    printf("Dequeued element is %d\n", new_data);
                break;
            }
            case 3:{
                print_queue(front);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }while(1);

    return 0;
}

//Function to add an element to the rear of the queue
void enqueue(struct node** front_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if(*front_ref == NULL){
        *front_ref = new_node;
        return;
    }

    struct node* last = *front_ref;
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = new_node;
}

//Function to remove an element from the front of the queue
int dequeue(struct node** front_ref){
    struct node* front = *front_ref;
    if(front == NULL)
        return -1;

    int data = front->data;
    struct node* temp = front;
    *front_ref = front->next;
    free(temp);

    return data;
}

//Function to check if the queue is empty
int is_empty(struct node* front){
    if(front == NULL)
        return 1;
    else
        return 0;
}

//Function to print the elements in the queue
void print_queue(struct node* front){
    if(is_empty(front))
        printf("Queue is empty\n");
    else{
        printf("Elements in the queue are: ");
        while(front!= NULL){
            printf("%d ", front->data);
            front = front->next;
        }
        printf("\n");
    }
}