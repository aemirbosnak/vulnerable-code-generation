//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", "Paris", 20},
    {"Who painted the Mona Lisa?", "Leonardo da Vinci", 15},
    {"Which planet is the largest?", "Jupiter", 20},
    {"Who invented the telephone?", "Alexander Graham Bell", 15},
    {"Which scientist developed the theory of relativity?", "Albert Einstein", 20},
    {"What is the meaning of the word 'entrepreneur'", "Someone who starts and manages their own business", 15},
    {"Which scientist won the Nobel Prize in Physics in 2022?", "Anya Andreyevna Gorodkova", 20},
    {"What is the sound of one hand clapping?", "Silence", 15},
    {"Which fruit is known for its sweet taste and juicy flesh?", "Orange", 20},
    {"What is the meaning of the word 'entrepreneur'", "Someone who starts and manages their own business", 15}
};

int main() {
    int i, score = 0, totalMarks = 0;
    time_t t = time(NULL);

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
    }

    // Get the user's answer for each question
    for (i = 0; i < MAX_QUESTIONS; i++) {
        char answer[256];
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
            totalMarks += questions[i].marks;
        }
    }

    // Calculate the user's total score and marks
    int finalScore = score * totalMarks / MAX_QUESTIONS;

    // Print the results
    printf("\nYour total score is: %d/%d", finalScore, MAX_QUESTIONS);
    printf("\nYour total marks are: %d", totalMarks);

    // Record the time taken to complete the examination
    t = time(NULL) - t;
    printf("\nTime taken: %d seconds", t);

    return 0;
}