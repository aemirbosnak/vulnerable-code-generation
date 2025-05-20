//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    //Declaring Variables for X,Y and Z coordinates of Drone
    float x_c,y_c,z_c;
    
    //Setting the initial coordinates to (0,0,0)
    x_c=0;
    y_c=0;
    z_c=0;

    //Declaring Variables for Movement Inputs
    char move_input;
    float move_val;

    //Displaying the Initial Coordinates of the Drone
    printf("\nCurrent Coordinates: ");
    printf("\nX: %.2f \t Y: %.2f \t Z: %.2f \n",x_c,y_c,z_c);

    //Loop to accept User Input for Drone Movement
    while(1){

        printf("\nEnter the Movement You Want to Do (F/B/L/R/U/D): ");
        scanf(" %c",&move_input);

        //Checking User Input for Movement Values
        if(move_input=='F' || move_input=='f'){
            printf("\nEnter the Distance Value for Forward Movement (in meters): ");
            scanf("%f",&move_val);
            z_c=z_c+move_val;
        }
        else if(move_input=='B' || move_input=='b'){
            printf("\nEnter the Distance Value for Backward Movement (in meters): ");
            scanf("%f",&move_val);
            z_c=z_c-move_val;
        }
        else if(move_input=='L' || move_input=='l'){
            printf("\nEnter the Distance Value for Left Movement (in meters): ");
            scanf("%f",&move_val);
            x_c=x_c-move_val;
        }
        else if(move_input=='R' || move_input=='r'){
            printf("\nEnter the Distance Value for Right Movement (in meters): ");
            scanf("%f",&move_val);
            x_c=x_c+move_val;
        }
        else if(move_input=='U' || move_input=='u'){
            printf("\nEnter the Distance Value for Upward Movement (in meters): ");
            scanf("%f",&move_val);
            y_c=y_c+move_val;
        }
        else if(move_input=='D' || move_input=='d'){
            printf("\nEnter the Distance Value for Downward Movement (in meters): ");
            scanf("%f",&move_val);
            y_c=y_c-move_val;
        }
        else{
            printf("\nInvalid Movement Input. Please try again.");
            continue;
        }

        //Displaying the Updated Coordinates of the Drone After Movement
        printf("\nUpdated Coordinates: ");
        printf("\nX: %.2f \t Y: %.2f \t Z: %.2f \n",x_c,y_c,z_c);
    }

    return 0;
}