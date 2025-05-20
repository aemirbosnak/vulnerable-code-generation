//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a question
struct Question {
    char question[256];
    char answer[256];
};

// Function to display a question
void displayQuestion(struct Question question) {
    printf("Question: %s\n", question.question);
    printf("Answer: ");
}

// Function to check if the answer is correct
int checkAnswer(struct Question question, char *answer) {
    if (strcmp(question.answer, answer) == 0) {
        return 1;
    }
    return 0;
}

// Function to generate a random question
struct Question generateQuestion() {
    struct Question question;
    srand(time(NULL));
    int random = rand() % 100 + 1;
    if (random < 50) {
        strcpy(question.question, "What is the capital of France?");
        strcpy(question.answer, "Paris");
    } else if (random < 75) {
        strcpy(question.question, "What is the currency of the United States?");
        strcpy(question.answer, "US Dollar");
    } else {
        strcpy(question.question, "What is the smallest country in the world?");
        strcpy(question.answer, "Vatican City");
    }
    return question;
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Generate a random question
    struct Question question = generateQuestion();

    // Display the question
    displayQuestion(question);

    // Get the answer from the user
    char answer[256];
    scanf("%s", answer);

    // Check if the answer is correct
    int result = checkAnswer(question, answer);

    // Display the result
    if (result) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", question.answer);
    }

    return 0;
}