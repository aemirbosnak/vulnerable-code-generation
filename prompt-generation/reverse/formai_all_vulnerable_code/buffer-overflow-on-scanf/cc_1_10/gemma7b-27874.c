//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

// Define the questions
char questions[MAX_QUESTIONS][100] = {
    "What is the capital of France?",
    "Who wrote the novel 'The Lord of the Flies'?",
    "Which planet is the largest?",
    "What is the meaning of the word 'entrepreneur'?",
    "What is the chemical formula for sulfuric acid?",
    "What is the significance of the number 42?",
    "Who was the first president of the United States?",
    "What is the sound of one hand clapping?",
    "What is the meaning of the idiom 'a dime a dozen'?",
    "What is the most common color of hair in the world?"
};

// Define the answer key
char answer_key[MAX_QUESTIONS][20] = {
    "Paris",
    "William Golding",
    "Jupiter",
    "Someone who owns and operates a business",
    "H2SO4",
    "The answer to the ultimate question of life, the universe, and everything",
    "George Washington",
    "A soft clicking sound",
    "A lot of something inexpensive",
    "Black"
};

// Function to generate a random question
char generate_question() {
    int rand_num = rand() % MAX_QUESTIONS;
    return questions[rand_num][0];
}

// Function to check the answer
int check_answer(char answer) {
    int i = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(answer, answer_key[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char question, answer;
    int score = 0;
    time_t start_time, end_time;

    // Start the timer
    start_time = time(NULL);

    // Generate a random question
    question = generate_question();

    // Get the answer from the user
    printf("Question: %s", question);
    scanf(" %s", &answer);

    // Check the answer
    if (check_answer(answer)) {
        score++;
        printf("Correct! You have scored 1 point.\n");
    } else {
        printf("Incorrect. The answer is: %s", answer_key[0]);
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the results
    printf("Your score is: %d", score);
    printf("\nTime taken: %d seconds", time_taken);

    return 0;
}