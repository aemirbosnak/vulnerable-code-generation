//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>

int main()
{
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("This quiz is designed to test your knowledge on the elements in the periodic table.\n");
    printf("Let's get started!\n\n");

    // Quiz questions
    char answer1, answer2, answer3;
    int score = 0;
    
    printf("Question 1: What is the symbol for Iron?\n");
    printf("a) Ir\nb) Fe\nc) I\n");
    scanf(" %c", &answer1);

    if(answer1 == 'b'){
        printf("Correct!\n");
        score++;
    }
    else {
        printf("Incorrect. The correct answer is b) Fe\n");
    }

    printf("Question 2: What is the atomic number of Oxygen?\n");
    printf("a) 6\nb) 8\nc) 16\n");
    scanf(" %c", &answer2);

    if(answer2 == 'b'){
        printf("Correct!\n");
        score++;
    }
    else {
        printf("Incorrect. The correct answer is b) 8\n");
    }

    printf("Question 3: What is the element symbol for Gold?\n");
    printf("a) Ag\nb) Au\nc) Al\n");
    scanf(" %c", &answer3);

    if(answer3 == 'b'){
        printf("Correct!\n");
        score++;
    }
    else {
        printf("Incorrect. The correct answer is b) Au\n");
    }

    // Quiz result
    printf("\nCongratulations, you have completed the quiz!\n");
    printf("You scored %d out of 3.\n", score);

    if(score == 3) {
        printf("Great job, you've earned the Periodic Table Genius title!\n");
    }
    else if(score == 2) {
        printf("Well done, you have a good knowledge of the periodic table.\n");
    }
    else {
        printf("You need to brush up on your periodic table knowledge.\n");
    }

    return 0;
}