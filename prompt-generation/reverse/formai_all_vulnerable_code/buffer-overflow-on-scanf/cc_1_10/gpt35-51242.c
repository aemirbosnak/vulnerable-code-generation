//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>

//struct that holds robot coordinates
struct Robot{
    int x;
    int y;
} robot;

//function to move the robot
void moveRobot(int x, int y){
    robot.x += x;
    robot.y += y;
    printf("Robot moved to (%d, %d)\n", robot.x, robot.y);
}

int main(){
    int input;
    robot.x = 0;
    robot.y = 0;
    printf("Welcome to Robot Movement Control Program\n");
    printf("------------------------------------------\n");

    //loop that accepts user input and moves the robot accordingly
    do{
        printf("\nEnter direction (1 - Move Left, 2 - Move Right, 3 - Move Up, 4 - Move Down, 0 - Quit): ");
        scanf("%d", &input);

        switch(input){
            case 0:
                printf("Exiting program\n");
                break;
            case 1:
                moveRobot(-1, 0);
                break;
            case 2:
                moveRobot(1, 0);
                break;
            case 3:
                moveRobot(0, 1);
                break;
            case 4:
                moveRobot(0, -1);
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(input != 0);
    return 0;
}