//FormAI DATASET v1.0 Category: Queue ; Style: curious
#include<stdio.h>
#define MAXSIZE 10      //Let's set the maximum size of our queue to 10
int queue[MAXSIZE], front=-1, rear=-1;     //Initialize queue, front and rear pointers 

void enqueue(int element){      //Function to add elements to the queue
    if((front == 0 && rear == MAXSIZE-1) || (front == rear+1)){      //Case where the queue is full and no more elements can be added
        printf("Cannot add more elements to the queue\n");
        return;
    }
    else if(front == -1 && rear == -1){         //Case for the empty queue
        front = rear = 0;
        queue[rear] = element;
    }
    else if(rear == MAXSIZE-1 && front != 0){      //Case for wrap around condition when rear has reached the end of the queue
        rear = 0;
        queue[rear] = element;
    }
    else{           //Normal case for adding elements to the queue
        rear++;
        queue[rear] = element;
    }
}

int dequeue(){          //Function to remove elements from the queue
    int element;
    if(front == -1){            //Case for empty queue
        printf("Cannot remove elements from the queue as it is empty\n");
        return -1;
    }
    else if(front == rear){         //Case where there is only one element in the queue
        element = queue[front];
        front = rear = -1;
    }
    else if(front == MAXSIZE-1){        //Case for wrap around condition when front has reached the end of the queue
        element = queue[front];
        front = 0;
    }
    else{           //Normal case for removing elements from the queue
        element = queue[front];
        front++;
    }
    return element;
}

void display(){          //Function to display the elements in the queue
    int i;
    if(front == -1 && rear == -1){          //Case for empty queue
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements in the queue are: ");
    if(front <= rear)                       //Case where front is less than or equal to rear
        for(i=front; i<=rear; i++)
            printf("%d ", queue[i]);
    else{                                   //Case where rear is less than front due to wrap around condition
        for(i=front; i<MAXSIZE; i++)
            printf("%d ", queue[i]);
        for(i=0; i<=rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){             //Main function
    printf("********** C QUEUE PROGRAM **********\n");
    printf("Max size of the queue is set to %d\n", MAXSIZE);
    int choice = 0, element = 0;
    while(choice != 4){
        printf("\nWhat would you like to do?\n");
        printf("1. Add element to the queue\n");
        printf("2. Remove element from the queue\n");
        printf("3. Display elements in the queue\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element to be added to the queue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if(element != -1)
                    printf("Element removed from the queue: %d\n", element);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}