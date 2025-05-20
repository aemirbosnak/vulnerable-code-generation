//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define TIME_LIMIT 60

// Define the question structure
typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

// Create a list of questions
Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who is good at business", "b. A person who is willing to take risks", "c. A person who is creative", "d. A person who is successful"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Bordeaux"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A beep"}, 5},
    {"Which fruit is orange?", {"a. Apple", "b. Banana", "c. Orange", "d. Grape"}, 6},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who is good at business", "b. A person who is willing to take risks", "c. A person who is creative", "d. A person who is successful"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 3},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Bordeaux"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A beep"}, 5}
};

// Function to start the examination
int startExamination(void) {
    // Get the current time
    time_t startTime = time(NULL);

    // Print the questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        // Print the answers
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s) %s\n", j + 1, questions[i].answers[j]);
        }

        // Get the user's answer
        int answer = getAnswer();

        // Check if the answer is correct
        if (answer == questions[i].correctAnswer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer is: %d\n", questions[i].correctAnswer);
        }
    }

    // Get the end time
    time_t endTime = time(NULL);

    // Calculate the time taken
    int timeTaken = endTime - startTime;

    // Print the time taken
    printf("Time taken: %d seconds\n", timeTaken);

    // Return the score
    return 0;
}

// Function to get the user's answer
int getAnswer(void) {
    int answer;

    printf("Enter your answer: ");
    scanf("%d", &answer);

    return answer;
}

int main() {
    startExamination();

    return 0;
}