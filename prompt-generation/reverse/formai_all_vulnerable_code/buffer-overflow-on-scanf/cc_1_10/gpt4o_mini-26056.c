//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10
#define MAX_QUESTION_LENGTH 100
#define MAX_OPTIONS 4

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[MAX_OPTIONS][MAX_QUESTION_LENGTH];
    int answer; // Index of correct answer (0-based)
} Question;

typedef struct {
    char name[50];
    int age;
    int student_id;
} Student;

typedef struct {
    char title[50];
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

Student students[MAX_STUDENTS];
int student_count = 0;

Exam exam;

void register_student() {
    if (student_count < MAX_STUDENTS) {
        printf("Registering Student:\n");
        printf("Enter Name: ");
        scanf("%s", students[student_count].name);
        printf("Enter Age: ");
        scanf("%d", &students[student_count].age);
        students[student_count].student_id = student_count + 1; // simple ID allocation
        student_count++;
        printf("Student Registered. ID: %d\n", students[student_count - 1].student_id);
    } else {
        printf("Maximum student limit reached!\n");
    }
}

void create_exam() {
    printf("Creating Exam:\n");
    printf("Enter Exam Title: ");
    scanf("%s", exam.title);
    printf("Enter Number of Questions: ");
    scanf("%d", &exam.num_questions);

    for (int i = 0; i < exam.num_questions; i++) {
        printf("Enter Question %d: ", i + 1);
        scanf(" %[^\n]", exam.questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter Option %d: ", j + 1);
            scanf(" %[^\n]", exam.questions[i].options[j]);
        }
        printf("Enter the index of correct answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &exam.questions[i].answer);
        exam.questions[i].answer--; // Convert to 0-based index
    }
    printf("Exam Created: %s\n", exam.title);
}

void take_exam() {
    if (exam.num_questions > 0) {
        printf("Taking Exam: %s\n", exam.title);
        int score = 0;
        int answer;

        for (int i = 0; i < exam.num_questions; i++) {
            printf("Question %d: %s\n", i + 1, exam.questions[i].question);
            for (int j = 0; j < MAX_OPTIONS; j++) {
                printf("Option %d: %s\n", j + 1, exam.questions[i].options[j]);
            }
            printf("Your answer (1-%d): ", MAX_OPTIONS);
            scanf("%d", &answer);
            if (answer - 1 == exam.questions[i].answer) {
                score++;
            }
            printf("\n");
        }
        printf("Your score: %d/%d\n", score, exam.num_questions);
    } else {
        printf("No exam created yet!\n");
    }
}

void display_menu() {
    printf("\n--- Online Examination System ---\n");
    printf("1. Register Student\n");
    printf("2. Create Exam\n");
    printf("3. Take Exam\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_student();
                break;
            case 2:
                create_exam();
                break;
            case 3:
                take_exam();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}