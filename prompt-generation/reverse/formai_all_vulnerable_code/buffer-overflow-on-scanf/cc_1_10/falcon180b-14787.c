//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search(int data) {
    node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("%d found\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", data);
}

void delete(int data) {
    node *temp = head;
    node *prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void display() {
    node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int choice, data;
    do {
        printf("Enter your choice:\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted:\n");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the data to be searched:\n");
                scanf("%d", &data);
                search(data);
                break;
            case 3:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                delete(data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}