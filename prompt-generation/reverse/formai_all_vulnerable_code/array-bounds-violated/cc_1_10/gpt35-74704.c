//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 5
#define COL 5

struct Node{
    int row;
    int col;
};

int start_row, start_col, end_row, end_col;
int maze[ROW][COL] = {
    {0, 1, 1, 0, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 1, 0}
};
int visited[ROW][COL] = {0};

struct Node queue[ROW*COL];
int front = -1;
int rear = -1;

bool is_valid(int row, int col) {
    return (row >= 0 && row < ROW && col >=0 && col < COL && maze[row][col] == 0 && visited[row][col] == 0);
}

void enqueue(int row, int col) {
    rear++;
    queue[rear].row = row;
    queue[rear].col = col;
}

struct Node dequeue() {
    front++;
    struct Node curr = queue[front];
    return curr;
}

bool is_queue_empty() {
    if (front > rear) {
        return true;
    }
    return false;
}

void breadth_first_search() {
    struct Node start = {start_row, start_col};
    visited[start_row][start_col] = 1;
    enqueue(start_row, start_col);

    while(!is_queue_empty()) {
        struct Node curr = dequeue();
        int row = curr.row;
        int col = curr.col;

        if(row == end_row && col == end_col) {
            printf("\nPath found!");
            return;
        }

        //Move Down
        if(is_valid(row+1, col)) {
            visited[row+1][col] = 1;
            enqueue(row+1, col);
        }
        //Move Up
        if(is_valid(row-1, col)) {
            visited[row-1][col] = 1;
            enqueue(row-1, col);
        }
        //Move Left
        if(is_valid(row, col-1)) {
            visited[row][col-1] = 1;
            enqueue(row, col-1);
        }
        //Move Right
        if(is_valid(row, col+1)) {
            visited[row][col+1] = 1;
            enqueue(row, col+1);
        }
    }
    printf("\nPath not found!");
}

int main() {
    printf("Enter starting row: ");
    scanf("%d", &start_row);
    printf("Enter starting column: ");
    scanf("%d", &start_col);
    printf("Enter ending row: ");
    scanf("%d", &end_row);
    printf("Enter ending column: ");
    scanf("%d", &end_col);

    breadth_first_search();

    return 0;
}