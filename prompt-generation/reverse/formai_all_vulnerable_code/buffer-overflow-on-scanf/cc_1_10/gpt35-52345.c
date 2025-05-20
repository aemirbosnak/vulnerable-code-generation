//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define remote control button codes */
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define UP 5
#define DOWN 6
#define LAND 7
#define TAKEOFF 8

/* Define drone status codes */
#define LANDED 0
#define FLYING 1

/* Drone status and position */
int status = LANDED;
int x_pos = 0;
int y_pos = 0;
int z_pos = 0;

/* Helper function for random number generation */
int random_number(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

/* Helper function for printing the drone's position */
void print_position(){
    printf("Current Position: (%d, %d, %d)\n", x_pos, y_pos, z_pos);
}

/* Remote control button function for moving the drone forward */
void move_forward(){
    printf("Moving drone forward...\n");
    y_pos += random_number(1,5);
    print_position();
}

/* Remote control button function for moving the drone backward */
void move_backward(){
    printf("Moving drone backward...\n");
    y_pos -= random_number(1,5);
    print_position();
}

/* Remote control button function for moving the drone left */
void move_left(){
    printf("Moving drone left...\n");
    x_pos -= random_number(1,5);
    print_position();
}

/* Remote control button function for moving the drone right */
void move_right(){
    printf("Moving drone right...\n");
    x_pos += random_number(1,5);
    print_position();
}

/* Remote control button function for moving the drone up */
void move_up(){
    printf("Moving drone up...\n");
    z_pos += random_number(1,5);
    print_position();
}

/* Remote control button function for moving the drone down */
void move_down(){
    printf("Moving drone down...\n");
    z_pos -= random_number(1,5);
    print_position();
}

/* Remote control button function for landing the drone */
void land(){
    printf("Landing drone...\n");
    status = LANDED;
    print_position();
}

/* Remote control button function for taking off the drone */
void takeoff(){
    printf("Taking off drone...\n");
    status = FLYING;
    print_position();
}

int main(){
    int button_code;

    srand(time(0));

    printf("Welcome to the C Drone Remote Control!\n");

    while(1){

        printf("\nEnter button code: ");
        scanf("%d", &button_code);

        switch(button_code){

            case FORWARD:
                if(status == FLYING)
                    move_forward();
                else
                    printf("Drone is not flying!\n");
                break;

            case BACKWARD:
                if(status == FLYING)
                    move_backward();
                else
                    printf("Drone is not flying!\n");
                break;

            case LEFT:
                if(status == FLYING)
                    move_left();
                else
                    printf("Drone is not flying!\n");
                break;

            case RIGHT:
                if(status == FLYING)
                    move_right();
                else
                    printf("Drone is not flying!\n");
                break;

            case UP:
                if(status == FLYING)
                    move_up();
                else
                    printf("Drone is not flying!\n");
                break;

            case DOWN:
                if(status == FLYING)
                    move_down();
                else
                    printf("Drone is not flying!\n");
                break;

            case LAND:
                if(status == FLYING)
                    land();
                else
                    printf("Drone is not flying!\n");
                break;

            case TAKEOFF:
                if(status == LANDED)
                    takeoff();
                else
                    printf("Drone is already flying!\n");
                break;

            default:
                printf("Invalid button code!\n");
        }
    }

    return 0;
}