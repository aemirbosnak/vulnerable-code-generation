//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>

int main(){
    int loveCount = 0; //start with 0
    printf("Welcome to the Fitness Tracker!\n");
    printf("This is where you can track your health and fitness.\n");
    printf("Shall we begin?\n");

    //Starts taking input
    char input;
    do{
        printf("Enter your current activity status: [E]ating, [W]orking out, [R]esting, [S]leeping\n");
        scanf(" %c", &input);

        switch(input){
            case 'E':
            case 'e':
                printf("Bon appetite! ");
                break;
            case 'W':
            case 'w':
                printf("Get that body moving! ");
                break;
            case 'R':
            case 'r':
                printf("Rest well! ");
                break;
            case 'S':
            case 's':
                printf("Sweet dreams! ");
                break;
            default:
                printf("Invalid input! ");
        }

        //count love
        if(input == 'W' || input == 'w')
            loveCount++;
        
        //decide to continue or not
        printf("Do you want to enter another status? [y/n]\n");
        scanf(" %c", &input);
    }while(input == 'y' || input == 'Y');

    //output love story
    printf("Thanks for sharing your activities. Here is your love story:\n");
    printf("There once was a couple who loved each other very much...\n");
    for(int i=1; i<=loveCount; i++){
        printf("...they went on %d fitness journeys together...\n", i);
    }
    printf("...and they lived happily ever after.\n");

    return 0;
}