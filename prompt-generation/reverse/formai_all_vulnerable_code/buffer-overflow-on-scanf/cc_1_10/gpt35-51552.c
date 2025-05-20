//FormAI DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x=0,y=0;
    char move;
    srand(time(NULL)); //initialize random seed

    printf("Welcome to Robot Movement Control!\n");
    printf("Enter 'w' to move forward, 'a' to move left, 's' to move backward, and 'd' to move right.\n");

    while(1){
        printf("\nCurrent position: (%d, %d)\n", x, y);
        printf("Enter move: ");
        scanf(" %c", &move);

        switch(move){
            case 'w':
                printf("Moving forward.\n");
                y+=1;
                break;
            case 'a':
                printf("Moving left.\n");
                x-=1;
                break;
            case 's':
                printf("Moving backward.\n");
                y-=1;
                break;
            case 'd':
                printf("Moving right.\n");
                x+=1;
                break;
            case 'q':
                printf("Quitting program.\n");
                return 0;
            default:
                printf("Invalid move.\n");
        }

        printf("New position: (%d, %d)\n", x, y);

        //Randomly generate an obstacle
        int obstacle = rand()%5;
        if(obstacle == 0){
            printf("Obstacle detected!\n");
            printf("Your robot crashed.\n");
            return 0;
        }
    }
}