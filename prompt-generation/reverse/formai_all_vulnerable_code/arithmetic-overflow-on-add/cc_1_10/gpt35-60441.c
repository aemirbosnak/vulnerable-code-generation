//FormAI DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and sides
int roll_dice(int sides){
    return rand() % sides + 1;
}

int main(){

    srand(time(NULL)); // seed the random number generator with the current time

    int num_dice, sides, num_rolls;

    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    printf("How many sides do your dice have? ");
    scanf("%d", &sides);

    printf("How many times would you like to roll? ");
    scanf("%d", &num_rolls);

    int results[num_rolls][num_dice]; // create a 2D array to store the results of each roll

    // roll the dice and store the results in the array
    for(int i=0; i<num_rolls; i++){
        for(int j=0; j<num_dice; j++){
            results[i][j] = roll_dice(sides);
        }
    }

    // print the results of each roll
    printf("\nResults:\n");
    for(int i=0; i<num_rolls; i++){
        printf("Roll %d: ", i+1);
        for(int j=0; j<num_dice; j++){
            printf("%d ", results[i][j]);
        }
        printf("\n");
    }

    // calculate and print the statistical data
    int total = 0;
    for(int i=0; i<num_rolls; i++){
        for(int j=0; j<num_dice; j++){
            total += results[i][j];
        }
    }
    double average = (double)total / (double)(num_rolls * num_dice);
    printf("\nStatistical Data:\n");
    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);

    return 0;
}