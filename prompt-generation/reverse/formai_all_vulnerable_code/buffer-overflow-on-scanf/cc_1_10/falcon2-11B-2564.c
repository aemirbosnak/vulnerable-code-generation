//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random question
char* get_question() {
    int num_questions = 10; // Number of questions
    char* questions[num_questions];
    
    // Populate the array with questions
    strcpy(questions[0], "What is the capital of France?");
    strcpy(questions[1], "Who is the Prime Minister of India?");
    strcpy(questions[2], "What is the largest planet in our solar system?");
    strcpy(questions[3], "What is the product of 5 and 6?");
    strcpy(questions[4], "What is the sum of 2 and 3?");
    strcpy(questions[5], "What is the cube root of 64?");
    strcpy(questions[6], "What is the square root of 81?");
    strcpy(questions[7], "What is the area of a circle with radius 5?");
    strcpy(questions[8], "What is the volume of a cube with side length 3?");
    strcpy(questions[9], "What is the greatest common divisor of 12 and 18?");
    
    return questions[rand_num(0, num_questions-1)];
}

// Function to get the user's answer
char* get_answer() {
    char answer[100];
    printf("Enter your answer: ");
    scanf("%s", answer);
    return answer;
}

// Function to check the user's answer
int check_answer(char* question, char* answer) {
    // Check if the answer is correct
    if (strcmp(question, "What is the capital of France?") == 0 && strcmp(answer, "Paris") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "Who is the Prime Minister of India?") == 0 && strcmp(answer, "Narendra Modi") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the largest planet in our solar system?") == 0 && strcmp(answer, "Jupiter") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the product of 5 and 6?") == 0 && strcmp(answer, "30") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the sum of 2 and 3?") == 0 && strcmp(answer, "5") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the cube root of 64?") == 0 && strcmp(answer, "4") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the square root of 81?") == 0 && strcmp(answer, "9") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the area of a circle with radius 5?") == 0 && strcmp(answer, "78.54") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the volume of a cube with side length 3?") == 0 && strcmp(answer, "27") == 0) {
        return 1; // Correct
    } else if (strcmp(question, "What is the greatest common divisor of 12 and 18?") == 0 && strcmp(answer, "6") == 0) {
        return 1; // Correct
    } else {
        return 0; // Incorrect
    }
}

// Main function
int main() {
    int num_questions = 10; // Number of questions
    int num_correct = 0; // Number of correct answers
    
    // Generate a random question
    char* question = get_question();
    printf("Question: %s\n", question);
    
    // Get the user's answer
    char* answer = get_answer();
    
    // Check the user's answer
    int result = check_answer(question, answer);
    
    // If the answer is correct, increment the number of correct answers
    if (result == 1) {
        num_correct++;
    }
    
    // Print the result
    if (result == 1) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }
    
    // Print the number of correct answers
    printf("Number of correct answers: %d\n", num_correct);
    
    return 0;
}