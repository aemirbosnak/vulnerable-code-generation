//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef struct {
    int x;
    int y;
} Robot;

void initialize_robot(Robot *r, int start_x, int start_y) {
    r->x = start_x;
    r->y = start_y;
}

void move_up(Robot *r) {
    r->y += 1;
}

void move_down(Robot *r) {
    r->y -= 1;
}

void move_left(Robot *r) {
    r->x -= 1;
}

void move_right(Robot *r) {
    r->x += 1;
}

void print_position(Robot *r) {
    printf("Robot is at position (%d, %d)\n", r->x, r->y);
}

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nExiting robot control...\n");
        exit(0);
    }
}

int main() {
    Robot robot;
    int command;

    // Signal handling for graceful exit
    signal(SIGINT, signal_handler);

    initialize_robot(&robot, 0, 0);
    
    printf("Welcome to the Robot Movement Control System!\n");
    printf("Commands:\n");
    printf("1 - Move Up\n2 - Move Down\n3 - Move Left\n4 - Move Right\n5 - Show Position\n0 - Exit\n");

    while (1) {
        printf("Enter command: ");
        scanf("%d", &command);
        
        switch (command) {
            case 1:
                move_up(&robot);
                break;
            case 2:
                move_down(&robot);
                break;
            case 3:
                move_left(&robot);
                break;
            case 4:
                move_right(&robot);
                break;
            case 5:
                print_position(&robot);
                break;
            case 0:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
        
        // Simulate a delay for visual effect
        usleep(500000); 
    }
    
    return 0;
}