//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node
{
    int data;
    struct node* next;
};

void enqueue(struct node** front_ref, int new_data);
int dequeue(struct node** front_ref);
int isEmpty(struct node* front);
void display(struct node* front);

int main()
{
    struct node* front = NULL;
    int choice, element;

    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be enqueued:\n");
                scanf("%d", &element);
                enqueue(&front, element);
                break;

            case 2:
                element = dequeue(&front);
                if(element!= -1)
                    printf("The dequeued element is %d\n", element);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void enqueue(struct node** front_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("Queue is full!\n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if(*front_ref == NULL)
        *front_ref = new_node;
    else
        printf("The queue is not empty!\n");
}

int dequeue(struct node** front_ref)
{
    struct node* temp = *front_ref;
    int data = -1;

    if(temp == NULL)
        return -1;
    else
    {
        data = temp->data;
        temp = temp->next;
        *front_ref = temp;
        free(temp);
        return data;
    }
}

int isEmpty(struct node* front)
{
    if(front == NULL)
        return 1;
    else
        return 0;
}

void display(struct node* front)
{
    if(front == NULL)
        printf("The queue is empty!\n");
    else
    {
        printf("The queue elements are:\n");
        while(front!= NULL)
        {
            printf("%d ", front->data);
            front = front->next;
        }
        printf("\n");
    }
}