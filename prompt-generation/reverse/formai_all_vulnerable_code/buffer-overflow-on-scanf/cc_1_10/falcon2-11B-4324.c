//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveForward(int steps){
    int i;
    for(i = 0; i < steps; i++){
        printf("Move forward: ");
        sleep(1);
    }
}

void moveBackward(int steps){
    int i;
    for(i = 0; i < steps; i++){
        printf("Move backward: ");
        sleep(1);
    }
}

void moveLeft(int steps){
    int i;
    for(i = 0; i < steps; i++){
        printf("Move left: ");
        sleep(1);
    }
}

void moveRight(int steps){
    int i;
    for(i = 0; i < steps; i++){
        printf("Move right: ");
        sleep(1);
    }
}

int main(){
    int steps = 5;
    srand(time(0));
    
    while(steps > 0){
        printf("Choose your movement: \n");
        printf("1. Forward \n");
        printf("2. Backward \n");
        printf("3. Left \n");
        printf("4. Right \n");
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                moveForward(steps);
                steps--;
                break;
            case 2:
                moveBackward(steps);
                steps--;
                break;
            case 3:
                moveLeft(steps);
                steps--;
                break;
            case 4:
                moveRight(steps);
                steps--;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}