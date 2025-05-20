//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    int x, y;
    int maze[MAX_SIZE][MAX_SIZE] = {{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    printf("Enter the starting position (x, y): ");
    scanf("%d %d", &x, &y);

    // Create a linked list to store the route
    head = malloc(sizeof(Node));
    head->x = x;
    head->y = y;
    head->next = NULL;

    // Traverse the maze to find the exit
    while (head) {
        x = head->x;
        y = head->y;

        // Check if the cell is the exit
        if (maze[x][y] == 2) {
            printf("Exit found at (x, y): (%d, %d)\n", x, y);
            break;
        }

        // Move to the next cell
        switch (maze[x][y]) {
            case 0:
                head->next = malloc(sizeof(Node));
                head->next->x = x - 1;
                head->next->y = y;
                head->next->next = NULL;
                head = head->next;
                break;
            case 1:
                head->next = malloc(sizeof(Node));
                head->next->x = x + 1;
                head->next->y = y;
                head->next->next = NULL;
                head = head->next;
                break;
            case 3:
                head->next = malloc(sizeof(Node));
                head->next->x = x;
                head->next->y = y - 1;
                head->next->next = NULL;
                head = head->next;
                break;
        }
    }

    // If the exit is not found, print an error message
    if (head == NULL) {
        printf("No exit found.\n");
    }

    return 0;
}