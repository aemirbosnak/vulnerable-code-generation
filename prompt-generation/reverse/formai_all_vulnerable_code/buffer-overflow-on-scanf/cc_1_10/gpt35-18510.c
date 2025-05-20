//FormAI DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>  
#define MAX 5           
int queue[MAX];  
int front = -1, rear = -1;   
int main()  
{  
    int choice;  
    while(1) //infinite loop  
    {  
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice: ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            Enqueue();  
            break;  
            case 2:  
            Dequeue();  
            break;  
            case 3:  
            Display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("\nInvalid Choice\n");  
        }  
    }  
}  
  
Enqueue()  
{  
    int element;  
    if(rear == MAX-1)  //Overflow condition  
    printf("\nQueue is full\n");  
    else  
    {  
        printf("\nEnter the element: ");  
        scanf("%d",&element);  
        if(front == -1 && rear == -1)  //Inserting first element  
        {  
            front = rear = 0;  
            queue[rear] = element;  
        }  
        else                      //Inserting any other element  
        {  
            rear++;  
            queue[rear] = element;  
        }  
    }  
}  
  
Dequeue()  
{  
    if(front == -1 && rear == -1)  //Underflow condition  
    printf("\nQueue is empty\n");  
    else  
    {  
        printf("\nDeleted element: %d\n",queue[front]);  
        if(front == rear)  //Queue becomes empty  
        front = rear = -1;  
        else  
        front++;  
    }  
}  
  
Display()  
{  
    int i;  
    if(front == -1 && rear == -1)   //Underflow condition  
    printf("\nQueue is empty\n");  
    else  
    {  
        printf("\nQueue Elements: \n");  
        for(i=front;i<=rear;i++)  
        printf("%d\t",queue[i]);  
    }  
}