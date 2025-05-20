//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_EXAMS 5
#define MAX_NAME_LEN 50

typedef struct {
    char question[255];
    char options[MAX_OPTIONS][100];
    int correctOption;
} Question;

typedef struct {
    char examName[MAX_NAME_LEN];
    Question questions[MAX_QUESTIONS];
    int numQuestions;
} Exam;

typedef struct {
    char name[MAX_NAME_LEN];
    int scores[MAX_EXAMS];
} Student;

Exam exams[MAX_EXAMS];
int examCount = 0;

void createExam() {
    if (examCount >= MAX_EXAMS) {
        printf("Maximum exam limit reached.\n");
        return;
    }
    
    Exam newExam;
    printf("Enter exam name: ");
    scanf(" %[^\n]", newExam.examName);
    printf("Enter number of questions: ");
    scanf("%d", &newExam.numQuestions);
    
    for (int i = 0; i < newExam.numQuestions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf(" %[^\n]", newExam.questions[i].question);
        
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d: ", j + 1);
            scanf(" %[^\n]", newExam.questions[i].options[j]);
        }
        printf("Enter correct option (1-%d): ", MAX_OPTIONS);
        scanf("%d", &newExam.questions[i].correctOption);
    }

    exams[examCount++] = newExam;
    printf("Exam created successfully!\n");
}

void takeExam(Student *student) {
    if (examCount == 0) {
        printf("No exams available.\n");
        return;
    }

    printf("Available Exams:\n");
    for (int i = 0; i < examCount; i++) {
        printf("%d. %s\n", i + 1, exams[i].examName);
    }
    
    int choice;
    printf("Select exam number (1-%d): ", examCount);
    scanf("%d", &choice);
    choice--; // adjust for zero-based index

    if (choice < 0 || choice >= examCount) {
        printf("Invalid choice.\n");
        return;
    }

    int score = 0;
    for (int i = 0; i < exams[choice].numQuestions; i++) {
        printf("%s\n", exams[choice].questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, exams[choice].questions[i].options[j]);
        }
        
        int answer;
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        
        if (answer == exams[choice].questions[i].correctOption) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer was option %d.\n", exams[choice].questions[i].correctOption);
        }
    }

    student->scores[choice] = score;
    printf("Your score for exam '%s': %d/%d\n", exams[choice].examName, score, exams[choice].numQuestions);
}

void viewResults(Student *student) {
    printf("Results:\n");
    for (int i = 0; i < examCount; i++) {
        printf("Exam '%s': Score: %d\n", exams[i].examName, student->scores[i]);
    }
}

int main() {
    Student student;
    memset(&student, 0, sizeof(Student)); // initialize scores to 0

    int option;
    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Create Exam\n");
        printf("2. Take Exam\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createExam();
                break;
            case 2:
                takeExam(&student);
                break;
            case 3:
                viewResults(&student);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}