//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surprised
#include<stdio.h>
#include<stdlib.h> //for rand() and srand()
#include<time.h> //for time()
#include<string.h> //for strcmp()

//Function to shake things up!
void shakeItUp(char str[]){
    srand(time(NULL)); //seed for random number generator
    int len = strlen(str); //calculate length of string
    for(int i=0;i<len;i++){
        int j = rand() % len; //generate random index within string
        //swap characters at i and j indices
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

//Function to check if command is valid
int checkCommand(char command[]){
    const char *validCommands[] = {"takeoff","land","up","down","left","right",
                                    "forward","back","cw","ccw","flip","emergency"};
    int numCommands = 12;
    for(int i=0;i<numCommands;i++){
        if(strcmp(command,validCommands[i]) == 0){ //if command matches a valid command
            return 1; //return true
        }
    }
    return 0; //return false
}

int main(){
    char droneName[20];
    printf("Enter the name of your drone:\n");
    scanf("%s",droneName);
    printf("Welcome to the %s Drone remote control!\n",droneName);
    printf("Type 'help' to see the list of available commands.\n");
    while(1){ //infinite loop
        char command[20];
        printf("Enter command:\n");
        scanf("%s",command);
        shakeItUp(command); //let's shake things up!
        if(checkCommand(command)){ //check if command is valid
            //execute command
            //...
        }
        else if(strcmp(command,"help") == 0){ //if command is 'help'
            printf("Available commands:\n");
            printf("takeoff - take off the drone\n");
            printf("land - land the drone\n");
            printf("up <value> - move the drone up by the given value (in cm)\n");
            printf("down <value> - move the drone down by the given value (in cm)\n");
            printf("left <value> - move the drone left by the given value (in cm)\n");
            printf("right <value> - move the drone right by the given value (in cm)\n");
            printf("forward <value> - move the drone forward by the given value (in cm)\n");
            printf("back <value> - move the drone back by the given value (in cm)\n");
            printf("cw <value> - rotate the drone clockwise by the given value (in degrees)\n");
            printf("ccw <value> - rotate the drone counter-clockwise by the given value (in degrees)\n");
            printf("flip - perform a flip\n");
            printf("emergency - emergency stop\n");
        }
        else{ //if command is invalid
            printf("Invalid command. Type 'help' to see the list of available commands.\n");
        }
    }
    return 0;
}