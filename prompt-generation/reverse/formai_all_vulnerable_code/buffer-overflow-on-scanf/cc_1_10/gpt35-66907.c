//FormAI DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h> 
  
#define SIZE 5 
  
int queue[SIZE];  
int front = -1;  
int rear = -1;  
  
void enqueue(int item)  
{  
    if(rear == SIZE-1)  
    {  
        printf("\nERROR: Queue is full\n");  
    }  
    else  
    {  
        if(front == -1)  
            front = 0;  
        rear++;  
        queue[rear] = item;  
        printf("\nInserted %d",item);  
    }  
}  
  
void dequeue()  
{  
    if(front == -1)  
    {  
        printf("\nERROR: Queue is empty\n");  
    }  
    else  
    {  
        printf("\nDeleted %d",queue[front]);  
        front++;  
        if(front > rear)  
            front = rear = -1;  
    }  
}  
  
void display()  
{  
    if(rear == -1)  
    {  
        printf("\nERROR: Queue is empty\n");  
    }  
    else  
    {  
        int i;  
        printf("\nQueue elements: \n");  
        for(i=front; i<=rear; i++)  
            printf("%d\t",queue[i]);  
    }  
}  
  
int main()  
{  
    printf("************C Queue Implementation************\n");  
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");  
    int choice,item;  
    do  
    {  
        printf("\nEnter your choice: ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1: printf("\nEnter the element to be inserted: ");  
                    scanf("%d",&item);  
                    enqueue(item);  
                    break;  
            case 2: dequeue();  
                    break;  
            case 3: display();  
                    break;  
            case 4: printf("\nExiting...");  
                    break;  
            default: printf("\nInvalid choice\n");  
                     break;  
        }  
    }while(choice!=4);  
    return 0;  
}