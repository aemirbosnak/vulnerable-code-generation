//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages a business venture", 5},
    {"Who wrote the novel 'Romeo and Juliet'?", "William Shakespeare", 4},
    {"What is the capital of France?", "Paris", 3},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4},
    {"What is the chemical formula for sulfuric acid?", "H2SO4", 3},
    {"Which planet is the largest?", "Jupiter", 5},
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages a business venture", 5},
    {"Who wrote the novel 'Romeo and Juliet'?", "William Shakespeare", 4},
    {"What is the capital of France?", "Paris", 3},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4}
};

int main() {
    int i, marks, score = 0;

    // Print the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
    }

    // Get the student's marks
    printf("Enter your marks for each question (separated by commas): ");
    scanf("%d,", &marks);

    // Calculate the student's score
    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (marks > questions[i].marks) {
            score += questions[i].marks;
        } else {
            score += marks;
        }
    }

    // Print the student's score
    printf("Your total score is: %d\n", score);

    return 0;
}