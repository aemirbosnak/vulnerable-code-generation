//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //intialize values
    int food = 10;
    int bullets = 6;
    int decision = 0;

    //seed the random number generator
    srand(time(0));

    printf("Welcome to the post-apocalyptic world!\n");
    printf("You are scrounging for supplies.\n");
    
    //simulate random error
    int error = rand() % 2;
    if(error == 1){
        printf("ERROR: Unable to locate supplies. Program will terminate.\n");
        exit(1);
    }

    printf("You stumble upon an abandoned convenience store.\n");
    printf("You have %d units of food and %d bullets for protection.\n", food, bullets);

    printf("Do you want to scavenge for supplies? (1 for yes or 0 for no): ");
    scanf("%d", &decision);

    //simulate runtime error
    if(decision < 0 || decision > 1){
        printf("ERROR: Invalid input. Program will terminate.\n");
        exit(1);
    }

    if(decision == 1){
        //simulate another random error
        int error2 = rand() % 3;
        if(error2 == 0){
            printf("ERROR: Radiation levels too high. Program will terminate.\n");
            exit(1);
        }
        printf("You scavenge through the aisles and collect some supplies.\n");
        food += 3;
        bullets += 2;
        printf("You now have %d units of food and %d bullets left.\n", food, bullets);
    }
    else{
        printf("You decide it's too dangerous and move on.\n");
    }

    printf("Thanks for playing!\n");

    return 0;
}