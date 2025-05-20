//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_welcome_message() {
    printf("========================================\n");
    printf("    Welcome to the Quest for Treasure!  \n");
    printf("   Deep in the Castle of Eldoria lies    \n");
    printf("     a treasure guarded by riddles!      \n");
    printf("========================================\n");
    printf("In order to proceed, brave knight, answer the following riddles wisely!\n\n");
}

int generate_question() {
    int a = rand() % 10 + 1; // Random number between 1 and 10
    int b = rand() % 10 + 1; // Random number between 1 and 10
    int operator = rand() % 2; // 0 for addition, 1 for subtraction

    if (operator == 0) { // Addition
        printf("What is %d + %d?\n", a, b);
        return a + b;
    } else { // Subtraction
        printf("What is %d - %d?\n", a, b);
        return a - b;
    }
}

void knight_challenges() {
    int answer, correct_answer;

    for (int i = 0; i < 5; i++) {
        printf("Challenge %d:\n", i + 1);
        correct_answer = generate_question();

        printf("Your answer: ");
        scanf("%d", &answer);

        if (answer == correct_answer) {
            printf("Well done, noble knight! You may pass.\n\n");
        } else {
            printf("Alas! That is incorrect. You must try again.\n\n");
            i--; // Allow the knight to retry the same challenge
        }
    }
}

void display_treasure() {
    printf("========================================\n");
    printf("          You have found the treasure! \n");
    printf("        Inside the treasure chest, you  \n");
    printf("          see gold, jewels, and magic! \n");
    printf("========================================\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    display_welcome_message();
    
    knight_challenges();
    
    display_treasure();
    
    printf("Thank you for playing, noble knight! Your journey in the Castle of Eldoria\n");
    printf("will be remembered in the annals of history!\n");
    
    return 0;
}