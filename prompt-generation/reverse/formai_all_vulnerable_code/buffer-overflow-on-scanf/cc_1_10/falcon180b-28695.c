//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define STACK_SIZE 100

struct stack{
    int top;
    int *arr;
};

void push(struct stack *s,int value){
    if(s->top>=STACK_SIZE-1){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top]=value;
}

int pop(struct stack *s){
    if(s->top<0){
        printf("Stack Underflow\n");
        return -1;
    }
    int value=s->arr[s->top];
    s->top--;
    return value;
}

void display(struct stack s){
    if(s.top<0){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i=s.top;i>=0;i--){
        printf("%d\n",s.arr[i]);
    }
}

void towerOfHanoi(int n,char source,char destination,char auxiliary){
    struct stack s1,s2,s3;
    s1.top=-1;
    s2.top=-1;
    s3.top=-1;
    s1.arr=(int*)malloc(STACK_SIZE*sizeof(int));
    s2.arr=(int*)malloc(STACK_SIZE*sizeof(int));
    s3.arr=(int*)malloc(STACK_SIZE*sizeof(int));

    push(&s1,n);

    int steps=0;

    while(s1.top>=0){
        if(s1.top==0){
            push(&s2,pop(&s1));
        }
        else{
            push(&s3,pop(&s1));
        }
        push(&s1,pop(&s2));
        steps++;
        display(s1);
        display(s2);
        display(s3);
    }

    printf("Minimum number of steps required to solve the problem is %d\n",steps);
}

int main(){
    int n;
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    towerOfHanoi(n,'A','C','B');
    return 0;
}