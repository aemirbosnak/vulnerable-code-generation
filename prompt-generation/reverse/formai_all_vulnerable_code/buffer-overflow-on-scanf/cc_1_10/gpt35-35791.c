//FormAI DATASET v1.0 Category: Queue ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct queue{
    int data[MAX];
    int front,rear;
};

void init_queue(struct queue *q){
    q->front=q->rear=-1;
}

int is_empty(struct queue *q){
    if(q->rear==-1 && q->front==-1)
        return 1;
    else
        return 0;
}

int is_full(struct queue *q){
    if(q->rear==MAX-1)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q,int x){
    if(is_full(q))
        printf("Queue is full\n");
    else if(is_empty(q)){
        q->front=0;
        q->rear=0;
        q->data[q->rear]=x;
    }
    else{
        q->rear++;
        q->data[q->rear]=x;
    }
}

int dequeue(struct queue *q){
    int x;
    if(is_empty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else if(q->front==q->rear){
        x=q->data[q->front];
        q->front=q->rear=-1;
    }
    else{
        x=q->data[q->front];
        q->front++;
    }
    return x;
}

void display(struct queue *q){
    int i;
    if(is_empty(q))
        printf("Queue is empty\n");
    else{
        for(i=q->front;i<=q->rear;i++)
            printf("%d\t",q->data[i]);
    }
}

int main(){
    struct queue q;
    init_queue(&q);
    int choice=0, value=0;

    printf("MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(choice!=4){
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value to be inserted:");
                scanf("%d",&value);
                enqueue(&q,value);
                break;

            case 2:
                value=dequeue(&q);
                if(value!=-1)
                    printf("Deleted element is:%d\n",value);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}