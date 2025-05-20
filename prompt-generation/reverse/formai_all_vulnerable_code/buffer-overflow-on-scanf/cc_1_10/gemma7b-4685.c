//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[255];
    char answer[255];
    int difficulty;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "a. A person who is willing to take risks to start and operate a business", 3},
    {"Which scientist invented the theory of relativity?", "b. Albert Einstein", 4},
    {"What is the capital of France?", "c. Paris", 2},
    {"Who was the first president of the United States?", "d. George Washington", 3},
    {"What is the chemical symbol for gold?", "e. Au", 2},
    {"Which planet is the largest?", "f. Jupiter", 4},
    {"What is the sound of one hand clapping?", "g. Silence", 2},
    {"Which animal is known for its sharp teeth?", "h. Lion", 3},
    {"What is the meaning of the word 'entrepreneur'?", "i. A person who is willing to take risks to start and operate a business", 3},
    {"Which country is the largest exporter of oil?", "j. Saudi Arabia", 4}
};

int main() {
    time_t t = time(NULL);
    srand(t);

    int score = 0;
    int currentQuestion = 0;

    printf("Welcome to the Future of Learning!");
    printf("\n");

    while (currentQuestion < MAX_QUESTIONS) {
        // Display the question
        printf("%s\n", questions[currentQuestion].question);

        // Get the user's answer
        char answer[255];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[currentQuestion].answer) == 0) {
            // Increment the score
            score++;

            // Move on to the next question
            currentQuestion++;

            // Display a congratulatory message
            printf("Correct! You have earned a point!\n");
        } else {
            // Display an error message
            printf("Incorrect. The answer is: %s\n", questions[currentQuestion].answer);
        }
    }

    // Display the final score
    printf("Your total score is: %d\n", score);

    return 0;
}