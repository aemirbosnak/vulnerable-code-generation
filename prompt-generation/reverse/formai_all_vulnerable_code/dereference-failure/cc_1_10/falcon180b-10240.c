//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

/* structure of a node */
struct node{
    int data;
    struct node* next;
};

/* function to create a new node */
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* function to add an element to the queue */
void enqueue(struct node** front_ref, int data){
    struct node* node = newNode(data);
    node->next = *front_ref;
    *front_ref = node;
}

/* function to remove an element from the queue */
int dequeue(struct node** front_ref){
    struct node* node = *front_ref;
    int data = node->data;
    struct node* temp = *front_ref;
    *front_ref = node->next;
    free(temp);
    return data;
}

/* function to display the elements in the queue */
void display(struct node* front){
    struct node* temp = front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* main function */
int main(){
    struct node* front = NULL;
    int choice, data;

    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;

            case 2:
                data = dequeue(&front);
                if(data == -1)
                    printf("Queue is empty.\n");
                else
                    printf("Deleted element is %d.\n", data);
                break;

            case 3:
                printf("Elements in the queue are: ");
                display(front);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}