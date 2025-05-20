//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: active
#include <stdio.h>
#include <stdbool.h>

int main(){
    bool landed = true;
    int altitude = 0;
    int speed = 0;

    //Initial Status
    printf("Drone Status\n");
    printf("------------------------------------\n");
    printf("Landed? : %s\n", landed ? "Yes" : "No");
    printf("Altitude : %d meters\n", altitude);
    printf("Speed : %d km/h\n", speed);
    printf("------------------------------------\n");

    //Remote Control Loop
    while(1){
        int command;
        printf("\nPlease enter a command:\n");
        printf("0 - Quit\n");
        printf("1 - Take Off\n");
        printf("2 - Increase Altitude\n");
        printf("3 - Decrease Altitude\n");
        printf("4 - Increase Speed\n");
        printf("5 - Decrease Speed\n");

        scanf("%d", &command);

        //Quit the Loop
        if(command == 0){
            printf("Good Bye!\n");
            break;
        }

        //Take Off
        if(command == 1 && landed){
            landed = false;
            altitude = 35;  //Flying at 35 meters
            speed = 10;     //Initial speed
            printf("Drone took off!\n");
        }

        //Increase Altitude
        if(command == 2 && !landed){
            altitude += 5;
            printf("Drone increased altitude to %d meters.\n", altitude);
        }

        //Decrease Altitude
        if(command == 3 && !landed){
            if(altitude >= 5){
                altitude -= 5;
                printf("Drone decreased altitude to %d meters.\n", altitude);
            }
            else{
                printf("Cannot decrease altitude.\n");
            }
        }

        //Increase Speed
        if(command == 4 && !landed){
            speed += 5;
            printf("Drone increased speed to %d km/h.\n", speed);
        }

        //Decrease Speed
        if(command == 5 && !landed){
            if(speed >= 5){
                speed -= 5;
                printf("Drone decreased speed to %d km/h.\n", speed);
            }
            else{
                printf("Cannot decrease speed.\n");
            }
        }

        //Invalid Command
        if(command < 0 || command > 5){
            printf("Invalid Command.\n");
        }

        //Print Updated Status
        printf("------------------------------------\n");
        printf("Landed? : %s\n", landed ? "Yes" : "No");
        printf("Altitude : %d meters\n", altitude);
        printf("Speed : %d km/h\n", speed);
        printf("------------------------------------\n");
    }

    return 0;
}