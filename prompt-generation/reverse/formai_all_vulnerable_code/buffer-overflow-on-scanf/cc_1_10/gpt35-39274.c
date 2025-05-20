//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to check if the entered password is correct or not
int check_pass(char pass[10]){
    return (strcmp(pass, "password")==0);
}

// function to check if the entered drone ID is correct or not
int check_id(char id[10]){
    return (strcmp(id, "DR001")==0 || strcmp(id, "DR002")==0);
}

// function to display menu and get user's choice
int menu(){
    int choice;
    printf("\n==============================\n");
    printf("1. Arm Drone\n");
    printf("2. Disarm Drone\n");
    printf("3. Set Altitude\n");
    printf("4. Set Heading\n");
    printf("5. Takeoff\n");
    printf("6. Land\n");
    printf("7. Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to arm the drone
void arm_drone(){
    printf("Drone armed successfully.\n");
}

// function to disarm the drone
void disarm_drone(){
    printf("Drone disarmed successfully.\n");
}

// function to set the altitude of the drone
void set_altitude(){
    int altitude;
    printf("Enter altitude in meters: ");
    scanf("%d", &altitude);
    printf("Altitude set to %dm.\n", altitude);
}

// function to set the heading of the drone
void set_heading(){
    int heading;
    printf("Enter heading in degrees: ");
    scanf("%d", &heading);
    printf("Heading set to %d°.\n", heading);
}

// function to takeoff the drone
void takeoff(){
    printf("Drone takeoff successful.\n");
}

// function to land the drone
void land(){
    printf("Drone landed successfully.\n");
}

int main(){
    char id[10], pass[10];
    int choice, authenticated=0;
    printf("Enter Drone ID: ");
    scanf("%s", id);
    printf("Enter Password: ");
    scanf("%s", pass);
    // check if the entered ID and password are correct
    if(check_id(id) && check_pass(pass)){
        authenticated = 1;
        printf("Authentication successful! Welcome, pilot.\n");
    }
    else{
        printf("Authentication failed! Please try again.\n");
        exit(0);
    }
    // main program loop
    while(1){
        choice = menu();
        switch(choice){
            case 1: // arm drone
                if(authenticated)
                    arm_drone();
                else
                    printf("Authentication failed!\n");
                break;
            case 2: // disarm drone
                if(authenticated)
                    disarm_drone();
                else
                    printf("Authentication failed!\n");
                break;
            case 3: // set altitude
                if(authenticated)
                    set_altitude();
                else
                    printf("Authentication failed!\n");
                break;
            case 4: // set heading
                if(authenticated)
                    set_heading();
                else
                    printf("Authentication failed!\n");
                break;
            case 5: // takeoff
                if(authenticated)
                    takeoff();
                else
                    printf("Authentication failed!\n");
                break;
            case 6: // land
                if(authenticated)
                    land();
                else
                    printf("Authentication failed!\n");
                break;
            case 7: // exit
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}