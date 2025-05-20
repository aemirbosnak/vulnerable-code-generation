//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Structure to store a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node in a linked list
void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to print a linked list
void print_list(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to visualize the linked list
void visualize_list(struct Node* head) {
    // Initialize the canvas
    int canvas[MAX_SIZE][MAX_SIZE] = {0};

    // Get the dimensions of the canvas
    int height = MAX_SIZE;
    int width = MAX_SIZE;

    // Initialize the coordinates of the head node
    int x = width / 2;
    int y = height / 2;

    // Initialize the direction of the head node
    int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up

    // Loop through the linked list
    while (head != NULL) {
        // Set the current node's value to 1
        canvas[y][x] = 1;

        // Update the direction of the next node
        direction = (direction + 1) % 4;

        // Update the coordinates of the next node
        switch (direction) {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
        }

        // Set the current node to the next node
        head = head->next;
    }

    // Print the canvas
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a linked list
    struct Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    // Visualize the linked list
    visualize_list(head);

    // Free the memory allocated for the linked list
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}