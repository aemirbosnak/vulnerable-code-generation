//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int roll_dice() {
    int roll = rand() % 6 + 1;
    return roll;
}

int main() {
    srand(time(NULL));
    int num_dice, num_rolls;
    printf("Welcome to the Cyberpunk Dice Roller!\n");
    printf("Enter the number of dice to roll: ");
    while (scanf("%d", &num_dice) != 1 || num_dice < 1) {
        clear_input_buffer();
        printf("Invalid input. Enter the number of dice to roll: ");
    }
    char modifier[10];
    printf("Enter a modifier, such as +2 or -1, or hit enter for no modifier: ");
    fgets(modifier, 10, stdin);
    modifier[strcspn(modifier, "\n")] = '\0';  // remove newline from input
    while (strcmp(modifier, "") != 0 && (modifier[0] != '+' && modifier[0] != '-')) {
        printf("Invalid input. Enter a modifier, such as +2 or -1, or hit enter for no modifier: ");
        fgets(modifier, 10, stdin);
        modifier[strcspn(modifier, "\n")] = '\0';
    }
    printf("Enter the number of rolls: ");
    while (scanf("%d", &num_rolls) != 1 || num_rolls < 1) {
        clear_input_buffer();
        printf("Invalid input. Enter the number of rolls: ");
    }
    printf("Rolling %d dice with %d rolls...\n", num_dice, num_rolls);
    int total = 0;
    for (int i = 0; i < num_rolls; i++) {
        int roll_sum = 0;
        printf("Roll %d: [", i+1);
        for (int j = 0; j < num_dice; j++) {
            int roll = roll_dice();
            roll_sum += roll;
            printf("%d", roll);
            if (j < num_dice - 1) {
                printf(", ");
            }
        }
        printf("] ");
        if (strcmp(modifier, "") != 0) {
            int mod = atoi(modifier);
            roll_sum += mod;
            if (mod >= 0) {
                printf("%s%d = %d\n", modifier, roll_sum - mod, roll_sum);
            } else {
                printf("%d - %d = %d\n", roll_sum - mod, -mod, roll_sum);
            }
        } else {
            printf("= %d\n", roll_sum);
        }
        total += roll_sum;
    }
    printf("Total: %d\n", total);
    return 0;
}