//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_QUESTIONS 10 // Define the number of questions in the quiz
#define NUM_OF_ELEMENTS 118 // Define the number of elements in the periodic table

// Define a struct for each question in the quiz
typedef struct {
    char *question; // The question to ask
    int answer; // The correct answer
} Question;

// Define a function to generate a random number between 0 and max
int generate_random_number(int max) {
    srand(time(NULL)); // Seed the random number generator
    return rand() % max;
}

int main() {
    Question quiz[NUM_OF_QUESTIONS]; // Create an array to hold the quiz questions
    int score = 0; // Initialize the score to 0

    // Define the quiz questions and their answers
    quiz[0].question = "What is the symbol for Carbon? (1) C (2) H (3) O\n";
    quiz[0].answer = 1;
    quiz[1].question = "What is the atomic number for Iron? (1) 14 (2) 26 (3) 59\n";
    quiz[1].answer = 2;
    quiz[2].question = "What is the symbol for Helium? (1) He (2) Ne (3) Ar\n";
    quiz[2].answer = 1;
    quiz[3].question = "What is the atomic number for Tin? (1) 47 (2) 50 (3) 92\n";
    quiz[3].answer = 2;
    quiz[4].question = "What is the symbol for Nitrogen? (1) N (2) Ni (3) Na\n";
    quiz[4].answer = 1;
    quiz[5].question = "What is the atomic number for Copper? (1) 17 (2) 29 (3) 63\n";
    quiz[5].answer = 2;
    quiz[6].question = "What is the symbol for Oxygen? (1) O (2) C (3) H\n";
    quiz[6].answer = 1;
    quiz[7].question = "What is the atomic number for Uranium? (1) 64 (2) 92 (3) 118\n";
    quiz[7].answer = 2;
    quiz[8].question = "What is the symbol for Sodium? (1) Na (2) K (3) Ca\n";
    quiz[8].answer = 1;
    quiz[9].question = "What is the atomic number for Gold? (1) 79 (2) 7 (3) 30\n";
    quiz[9].answer = 1;

    printf("========== Welcome to the Periodic Table Quiz! ==========\n");

    for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
        printf("\nQuestion %d: %s", i+1, quiz[i].question);

        int user_answer = 0;
        printf("> ");
        scanf("%d", &user_answer);

        if (user_answer == quiz[i].answer) {
            printf("Congratulations, that is correct!\n");
            score++;
        } else {
            printf("Sorry, that is incorrect.\n");
        }
    }

    printf("\n========== Quiz complete! ========== \nYou answered %d out of %d questions correctly.\n", score, NUM_OF_QUESTIONS);

    return 0;
}