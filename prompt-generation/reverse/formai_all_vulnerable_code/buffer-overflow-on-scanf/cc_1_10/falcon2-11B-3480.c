//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a question
typedef struct question {
    char question[100];
    char answer[100];
    int correct_answer;
} question;

// Function to generate a random question
question generate_question(question questions[], int num_questions) {
    int index = rand() % num_questions;
    question question = questions[index];
    return question;
}

// Function to mark the student's answer
int mark_answer(char* answer, question question) {
    if (strcmp(answer, question.answer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display the score
void display_score(int score, char* name) {
    printf("Score: %d/%d\n", score, 10);
    printf("Name: %s\n", name);
}

// Function to run the examination
int run_examination(question questions[], int num_questions) {
    char answer[100];
    int score = 0;
    char name[100];
    printf("Name: ");
    scanf("%s", name);

    for (int i = 0; i < num_questions; i++) {
        question question = generate_question(questions, num_questions);
        printf("Question: %s\n", question.question);
        printf("Answer: ");
        scanf("%s", answer);
        score += mark_answer(answer, question);
    }

    display_score(score, name);
    return score;
}

int main() {
    question questions[] = {
        {"What is the capital of India?", "New Delhi", 1},
        {"What is the currency of Japan?", "Yen", 2},
        {"What is the largest planet in our solar system?", "Jupiter", 3}
    };
    int num_questions = sizeof(questions) / sizeof(question);

    int score = run_examination(questions, num_questions);

    return 0;
}