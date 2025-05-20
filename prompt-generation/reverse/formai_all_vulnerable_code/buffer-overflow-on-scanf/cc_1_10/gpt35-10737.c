//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10  // Defining the maximum size of the Queue

typedef struct queue{
    int data[SIZE];
    int rear, front;
}Queue;

void enqueue(Queue *q, int val){
    if(q->rear == SIZE - 1){   // If Queue is full
        printf("Queue is full!\n");
        return;
    }
    q->data[++q->rear] = val;
}

int dequeue(Queue *q){
    if(q->front == q->rear){   // If Queue is empty
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[++q->front];
}

void display(Queue q){
    if(q.front == q.rear){   // If Queue is empty
        printf("Queue is empty!\n");
        return;
    }
    for(int i=q.front+1; i<=q.rear; i++)
        printf("%d ", q.data[i]);
    printf("\n");
}

int main(){
    Queue q1, q2;
    q1.front = q1.rear = -1;
    q2.front = q2.rear = -1;
    int num, result;
    
    printf("Player 1, enter your numbers (Enter -1 to stop): ");
    do{
        scanf("%d", &num);
        if(num == -1)
            break;
        enqueue(&q1, num);
    }while(1);
    
    printf("Player 2, enter your numbers (Enter -1 to stop): ");
    do{
        scanf("%d", &num);
        if(num == -1)
            break;
        enqueue(&q2, num);
    }while(1);
    
    printf("Queue of Player 1: ");
    display(q1);
    
    printf("Queue of Player 2: ");
    display(q2);

    printf("\nGame Starts...\n");
    while(1){
        if(q1.front == q1.rear){   // If Player 1's Queue is empty
            printf("Player 2 won the game!\n");
            break;
        }
        num = dequeue(&q1);
        printf("Player 1's turn, number is %d\n", num);
        printf("Queue of Player 1: ");
        display(q1);
        if(num == 7){   // If 7 is produced by Player 1
            printf("Player 1 wins the game!\n");
            break;
        }
        enqueue(&q2, num);
        
        if(q2.front == q2.rear){   // If Player 2's Queue is empty
            printf("Player 1 won the game!\n");
            break;
        }
        num = dequeue(&q2);
        printf("Player 2's turn, number is %d\n", num);
        printf("Queue of Player 2: ");
        display(q2);
        if(num == 7){   // If 7 is produced by Player 2
            printf("Player 2 wins the game!\n");
            break;
        }
        enqueue(&q1, num);
    }
    
    return 0;
}