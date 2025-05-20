//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SPEED 10
#define MAX_TURN_ANGLE 30

typedef struct{
    int x;
    int y;
}Position;

typedef struct{
    int speed;
    int turn_angle;
}Control;

void move(Position* current_pos, Control* control_input){
    int turn = rand()%2;

    if(turn){
        current_pos->x += control_input->speed;
        current_pos->y += control_input->speed * tan(control_input->turn_angle);
    }
    else{
        current_pos->x += control_input->speed * cos(control_input->turn_angle);
        current_pos->y += control_input->speed * sin(control_input->turn_angle);
    }
}

int main(){
    srand(time(0));
    Position vehicle_pos = {0, 0};
    Control operator_control = {0, 0};
    char command;

    printf("Welcome to Remote Control Vehicle Simulator!\n");
    printf("Commands: \n");
    printf("w - Increase Speed\t\t s - Decrease Speed\n");
    printf("a - Turn Left\t\t\t d - Turn Right\n");
    printf("e - Exit Simulator\n\n");

    while(command != 'e'){
        printf("Current Position: (%d,%d)\t", vehicle_pos.x, vehicle_pos.y);
        printf("Current Speed: %d\tCurrent Turn Angle: %d\n", operator_control.speed, operator_control.turn_angle);

        printf("Enter a command: ");
        scanf(" %c", &command);

        switch(command){
            case 'w':
                if(operator_control.speed < MAX_SPEED)
                    operator_control.speed++;
                break;
            case 's':
                if(operator_control.speed > 0)
                    operator_control.speed--;
                break;
            case 'a':
                operator_control.turn_angle += MAX_TURN_ANGLE;
                break;
            case 'd':
                operator_control.turn_angle -= MAX_TURN_ANGLE;
                break;
            case 'e':
                printf("Thank you for using the Remote Control Vehicle Simulator! Goodbye.\n");
                break;
            default:
                printf("Invalid command, please try again.\n");
                break;
        }

        move(&vehicle_pos, &operator_control);
    }

    return 0;
}