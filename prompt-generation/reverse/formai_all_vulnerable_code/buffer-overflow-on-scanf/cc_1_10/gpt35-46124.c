//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include<stdio.h>
#define MAX 5  // Maximum size of the Queue

// Queue using C

int f = -1, r = -1;   // f: front index of the Queue, r: rear index of the Queue

int Queue[MAX];   // Queue declaration

void Enqueue(int x){    // To Enqueue elements into the Queue
    if (r == MAX-1){
        printf("\n Queue Overflow!!!");    // When the Queue is full, print overflow message
    }
    else if (f == -1 && r == -1){
        f = r = 0;
        Queue[r] = x;
    }
    else{
        r++;
        Queue[r] = x;
    }
}

void Dequeue(){    // To Dequeue elements from the Queue
    if (f == -1 && r == -1){
        printf("\n Queue Underflow!!!");    // When the Queue is empty, print underflow message
    }
    else if (f==r){
        printf("\n Dequeued: %d", Queue[f]);
        f = r = -1;
    }
    else{
        printf("\n Dequeued: %d", Queue[f]);
        f++;
    }
}

void Display(){    // To Display elements of the Queue
    if (f == -1 && r == -1){
        printf("\n Empty Queue!!!");    // When the Queue is empty, print empty message
    }
    else{
        printf("\n Queue elements are: ");
        for (int i=f; i<=r; i++){
            printf("%d ", Queue[i]);
        }
    }
}

int main(){
    int choice, x;
    do{
        printf("\n\n Choose an option: ");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Quit");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Enter the element to enqueue: ");
                scanf("%d", &x);
                Enqueue(x);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                Display();
                break;

            case 4:
                printf("\n Quitting the program...Thank you!");
                break;

            default:
                printf("\n Invalid choice...Try Again!");
                break;
        }
    }while(choice != 4);
    return 0;
}