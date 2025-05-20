//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 0);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 0, 1);
    insert(&head, 1, 1);
    insert(&head, 2, 1);
    insert(&head, 3, 1);

    int x, y;
    printf("Enter the starting point (x, y): ");
    scanf("%d %d", &x, &y);

    int destination_x, destination_y;
    printf("Enter the destination point (x, y): ");
    scanf("%d %d", &destination_x, &destination_y);

    // Find the route
    Node* current = head;
    while (current) {
        if (current->x == destination_x && current->y == destination_y) {
            break;
        } else if (current->x == x && current->y == y) {
            x = current->next->x;
            y = current->next->y;
            current = current->next;
        } else {
            current = current->next;
        }
    }

    // Print the route
    if (current) {
        printf("The route is: (%d, %d) ", x, y);
        while (x != destination_x || y != destination_y) {
            printf("-> (%d, %d) ", x, y);
            x = current->next->x;
            y = current->next->y;
            current = current->next;
        }
        printf("-> (%d, %d)\n", destination_x, destination_y);
    } else {
        printf("No route found.\n");
    }

    return 0;
}