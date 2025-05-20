//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char value;
    struct node *next;
};

struct node *head;

void push(char value);
char pop();
int is_empty();
int is_full();
void display();

int main() {
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    head->value = '\0';
    head->next = NULL;
    char choice;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (is_full()) {
                    printf("Stack Overflow\n");
                } else {
                    char value;
                    printf("Enter the value to be pushed: ");
                    scanf("%c", &value);
                    push(value);
                }
                break;
            case '2':
                if (is_empty()) {
                    printf("Stack Underflow\n");
                } else {
                    char value = pop();
                    printf("Popped value: %c\n", value);
                }
                break;
            case '3':
                display();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(char value) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->value = value;
    temp->next = head->next;
    head->next = temp;
}

char pop() {
    char value;
    if (is_empty()) {
        printf("Stack Underflow\n");
        value = '\0';
    } else {
        struct node *temp = head->next;
        value = temp->value;
        head->next = temp->next;
        free(temp);
    }
    return value;
}

int is_empty() {
    return head->next == NULL;
}

int is_full() {
    struct node *temp = head;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

void display() {
    struct node *temp = head->next;
    while (temp!= NULL) {
        printf("%c ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}