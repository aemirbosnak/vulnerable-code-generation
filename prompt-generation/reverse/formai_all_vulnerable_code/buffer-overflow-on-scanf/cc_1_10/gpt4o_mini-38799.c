//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 50
#define MAX_ANSWER_LENGTH 256

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[4][MAX_ANSWER_LENGTH];
    char correctAnswer;
} Question;

typedef struct {
    int id;
    char name[50];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int totalQuestions = 0;
int totalStudents = 0;

void addQuestion();
void takeExam();
void viewResults();
void calculateStatistics();
void clearInputBuffer();

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Online Examination System ---\n");
        printf("1. Add Question\n");
        printf("2. Take Exam\n");
        printf("3. View Results\n");
        printf("4. Calculate Statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                takeExam();
                break;
            case 3:
                viewResults();
                break;
            case 4:
                calculateStatistics();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void addQuestion() {
    if (totalQuestions >= MAX_QUESTIONS) {
        printf("Maximum question limit reached!\n");
        return;
    }
    
    Question q;
    printf("Enter the question: ");
    fgets(q.question, MAX_ANSWER_LENGTH, stdin);
    
    printf("Enter option A: ");
    fgets(q.options[0], MAX_ANSWER_LENGTH, stdin);
    printf("Enter option B: ");
    fgets(q.options[1], MAX_ANSWER_LENGTH, stdin);
    printf("Enter option C: ");
    fgets(q.options[2], MAX_ANSWER_LENGTH, stdin);
    printf("Enter option D: ");
    fgets(q.options[3], MAX_ANSWER_LENGTH, stdin);
    
    printf("Enter the correct answer (A/B/C/D): ");
    scanf(" %c", &q.correctAnswer);
    clearInputBuffer();

    questions[totalQuestions++] = q;
    printf("Question added successfully!\n");
}

void takeExam() {
    if (totalQuestions == 0) {
        printf("No questions available. Please add questions first.\n");
        return;
    }
    
    Student s;
    s.score = 0;

    printf("Enter your Student ID: ");
    scanf("%d", &s.id);
    clearInputBuffer();
    
    printf("Enter your name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline character
    
    printf("\n--- Exam Start ---\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s", i + 1, questions[i].question);
        printf("A: %s", questions[i].options[0]);
        printf("B: %s", questions[i].options[1]);
        printf("C: %s", questions[i].options[2]);
        printf("D: %s", questions[i].options[3]);
        printf("Your answer: ");
        
        char answer;
        scanf(" %c", &answer);
        clearInputBuffer();
        
        if (answer == questions[i].correctAnswer) {
            s.score++;
        }
    }
    
    students[totalStudents++] = s;
    printf("Exam completed! Your score: %d/%d\n", s.score, totalQuestions);
}

void viewResults() {
    if (totalStudents == 0) {
        printf("No results available. Please take the exam first.\n");
        return;
    }
    
    printf("\n--- Exam Results ---\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("ID: %d, Name: %s, Score: %d/%d\n", 
                students[i].id, students[i].name, students[i].score, totalQuestions);
    }
}

void calculateStatistics() {
    if (totalStudents == 0) {
        printf("No results available to calculate statistics.\n");
        return;
    }

    int totalScore = 0;
    for (int i = 0; i < totalStudents; i++) {
        totalScore += students[i].score;
    }
    
    float averageScore = (float)totalScore / totalStudents;
    
    printf("Total Students: %d\n", totalStudents);
    printf("Average Score: %.2f\n", averageScore);
}