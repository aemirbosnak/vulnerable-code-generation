//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: mind-bending
#include<stdio.h>

#define FORWARD 'f'
#define BACKWARD 'b'
#define LEFT 'l'
#define RIGHT 'r'

struct vehicle{
    int x;
    int y;
    char direction;
} car;

void moveforward(){
    if(car.direction == 'N'){
        car.y++;
    }
    else if(car.direction == 'S'){
        car.y--;
    }
    else if(car.direction == 'E'){
        car.x++;
    }
    else if(car.direction == 'W'){
        car.x--;
    }
}

void movebackward(){
    if(car.direction == 'N'){
        car.y--;
    }
    else if(car.direction == 'S'){
        car.y++;
    }
    else if(car.direction == 'E'){
        car.x--;
    }
    else if(car.direction == 'W'){
        car.x++;
    }
}

void turnleft(){
    if(car.direction == 'N'){
        car.direction = 'W';
    }
    else if(car.direction == 'S'){
        car.direction = 'E';
    }
    else if(car.direction == 'E'){
        car.direction = 'N';
    }
    else if(car.direction == 'W'){
        car.direction = 'S';
    }
}

void turnright(){
    if(car.direction == 'N'){
        car.direction = 'E';
    }
    else if(car.direction == 'S'){
        car.direction = 'W';
    }
    else if(car.direction == 'E'){
        car.direction = 'S';
    }
    else if(car.direction == 'W'){
        car.direction = 'N';
    }
}

int main(){
    car.x = 0;
    car.y = 0;
    car.direction = 'N';

    char command;
    printf("Enter command: ");
    scanf("%c", &command);

    while(command != 'q'){
        switch(command){
            case FORWARD: moveforward(); break;
            case BACKWARD: movebackward(); break;
            case LEFT: turnleft(); break;
            case RIGHT: turnright(); break;
            default: printf("Invalid command\n");
        }

        printf("Position: (%d, %d), Direction: %c\n", car.x, car.y, car.direction);

        printf("Enter command: ");
        scanf("%c", &command);
    }

    printf("Exiting program\n");

    return 0;
}