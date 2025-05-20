//FormAI DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5 /* size of the queue */

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void insert(int data);
int delete();
void display();

int main()
{
    int choice, data;

    while (1) {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                data = delete();
                if (data != -1) {
                    printf("Deleted element is %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void insert(int data)
{
    if (rear == QUEUE_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("Element inserted successfully\n");
}

int delete()
{
    int data;
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    data = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return data;
}

void display()
{
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in queue are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}