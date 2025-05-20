//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a) A person who sells things", "b) A person who is good at math", "c) A person who is creative", "d) A person who is rich"}, 2},
    {"Which scientist invented the theory of relativity?", {"a) Albert Einstein", "b) Isaac Newton", "c) Charles Darwin", "d) Galileo Galilei"}, 1},
    {"What is the capital of France?", {"a) Paris", "b) Rome", "c) Lyon", "d) Marseille"}, 3},
    // Add more questions here
};

int main() {
    int numQuestions = sizeof(questions) / sizeof(Question);

    time_t startTime = time(NULL);

    // Generate a random question
    int randomQuestionIndex = rand() % numQuestions;

    Question currentQuestion = questions[randomQuestionIndex];

    // Display the question and answers
    printf("Question: %s\n", currentQuestion.question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("Answer: %s\n", currentQuestion.answers[i]);
    }

    // Get the user's answer
    char userAnswer[MAX_ANSWERS];
    printf("Enter your answer: ");
    scanf("%s", userAnswer);

    // Check if the user's answer is correct
    int isAnswerCorrect = (userAnswer[0] == (questions[randomQuestionIndex].correctAnswer - 1) + 'a');

    // Display the results
    if (isAnswerCorrect) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry, your answer is incorrect. The correct answer is: %s\n", questions[randomQuestionIndex].answers[questions[randomQuestionIndex].correctAnswer - 1]);
    }

    time_t endTime = time(NULL);

    // Calculate the time taken to complete the question
    int timeTaken = endTime - startTime;

    // Display the time taken
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}