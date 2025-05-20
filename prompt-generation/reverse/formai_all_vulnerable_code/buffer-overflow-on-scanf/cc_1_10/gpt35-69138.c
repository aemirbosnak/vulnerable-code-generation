//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_QUESTIONS 100 // Maximum number of questions
#define MAX_ANS_LENGTH 50 // Maximum length of answer
#define MAX_NAME_LENGTH 50 // Maximum length of student name

// Define Question structure
struct question {
    char question_text[MAX_ANS_LENGTH];
    char correct_answer[MAX_ANS_LENGTH];
};

// Function to display welcome message
void displayWelcomeMsg() {
    printf("*******************************\n");
    printf("Welcome to the Future Online Examination System\n");
    printf("*******************************\n\n");
}

// Function to get the number of questions from the user
int getNumQuestions() {
    int num_questions;

    printf("Please enter the number of questions: ");
    scanf("%d", &num_questions);

    return num_questions;
}

// Function to get the questions from the user
void getQuestions(int num_questions, struct question *questions) {
    for(int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d\n", i+1);
        printf("Please enter the question: ");
        getchar();
        fgets(questions[i].question_text, MAX_ANS_LENGTH, stdin);
        strtok(questions[i].question_text, "\n");

        printf("Please enter the answer: ");
        fgets(questions[i].correct_answer, MAX_ANS_LENGTH, stdin);
        strtok(questions[i].correct_answer, "\n");
    }
}

// Function to display questions
void displayQuestions(int num_questions, struct question *questions) {
    printf("\n--- Questions ---\n");
    for(int i = 0; i < num_questions; i++) {
        printf("\n%d. %s\n", i+1, questions[i].question_text);
    }
}

// Function to get student name
void getStudentName(char *student_name) {
    printf("\nEnter your name: ");
    fgets(student_name, MAX_NAME_LENGTH, stdin);
    strtok(student_name, "\n");
}

// Function to display exam results
void displayExamResults(int num_questions, struct question *questions, char *student_name) {
    int total_correct_answers = 0;
    char answer[MAX_ANS_LENGTH];

    printf("\n\n--- Exam Results for %s ---\n", student_name);
    for(int i = 0; i < num_questions; i++) {
        printf("\n%d. %s\n", i+1, questions[i].question_text);
        printf("Your answer: ");
        fgets(answer, MAX_ANS_LENGTH, stdin);
        strtok(answer, "\n");

        if(strcmp(answer, questions[i].correct_answer) == 0) {
            printf("Correct!\n");
            total_correct_answers++;
        } else {
            printf("Incorrect! The correct answer is: %s\n", questions[i].correct_answer);
        }
    }

    printf("\n\nTotal Correct Answers: %d / %d\n", total_correct_answers, num_questions);
    printf("Thank you for taking the exam!");
}

int main() {
    // Initialize variables
    int num_questions;
    char student_name[MAX_NAME_LENGTH];
    struct question questions[MAX_QUESTIONS];

    // Display welcome message
    displayWelcomeMsg();

    // Get number of questions from user
    num_questions = getNumQuestions();

    // Get questions from user
    getQuestions(num_questions, questions);

    // Display questions
    displayQuestions(num_questions, questions);

    // Get student name
    getStudentName(student_name);

    // Display exam results
    displayExamResults(num_questions, questions, student_name);

    return 0;
}