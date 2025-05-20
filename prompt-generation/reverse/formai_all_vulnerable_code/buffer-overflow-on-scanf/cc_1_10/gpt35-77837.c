//FormAI DATASET v1.0 Category: Robot movement control ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

int main(){
    int movement=0;
    char command[20];

    printf("Initializing Cyboz v1.0...\n");
    printf("Connection Established...\n");
    printf("Ready for Commands...\n");

    while(1){
        printf("Enter Command: ");
        scanf("%s", command);

        if (strcmp(command,"forward")==0){
            printf("Moving Forward\n");
            movement+=1;
        }
        else if (strcmp(command,"backward")==0){
            printf("Moving Backward\n");
            movement-=1;
        }
        else if (strcmp(command,"left")==0){
            printf("Turning Left\n");
            movement+=2;
        }
        else if (strcmp(command,"right")==0){
            printf("Turning Right\n");
            movement-=2;
        }
        else if (strcmp(command,"jump")==0){
            printf("Jumping...\n");
            movement+=5;
        }
        else if (strcmp(command,"fire")==0){
            printf("Firing Weapons...\n");
            movement-=5;
        }
        else if (strcmp(command,"self-destruct")==0){
            printf("Activating Self-Destruct in 5 seconds...\n");
            printf("5...\n");
            printf("4...\n");
            printf("3...\n");
            printf("2...\n");
            printf("1...\n");
            printf("BOOM!!!");
            exit(0);
        }
        else{
            printf("Invalid Command! Try Again...\n");
        }

        if(movement<0){
            printf("WARNING: SYSTEM OVERLOAD - CIRCUITS DAMAGED!\n");
            printf("CURRENT MOVEMENT - %d\n", movement);
        }
        else{
            printf("CURRENT MOVEMENT - %d\n", movement);
        }
    }

    return 0;
}