//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][20];
int top = -1;

void push(char s[])
{
    top++;
    strcpy(stack[top], s);
}

char* pop()
{
    char s[20];
    if (top == -1)
    {
        printf("Stack is empty\n");
        exit(0);
    }
    strcpy(s, stack[top]);
    top--;
    return s;
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%s\n", stack[i]);
    }
}

int main()
{
    int n, i;
    char s[20];
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the disks:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        push(s);
    }
    printf("Initial state:\n");
    display();

    printf("Final state:\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("Move disk %d from %s to %s\n", i + 1, pop(), pop());
        push(s);
    }
    for (i = 0; i < n; i++)
    {
        printf("Move disk %d from %s to %s\n", i + 1, pop(), pop());
    }
    return 0;
}