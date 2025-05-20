//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numQuestions = 10; // number of questions in the quiz
    int correctAnswers = 0; // number of correct answers given by the user
    int totalQuestions = numQuestions; // total number of questions in the quiz

    // create an array to store the questions
    char *questions[] = {
        "What is the symbol for Hydrogen?",
        "What is the symbol for Helium?",
        "What is the symbol for Lithium?",
        "What is the symbol for Beryllium?",
        "What is the symbol for Boron?",
        "What is the symbol for Carbon?",
        "What is the symbol for Nitrogen?",
        "What is the symbol for Oxygen?",
        "What is the symbol for Fluorine?",
        "What is the symbol for Neon?"
    };

    // create an array to store the correct answers
    char *answers[] = {
        "H",
        "He",
        "Li",
        "Be",
        "B",
        "C",
        "N",
        "O",
        "F",
        "Ne"
    };

    // ask the user questions and store their answers
    for (int i = 0; i < numQuestions; i++) {
        int index = rand() % numQuestions; // randomly select a question from the quiz
        printf("%s. ", questions[index]); // print the question

        // get user input for the answer
        char userInput[10];
        scanf("%s", userInput);

        // compare the user's answer with the correct answer
        if (strcmp(userInput, answers[index]) == 0) {
            correctAnswers++; // user gave a correct answer
        } else {
            printf("Sorry, that is incorrect. The correct answer is %s.\n", answers[index]); // user gave an incorrect answer
        }
    }

    // display the quiz results
    printf("Congratulations! You got %d out of %d questions correct.\n", correctAnswers, totalQuestions); // display the quiz results

    return 0;
}