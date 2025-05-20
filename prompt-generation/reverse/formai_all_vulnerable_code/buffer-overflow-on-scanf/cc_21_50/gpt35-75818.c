//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>

int main(){
    int x = 0; //x-coordinate
    int y = 0; //y-coordinate
    char direction = 'N'; //current direction: N, S, E, W
    
    //loop for receiving user inputs
    while(1){
        //print current location and direction
        printf("Current location: (%d,%d)\n", x, y);
        printf("Current direction: %c\n", direction);
        
        //receive user input
        char input[10];
        printf("> ");
        scanf("%s", input);
        
        //decide on action based on user input
        if(input[0] == 'F'){ //move forward
            int distance = input[1] - '0'; //convert char to int
            switch(direction){
                case 'N':
                    y += distance;
                    break;
                case 'S':
                    y -= distance;
                    break;
                case 'E':
                    x += distance;
                    break;
                case 'W':
                    x -= distance;
                    break;
            }
        }
        else if(input[0] == 'L'){ //turn left
            int angle = input[1] - '0'; //convert char to int
            switch(direction){
                case 'N':
                    if(angle == 9) direction = 'W';
                    else direction = 'E';
                    break;
                case 'S':
                    if(angle == 9) direction = 'E';
                    else direction = 'W';
                    break;
                case 'E':
                    if(angle == 9) direction = 'N';
                    else direction = 'S';
                    break;
                case 'W':
                    if(angle == 9) direction = 'S';
                    else direction = 'N';
                    break;
            }
        }
        else if(input[0] == 'R'){ //turn right
            int angle = input[1] - '0'; //convert char to int
            switch(direction){
                case 'N':
                    if(angle == 9) direction = 'E';
                    else direction = 'W';
                    break;
                case 'S':
                    if(angle == 9) direction = 'W';
                    else direction = 'E';
                    break;
                case 'E':
                    if(angle == 9) direction = 'S';
                    else direction = 'N';
                    break;
                case 'W':
                    if(angle == 9) direction = 'N';
                    else direction = 'S';
                    break;
            }
        }
        else if(input[0] == 'X'){ //exit program
            printf("Program terminated.\n");
            break;
        }
        else{ //invalid input
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}