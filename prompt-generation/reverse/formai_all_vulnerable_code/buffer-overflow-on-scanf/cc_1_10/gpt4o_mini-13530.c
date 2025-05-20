//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 5
#define MAX_LEN 50

typedef struct {
    char question[MAX_LEN];
    char options[4][MAX_LEN];
    char answer;
} Question;

typedef struct {
    char name[MAX_LEN];
    int id;
    int score;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"A) London", "B) Paris", "C) Rome", "D) Berlin"}, 'B'},
    {"Which language is primarily spoken in Brazil?", {"A) Spanish", "B) Portuguese", "C) English", "D) French"}, 'B'},
    {"What is 2 + 2?", {"A) 3", "B) 4", "C) 2", "D) 5"}, 'B'},
    {"What is the boiling point of water?", {"A) 100°C", "B) 90°C", "C) 80°C", "D) 70°C"}, 'A'},
    {"Which planet is known as the Red Planet?", {"A) Earth", "B) Mars", "C) Jupiter", "D) Saturn"}, 'B'}
};

void registerStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Registration is full.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[student_count].name);
    students[student_count].id = student_count + 1; // Assign a unique ID
    students[student_count].score = 0; // Initialize score to zero
    student_count++;
    printf("Registration successful! Your ID is: %d\n", students[student_count - 1].id);
}

void takeExam(int student_id) {
    char answer;
    int score = 0;

    printf("\nStarting Exam...\n");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &answer);  // Space before %c to consume newline character

        if (answer == questions[i].answer) {
            score++;
        }
    }

    students[student_id - 1].score = score;
    printf("Exam completed! Your score is: %d out of %d\n", score, MAX_QUESTIONS);
}

void viewResults(int student_id) {
    printf("Student Name: %s\n", students[student_id - 1].name);
    printf("Your Score: %d out of %d\n", students[student_id - 1].score, MAX_QUESTIONS);
}

int main() {
    int choice, student_id;

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Register\n");
        printf("2. Take Exam\n");
        printf("3. View Result\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                printf("Enter your student ID: ");
                scanf("%d", &student_id);
                if (student_id > 0 && student_id <= student_count) {
                    takeExam(student_id);
                } else {
                    printf("Invalid student ID.\n");
                }
                break;
            case 3:
                printf("Enter your student ID: ");
                scanf("%d", &student_id);
                if (student_id > 0 && student_id <= student_count) {
                    viewResults(student_id);
                } else {
                    printf("Invalid student ID.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}