//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
/*
 * A unique C Online Examination System program in the style of Donald Knuth
 *
 * This program is a simple example of an online examination system that
 * demonstrates the use of arrays, pointers, and functions in C programming.
 *
 * The program is designed to simulate an online examination system where a
 * student can take an exam and see their results. The program will ask the
 * student to enter their name and ID, then it will generate a random number
 * of questions and answers for the exam. The student will then be asked to
 * answer the questions and the program will check their answers and provide
 * feedback.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions and answers
#define NUM_QUESTIONS 10
#define NUM_ANSWERS 4

// Define the structure for the questions and answers
struct Question {
    char question[100];
    char answers[NUM_ANSWERS][100];
    char correct_answer[100];
};

// Define the structure for the student's exam
struct Exam {
    char name[100];
    int id;
    int score;
    struct Question questions[NUM_QUESTIONS];
};

// Function to generate a random integer between a range
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random string of characters
void rand_string(char *str, int len) {
    for (int i = 0; i < len; i++) {
        str[i] = rand_int('a', 'z');
    }
}

// Function to create a new exam
struct Exam create_exam(char *name, int id) {
    struct Exam exam;
    strcpy(exam.name, name);
    exam.id = id;
    exam.score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        rand_string(exam.questions[i].question, 100);
        for (int j = 0; j < NUM_ANSWERS; j++) {
            rand_string(exam.questions[i].answers[j], 100);
        }
        rand_string(exam.questions[i].correct_answer, 100);
    }
    return exam;
}

// Function to display the exam
void display_exam(struct Exam *exam) {
    printf("Exam for %s (ID: %d)\n", exam->name, exam->id);
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < NUM_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].answers[j]);
        }
        printf("Enter your answer: ");
        char answer[100];
        scanf("%s", answer);
        if (strcmp(answer, exam->questions[i].correct_answer) == 0) {
            exam->score++;
        }
    }
    printf("Your score: %d/%d\n", exam->score, NUM_QUESTIONS);
}

// Function to generate the exam
struct Exam generate_exam(char *name, int id) {
    srand(time(NULL));
    struct Exam exam = create_exam(name, id);
    display_exam(&exam);
    return exam;
}

// Main function
int main() {
    char name[100];
    int id;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your ID: ");
    scanf("%d", &id);
    generate_exam(name, id);
    return 0;
}