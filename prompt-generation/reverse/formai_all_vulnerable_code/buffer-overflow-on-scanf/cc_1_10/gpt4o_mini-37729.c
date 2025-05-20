//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayLoveMessage(int roll) {
    // A delightful message based on the rolled number
    switch (roll) {
        case 1:
            printf("Ah, my dearest, with a single roll,\nTogether, we make a perfect whole.\n");
            break;
        case 2:
            printf("Two hearts entwined, like a blooming flower,\nIn each other's arms, we find our power.\n");
            break;
        case 3:
            printf("Three little words, 'I love you' so true,\nEvery moment spent, I cherish with you.\n");
            break;
        case 4:
            printf("Four seasons pass, yet our love won't fade,\nThrough stormy weather, our bond is made.\n");
            break;
        case 5:
            printf("Five golden rings, a promise in sight,\nTogether forever, our love burns bright.\n");
            break;
        case 6:
            printf("Six sweet kisses, under the moon's glow,\nIn the garden of dreams, our love will grow.\n");
            break;
        default:
            printf("Roll of destiny, bring forth our fate,\nEach number a promise, love never late.\n");
            break;
    }
}

int main() {
    int roll;
    char choice;

    printf("Welcome, my love, to the enchanting Dice Roller!\n");
    printf("Shall we commence this romantic journey? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        srand(time(NULL)); // Seed for randomness
        printf("With bated breath, I roll the dice...\n");
        
        for(int i = 0; i < 5; i++) { // Roll the dice five times
            roll = (rand() % 6) + 1; // Roll between 1 and 6
            printf("Roll %d: The die reveals a gentle %d...\n", i + 1, roll);
            displayLoveMessage(roll);
            printf("\n");
        }

        printf("Dearest, remember...\nOur love is like the roll of the dice,\nFull of surprises, both sweet and nice.\n");
    } else {
        printf("Ah, my love, perhaps another time?\nBut know this, my heart rolls for you, sublime.\n");
    }

    printf("Farewell, until we converse again,\nMay our paths cross, like dice, now and then.\n");
    return 0;
}