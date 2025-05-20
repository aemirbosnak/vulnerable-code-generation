//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Greedy Knapsack Problem!\n");

    // Initialize the list of items and their values and weights
    Node *head = NULL;
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    insert_node(&head, 40);
    insert_node(&head, 50);

    // Get the weight capacity of the knapsack
    int capacity;
    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Create an array to store the items that will be included in the knapsack
    int knapsack[capacity];

    // Set the initial value of the total value and weight to 0
    int total_value = 0;
    int total_weight = 0;

    // Iterate over the list of items and fill the knapsack with the most valuable items that fit
    Node *current = head;
    while (current != NULL) {
        if (total_weight + current->data <= capacity) {
            knapsack[total_weight] = current->data;
            total_value += current->data;
            total_weight += current->data;
        }
        current = current->next;
    }

    // Print the items that were included in the knapsack
    printf("The items that were included in the knapsack are: ");
    for (int i = 0; i < total_weight; i++) {
        printf("%d ", knapsack[i]);
    }
    printf("\n");

    // Print the total value and weight of the items in the knapsack
    printf("The total value of the items in the knapsack is: %d\n", total_value);
    printf("The total weight of the items in the knapsack is: %d\n", total_weight);

    return 0;
}