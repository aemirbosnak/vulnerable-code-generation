//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int n;
    int i, j, k;
    int count = 0;
    char str[100];
    int roll;
    int dice;
    int seed;
    int limit;
    int choice;
    int player;
    int computer;
    int sum;
    int win;
    int playAgain;

    printf("Welcome to the Dice Roller!\n");
    printf("How many sides does your dice have?\n");
    scanf("%d", &n);

    printf("How many times do you want to roll the dice?\n");
    scanf("%d", &limit);

    //initialize random seed
    seed = time(NULL);
    srand(seed);

    for(i = 0; i < limit; i++) {
        roll = rand() % n + 1;
        printf("Roll %d: %d\n", i+1, roll);
        count += roll;
        printf("Total: %d\n", count);
    }

    printf("Do you want to play again? (y/n)\n");
    scanf("%s", str);

    if(tolower(str[0]) == 'y') {
        main();
    } else {
        printf("Thank you for playing!\n");
    }

    return 0;
}