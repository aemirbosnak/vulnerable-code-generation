//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    char answer;
    int score = 0;
    
    printf("Welcome to the Periodic Table Quiz, fair Romeo and delightful Juliet!\n");
    printf("This quiz will test your knowledge of the elements of the periodic table.\n");
    printf("Are you ready to begin? (Y/N): ");
    scanf("%c", &answer);

    if (answer == 'Y' || answer == 'y') {
        printf("Very well, let us begin our journey together!\n");
        printf("Question 1: What is the symbol for Gold?\n");
        printf("A) G\nB) Au\nC) Ag\nD) Go\n");
        scanf(" %c", &answer);
        if (answer == 'B' || answer == 'b') {
            printf("Well done, my sweet Romeo! Gold's symbol is indeed Au.\n");
            score++;
        } else {
            printf("Alas, fair Juliet! The correct answer is B) Au.\n");
        }

        printf("\nQuestion 2: What is the atomic number of Carbon?\n");
        printf("A) 6\nB) 12\nC) 16\nD) 24\n");
        scanf(" %c", &answer);
        if (answer == 'A' || answer == 'a') {
            printf("Magnificent, my dearest Juliet! Carbon's atomic number is 6.\n");
            score++;
        } else {
            printf("Oh Romeo, what a tragedy! The correct answer is A) 6.\n");
        }

        printf("\nQuestion 3: Which element is named after a small European country?\n");
        printf("A) Germanium\nB) Polonium\nC) Francium\nD) Lithium\n");
        scanf(" %c", &answer);
        if (answer == 'A' || answer == 'a') {
            printf("Impressive, sweet Juliet! Germanium is indeed named after Germany.\n");
            score++;
        } else {
            printf("My heart aches, dear Romeo. The correct answer is A) Germanium.\n");
        }
        
        printf("\nCongratulations, fair lovers! You have completed the quiz.\n");
        printf("Your score is %d out of 3. T'was a pleasure, my dear friends.\n", score);

    } else if (answer == 'N' || answer == 'n') {
        printf("Ah, I see. Farewell, then. Until we meet again!\n");
    } else {
        printf("My apologies, kind Romeo and gracious Juliet. I do not understand your answer.\n");
    }

    return 0;
}