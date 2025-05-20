//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#define MAX_FLOOR 5 // Maximum floors in the castle

void draw_elevator(int floor, int current_floor); // Function to draw the elevator
int move_elevator(int floor, int current_floor); // Function to move the elevator
void play_sound(); // Function to play sound effect

int main() {
    int current_floor = 1; // Elevator starts at the first floor
    int floor; // User input for floor choice

    printf("Welcome to the Castle Elevator!\n");
    printf("You are currently at the first floor.\n");

    while(1) {
        printf("Which floor would you like to go? (Choose 1 to %d, or 0 to exit)\n", MAX_FLOOR);
        scanf("%d", &floor);

        if(floor == 0) {
            printf("Thank you for using Castle Elevator!\n");
            break;
        }

        if(floor == current_floor) {
            printf("You are already on floor %d!\n", current_floor);
            play_sound();
            continue;
        }

        if(floor > MAX_FLOOR || floor < 1) {
            printf("Invalid floor choice. Please choose again.\n");
            play_sound();
            continue;
        }

        current_floor = move_elevator(floor, current_floor);
        draw_elevator(floor, current_floor);
    }

    return 0;
}

void draw_elevator(int floor, int current_floor) {
    int i,j;
    printf("\n");

    for(i = MAX_FLOOR; i >= 1; i--) {
        if(i == current_floor) {
            if(i == floor) {
                printf("| %dTH FLOOR ELEVATOR ^ |\n", i);
            } else {
                printf("| %dTH FLOOR ELEVATOR | |\n", i);
            }
        } else {
            printf("|                     |\n");
        }
    }

    printf("+---------------------+\n");

    // Draw floors indicator
    printf("\nFLOORS: ");
    for(j = 1; j <= MAX_FLOOR; j++) {
        if (j == current_floor) {
            printf("| %d | ", j);
        } else {
            printf("%d ", j);
        }
    }
    printf("\n\n");
}

int move_elevator(int floor, int current_floor) {
    while(current_floor != floor) {
        if(current_floor < floor) {
            current_floor++;
            draw_elevator(floor, current_floor);
            play_sound();
        } else {
            current_floor--;
            draw_elevator(floor, current_floor);
            play_sound();
        }
    }

    printf("You have arrived at the %dTH FLOOR.\n", floor);
    return current_floor;
}

void play_sound() {
    printf("[DING DING DING] \n");
}