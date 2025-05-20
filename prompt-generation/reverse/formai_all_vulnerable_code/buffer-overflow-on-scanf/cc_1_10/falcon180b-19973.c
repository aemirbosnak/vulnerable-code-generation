//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

struct Node {
    char data[MAX_SIZE];
    int size;
    struct Node *next;
};

struct Node *head = NULL;

void push(char *str) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    strcpy(newnode->data, str);
    newnode->size = strlen(str);
    newnode->next = head;
    head = newnode;
}

void pop() {
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void printstack() {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

int isempty() {
    return head == NULL;
}

int isfull() {
    struct Node *temp = head;
    while (temp!= NULL) {
        if (temp->size == MAX_SIZE)
            return TRUE;
        temp = temp->next;
    }
    return FALSE;
}

int main() {
    int choice, size;
    char str[MAX_SIZE];

    do {
        printf("\n\n1. Push\n2. Pop\n3. Print Stack\n4. Check if Stack is Empty\n5. Check if Stack is Full\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string: ");
                scanf("%s", str);
                push(str);
                break;
            case 2:
                pop();
                break;
            case 3:
                printstack();
                break;
            case 4:
                if (isempty())
                    printf("Stack is Empty\n");
                else
                    printf("Stack is not Empty\n");
                break;
            case 5:
                if (isfull())
                    printf("Stack is Full\n");
                else
                    printf("Stack is not Full\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 6);

    return 0;
}