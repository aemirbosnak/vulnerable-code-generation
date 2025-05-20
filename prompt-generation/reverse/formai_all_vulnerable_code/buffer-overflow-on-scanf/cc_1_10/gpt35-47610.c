//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char answer[20];
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Your score will be displayed at the end of the quiz.\n\n");

    // Question 1
    printf("1. What is the symbol for hydrogen?\n");
    scanf("%s", answer);
    if (strcmp(answer, "H") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct symbol for hydrogen is H.\n");
    }

    // Question 2
    printf("2. What element has the symbol S?\n");
    scanf("%s", answer);
    if (strcmp(answer, "Sulfur") == 0 || strcmp(answer, "sulfur") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Sulfur.\n");
    }

    // Question 3
    printf("3. What is the atomic number of oxygen?\n");
    scanf("%s", answer);
    if (strcmp(answer, "8") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The atomic number of oxygen is 8.\n");
    }

    // Question 4
    printf("4. What element is represented by the symbol Fe?\n");
    scanf("%s", answer);
    if (strcmp(answer, "Iron") == 0 || strcmp(answer, "iron") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Iron.\n");
    }

    // Question 5
    printf("5. What is the symbol for gold?\n");
    scanf("%s", answer);
    if (strcmp(answer, "Au") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The symbol for gold is Au.\n");
    }

    // Display score
    printf("\nCongratulations, you have completed the quiz!\n");
    printf("Your score is: %d out of 5.\n", score);

    return 0;
}