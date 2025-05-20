//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x) {
	if((rear+1)%MAX == front) {
		printf("Queue is full!\n");
		return;
	}
	if(front == -1 && rear == -1) {
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear+1)%MAX;
	}
	queue[rear] = x;
	printf("%d was added to the queue!\n", x);
}

void dequeue() {
	if(front == -1 && rear == -1) {
		printf("Queue is empty!\n");
		return;
	}
	printf("%d was removed from the queue!\n", queue[front]);
	if(front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front = (front+1)%MAX;
	}
}

void display() {
	int i = front;
	if(front == -1 && rear == -1) {
		printf("Queue is empty!\n");
		return;
	}
	printf("The queue is:\n");
	while(i != rear) {
		printf("%d\n", queue[i]);
		i = (i+1)%MAX;
	}
	printf("%d\n", queue[rear]);
}

int main() {
	int choice, value;
	printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
	while(1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: printf("Enter the value to be added: ");
				scanf("%d", &value);
				enqueue(value);
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Invalid choice!\n");
		}
	}
	return 0;
}