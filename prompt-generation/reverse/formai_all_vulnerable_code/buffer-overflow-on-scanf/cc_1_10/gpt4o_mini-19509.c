//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char question[256];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;
} Question;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int questionCount = 0;
int studentCount = 0;

void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Cannot add more questions.\n");
        return;
    }
    printf("Enter question ID: ");
    scanf("%d", &questions[questionCount].id);
    printf("Enter question: ");
    getchar(); // to consume newline character
    fgets(questions[questionCount].question, 256, stdin);
    printf("Enter option A: ");
    fgets(questions[questionCount].optionA, 100, stdin);
    printf("Enter option B: ");
    fgets(questions[questionCount].optionB, 100, stdin);
    printf("Enter option C: ");
    fgets(questions[questionCount].optionC, 100, stdin);
    printf("Enter option D: ");
    fgets(questions[questionCount].optionD, 100, stdin);
    printf("Enter correct answer (A/B/C/D): ");
    scanf(" %c", &questions[questionCount].correctAnswer);
    
    questionCount++;
    printf("Question added successfully!\n");
}

void registerStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot register more students.\n");
        return;
    }
    printf("Enter student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter student name: ");
    getchar(); // to consume newline character
    fgets(students[studentCount].name, MAX_NAME_LENGTH, stdin);
    students[studentCount].score = 0;

    studentCount++;
    printf("Student registered successfully!\n");
}

void takeExam(int studentId) {
    int score = 0;
    printf("Exam started for student ID: %d\n", studentId);
    for (int i = 0; i < questionCount; i++) {
        char answer;
        printf("Question %d: %s", questions[i].id, questions[i].question);
        printf("A) %s", questions[i].optionA);
        printf("B) %s", questions[i].optionB);
        printf("C) %s", questions[i].optionC);
        printf("D) %s", questions[i].optionD);
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        if (answer == questions[i].correctAnswer) {
            score++;
        }
    }
    printf("Exam completed! Your score: %d out of %d\n", score, questionCount);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            students[i].score = score;
            break;
        }
    }
}

void viewResults() {
    printf("Results:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Student ID: %d, Name: %s, Score: %d\n", students[i].id, students[i].name, students[i].score);
    }
}

void displayMenu() {
    printf("---- Online Examination System ----\n");
    printf("1. Add Question\n");
    printf("2. Register Student\n");
    printf("3. Take Exam\n");
    printf("4. View Results\n");
    printf("5. Exit\n");
    printf("----------------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                registerStudent();
                break;
            case 3: {
                int studentId;
                printf("Enter student ID: ");
                scanf("%d", &studentId);
                takeExam(studentId);
                break;
            }
            case 4:
                viewResults();
                break;
            case 5:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}