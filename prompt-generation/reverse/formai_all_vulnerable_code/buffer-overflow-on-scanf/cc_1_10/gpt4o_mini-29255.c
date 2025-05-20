//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 5
#define MAX_OPTION 4

typedef struct {
    char question[256];
    char options[MAX_OPTION][256];
    int answer;
} Question;

typedef struct {
    char name[50];
    char username[50];
    char password[50];
    int score;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Lisbon"}, 2},
    {"What is 2 + 2?", {"3", "4", "5", "6"}, 1},
    {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 1},
    {"What is the largest ocean on Earth?", {"Atlantic", "Indian", "Arctic", "Pacific"}, 3},
    {"Who wrote 'Romeo and Juliet'?", {"Mark Twain", "William Shakespeare", "Charles Dickens", "J.K. Rowling"}, 1}
};

void registerStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached. Cannot register more students.\n");
        return;
    }

    Student newStudent;
    printf("Enter name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter username: ");
    scanf("%s", newStudent.username);
    printf("Enter password: ");
    scanf("%s", newStudent.password);
    newStudent.score = 0;

    students[studentCount++] = newStudent;
    printf("Registration successful! Welcome, %s!\n", newStudent.name);
}

int loginStudent(Student *loggedInStudent) {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].username, username) == 0 && strcmp(students[i].password, password) == 0) {
            *loggedInStudent = students[i];
            return 1;
        }
    }
    printf("Invalid username or password!\n");
    return 0;
}

void takeExam(Student *student) {
    printf("Hello, %s! Let's start the exam!\n", student->name);
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTION; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-%d): ", MAX_OPTION);
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            student->score++;
        }
    }
    printf("\nExam finished! Your score: %d/%d\n", student->score, MAX_QUESTIONS);
}

void viewResults(Student *student) {
    printf("\nResults for %s:\n", student->name);
    printf("Score: %d/%d\n", student->score, MAX_QUESTIONS);
}

int main() {
    int choice;
    printf("Welcome to the Online Examination System!\n");

    while (1) {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2: {
                Student loggedInStudent;
                if (loginStudent(&loggedInStudent)) {
                    takeExam(&loggedInStudent);
                    viewResults(&loggedInStudent);
                }
                break;
            }
            case 3:
                printf("Thank you for using the Online Examination System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}