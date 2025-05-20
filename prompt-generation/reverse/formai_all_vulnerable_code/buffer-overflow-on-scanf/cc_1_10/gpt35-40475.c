//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int head = -1, tail = -1;
int queue[MAX];

void queueInsert(int data) {
    if(head == 0 && tail == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    else if(head == -1 && tail == -1) {
        head = tail = 0;
    }
    else if(tail == MAX - 1 && head != 0) {
        tail = 0;
    }
    else {
        tail++;
    }
    queue[tail] = data;
}

int queueDelete() {
    int data;
    if(head == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    data = queue[head];
    if(head == tail) {
        head = tail = -1;
    }
    else if(head == MAX - 1) {
        head = 0;
    }
    else {
        head++;
    }
    return data;
}

void display() {
    int i;
    if(head == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue are : ");
    for(i = head;i != tail;i = (i+1)%MAX) {
        printf("%d ",queue[i]);
    }
    printf("%d\n",queue[i]);
}

int main() {
    int data, choice;
    while(1) {
        printf("1. Insert the element\n");
        printf("2. Delete the element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                queueInsert(data);
                break;
            case 2:
                data = queueDelete();
                if(data != -1) {
                    printf("Deleted element is : %d\n",data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}