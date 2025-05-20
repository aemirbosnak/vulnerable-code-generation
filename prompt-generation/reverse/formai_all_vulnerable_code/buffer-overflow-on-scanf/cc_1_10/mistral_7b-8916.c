//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures and constants
typedef struct {
    char name[50];
    int score;
} Student;

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10

// Global variables
Student students[MAX_STUDENTS];
int num_students = 0;
int questions[MAX_QUESTIONS][2];
int num_questions = 0;

// Function prototypes
void register_student();
void ask_question();
void display_results();

// Main function
int main() {
    srand(time(NULL));

    while (1) {
        int choice;
        printf("\n--- ONLINE EXAMINATION SYSTEM ---\n");
        printf("1. Register as student\n");
        printf("2. Ask question\n");
        printf("3. Display results\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_student();
                break;
            case 2:
                ask_question();
                break;
            case 3:
                display_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to register a new student
void register_student() {
    if (num_students >= MAX_STUDENTS) {
        printf("Maximum number of students reached. Please try again later.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", students[num_students].name);
    num_students++;

    printf("Student %s registered successfully.\n", students[num_students - 1].name);
}

// Function to ask a question
void ask_question() {
    if (num_questions >= MAX_QUESTIONS) {
        printf("Maximum number of questions reached. Please try again later.\n");
        return;
    }

    int question_number = rand() % 10 + 1;
    int answer;

    printf("Question %d:\n", question_number);
    printf("Which programming language was used to write this program?\n");
    printf("1. Java\n");
    printf("2. C\n");
    printf("3. Python\n");
    printf("Enter your answer (1, 2 or 3): ");
    scanf("%d", &answer);

    if (answer == 2) {
        printf("Correct answer! You have gained 5 points.\n");
        students[num_students - 1].score += 5;
    } else {
        printf("Incorrect answer. Better luck next time.\n");
    }

    questions[num_questions][0] = question_number;
    questions[num_questions][1] = answer;
    num_questions++;
}

// Function to display results
void display_results() {
    if (num_students == 0) {
        printf("No students have registered yet.\n");
        return;
    }

    printf("\n--- RESULTS ---\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d points\n", students[i].name, students[i].score);
    }
}