//Falcon-180B DATASET v1.0 Category: Recursive ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int arr[MAX];
int top=-1;

void push(int x) {
	if(top==MAX-1) {
		printf("\nStack Overflow");
		return;
	}
	top++;
	arr[++top]=x;
}

void pop() {
	if(top==-1) {
		printf("\nStack Underflow");
		return;
	}
	printf("\n%d popped from stack",arr[top--]);
}

void display() {
	int i;
	if(top==-1) {
		printf("\nStack is Empty");
		return;
	}
	printf("\nElements in the Stack are:");
	for(i=top;i>=0;i--) {
		printf("\n%d",arr[i]);
	}
}

int main() {
	int choice,x;
	while(1) {
		printf("\n\n***STACK OPERATIONS USING ARRAY***");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("\nEnter the element to be pushed:");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid choice");
		}
	}
	return 0;
}