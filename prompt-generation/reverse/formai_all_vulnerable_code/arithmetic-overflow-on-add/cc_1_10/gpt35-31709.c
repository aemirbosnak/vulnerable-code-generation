//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

int visited[ROW][COL];
int maze[ROW][COL] ={
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                        {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     };

int x_start, y_start, x_end, y_end;

// defining the structure for queue
struct Node
{
    int x, y;
    struct Node* next;
};

struct Node *head = NULL, *tail = NULL;

// enqueue a new node to the queue
void enqueue(int x, int y)
{
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;

    if(tail == NULL){
        head = tail = new_node;
    }
    else{
        tail->next = new_node;
        tail = new_node;
    }
}

// dequeue a node from the queue
struct Node* dequeue()
{
    if(head == NULL){
        return NULL;
    }
    else{
        struct Node* dequeued_node = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }
        return dequeued_node;
    }
}

// to check if a cell is valid or not
int is_valid(int row, int col)
{
    if(row < 0 || col < 0 || row >= ROW || col >= COL){
        return 0;
    }
    else if(maze[row][col] == 1 || visited[row][col] == 1){
        return 0;
    }
    else{
        return 1;
    }
}

// breadth first search
void bfs()
{
    int row_move[4] = {-1, 0, 1, 0};
    int col_move[4] = {0, 1, 0, -1};

    struct Node* current;

    visited[x_start][y_start] = 1;
    enqueue(x_start, y_start);

    while(head != NULL)
    {
        current = dequeue();

        if(current->x == x_end && current->y == y_end){
            printf("Path found!\n");
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int x_new = current->x + row_move[i];
            int y_new = current->y + col_move[i];

            if(is_valid(x_new, y_new)){
                visited[x_new][y_new] = 1;
                enqueue(x_new, y_new);
            }
        }
    }

    printf("No path found.\n");
}

int main()
{
    printf("Enter the start position (x y): ");
    scanf("%d %d", &x_start, &y_start);

    printf("Enter the end position (x y): ");
    scanf("%d %d", &x_end, &y_end);

    bfs();

    return 0;
}