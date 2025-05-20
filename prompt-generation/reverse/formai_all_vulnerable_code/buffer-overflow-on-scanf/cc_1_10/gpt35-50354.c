//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    char answer;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to test your knowledge? (y/n) ");
    scanf(" %c", &answer);
    
    if(answer != 'y') {
        printf("Goodbye!\n");
        return 0;
    }
    
    printf("\nQuestion 1: What is the symbol for Hydrogen?\n");
    printf("a) Hs\tb) He\tc) H\td) Ho\n");
    scanf(" %c", &answer);
    if(answer == 'c') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is c) H.\n");
    }
    
    printf("\nQuestion 2: What is the symbol for Carbon?\n");
    printf("a) C\tb) Ca\tc) Cr\td) Co\n");
    scanf(" %c", &answer);
    if(answer == 'a') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is a) C.\n");
    }
    
    printf("\nQuestion 3: What is the atomic number of Nitrogen?\n");
    printf("a) 8\tb) 7\tc) 9\td) 6\n");
    scanf(" %c", &answer);
    if(answer == 'b') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is b) 7.\n");
    }
    
    printf("\nQuestion 4: What is the symbol for Gold?\n");
    printf("a) G\tb) Go\tc) Au\td) Ag\n");
    scanf(" %c", &answer);
    if(answer == 'c') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is c) Au.\n");
    }
    
    printf("\nQuestion 5: What is the symbol for Calcium?\n");
    printf("a) Cu\tb) Ca\tc) Cd\td) Cn\n");
    scanf(" %c", &answer);
    if(answer == 'b') {
        score++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is b) Ca.\n");
    }
    
    printf("\nYou scored %d out of 5.\n", score);
    
    // Random fun fact
    srand(time(NULL));
    int random = rand() % 3;
    if(random == 0) {
        printf("\nFun Fact: The scientific name for a molecule of caffeine is 1,3,7-trimethylxanthine.\n");
    } else if(random == 1) {
        printf("\nFun Fact: The first element on the periodic table, Hydrogen, was created during the Big Bang.\n");
    } else {
        printf("\nFun Fact: Oxygen makes up about 65% of the human body by mass.\n");
    }
    
    return 0;
}