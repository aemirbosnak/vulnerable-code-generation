//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>

int main() {
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Are you ready to show off your chemistry skills?\n\n");

    // Question 1
    printf("Question 1: What is the chemical symbol for sodium?\n");
    printf("A. So\tB. Na\tC. Sa\n");
    char answer1;
    scanf("%c", &answer1);
    
    if (answer1 == 'B' || answer1 == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is B. Na\n");
    }
    printf("Score: %d\n\n", score);
    
    // Question 2
    printf("Question 2: Which element has the symbol 'Fe'?\n");
    printf("A. Fluorine\tB. Iron\tC. Carbon\n");
    char answer2;
    scanf(" %c", &answer2); // the space before %c is important to consume the newline character
    
    if (answer2 == 'B' || answer2 == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is B. Iron\n");
    }
    printf("Score: %d\n\n", score);
    
    // Question 3
    printf("Question 3: What is the chemical symbol for gold?\n");
    printf("A. Au\tB. Ag\tC. Al\n");
    char answer3;
    scanf(" %c", &answer3);
    
    if (answer3 == 'A' || answer3 == 'a') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is A. Au\n");
    }
    printf("Score: %d\n\n", score);
    
    // Final score
    printf("Congratulations, you finished the quiz!\n");
    printf("Your final score is %d out of 3.\n", score);
    
    return 0;
}