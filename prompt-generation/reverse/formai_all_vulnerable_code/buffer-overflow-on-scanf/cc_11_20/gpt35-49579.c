//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
// Shape-shifting C Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Shape-shifting C Online Examination System!\n\n");

    // Randomly select number of questions
    srand(time(NULL));
    int num_questions = (rand() % 11) + 5; // 5 to 15 questions

    // Shape-shift the questions
    printf("Please answer the following questions:\n");
    for (int i = 0; i < num_questions; i++) {
        int question_type = rand() % 3; // 0, 1, or 2
        printf("\nQuestion %d:\n", i+1);
        if (question_type == 0) {
            // Multiple choice question
            printf("What is the meaning of the word 'abstemious'?\n");
            printf("A. Hungry\nB. Thirsty\nC. Moderate\nD. Sleepy\n");
            // Randomly select correct answer
            int correct_answer = rand() % 4; // 0, 1, 2, or 3
            char letter;
            switch (correct_answer) {
                case 0:
                    letter = 'A';
                    break;
                case 1:
                    letter = 'B';
                    break;
                case 2:
                    letter = 'C';
                    break;
                case 3:
                    letter = 'D';
                    break;
            }
            // Get user input
            char user_input;
            printf("Your answer: ");
            scanf(" %c", &user_input);
            if (user_input == letter) {
                printf("Correct!\n");
            } else {
                printf("Sorry, the correct answer was %c.\n", letter);
            }
        } else if (question_type == 1) {
            // Fill-in-the-blank question
            printf("What is the output of the following C code snippet?\n");
            printf("int a = 5;\n");
            printf("int b = 3;\n");
            printf("printf(\"a + b = %%d\\n\", a + b);\n");
            // Get user input
            int user_input;
            printf("Your answer: ");
            scanf(" %d", &user_input);
            if (user_input == 8) {
                printf("Correct!\n");
            } else {
                printf("Sorry, the correct answer was 8.\n");
            }
        } else {
            // Short answer question
            printf("Who is considered the father of C programming language?\n");
            // Get user input
            char user_input[30];
            printf("Your answer: ");
            scanf(" %[^\n]", user_input);
            if (strcmp(user_input, "Dennis Ritchie") == 0) {
                printf("Correct!\n");
            } else {
                printf("Sorry, the correct answer was 'Dennis Ritchie'.\n");
            }
        }
    }

    // Calculate and display score
    int score = (num_questions * 10); // Each question is worth 10 points
    printf("\nYour score is: %d/%d\n", score, num_questions*10);

    // Goodbye message
    printf("Thank you for taking the Shape-shifting C Online Examination!\n");

    return 0;
}