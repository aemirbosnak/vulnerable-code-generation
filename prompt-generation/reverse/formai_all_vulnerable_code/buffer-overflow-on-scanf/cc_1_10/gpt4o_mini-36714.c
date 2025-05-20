//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][100];
    int answerIndex; // The index of the correct answer
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int totalQuestions = 0;
int totalStudents = 0;

void addQuestion() {
    if (totalQuestions < MAX_QUESTIONS) {
        printf("Enter question: ");
        getchar(); // Clear the newline character from buffer
        fgets(questions[totalQuestions].question, sizeof(questions[totalQuestions].question), stdin);
        questions[totalQuestions].question[strcspn(questions[totalQuestions].question, "\n")] = 0; // Remove newline

        for (int i = 0; i < MAX_OPTIONS; i++) {
            printf("Enter option %d: ", i + 1);
            fgets(questions[totalQuestions].options[i], sizeof(questions[totalQuestions].options[i]), stdin);
            questions[totalQuestions].options[i][strcspn(questions[totalQuestions].options[i], "\n")] = 0; // Remove newline
        }

        printf("Enter the index of the correct option (1-%d): ", MAX_OPTIONS);
        scanf("%d", &questions[totalQuestions].answerIndex);
        questions[totalQuestions].answerIndex--; // Convert to zero-based index
        totalQuestions++;
    } else {
        printf("Cannot add more questions. Maximum limit reached.\n");
    }
}

void conductExam() {
    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    getchar(); // Clear the newline character from buffer
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    int score = 0;
    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);

        if (answer - 1 == questions[i].answerIndex) {
            score++;
        }
    }

    strcpy(students[totalStudents].name, name);
    students[totalStudents].score = score;
    totalStudents++;
    
    printf("Exam finished! Your score is: %d/%d\n", score, totalQuestions);
}

void displayResults() {
    printf("\n===== Exam Results =====\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("Student: %s, Score: %d/%d\n", students[i].name, students[i].score, totalQuestions);
    }
}

int main() {
    int choice;
    do {
        printf("\n===== Online Examination System =====\n");
        printf("1. Add Question\n");
        printf("2. Conduct Exam\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion();
                break;
            case 2:
                conductExam();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}