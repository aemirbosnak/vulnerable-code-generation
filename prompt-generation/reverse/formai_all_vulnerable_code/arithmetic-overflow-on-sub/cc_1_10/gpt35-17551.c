//FormAI DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_dice(int sides){
    int result = rand() % sides + 1;
    return result;
}

int main(){
    int sides, dice, i, j;

    srand(time(NULL));

    printf("Welcome to the Dice Roller program!\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &sides);
    printf("How many dice do you want to roll? ");
    scanf("%d", &dice);
    printf("Rolling %d dice with %d sides...\n", dice, sides);

    for(i = 1; i <= dice; i++){
        printf("Dice %d:", i);
        int roll = roll_dice(sides);
        printf("%d ", roll);
        if(roll == sides){
            printf("(Critical!)");
        }
        printf("\n");
    }

    printf("\nRolling 1000 dice to see distribution...\n");
    int counts[sides];
    for(i = 0; i < sides; i++){
        counts[i] = 0;
    }
    for(i = 0; i < 1000; i++){
        int roll = roll_dice(sides);
        counts[roll - 1]++;
    }
    printf("Results:\n");
    for(i = 0; i < sides; i++){
        printf("%d: ", i + 1);
        double percentage = (double) counts[i] / 10;
        for(j = 0; j < percentage; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}