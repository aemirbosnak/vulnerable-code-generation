//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// A maze is a 2D array of characters representing walls ('#') and paths ('.')
char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '.', '.', '.', '.', '.', '.', '.', '.', '+'},
    {'+', '.', '#', '#', '#', '#', '#', '#', '.', '+'},
    {'+', '.', '.', '.', '.', '.', '.', '.', '.', '+'},
    {'+', '.', '#', '#', '#', '#', '#', '#', '.', '+'},
    {'+', '.', '.', '.', '.', '.', '.', '.', '.', '+'},
    {'+', '#', '#', '#', '#', '#', '#', '#', '#', '+'},
    {'+', '.', '.', '.', '.', '.', '.', '.', '.', '+'},
    {'+', '.', '#', '#', '#', '#', '#', '#', '.', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'},
};

// A stack is a data structure for storing positions in the maze
typedef struct Stack {
    int x;
    int y;
    struct Stack *next;
} Stack;

// Create a new stack node
Stack *new_node(int x, int y) {
    Stack *node = malloc(sizeof(Stack));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

// Push a position onto the stack
void push(Stack **head, int x, int y) {
    Stack *new = new_node(x, y);
    new->next = *head;
    *head = new;
}

// Pop a position from the stack
int pop(Stack **head) {
    if (*head == NULL) {
        return -1;
    }
    int x = (*head)->x;
    int y = (*head)->y;
    *head = (*head)->next;
    return x;
}

// Check if a position is valid (not a wall)
int is_valid(int x, int y) {
    if (x < 0 || x >= MAZE_WIDTH || y < 0 || y >= MAZE_HEIGHT) {
        return 0;
    }
    return maze[y][x] == '.';
}

// Check if a position is the exit
int is_exit(int x, int y) {
    return x == MAZE_WIDTH - 1 && y == MAZE_HEIGHT - 1;
}

// Find the path through the maze using a DFS algorithm
void find_path() {
    // Create a stack to store the positions we've visited
    Stack *stack = NULL;

    // Start at the entrance of the maze
    int x = 1;
    int y = 1;

    // While we haven't reached the exit
    while (!is_exit(x, y)) {
        // Push the current position onto the stack
        push(&stack, x, y);

        // Mark the current position as visited
        maze[y][x] = 'v';

        // Check if there are any valid paths to explore
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (is_valid(new_x, new_y)) {
                x = new_x;
                y = new_y;
                break;
            }
        }

        // If there are no valid paths to explore, backtrack
        if (!is_valid(x, y)) {
            x = pop(&stack);
            y = pop(&stack);
        }
    }

    // Print the path through the maze
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Set the random seed for generating the maze
    srand(time(NULL));

    // Generate the maze
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (i == 0 || i == MAZE_HEIGHT - 1 || j == 0 || j == MAZE_WIDTH - 1) {
                maze[i][j] = '+';
            } else {
                maze[i][j] = (rand() % 2) == 0 ? '#' : '.';
            }
        }
    }

    // Find the path through the maze
    find_path();

    return 0;
}