//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
 
#define ROW 10
#define COL 20
 
// Creating the structure for node and also linked list to store the path
struct node{
    int x, y;
    int f, g, h;
    struct node* parent;
    struct node* next;
};
 
// Creating the start and goal nodes
struct node* start = NULL, *goal = NULL;
 
// Creating the priority queue as linked list
struct p_queue{
    struct node* data;
    int priority;
    struct p_queue* next;
}*front=NULL, *rear=NULL;
 
int visited[ROW][COL], closed[ROW][COL];
int row = ROW, col = COL;
int obstacle[ROW][COL];
int sx, sy, dx, dy;
int dX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dY[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
// Function to create a node and set its initial values
struct node* create_node(int x, int y, int f, int g, int h){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->x = x;
    new_node->y = y;
    new_node->f = f;
    new_node->g = g;
    new_node->h = h;
    new_node->parent = NULL;
    new_node->next = NULL;
    return new_node;
}
 
// Enqueuing the priority queue
void enqueue(struct node* n, int priority){
    struct p_queue* newp = (struct p_queue*)malloc(sizeof(struct p_queue));
    newp->data = n;
    newp->priority = priority;
    newp->next = NULL;
    if(front==NULL){
        front = newp;
        rear = newp;
    }
    else{
        if(priority<front->priority){
            newp->next = front;
            front = newp;
        }
        else if(priority>rear->priority){
            rear->next = newp;
            rear = newp;
        }
        else{
            struct p_queue* ptr = front;
            while(ptr->next->priority<priority){
                ptr = ptr->next;
            }
            newp->next = ptr->next;
            ptr->next = newp;
        }
    }
}
 
// Dequeuing the priority queue
struct node* dequeue(){
    if(front==NULL){
        return NULL;
    }
    else if(front==rear){
        struct node* k = front->data;
        front = NULL;
        rear = NULL;
        return k;
    }
    else{
        struct node* k = front->data;
        front = front->next;
        return k;
    }
}
 
// Function to get the minimum f-value node from the p_queue
struct node* minimum(){
    return front->data;
}
 
// Heuristic function to get the manhattan distance to the goal
int heuristic(int x, int y){
    return abs(dx-x)+abs(dy-y);
}
 
// Function to check whether the given cell is valid or not
int is_valid(int x, int y){
    return (x>=0)&&(x<row)&&(y>=0)&&(y<col);
}
 
// Function to check whether the given cell is open or it's blocked
int is_unblocked(int x, int y){
    return !obstacle[x][y];
}
 
// Function to check whether the given cell is the goal or not
int is_goal(int x, int y){
    return ((x==dx)&&(y==dy));
}
 
// Function to trace the path from start to end using linked list
void trace(struct node* q){
    while(q!=NULL){
        printf("(%d,%d)<-", q->x, q->y);
        q = q->parent;
    }
}
 
// Function to implement the A* Search Algorithm
void A_star(){
    // Checking if the start node is same as goal node or not
    if(is_goal(sx, sy)){
        printf("Start is the same as Goal. Experiment Terminated.");
        return;
    }
    if(!is_unblocked(sx, sy)){
        printf("Start is blocked. Experiment Terminated.");
    }
    
    // Creating and initializing the starting node
    start = create_node(sx, sy, 0, 0, 0);
    start->f = start->g + start->h;
    enqueue(start, start->f);
    
    while(front!=NULL){
        // Dequeuing the priority queue for evaluating a cell
        struct node* current = dequeue();
        
        // Checking if the current node is the goal node or not
        if(is_goal(current->x, current->y)){
            printf("Path Found! Path is:\n");
            trace(current);
            return;
        }
        
        closed[current->x][current->y] = 1;
        int i;
        for(i=0; i<8; i++){
            int x = current->x + dX[i];
            int y = current->y + dY[i];
            if(is_valid(x, y)){
                if(is_goal(x, y)){
                    printf("Path Found! Path is:\n");
                    struct node* temp = create_node(x, y, 0, 0, 0);
                    temp->parent = current;
                    trace(temp);
                    return;
                }
                if(!is_unblocked(x, y)) continue;
                if(closed[x][y]==1) continue;
                int g = current->g + 1;
                int h = heuristic(x, y);
                int f = g+h;
                struct node* temp = create_node(x, y, f, g, h);
                temp->parent = current;
                enqueue(temp, f);
            }
        }
    }
    printf("No Path Found.\n");
}
 
int main(){
    memset(obstacle, 0, sizeof(obstacle));
    obstacle[1][0] = 1;
    obstacle[1][1] = 1;
    obstacle[1][2] = 1;
    obstacle[2][2] = 1;
    obstacle[3][2] = 1;
    obstacle[3][3] = 1;
    obstacle[3][4] = 1;
    obstacle[4][4] = 1;
    obstacle[5][4] = 1;
    obstacle[5][5] = 1;
    obstacle[5][6] = 1;
    obstacle[6][6] = 1;
    obstacle[7][6] = 1;
    obstacle[7][7] = 1;
    obstacle[7][8] = 1;
    obstacle[8][8] = 1;
    obstacle[9][8] = 1;
    obstacle[9][9] = 1;
    sx = 0;
    sy = 0;
    dx = 9;
    dy = 19;
    A_star();
    return 0;
}