//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Greetings! Welcome to the Zany Zucchini Zapper Program (ZZZ) 
// Where we count your zucchinis, zap your zucchinis, and maybe make you laugh! 
// Let's get started!

#define MAX_ZUCCHINIS 10

// Function declaration
void zapZucchini(int zucchinis);
void welcomeMessage();

int main() {
    int zucchinis = 0;
    
    welcomeMessage();
    
    // Let's gather some zucchinis!
    printf("How many zucchinis do you have (Max %d)? ", MAX_ZUCCHINIS);
    
    scanf("%d", &zucchinis);
    
    // Make sure our zucchini number is within a valid range
    if (zucchinis < 0 || zucchinis > MAX_ZUCCHINIS) {
        printf("Oh no! That's too many zucchinis! Try to keep it between 0 and %d!\n", MAX_ZUCCHINIS);
        return 1;
    }

    if (zucchinis == 0) {
        printf("No zucchinis? Well, you can't have fun without zucchinis! Go plant some!\n");
        return 1;
    }

    // Time to zap those zucchinis!
    zapZucchini(zucchinis);

    return 0;
}

// Zaps each zucchini one at a time!
void zapZucchini(int zucchinis) {
    printf("Zapping %d zucchinis!\n", zucchinis);
    for (int i = 1; i <= zucchinis; i++) {
        printf("Zipping through zucchini #%d... ", i);
        // Simulating zap with a random delay
        int delay = rand() % 3 + 1; // Random delay between 1 and 3 seconds
        sleep(delay); // Pause for the zap delay
        printf("ZAP! Zucchini #%d is now a ZUCCHINI-POPPER!\n", i);
        
        // Let’s add some whimsical comments
        switch(i) {
            case 1:
                printf("Watch out! This one's got a crunchy attitude!\n");
                break;
            case 2:
                printf("Zucchini #2 is feeling green with envy!\n");
                break;
            case 3:
                printf("Oh no! Zucchini #3 is rolling away! Catch it!\n");
                break;
            case 4:
                printf("Zucchini #4 wants to be the star of a vegetable show!\n");
                break;
            case 5:
                printf("Can you hear that? Zucchini #5 is singing!\n");
                break;
            case 6:
                printf("Zucchini #6 just signed a contract for a vegetable-themed movie!\n");
                break;
            case 7:
                printf("Zucchini #7 says it's going to run for President!\n");
                break;
            case 8:
                printf("Zucchini #8 has given up on life and is now a philosopher!\n");
                break;
            case 9:
                printf("Zucchini #9 is hosting a cooking show!\n");
                break;
            case 10:
                printf("Zucchini #10 is opening a Zucchini Spa & Resort!\n");
                break;
            default:
                break;
        }
    }
}

// Display a quirky welcome message
void welcomeMessage() {
    printf("~~~~~~ Welcome to the Zany Zucchini Zapper! ~~~~~~\n");
    printf("Here, zucchinis are our best friends. They're green, they're crunchy, and they have a zest for life!\n");
    printf("Get ready to zap those zucchinis!\n");
    srand(time(NULL)); // Seed for random delays!
    printf("---------------------------------------------------\n");
}