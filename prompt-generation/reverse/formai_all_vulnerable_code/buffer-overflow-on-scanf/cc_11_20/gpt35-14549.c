//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j;
    int ATTACK_PROBABILITY[10][10] = {{70, 70, 60, 50, 40, 30, 20, 10, 5, 5},
                                      {70, 60, 50, 40, 30, 20, 10, 5, 5, 0},
                                      {60, 50, 40, 30, 20, 10, 5, 5, 0, 0},
                                      {50, 40, 30, 20, 10, 5, 5, 0, 0, 0},
                                      {40, 30, 20, 10, 5, 5, 0, 0, 0, 0},
                                      {30, 20, 10, 5, 5, 0, 0, 0, 0, 0},
                                      {20, 10, 5, 5, 0, 0, 0, 0, 0, 0},
                                      {10, 5, 5, 0, 0, 0, 0, 0, 0, 0},
                                      {5, 5, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {5, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int INVASION_PROBABILITY[10][10] = {{5, 10, 20, 30, 40, 50, 60, 70, 70, 70},
                                        {5, 5, 10, 20, 30, 40, 50, 60, 70, 70},
                                        {0, 5, 5, 10, 20, 30, 40, 50, 60, 70},
                                        {0, 0, 5, 5, 10, 20, 30, 40, 50, 60},
                                        {0, 0, 0, 5, 5, 10, 20, 30, 40, 50},
                                        {0, 0, 0, 0, 5, 5, 10, 20, 30, 40},
                                        {0, 0, 0, 0, 0, 5, 5, 10, 20, 30},
                                        {0, 0, 0, 0, 0, 0, 5, 5, 10, 20},
                                        {0, 0, 0, 0, 0, 0, 0, 5, 5, 10},
                                        {0, 0, 0, 0, 0, 0, 0, 0, 5, 5}};
    int x, y, prob_attack, prob_invasion, total_prob_attack, total_prob_invasion;
    srand(time(NULL));
    printf("**** C Alien Invasion Probability Calculator ****\n");
    printf("Please enter the X and Y coordinates of the target location (0 to 9):\n");
    scanf("%d%d", &x, &y);
    if (x < 0 || x > 9 || y < 0 || y > 9) {
        printf("Invalid coordinates. Program exiting...\n");
        return 0;
    }
    printf("Calculating probability of attack and invasion at (%d, %d)...\n", x, y);
    total_prob_attack = 0;
    total_prob_invasion = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            prob_attack = ATTACK_PROBABILITY[i][j];
            prob_invasion = INVASION_PROBABILITY[i][j];
            if (i == x && j == y) {
                total_prob_attack += prob_attack;
                total_prob_invasion += prob_invasion;
            }
        }
    }
    printf("Probability of attack: %d%%\n", total_prob_attack);
    printf("Probability of invasion: %d%%\n", total_prob_invasion);
    printf("Do you want to simulate an attack at (%d, %d)? (y/n)\n", x, y);
    getchar();  // clear input buffer
    if (getchar() == 'y') {
        printf("Simulating attack...\n");
        if (rand() % 100 < total_prob_attack) {
            printf("Attack successful!\n");
            if (rand() % 100 < total_prob_invasion) {
                printf("The aliens have invaded the planet...\n");
            } else {
                printf("The aliens have failed to invade the planet!\n");
            }
        } else {
            printf("Attack failed...\n");
        }
    } else {
        printf("Program exiting...\n");
    }
    return 0;
}