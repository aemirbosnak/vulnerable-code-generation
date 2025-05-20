//FormAI DATASET v1.0 Category: Robot movement control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{
    int x,y,z;
} Position;

Position currentPosition;
bool isMoving = false;

void moveUp(){
    currentPosition.z += 1;
}

void moveDown(){
    currentPosition.z -= 1;
}

void moveRight(){
    currentPosition.x += 1;
}

void moveLeft(){
    currentPosition.x -= 1;
}

void moveForward(){
    currentPosition.y += 1;
}

void moveBackward(){
    currentPosition.y -= 1;
}

void stopMoving(){
    isMoving = false;
}

void printPosition(){
    printf("Current Position: (%d,%d,%d)\n",currentPosition.x,currentPosition.y,currentPosition.z);
}

void inputHandler(char input){
    input = tolower(input);
    if(input == 'w'){
        moveUp();
        isMoving = true;
    }
    else if(input == 'a'){
        moveLeft();
        isMoving = true;
    }
    else if(input == 's'){
        moveDown();
        isMoving = true;
    }
    else if(input == 'd'){
        moveRight();
        isMoving = true;
    }
    else if(input == 'f'){
        moveForward();
        isMoving = true;
    }
    else if(input == 'b'){
        moveBackward();
        isMoving = true;
    }
    else if(input == 'q'){
        stopMoving();
    }
    else if(input == 'p'){
        printPosition();
    }
    else{
        printf("Invalid input. Please enter w,a,s,d,f,b,q or p.\n");
    }
}

int main(){
    char input;
    currentPosition.x = 0;
    currentPosition.y = 0;
    currentPosition.z = 0;
    printf("Welcome to the C Robot Movement Control Program!\n");
    printf("Use w,a,s,d,f,b to move and p to print current position.\n");
    printf("Use q to stop moving.\n");
    while(true){
        printf("Enter a command: ");
        scanf(" %c",&input);
        inputHandler(input);
        if(isMoving){
            printf("Current Position: (%d,%d,%d)\n",currentPosition.x,currentPosition.y,currentPosition.z);
        }
    }
    return 0;
}