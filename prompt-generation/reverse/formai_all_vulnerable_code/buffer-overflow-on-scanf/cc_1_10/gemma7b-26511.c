//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages a business venture", 5},
    {"Which planet is the largest?", "Mars", 4},
    {"What is the capital of France?", "Paris", 3},
    {"Who invented the telephone?", "Alexander Graham Bell", 2},
    {"What is the chemical symbol for gold?", "Au", 1},
    {"Which scientist developed the theory of relativity?", "Albert Einstein", 5},
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages a business venture", 5},
    {"Which planet is the largest?", "Mars", 4},
    {"What is the capital of France?", "Paris", 3},
    {"Who invented the telephone?", "Alexander Graham Bell", 2}
};

int main() {
    int i, score = 0, total_marks = 0;

    // Print questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
    }

    // Get student's answers
    for (i = 0; i < MAX_QUESTIONS; i++) {
        char answer[256];
        printf("Enter your answer: ");
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            questions[i].marks++;
            score++;
        }
        total_marks += questions[i].marks;
    }

    // Print results
    printf("Your score: %d/%d\n", score, total_marks);
    printf("Your total marks: %d\n", total_marks);

    return 0;
}