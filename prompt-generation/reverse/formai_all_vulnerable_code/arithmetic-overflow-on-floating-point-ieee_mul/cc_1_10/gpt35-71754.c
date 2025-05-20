//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct node{
    int row, col;
    double f, g, h;
    struct node* parent;
}node;

node* create_node(int row, int col, double f, double g, double h, node* parent){
    node* new_node = malloc(sizeof(node));
    new_node->row = row;
    new_node->col = col;
    new_node->f = f;
    new_node->g = g;
    new_node->h = h;
    new_node->parent = parent;
    return new_node;
}

void destroy_node(node* target){
    free(target);
}

double heuristic(node* current_node, node* goal_node){
    int row_diff = abs(current_node->row - goal_node->row);
    int col_diff = abs(current_node->col - goal_node->col);
    return sqrt(pow(row_diff, 2) + pow(col_diff, 2));
}

bool is_valid(int row, int col){
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

bool is_obstacle(int row, int col){
    return (row == 4 && col >= 1 && col <= 8) || (col == 4 && row >= 1 && row <= 6);
}

void get_neighbors(node* current_node, node** neighbors, int* num_neighbors){
    int row = current_node->row;
    int col = current_node->col;

    // right neighbor
    if(is_valid(row, col+1) && !is_obstacle(row, col+1)){
        neighbors[*num_neighbors] = create_node(row, col+1, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // left neighbor
    if(is_valid(row, col-1) && !is_obstacle(row, col-1)){
        neighbors[*num_neighbors] = create_node(row, col-1, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // top neighbor
    if(is_valid(row-1, col) && !is_obstacle(row-1, col)){
        neighbors[*num_neighbors] = create_node(row-1, col, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // bottom neighbor
    if(is_valid(row+1, col) && !is_obstacle(row+1, col)){
        neighbors[*num_neighbors] = create_node(row+1, col, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // top-left neighbor
    if(is_valid(row-1, col-1) && !is_obstacle(row-1, col-1)){
        neighbors[*num_neighbors] = create_node(row-1, col-1, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // top-right neighbor
    if(is_valid(row-1, col+1) && !is_obstacle(row-1, col+1)){
        neighbors[*num_neighbors] = create_node(row-1, col+1, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // bottom-left neighbor
    if(is_valid(row+1, col-1) && !is_obstacle(row+1, col-1)){
        neighbors[*num_neighbors] = create_node(row+1, col-1, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }

    // bottom-right neighbor
    if(is_valid(row+1, col+1) && !is_obstacle(row+1, col+1)){
        neighbors[*num_neighbors] = create_node(row+1, col+1, 0, 0, 0, current_node);
        (*num_neighbors)++;
    }
}

bool is_in_list(node* target, node** list, int num_nodes){
    for(int i=0; i<num_nodes; i++){
        if(target->row == list[i]->row && target->col == list[i]->col) return true;
    }
    return false;
}

node* get_node_in_list(node* target, node** list, int num_nodes){
    for(int i=0; i<num_nodes; i++){
        if(target->row == list[i]->row && target->col == list[i]->col) return list[i];
    }
    return NULL;
}

node* lowest_f_node(node** list, int num_nodes){
    double lowest_f = INFINITY;
    node* lowest_node = NULL;
    for(int i=0; i<num_nodes; i++){
        if(list[i]->f < lowest_f){
            lowest_f = list[i]->f;
            lowest_node = list[i];
        }
    }
    return lowest_node;
}

void a_star(node* start, node* goal){
    node* open_list[ROW*COL] = {NULL};
    int num_open = 0;
    node* closed_list[ROW*COL] = {NULL};
    int num_closed = 0;

    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;

    open_list[num_open++] = start;

    while(num_open > 0){
        node* current_node = lowest_f_node(open_list, num_open);
        if(current_node == goal){
            printf("Path found!\n");
            node* trace_path = current_node;
            while(trace_path != NULL){
                printf("(%d, %d) -> ", trace_path->row, trace_path->col);
                trace_path = trace_path->parent;
            }
            printf("\n");
            return;
        }

        for(int i=0; i<num_open; i++){
            if(open_list[i] == current_node){
                for(int j=i; j<num_open-1; j++){
                    open_list[j] = open_list[j+1];
                }
                num_open--;
                break;
            }
        }

        closed_list[num_closed++] = current_node;

        node* neighbors[8] = {NULL};
        int num_neighbors = 0;
        get_neighbors(current_node, neighbors, &num_neighbors);

        for(int i=0; i<num_neighbors; i++){
            node* neighbor = neighbors[i];
            if(is_in_list(neighbor, closed_list, num_closed)){
                destroy_node(neighbor);
                continue;
            }

            double tentative_g_score = current_node->g + heuristic(current_node, neighbor);
            bool tentative_better = false;

            node* existing_node = get_node_in_list(neighbor, open_list, num_open);
            if(existing_node == NULL){
                neighbor->h = heuristic(neighbor, goal);
                open_list[num_open++] = neighbor;
                tentative_better = true;
            }else if(tentative_g_score < existing_node->g){
                tentative_better = true;
            }

            if(tentative_better){
                neighbor->parent = current_node;
                neighbor->g = tentative_g_score;
                neighbor->f = neighbor->g + neighbor->h;
            }else{
                destroy_node(neighbor);
            }
        }
    }
    printf("Path not found!\n");
}

int main(){
    node* start = create_node(0, 0, 0, 0, 0, NULL);
    node* goal = create_node(9, 9, 0, 0, 0, NULL);

    a_star(start, goal);

    destroy_node(start);
    destroy_node(goal);

    return 0;
}