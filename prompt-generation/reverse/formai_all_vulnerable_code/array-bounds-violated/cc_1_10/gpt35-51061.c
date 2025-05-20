//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 50

typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node* parent;
}node_t;

node_t* start_node;
node_t* end_node;
node_t* open_list[MAXSIZE];
node_t* closed_list[MAXSIZE];
int open_list_size = 0;
int closed_list_size = 0;

int heuristic(node_t* current_node) {
    return abs(current_node->x - end_node->x) + abs(current_node->y - end_node->y);
}

void add_node_to_open_list(node_t* current_node) {
    open_list[open_list_size] = current_node;
    open_list_size++;
}

void remove_node_from_open_list(int index) {
    for(int i=index; i<open_list_size-1; i++) {
        open_list[i] = open_list[i+1];
    }
    open_list_size--;
}

int node_already_in_closed_list(node_t* current_node) {
    for(int i=0; i<closed_list_size; i++) {
        if(closed_list[i]->x == current_node->x && closed_list[i]->y == current_node->y) {
            return i;
        }
    }
    return -1;
}

void add_node_to_closed_list(node_t* current_node) {
    closed_list[closed_list_size] = current_node;
    closed_list_size++;
}

node_t* get_node_with_lowest_f() {
    int lowest_f = open_list[0]->f;
    int lowest_f_index = 0;
    for(int i=1; i<open_list_size; i++) {
        if(open_list[i]->f < lowest_f) {
            lowest_f = open_list[i]->f;
            lowest_f_index = i;
        }
    }
    return open_list[lowest_f_index];
}

void print_path(node_t* current_node) {
    if(current_node->parent != NULL) {
        print_path(current_node->parent);
    }
    printf("(%d,%d) ", current_node->x, current_node->y);
}

void generate_path() {
    int path_found = 0;
    int iterations = 0;
    add_node_to_open_list(start_node);
    while(open_list_size > 0) {
        iterations++;
        node_t* current_node = get_node_with_lowest_f();
        remove_node_from_open_list(current_node);
        add_node_to_closed_list(current_node);
        if(current_node->x == end_node->x && current_node->y == end_node->y) {
            path_found = 1;
            break;
        }
        int x = current_node->x;
        int y = current_node->y;
        node_t* children[8];
        children[0] = &(node_t){x+1,y+1,0,0,0,current_node};
        children[1] = &(node_t){x+1,y,0,0,0,current_node};
        children[2] = &(node_t){x+1,y-1,0,0,0,current_node};
        children[3] = &(node_t){x,y-1,0,0,0,current_node};
        children[4] = &(node_t){x-1,y-1,0,0,0,current_node};
        children[5] = &(node_t){x-1,y,0,0,0,current_node};
        children[6] = &(node_t){x-1,y+1,0,0,0,current_node};
        children[7] = &(node_t){x,y+1,0,0,0,current_node};
        for(int i=0; i<8; i++) {
            node_t* current_child = children[i];
            if(current_child->x < 1 || current_child->x > MAXSIZE || current_child->y < 1 || current_child->y > MAXSIZE) {
                continue;
            }
            int child_already_in_closed_list = node_already_in_closed_list(current_child);
            if(child_already_in_closed_list != -1) {
                continue;
            }
            int tentative_g = current_node->g + 1;
            int child_already_in_open_list = 0;
            for(int j=0; j<open_list_size; j++) {
                if(open_list[j]->x == current_child->x && open_list[j]->y == current_child->y) {
                    child_already_in_open_list = 1;
                    break;
                }
            }
            if(!child_already_in_open_list || tentative_g < current_child->g) {
                current_child->g = tentative_g;
                current_child->h = heuristic(current_child);
                current_child->f = current_child->g + current_child->h;
                if(!child_already_in_open_list) {
                    add_node_to_open_list(current_child);
                }
            }
        }
    }
    if(path_found) {
        printf("Path:");
        print_path(end_node);
    }
    else {
        printf("Path not found!");
    }
    printf("\nIterations: %d", iterations);
}

int main() {
    start_node = &(node_t){2,2,0,0,0,NULL};
    end_node = &(node_t){10,10,0,0,0,NULL};
    generate_path();
    return 0;
}