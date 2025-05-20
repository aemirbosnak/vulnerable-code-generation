//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct Node
{
    int data;
    struct Node* link;
};

void enqueue(struct Node** front_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->link = NULL;

    if(*front_ref == NULL)
    {
        new_node->link = new_node;
        *front_ref = new_node;
    }
    else
    {
        new_node->link = *front_ref;
        *front_ref = new_node;
    }
}

int dequeue(struct Node** front_ref)
{
    struct Node* temp = *front_ref;
    int data = temp->data;

    if(*front_ref == NULL)
        return -1;

    if(*front_ref == temp)
    {
        *front_ref = temp->link;
        free(temp);
    }
    else
    {
        struct Node* prev = *front_ref;
        while(prev->link!= temp)
        {
            prev = prev->link;
        }
        prev->link = temp->link;
        free(temp);
    }

    return data;
}

int peek(struct Node* front)
{
    if(front == NULL)
        return -1;
    else
        return front->data;
}

int is_empty(struct Node* front)
{
    if(front == NULL)
        return 1;
    else
        return 0;
}

void display(struct Node* front)
{
    if(front == NULL)
        printf("\nQueue is Empty\n");
    else
    {
        printf("\nQueue is:\n");
        struct Node* temp = front;
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        while(temp!= front);
    }
}

int main()
{
    struct Node* front = NULL;
    int choice, data;

    do
    {
        printf("\n\nCIRCULAR QUEUE IMPLEMENTATION\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;

            case 2:
                data = dequeue(&front);
                if(data!= -1)
                    printf("\nDequeued data is: %d", data);
                break;

            case 3:
                data = peek(front);
                if(data!= -1)
                    printf("\nFront data is: %d", data);
                else
                    printf("\nQueue is Empty");
                break;

            case 4:
                display(front);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }
    while(1);

    return 0;
}