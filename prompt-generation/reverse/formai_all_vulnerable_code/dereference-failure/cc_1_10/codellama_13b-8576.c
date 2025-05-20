//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4

// Structure to represent a question
struct question {
    char question[100];
    char answers[MAX_ANSWERS][100];
    int correct_answer;
};

// Function to generate a random number
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random question
struct question generate_random_question(char *questions[], int num_questions) {
    // Generate a random question index
    int question_index = generate_random_number(0, num_questions - 1);

    // Generate a random answer index
    int answer_index = generate_random_number(0, MAX_ANSWERS - 1);

    // Create a new question struct
    struct question q;
    strcpy(q.question, questions[question_index]);
    strcpy(q.answers[0], questions[question_index + 1]);
    strcpy(q.answers[1], questions[question_index + 2]);
    strcpy(q.answers[2], questions[question_index + 3]);
    strcpy(q.answers[3], questions[question_index + 4]);
    q.correct_answer = answer_index;

    return q;
}

// Function to display a question
void display_question(struct question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i + 1, q.answers[i]);
    }
}

// Function to check the answer
int check_answer(struct question q, int answer) {
    return q.correct_answer == answer;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Array of questions
    char *questions[] = {
        "What is the capital of France?",
        "Paris",
        "London",
        "Rome",
        "Berlin",
        "What is the largest planet in our solar system?",
        "Earth",
        "Saturn",
        "Jupiter",
        "Uranus",
        "What is the smallest country in the world?",
        "Vatican City",
        "Russia",
        "Norway",
        "Switzerland"
    };

    // Number of questions
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Generate a random question
    struct question q = generate_random_question(questions, num_questions);

    // Display the question
    display_question(q);

    // Get the user's answer
    int answer;
    scanf("%d", &answer);

    // Check the answer
    if (check_answer(q, answer)) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %s.\n", q.answers[q.correct_answer]);
    }

    return 0;
}