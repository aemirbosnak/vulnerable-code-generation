//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int probability;
    int i, j, k, n;
    char name[20];

    // seed for random number generator
    srand(time(NULL));

    // greeting message
    printf("\n*** Welcome to the Alien Invasion Probability Calculator ***\n");

    // get user's name
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello %s! Let's calculate the probability of an alien invasion.\n", name);

    // get number of galaxies
    printf("How many galaxies are within range of Earth? ");
    scanf("%d", &n);

    // calculate total probability
    probability = rand() % (n * 10);

    // display outcome
    if (probability < 5) {
        printf("\nThe probability of an alien invasion is very low.\n");
    }
    else if (probability < 20) {
        printf("\nThere is a slim chance of an alien invasion.\n");
    }
    else if (probability < 50) {
        printf("\nThe probability of an alien invasion is moderate.\n");
    }
    else if (probability < 80) {
        printf("\nThere is a high probability of an alien invasion.\n");
    }
    else {
        printf("\nThe probability of an alien invasion is extremely high!\n");
    }

    // display detailed calculation
    printf("\nHere is the detailed calculation:\n\n");
    for (i = 1; i <= n; i++) {
        printf("Galaxy %d:\n", i);
        for (j = 1; j <= 10; j++) {
            k = rand() % 10;
            if (k < 3) {
                printf("    There is evidence of alien activity in this galaxy.\n");
            }
            else {
                printf("    No evidence of alien activity in this galaxy.\n");
            }
        }
        printf("\n");
    }
    printf("\nThe total probability of an alien invasion is %d%%.\n\n", probability);

    // farewell message
    printf("Thank you for using the Alien Invasion Probability Calculator.\n");
    printf("Come back again another day!\n\n");

    // end program
    return 0;
}