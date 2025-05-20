//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP_SAMPLES 1000

typedef struct {
    int temperature;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int temperature) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->temperature = temperature;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node *current_node = head;
    while (current_node->next!= NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

void display() {
    Node *current_node = head;
    int count = 0;

    printf("Temperature Samples:\n");
    while (current_node!= NULL && count < MAX_TEMP_SAMPLES) {
        printf("%d\n", current_node->temperature);
        count++;
        current_node = current_node->next;
    }
}

int main() {
    int choice, temperature;

    do {
        printf("1. Insert Temperature\n2. Display Temperature\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Temperature: ");
                scanf("%d", &temperature);
                insert(temperature);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}