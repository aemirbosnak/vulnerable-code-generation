//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int score = 0;
    char answer;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter your name: ");
    char name[20];
    scanf("%s", name);
    printf("Hi %s! Let's get started!\n", name);
    printf("Question 1: What is the chemical symbol for carbon? ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 2: What is the chemical symbol for gold? ");
    scanf(" %c", &answer);
    if (answer == 'Au' || answer == 'au') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 3: What is the chemical symbol for oxygen? ");
    scanf(" %c", &answer);
    if (answer == 'O' || answer == 'o') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 4: What is the chemical symbol for sulfur? ");
    scanf(" %c", &answer);
    if (answer == 'S' || answer == 's') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 5: What is the chemical symbol for magnesium? ");
    scanf(" %c", &answer);
    if (answer == 'Mg' || answer == 'mg') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 6: What is the chemical symbol for iron? ");
    scanf(" %c", &answer);
    if (answer == 'Fe' || answer == 'fe') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 7: What is the chemical symbol for potassium? ");
    scanf(" %c", &answer);
    if (answer == 'K' || answer == 'k') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 8: What is the chemical symbol for tin? ");
    scanf(" %c", &answer);
    if (answer == 'Sn' || answer == 'sn') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 9: What is the chemical symbol for lead? ");
    scanf(" %c", &answer);
    if (answer == 'Pb' || answer == 'pb') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your current score is %d.\n", score);
    
    printf("Question 10: What is the chemical symbol for neon? ");
    scanf(" %c", &answer);
    if (answer == 'Ne' || answer == 'ne') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect.\n");
    }
    printf("Your final score is %d out of 10.\n", score);
    return 0;
}