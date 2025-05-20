//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 10
#define MAX_STUDENTS 100

// Structure to store a question
struct question {
    char question[100];
    char answers[MAX_ANSWERS][100];
    int correct_answer;
};

// Structure to store a student's answer
struct student_answer {
    int question_id;
    int answer_id;
    int correct;
};

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// Function to shuffle an array of integers
void shuffle(int *arr, int n) {
    if (n > 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            int j = i + random_int(0, n - i - 1);
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
}

// Function to print a question
void print_question(struct question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i + 1, q->answers[i]);
    }
    printf("Answer: ");
}

// Function to check if a student's answer is correct
int check_answer(struct question *q, struct student_answer *sa) {
    return sa->answer_id == q->correct_answer;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Declare variables
    int i, j;
    struct question questions[MAX_QUESTIONS];
    struct student_answer student_answers[MAX_STUDENTS][MAX_QUESTIONS];
    int num_questions, num_students;

    // Get number of questions and students
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Generate questions
    for (i = 0; i < num_questions; i++) {
        // Generate a random question
        sprintf(questions[i].question, "Question %d", i + 1);
        for (j = 0; j < MAX_ANSWERS; j++) {
            sprintf(questions[i].answers[j], "Answer %d", j + 1);
        }
        questions[i].correct_answer = random_int(0, MAX_ANSWERS - 1);
    }

    // Shuffle questions
    shuffle(questions, num_questions);

    // Generate student answers
    for (i = 0; i < num_students; i++) {
        for (j = 0; j < num_questions; j++) {
            student_answers[i][j].question_id = j;
            student_answers[i][j].answer_id = random_int(0, MAX_ANSWERS - 1);
        }
    }

    // Check student answers
    for (i = 0; i < num_students; i++) {
        for (j = 0; j < num_questions; j++) {
            if (check_answer(&questions[j], &student_answers[i][j])) {
                printf("Student %d, Question %d: Correct\n", i + 1, j + 1);
            } else {
                printf("Student %d, Question %d: Incorrect\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}