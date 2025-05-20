//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo's Questions
char *romeoQuestions[] = {
    "But soft! What light through yonder window breaks?",
    "It is the east, and Juliet is the sun.",
    "Arise, fair sun, and kill the envious moon,",
    "Who is already sick and pale with grief"
};

// Juliet's Answers
char *julietAnswers[] = {
    "O Romeo, Romeo! Wherefore art thou Romeo?",
    "Deny thy father and refuse thy name;",
    "Or, if thou wilt not, be but sworn my love,",
    "And I'll no longer be a Capulet."
};

// Function to ask a question
void askQuestion(char *question) {
    printf("%s\n", question);
    printf("Answer: ");
}

// Function to check if the answer is correct
int checkAnswer(char *answer, char *correctAnswer) {
    return strcmp(answer, correctAnswer) == 0;
}

// Function to start the examination
void startExam() {
    int score = 0;

    // Ask Romeo's questions
    for (int i = 0; i < 4; i++) {
        askQuestion(romeoQuestions[i]);
        char answer[100];
        scanf("%s", answer);
        if (checkAnswer(answer, julietAnswers[i])) {
            score++;
        }
    }

    // Print the score
    printf("Your score is %d\n", score);
}

int main() {
    // Welcome the user
    printf("Welcome to the Romeo and Juliet Online Examination System!\n");

    // Start the exam
    startExam();

    return 0;
}