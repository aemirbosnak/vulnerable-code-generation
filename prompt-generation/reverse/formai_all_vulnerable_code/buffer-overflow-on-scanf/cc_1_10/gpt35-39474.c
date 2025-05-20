//FormAI DATASET v1.0 Category: Queue Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#define max 5

int areyousure() {   //function to confirm the choice of the user
    char choice;
    printf("Are you sure? (y/n): ");
    scanf(" %c",&choice);
    if(choice == 'y' || choice == 'Y')
        return 1;
    else
        return -1;
}

int main() {
    int queue[max],front=-1,rear=-1;   //intializing the queue
    int choice,num;

    printf("\n\t\t\t-Queue Implementation Program-\n");
    do {
        printf("\nPlease select an operation:\n1. Insert element into queue.\n");
        printf("2. Delete element from queue.\n3. Display the queue.\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: //insertion of element in queue
                if(rear==max-1) {
                    printf("\nQueue Overflow.");
                } else {
                    printf("\nEnter element: ");
                    scanf("%d",&num);
                    if(front==-1 && rear==-1) {
                        front = rear = 0;   //if queue is empty or queue is left with only one element
                    } else {
                        rear++;
                    }
                    queue[rear]=num;   //storing element in the last position
                }
                break;

            case 2:  //deletion of element from queue
                if(front==-1 || front>rear) {
                    printf("\nQueue Underflow.");   //if queue is empty or there are already elements deleted from the queue
                } else {
                    printf("\nElement deleted from queue is : %d",queue[front]);
                    front++;   //incrementing front pointer to the next element in the queue
                }
                break;

            case 3: //displaying the elements in queue
                printf("\n");
                if(front==-1 || front>rear) {
                    printf("\nQueue is empty.");  //if the queue is empty
                } else {
                    for(int i=front;i<=rear;i++) {
                        printf("%d ",queue[i]);  //printing the queue elements
                    }
                }
                break;

            case 4: //exit condition
                if(areyousure() == 1) {
                    exit(0);   //if user confirms exit
                } else {
                    break; //if user changes their mind
                }
            
            default:
                printf("\nPlease select a valid operation");
                break;
        }
    } while(choice!=4); //loop condition until user chooses to exit

    return 0; //successful execution
}