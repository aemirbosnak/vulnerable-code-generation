//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_LENGTH 100
#define MAX_STUDENTS 50

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    int answer; // index of the correct option (0-based)
} Question;

typedef struct {
    char name[MAX_LENGTH];
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
    Question q;
    printf("Enter the question: ");
    getchar(); // consume the newline character
    fgets(q.question, sizeof(q.question), stdin);
    q.question[strcspn(q.question, "\n")] = 0; // remove newline

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(q.options[i], sizeof(q.options[i]), stdin);
        q.options[i][strcspn(q.options[i], "\n")] = 0; // remove newline
    }

    printf("Enter the correct option number (1-%d): ", MAX_OPTIONS);
    scanf("%d", &q.answer);
    q.answer--; // convert to 0-based index

    questions[questionCount++] = q;
    printf("Question added successfully!\n");
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    Student s;
    printf("Enter student name: ");
    getchar(); // consume the newline character
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // remove newline
    s.score = 0;

    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

void conductExam() {
    if (studentCount == 0 || questionCount == 0) {
        printf("No students or questions available.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("Starting exam for %s\n", students[i].name);
        for (int j = 0; j < questionCount; j++) {
            printf("Q%d: %s\n", j + 1, questions[j].question);
            for (int k = 0; k < MAX_OPTIONS; k++) {
                printf("   %d. %s\n", k + 1, questions[j].options[k]);
            }
            int answer;
            printf("Your answer (1-%d): ", MAX_OPTIONS);
            scanf("%d", &answer);
            if (answer - 1 == questions[j].answer) {
                students[i].score++;
            }
        }
        printf("Exam finished. %s scored: %d/%d\n", students[i].name, students[i].score, questionCount);
    }
}

void saveResults() {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        printf("Error opening file to save results.\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "Student: %s, Score: %d/%d\n", students[i].name, students[i].score, questionCount);
    }
    fclose(file);
    printf("Results saved to results.txt\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Add Question\n");
        printf("2. Add Student\n");
        printf("3. Conduct Exam\n");
        printf("4. Save Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addQuestion();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            conductExam();
            break;
        case 4:
            saveResults();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}