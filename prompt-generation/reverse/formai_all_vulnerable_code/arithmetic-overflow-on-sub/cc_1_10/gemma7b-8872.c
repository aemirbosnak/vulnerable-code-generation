//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: retro
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
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and operates a business", 10},
    {"Who wrote the novel 'The Lord of the Flies'?", "William Golding", 10},
    {"Which planet is the largest?", "Jupiter", 10},
    {"What is the chemical symbol for gold?", "Au", 10},
    {"What is the square of 5?", "25", 10},
    {"Who was the first president of the United States?", "George Washington", 10},
    {"Which scientist invented the microscope?", "Robert Hooke", 10},
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and operates a business", 10},
    {"What is the capital of France?", "Paris", 10},
    {"What is the sound of one hand clapping?", "Silence", 10}
};

int main() {
    int i, score = 0;

    // Display the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
    }

    // Get the user's answer
    int answerNumber;
    printf("Enter the number of the question you want to answer: ");
    scanf("%d", &answerNumber);

    // Check if the answer is correct
    if (questions[answerNumber - 1].answer) {
        printf("Your answer is correct.\n");
        score += questions[answerNumber - 1].marks;
    } else {
        printf("Your answer is incorrect.\n");
    }

    // Display the user's score
    printf("Your total score is: %d\n", score);

    return 0;
}