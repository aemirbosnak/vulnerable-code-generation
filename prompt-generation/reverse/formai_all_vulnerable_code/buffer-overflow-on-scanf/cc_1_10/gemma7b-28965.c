//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[255];
    char answer[255];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", "Paris", 5},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 5},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 4},
    {"Who was the first president of the United States?", "George Washington", 4},
    {"What is the most populous country in the world?", "China", 5},
    {"Which planet is the largest?", "Jupiter", 5},
    {"What is the chemical symbol for gold?", "Au", 4},
    {"Which animal is known for its intelligence?", "Humans", 4},
    {"What is the most common color of hair in the world?", "Black", 5},
    {"What is the sound of one hand clapping?", "Silence", 4}
};

int main() {
    int i, marks, total_marks = 0;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
    }

    // Get the student's answers
    for (i = 0; i < MAX_QUESTIONS; i++) {
        char answer[255];
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            marks = questions[i].marks;
        } else {
            marks = 0;
        }

        // Add the marks to the total marks
        total_marks += marks;
    }

    // Print the total marks
    printf("Your total marks are: %d\n", total_marks);

    // Check if the student has passed the exam
    if (total_marks >= 50) {
        printf("You have passed the exam!\n");
    } else {
        printf("You have not passed the exam.\n");
    }

    return 0;
}