//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed the random number generator
    
    float probability = 0.0; //initialize probability of alien invasion as 0%
    
    printf("Welcome to the Surrealist Alien Invasion Probability Calculator!\n");
    printf("Answer the following Surrealist questions to determine the probability of an alien invasion.\n");
    printf("Enter 'y' for yes and 'n' for no.\n\n");
    
    //Question 1
    char answer1;
    printf("1. Do you dream of purple unicorns riding on rainbows? ");
    scanf("%c", &answer1);
    getchar(); //clear input buffer
    if(answer1 == 'y') {
        probability += 5.0; //increase probability by 5%
    }
    
    //Question 2
    char answer2;
    printf("2. Do you sometimes see your reflection in a glass of milk and think it's a parallel universe? ");
    scanf("%c", &answer2);
    getchar(); //clear input buffer
    if(answer2 == 'y') {
        probability += 10.0; //increase probability by 10%
    }
    
    //Question 3
    char answer3;
    printf("3. Have you ever eaten a banana while standing on one foot? ");
    scanf("%c", &answer3);
    getchar(); //clear input buffer
    if(answer3 == 'y') {
        probability += 15.0; //increase probability by 15%
    }
    
    //Question 4
    char answer4;
    printf("4. When you listen to music, do you feel like you're in a different dimension? ");
    scanf("%c", &answer4);
    getchar(); //clear input buffer
    if(answer4 == 'y') {
        probability += 20.0; //increase probability by 20%
    }
    
    //Question 5
    char answer5;
    printf("5. Do you believe that cats are actually aliens in disguise? ");
    scanf("%c", &answer5);
    getchar(); //clear input buffer
    if(answer5 == 'y') {
        probability += 25.0; //increase probability by 25%
    }
    
    //generate random number between 1 to 100
    int random_num = rand() % 100 + 1;
    
    //print final probability result and the surreal message based on random number generated
    if(probability == 0.0) {
        printf("\nThe probability of an alien invasion is.. 0%. That's too normal for any aliens to come.");
    }
    else {
        printf("\nThe probability of an alien invasion is.. %.2f%%.\n", probability);
        printf("And according to Surrealist logic, if the random number between 1 to 100 is %d, then the alien invasion will happen in a surreal way!\n", random_num);
        switch(random_num) {
            case 1:
                printf("All humans will turn into pineapples and the aliens will harvest them as a delicacy.\n");
                break;
            case 2:
                printf("The aliens will arrive and only communicate through interpretive dance.\n");
                break;
            case 3:
                printf("The skies will turn pink and all water will flow upwards, inviting the aliens to come down.\n");
                break;
            case 4:
                printf("The aliens will bring peace and prosperity to the world by making everyone's nose bigger.\n");
                break;
            case 5:
                printf("The aliens will offer free teleportation to any destination in the world, but only if you learn the alien language first.\n");
                break;
            //add more surreal messages
            default:
                printf("The aliens will arrive in a way that's too surreal to describe. Brace yourselves!\n");
                break;
        }
    }
    
    return 0;
}