//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store questions and answers
typedef struct {
    char question[100];
    char answer[100];
} Question;

// Array of questions and answers
Question questions[] = {
    {"What is the capital of France?", "Paris"},
    {"What is the largest ocean in the world?", "Pacific Ocean"},
    {"Who is the author of the Harry Potter series?", "J.K. Rowling"},
    {"What is the chemical symbol for gold?", "Au"},
    {"What is the speed of light?", "299,792,458 m/s"}
};

// Function to generate a random question
Question generate_question() {
    int index = rand() % (sizeof(questions) / sizeof(Question));
    return questions[index];
}

// Function to check if the answer is correct
int check_answer(char *answer, char *correct_answer) {
    return strcmp(answer, correct_answer) == 0;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random question
    Question question = generate_question();

    // Prompt the user to answer the question
    printf("Question: %s\n", question.question);
    printf("Answer: ");
    char answer[100];
    scanf("%s", answer);

    // Check if the answer is correct
    int correct = check_answer(answer, question.answer);

    // Print the result
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", question.answer);
    }

    return 0;
}