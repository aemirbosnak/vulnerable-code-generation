//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Structure to store question and answer
typedef struct Question {
    char question[256];
    char answer[128];
} Question;

// Array of questions and answers
Question questions[] = {
    {"What is the capital of France?", "Paris"},
    {"Who wrote the Mona Lisa?", "Leonardo da Vinci"},
    {"What is the chemical symbol for gold?", "Au"},
    {"What is the name of the largest ocean in the world?", "Pacific Ocean"},
    {"What is the currency of Japan?", "Yen"}
};

// Function to print a question and get the answer from the user
int askQuestion(Question question) {
    printf("%s: ", question.question);
    char answer[128];
    scanf("%s", answer);

    // Return 1 if the answer is correct, 0 otherwise
    return strcmp(answer, question.answer) == 0;
}

// Function to start the examination
int startExam() {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        if (askQuestion(questions[i])) {
            score++;
        }
    }

    return score;
}

// Function to print the result of the examination
void printResult(int score) {
    printf("Your score is %d out of 5.\n", score);

    if (score >= 3) {
        printf("Congratulations! You passed the examination.\n");
    } else {
        printf("Sorry, you failed the examination.\n");
    }
}

// Main function
int main() {
    int score = startExam();

    printResult(score);

    return 0;
}