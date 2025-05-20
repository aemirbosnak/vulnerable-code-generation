//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10

int main() {
    int i;
    int j;
    int k;
    int l;
    int numbers[MAX_NUMBERS];
    int sum = 0;
    int target = 0;
    int round_count = 0;
    srand(time(NULL));

    printf("Welcome to the multiplayer arithmetic game!\n");
    printf("The objective is to reach the target sum using the given numbers.\n");
    printf("Each player can choose 2 numbers, and the sum of those numbers will be added to the target.\n");
    printf("The first player to reach the target sum wins!\n");

    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 100;
        sum += numbers[i];
    }

    printf("Player 1, choose 2 numbers:\n");
    for (j = 0; j < 2; j++) {
        printf("Enter a number: ");
        scanf("%d", &k);
        numbers[j] = k;
    }
    printf("Player 1's sum: %d\n", sum + numbers[0] + numbers[1]);
    sum += numbers[0] + numbers[1];

    printf("Player 2, choose 2 numbers:\n");
    for (j = 0; j < 2; j++) {
        printf("Enter a number: ");
        scanf("%d", &k);
        numbers[j + 2] = k;
    }
    printf("Player 2's sum: %d\n", sum + numbers[2] + numbers[3]);
    sum += numbers[2] + numbers[3];

    while (sum!= target) {
        printf("Current sum: %d\n", sum);
        printf("Player 3, choose 2 numbers:\n");
        for (j = 0; j < 2; j++) {
            printf("Enter a number: ");
            scanf("%d", &k);
            numbers[j + 4] = k;
        }
        printf("Player 3's sum: %d\n", sum + numbers[4] + numbers[5]);
        sum += numbers[4] + numbers[5];

        printf("Player 4, choose 2 numbers:\n");
        for (j = 0; j < 2; j++) {
            printf("Enter a number: ");
            scanf("%d", &k);
            numbers[j + 6] = k;
        }
        printf("Player 4's sum: %d\n", sum + numbers[6] + numbers[7]);
        sum += numbers[6] + numbers[7];

        printf("Player 5, choose 2 numbers:\n");
        for (j = 0; j < 2; j++) {
            printf("Enter a number: ");
            scanf("%d", &k);
            numbers[j + 8] = k;
        }
        printf("Player 5's sum: %d\n", sum + numbers[8] + numbers[9]);
        sum += numbers[8] + numbers[9];

        round_count++;
        printf("Round: %d\n", round_count);
    }

    printf("Congratulations, Player 1! You won!\n");
    return 0;
}