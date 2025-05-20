//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>

int main(){
    char input;
    int connected = 0;
    
    while(1){
        printf("Please choose an action:\n");
        printf("  c - connect to drone\n");
        printf("  d - disconnect from drone\n");
        printf("  f - fly drone\n");
        printf("  l - land drone\n");
        printf("  e - exit program\n");

        scanf(" %c", &input);
        printf("\n");

        if(input == 'c'){
            if(connected){
                printf("Already connected to drone.\n");
            } else {
                printf("Connecting to drone...\n");
                connected = 1;
            }
        } else if(input == 'd'){
            if(!connected){
                printf("Not connected to drone.\n");
            } else {
                printf("Disconnecting from drone...\n");
                connected = 0;
            }
        } else if(input == 'f'){
            if(!connected){
                printf("Cannot fly drone if not connected.\n");
            } else {
                printf("Drone is flying!\n");
            }
        } else if(input == 'l'){
            if(!connected){
                printf("Cannot land drone if not connected.\n");
            } else {
                printf("Drone is landing.\n");
            }
        } else if(input == 'e'){
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid input.\n");
        }
        printf("\n");
    }
    
    return 0;
}