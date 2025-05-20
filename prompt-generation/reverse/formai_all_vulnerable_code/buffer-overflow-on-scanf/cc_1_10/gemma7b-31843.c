//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[255];
    char answer[255];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", "Paris", 5},
    {"What is the square of 8?", "64", 4},
    {"Who wrote the novel Harry Potter?", "J.K. Rowling", 3},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 2},
    {"What is the sound of one hand clapping?", "Silence", 4},
    {"Which planet is known for its many moons?", "Saturn", 3},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 2},
    {"What is the most common color of hair in the world?", "Black", 4},
    {"What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 2},
    {"What is the capital of Australia?", "Canberra", 5}
};

int main() {
    int i, score = 0, totalMarks = 0;
    char answer;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
    }

    // Get the user's answer for each question
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf(" %c", &answer);

        // Check if the answer is correct
        if (answer == questions[i].answer[0]) {
            // Award marks for the question
            score += questions[i].marks;
            totalMarks += questions[i].marks;
        }
    }

    // Print the user's score
    printf("\nYour total score is: %d", score);

    // Print the total marks
    printf("\nThe total marks for the examination are: %d", totalMarks);

    return 0;
}