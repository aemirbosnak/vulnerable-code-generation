//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Constants for the number of questions and the maximum score
#define NUM_QUESTIONS 10
#define MAX_SCORE 100

// Structure to hold the question and possible answers
typedef struct {
    char question[100];
    char correct_answer[10];
    char answer1[10];
    char answer2[10];
    char answer3[10];
    char answer4[10];
} Question;

// Function to display the quiz questions and answers
void display_question(Question* question) {
    printf("%s. ", question->question);
    printf("%s. ", question->answer1);
    printf("%s. ", question->answer2);
    printf("%s. ", question->answer3);
    printf("%s. ", question->answer4);
    printf("%s\n", question->correct_answer);
}

// Function to get the user's answer and check if it is correct
bool get_answer(Question* question, int* score) {
    char answer[10];
    printf("%s. ", question->answer1);
    printf("%s. ", question->answer2);
    printf("%s. ", question->answer3);
    printf("%s. ", question->answer4);
    printf("%s\n", question->correct_answer);
    scanf("%s", answer);
    if (strcmp(answer, question->correct_answer) == 0) {
        *score += 10;
        return true;
    }
    return false;
}

// Function to display the quiz results
void display_results(int score) {
    printf("Your score is %d out of %d.\n", score, MAX_SCORE);
}

int main() {
    Question questions[] = {
        {"What is the symbol for iron?", "Fe", "Co", "Ni", "Cu"},
        {"What is the atomic number of sodium?", "1", "11", "19", "23"},
        {"What is the name of the element with the symbol Cl?", "Chlorine", "Chromium", "Cobalt", "Copper"},
        {"What is the electron configuration of neon?", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6"},
        {"What is the name of the element with the symbol Pb?", "Platinum", "Plutonium", "Phosphorus", "Potassium"},
        {"What is the atomic weight of helium?", "4.0026", "4.0026", "4.0026", "4.0026"},
        {"What is the name of the element with the symbol Hg?", "Hydrogen", "Helium", "Hydrogen", "Hydrogen"},
        {"What is the symbol for silver?", "Ag", "Al", "Am", "As"},
        {"What is the electron configuration of magnesium?", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6", "1s2 2s2 2p6 3s2 3p6 4s2 3d10 4p6"},
        {"What is the name of the element with the symbol As?", "Arsenic", "Antimony", "Arsenic", "Antimony"},
        {"What is the electron configuration of oxygen?", "1s2 2s2 2p4", "1s2 2s2 2p4", "1s2 2s2 2p4", "1s2 2s2 2p4"}
    };
    int score = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        Question question = questions[i];
        display_question(&question);
        bool correct = get_answer(&question, &score);
        if (correct) {
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }

    display_results(score);
    return 0;
}