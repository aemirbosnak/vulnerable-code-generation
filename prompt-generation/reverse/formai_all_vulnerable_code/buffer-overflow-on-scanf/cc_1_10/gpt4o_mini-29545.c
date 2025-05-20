//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 10
#define MAX_OPTION_LENGTH 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char question[MAX_OPTION_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    int answer; // index of the correct option
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int score;
} Student;

Student students[MAX_STUDENTS];
Question questions[MAX_QUESTIONS];
int studentCount = 0;
int questionCount = 0;

void add_question() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Maximum question limit reached!\n");
        return;
    }
    printf("Enter question: ");
    getchar(); // clear newline character
    fgets(questions[questionCount].question, MAX_OPTION_LENGTH, stdin);
    questions[questionCount].question[strcspn(questions[questionCount].question, "\n")] = 0;

    for(int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(questions[questionCount].options[i], MAX_OPTION_LENGTH, stdin);
        questions[questionCount].options[i][strcspn(questions[questionCount].options[i], "\n")] = 0;
    }

    printf("Enter the correct option (1-4): ");
    scanf("%d", &(questions[questionCount].answer));
    questionCount++;
}

void register_student() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    printf("Enter student name: ");
    getchar();
    fgets(students[studentCount].name, MAX_NAME_LENGTH, stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;

    students[studentCount].id = studentCount + 1; // Assign ID incrementally
    students[studentCount].score = 0;

    studentCount++;
}

void conduct_exam() {
    if (questionCount == 0) {
        printf("No questions available in the system!\n");
        return;
    }
    printf("Conducting Exam. Select your student ID: ");
    int id;
    scanf("%d", &id);
    
    if (id < 1 || id > studentCount) {
        printf("Invalid student ID!\n");
        return;
    }

    printf("Starting exam for %s...\n", students[id - 1].name);
    for (int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            students[id - 1].score++;
        }
    }

    printf("%s's final score: %d/%d\n", students[id - 1].name, students[id - 1].score, questionCount);
}

void view_results() {
    printf("Results:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Student: %s, ID: %d, Score: %d/%d\n", students[i].name, students[i].id, students[i].score, questionCount);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\nOnline Examination System\n");
        printf("1. Register Student\n");
        printf("2. Add Question\n");
        printf("3. Conduct Exam\n");
        printf("4. View Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                register_student();
                break;
            case 2:
                add_question();
                break;
            case 3:
                conduct_exam();
                break;
            case 4:
                view_results();
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