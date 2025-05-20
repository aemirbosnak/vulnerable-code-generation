//FormAI DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h>
#define MAX 100  

int queue[MAX];  
int front = -1, rear = -1;  

void enqueue(int data) {  
    if (rear == MAX - 1) {  
        printf("\n Overflow!");  
        return;  
    }  
    if (front == -1)  
        front = 0;  
    rear++;  
    queue[rear] = data;  
    printf("\n %d added to Queue", data);  
}  
  
void dequeue() {  
    if (front == -1 || front > rear) {  
        printf("\n Underflow!");  
        return;  
    }  
    printf("\n %d dequeued from Queue", queue[front]);  
    front++;  
}  
  
void display() {  
    if (front == -1) {  
        printf("\n Empty Queue");  
        return;  
    }  
    printf("\n Queue elements are:\n");  
    for (int i = front; i <= rear; i++)  
        printf("%d\t", queue[i]);  
}  
  
int main() {  
    int choice, data;  
    while (1) {  
        printf("\n Queue Operations: \n");  
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");  
        printf("\nEnter your choice:");  
        scanf("%d", &choice);  
        switch (choice) {  
            case 1:  
                printf("\nEnter data to enqueue:");  
                scanf("%d", &data);  
                enqueue(data);  
                break;  
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nIncorrect Choice!");  
        }  
    }  
    return 0;  
}