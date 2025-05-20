//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    /* Seed rand with current time */
    srand(time(NULL));

    int numDice, numSides, i, j, roll, total, paranoidSum = 0;

    printf("Welcome to the Paranoid Dice Roller! \n");
    printf("How many dice do you want to roll? (max 10) ");
    scanf("%d", &numDice);

    /* Paranoid check for number of dice */
    if (numDice <= 0 || numDice > 10) {
        printf("Invalid number of dice!\n");
        return 1;
    }

    printf("How many sides does each die have? ");
    scanf("%d", &numSides);

    /* Paranoid check for number of sides */
    if (numSides <= 1) {
        printf("Dice must have at least 2 sides!\n");
        return 1;
    }

    printf("Rolling %d %d-sided dice...\n", numDice, numSides);

    /* Roll each dice and print result */
    for (i = 1; i <= numDice; i++) {
        roll = rand() % numSides + 1;
        printf("Dice %d: %d\n", i, roll);
        paranoidSum += roll; // Add each individual result to paranoid sum variable
    }

    /* Calculate total sum of all dice rolls */
    total = paranoidSum;

    /* Print paranoid sum */
    printf("Paranoid sum: %d\n", paranoidSum);

    /* Check for suspiciously low sum */
    if (total <= 5 * numDice) {
        printf("Suspiciously low sum detected. Please enter password to continue.\n");
        char password[20];
        scanf("%s", password);
        /* Check password */
        if (strcmp(password, "Paranoia") != 0) {
            printf("Incorrect password. Terminating program.\n");
            return 1;
        }
    }

    /* Check for suspiciously high sum */
    if (total > 100 * numDice) {
        printf("Suspiciously high sum detected. Initiating self-destruct sequence.\n");
        /* Pause for dramatic effect */
        for (j = 0; j < 5; j++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
        /* Simulate crash */
        printf("Program has encountered a fatal error and must terminate.\n");
        printf("Error code: F46D5C-7\n");
        return 1;
    }

    /* Program successful */
    printf("Rolls successful. Total sum: %d\n", total);
    return 0;
}