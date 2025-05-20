//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));  // Initializing random seed 

    printf("*** Welcome to the Alien Invasion Probability Calculator ***\n\n");

    int number_of_eyes;
    printf("Enter the number of eyes of the alien: ");
    scanf("%d", &number_of_eyes);

    if(number_of_eyes < 0){
        printf("Invalid input! Number of eyes cannot be negative\n");
        exit(0);
    }

    int number_of_arms;
    printf("Enter the number of arms of the alien: ");
    scanf("%d", &number_of_arms);

    if(number_of_arms < 0){
        printf("Invalid input! Number of arms cannot be negative\n");
        exit(0);
    }

    int number_of_legs;
    printf("Enter the number of legs of the alien: ");
    scanf("%d", &number_of_legs);

    if(number_of_legs < 0){
        printf("Invalid input! Number of legs cannot be negative\n");
        exit(0);
    }

    int number_of_aliens;
    printf("Enter the number of aliens you expect to invade: ");
    scanf("%d", &number_of_aliens);

    if(number_of_aliens < 1){
        printf("Invalid input! Number of aliens cannot be less than 1\n");
        exit(0);
    }
    printf("\nCalculating invasion probability...\n\n");

    int invasion_probability = (number_of_eyes + number_of_arms + number_of_legs) * number_of_aliens * rand()%100;

    printf("The probability of %d aliens with %d eyes, %d arms and %d legs invading our planet is %d%%\n", number_of_aliens, number_of_eyes, number_of_arms, number_of_legs, invasion_probability);

    if(invasion_probability >= 50){
        printf("Oh no! It seems like the aliens are coming to take over our planet. Start preparing for the invasion!\n");
    }
    else{
        printf("Phew! It seems like we are safe from the alien invasion. Let's go about our normal lives.\n");
    }

    return 0;
}