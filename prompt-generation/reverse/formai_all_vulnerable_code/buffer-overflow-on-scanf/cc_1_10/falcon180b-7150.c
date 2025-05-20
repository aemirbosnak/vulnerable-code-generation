//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

struct Node {
    char data;
    struct Node *next;
};

struct Node *head = NULL;

void push(char data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void peek() {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%c\n", head->data);
}

int isEmpty() {
    return head == NULL;
}

int isFull() {
    return head == NULL;
}

void reverseString(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}