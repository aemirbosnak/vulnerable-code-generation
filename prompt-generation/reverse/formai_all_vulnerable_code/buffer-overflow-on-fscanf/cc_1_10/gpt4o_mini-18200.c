//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_STUDENTS 50
#define QUESTION_LENGTH 256
#define OPTION_LENGTH 128
#define NAME_LENGTH 50

typedef struct {
    char question[QUESTION_LENGTH];
    char options[MAX_OPTIONS][OPTION_LENGTH];
    int answer; // 0-based index for the correct answer
} Question;

typedef struct {
    char name[NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int questionCount = 0;
int studentCount = 0;

void loadQuestions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "\n%[^\n]\n", questions[questionCount].question) != EOF) {
        for (int i = 0; i < MAX_OPTIONS; i++) {
            fscanf(file, "%[^\n]\n", questions[questionCount].options[i]);
        }
        fscanf(file, "%d\n", &questions[questionCount].answer);
        questionCount++;
    }

    fclose(file);
}

void registerStudent() {
    if(studentCount >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", students[studentCount].name);
    students[studentCount].score = 0;
    studentCount++;
}

void conductExam(Student *student) {
    printf("Starting exam for %s...\n", student->name);
    for (int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf(" %c) %s\n", 'A' + j, questions[i].options[j]);
        }
        char answer;
        printf("Your answer: ");
        getchar(); // To consume newline from previous input
        scanf("%c", &answer);
        int index = answer - 'A';
        if (index == questions[i].answer) {
            printf("Correct!\n");
            student->score++;
        } else {
            printf("Wrong! The correct answer was %c\n", 'A' + questions[i].answer);
        }
    }
    printf("Exam completed. Your score: %d/%d\n", student->score, questionCount);
}

void displayScores() {
    printf("\nScores:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

int main() {
    int choice;
    loadQuestions("questions.txt");
    
    do {
        printf("\nOnline Examination System\n");
        printf("1. Register Student\n");
        printf("2. Conduct Exam\n");
        printf("3. Display Scores\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                registerStudent();
                break;
            case 2: {
                if (studentCount > 0) {
                    for (int i = 0; i < studentCount; i++) {
                        conductExam(&students[i]);
                    }
                } else {
                    printf("No students registered.\n");
                }
                break;
            }
            case 3: 
                displayScores();
                break;
            case 4:
                printf("Exiting the system... Bye!\n");
                break;
            default: 
                printf("Invalid option, try again!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}