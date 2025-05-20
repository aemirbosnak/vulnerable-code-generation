//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char element[50];
    char answer[50];
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter the symbol or name of the element:\n");
    printf("Answer all questions correctly to earn a high score!\n\n");
    
    // First Question
    printf("What is the symbol for Gallium?\n");
    scanf("%s", element);
    if (strcmp(element, "Ga") == 0 || strcmp(element, "gallium") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Ga.\n\n");
    }
    
    // Second Question
    printf("What is the name of the element with the symbol Fe?\n");
    scanf("%s", element);
    if (strcmp(element, "Iron") == 0 || strcmp(element, "iron") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Iron.\n\n");
    }
    
    // Third Question
    printf("What is the atomic number of Sodium?\n");
    scanf("%s", element);
    if (strcmp(element, "11") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is 11.\n\n");
    }
    
    // Fourth Question
    printf("What is the symbol for Silver?\n");
    scanf("%s", element);
    if (strcmp(element, "Ag") == 0 || strcmp(element, "silver") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Ag.\n\n");
    }
    
    // Fifth Question
    printf("What is the name of the element with the symbol C?\n");
    scanf("%s", element);
    if (strcmp(element, "carbon") == 0 || strcmp(element, "Carbon") == 0) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is Carbon.\n\n");
    }
    
    // Final Score
    printf("Congratulations, you have completed the quiz!\n");
    printf("Your final score is %d out of 5.\n", score);
    
    // High Score
    FILE *fp;
    fp = fopen("high_scores.txt", "a+");
    if (score == 5) {
        printf("You got a perfect score! Enter your name to be added to the high score list:\n");
        scanf("%s", answer);
        fprintf(fp, "%s - %d/5\n", answer, score);
    }
    fclose(fp);
    
    return 0;
}