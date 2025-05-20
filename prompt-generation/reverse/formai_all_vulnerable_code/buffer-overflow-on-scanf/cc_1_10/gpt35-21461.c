//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define FLOOR_COUNT 10
#define ELEVATOR_CAPACITY 10

typedef struct node {
    int floor;
    struct node* next;
} node;

typedef struct elevator {
    int capacity;
    int current_floor;
    node* schedule;
    int direction; /* -1 for going down, 0 for idle, 1 for going up */
} elevator;

void print_status(elevator e) {
    printf("Current floor: %d\n", e.current_floor);
    printf("Direction: %s\n", (e.direction == -1) ? "down" : (e.direction == 0) ? "idle" : "up");
    printf("Passengers: %d\n", e.capacity);
    printf("Schedule:");
    if (e.schedule == NULL) {
        printf(" idle\n");
    } else {
        printf("\n");
        node* n = e.schedule;
        while (n != NULL) {
            printf("  - Floor %d\n", n->floor);
            n = n->next;
        }
    }
}

node* create_node(int floor) {
    node* n = (node*) malloc(sizeof(node));
    n->floor = floor;
    n->next = NULL;
    return n;
}

void add_node_to_schedule(node** schedule, int floor) {
    node* new_node = create_node(floor);
    
    if (*schedule == NULL) { /* schedule is empty */
        *schedule = new_node;
    } else {
        node* n = *schedule;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = new_node;
    }
}

void remove_node_from_schedule(node** schedule, int floor) {
    if (*schedule == NULL) {
        return;
    }
    
    if ((*schedule)->floor == floor) { /* first node in schedule should be removed */
        node* old_node = *schedule;
        *schedule = (*schedule)->next;
        free(old_node);
        return;
    }
    
    node* n = *schedule;
    while (n->next != NULL) {
        if (n->next->floor == floor) {
            node* old_node = n->next;
            n->next = old_node->next;
            free(old_node);
            return;
        }
        n = n->next;
    }
}

void move_elevator(elevator* e) {
    if (e->schedule == NULL) {
        return;
    }
    
    if (e->current_floor == e->schedule->floor) {
        remove_node_from_schedule(&(e->schedule), e->current_floor);
        e->capacity--;
        return;
    }
    
    if (e->direction == 1) {
        e->current_floor++;
    } else {
        e->current_floor--;
    }
}

void press_button(elevator* e, int floor) {
    if (floor == e->current_floor) {
        printf("Elevator is already on floor %d\n", floor);
        return;
    }
    
    add_node_to_schedule(&(e->schedule), floor);
    
    if (e->direction == 0) { /* if idle, set direction */
        e->direction = (floor < e->current_floor) ? -1 : 1;
    } else if ((floor < e->current_floor && e->direction == 1) ||
               (floor > e->current_floor && e->direction == -1)) {
        /* if opposite direction of current direction,  */
        /* reverse direction and go to last floor in schedule */
        node* n = e->schedule;
        while (n->next != NULL) {
            n = n->next;
        }
        e->direction *= -1;
        add_node_to_schedule(&(e->schedule), n->floor);
    }
}

int main() {
    elevator e = {ELEVATOR_CAPACITY, 0, NULL, 0};
    
    printf("Welcome to the elevator simulation!\n\n");
    
    while (1) {
        printf("Enter floor number (0-%d) to request elevator, -1 to quit: ", FLOOR_COUNT-1);
        int floor;
        scanf("%d", &floor);
        if (floor == -1) {
            break;
        }
        if (floor < 0 || floor >= FLOOR_COUNT) {
            printf("Invalid floor number\n");
            continue;
        }
        
        printf("Elevator called to floor %d\n", floor);
        press_button(&e, floor);
        while (e.schedule != NULL) {
            printf("\n");
            print_status(e);
            move_elevator(&e);
        }
        printf("\n");
        print_status(e);
        printf("\n");
    }
    
    printf("Thank you for using the elevator simulation!\n");
    
    return 0;
}