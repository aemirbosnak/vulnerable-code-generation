//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Number of questions in the quiz
#define NUM_QUESTIONS 10

// Struct defining a question
typedef struct {
    char* question;
    char* options[4];
    char answer;
} Question;

// Array of questions
Question questions[NUM_QUESTIONS] = {
    {"What is the symbol for Carbon?", {"A: Ca", "B: Co", "C: C", "D: Cu"}, 'C'},
    {"How many protons does Oxygen have?", {"A: 6", "B: 7", "C: 8", "D: 9"}, 'C'},
    {"What is the symbol for Iron?", {"A: Ir", "B: Fe", "C: In", "D: I"}, 'B'},
    {"What element is represented by the symbol K?", {"A: Potassium", "B: Krypton", "C: Silicon", "D: Calcium"}, 'A'},
    {"What element has the atomic number 92?", {"A: Uranium", "B: Mercury", "C: Aluminum", "D: Sodium"}, 'A'},
    {"What is the symbol for Neon?", {"A: Na", "B: Ne", "C: Ni", "D: Nb"}, 'B'},
    {"What is the atomic number of Nitrogen?", {"A: 7", "B: 8", "C: 9", "D: 10"}, 'A'},
    {"What is the symbol for Silver?", {"A: Si", "B: Ag", "C: Au", "D: Al"}, 'B'},
    {"What is the chemical formula for water?", {"A: HO", "B: H2O", "C: H3O", "D: H4O"}, 'B'},
    {"What gas makes up the majority of the Earth's atmosphere?", {"A: Oxygen", "B: Carbon Dioxide", "C: Nitrogen", "D: Helium"}, 'C'},
};

// Function to get a random index between 0 and max
int getRandomIndex(int max) {
    srand(time(NULL));
    return rand() % max;
}

int main() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following %d questions to test your knowledge.\n\n", NUM_QUESTIONS);

    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Get a random question
        int randomIndex = getRandomIndex(NUM_QUESTIONS);
        Question question = questions[randomIndex];

        printf("Question #%d: %s\n", i+1, question.question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", question.options[j]);
        }

        char chosenAnswer;
        printf("Choose your answer (A, B, C, or D): ");
        scanf(" %c", &chosenAnswer);

        // Check if the chosen answer is correct
        if (chosenAnswer == question.answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c.\n\n", question.answer);
        }
    }

    // Print final score
    printf("Congratulations, you completed the quiz!\n");
    printf("Your final score is %d/%d.", score, NUM_QUESTIONS);

    return 0;
}