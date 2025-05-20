//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store student's details
typedef struct Student {
    char name[50];
    int roll_no;
    int marks;
} Student;

// Function to generate random questions
void generateQuestions(char questions[][100], int num_questions) {
    // Array of possible questions
    char possible_questions[][100] = {
        "What is the capital of India?",
        "Who is the current Prime Minister of India?",
        "What is the national animal of India?",
        "What is the currency of India?",
        "What is the largest city in India?"
    };

    // Generate random numbers to select questions
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        int random_index = rand() % 5;
        strcpy(questions[i], possible_questions[random_index]);
    }
}

// Function to get student's answers
void getAnswers(char questions[][100], char answers[][100], int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i]);
        scanf("%s", answers[i]);
    }
}

// Function to check student's answers
int checkAnswers(char questions[][100], char answers[][100], int num_questions) {
    // Array of correct answers
    char correct_answers[][100] = {
        "New Delhi",
        "Narendra Modi",
        "Tiger",
        "Indian Rupee",
        "Mumbai"
    };

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (strcmp(answers[i], correct_answers[i]) == 0) {
            score++;
        }
    }

    return score;
}

// Function to print student's result
void printResult(Student student, int score) {
    printf("Name: %s\n", student.name);
    printf("Roll No.: %d\n", student.roll_no);
    printf("Score: %d\n", score);
}

// Main function
int main() {
    // Get student's details
    Student student;
    printf("Enter your name: ");
    scanf("%s", student.name);
    printf("Enter your roll number: ");
    scanf("%d", &student.roll_no);

    // Generate random questions
    char questions[10][100];
    generateQuestions(questions, 10);

    // Get student's answers
    char answers[10][100];
    getAnswers(questions, answers, 10);

    // Check student's answers
    int score = checkAnswers(questions, answers, 10);

    // Print student's result
    printResult(student, score);

    return 0;
}