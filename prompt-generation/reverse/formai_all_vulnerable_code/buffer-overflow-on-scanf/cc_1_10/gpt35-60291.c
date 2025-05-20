//FormAI DATASET v1.0 Category: Online Examination System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWER_CHOICE 4
#define MAX_NAME_LENGTH 50

// Structures

typedef struct {
    char question[1000];
    char choices[MAX_ANSWER_CHOICE][1000];
    int answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Question questions[MAX_QUESTIONS];
} Exam;

// Function prototypes

int startMenu();
void createExam(Exam *exam);
void listExams(Exam *exams, int numExams);
int takeExam(Exam *exam);

// Main function

int main() {

    int choice;
    int numExams = 0;
    Exam exams[10];

    do {
        choice = startMenu();

        switch (choice) {
            case 1:
                createExam(&exams[numExams]);
                numExams++;
                break;
            case 2:
                listExams(exams, numExams);
                break;
            case 3:
                if (numExams == 0) {
                    printf("No exams available\n");
                } else {
                    int examChoice;
                    do {
                        printf("Which exam would you like to take? ");
                        scanf("%d", &examChoice);
                    } while (examChoice < 1 || examChoice > numExams);
                    int score = takeExam(&exams[examChoice-1]);
                    printf("Your score is %d/%d\n", score, MAX_QUESTIONS);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}

// Functions

int startMenu() {
    int choice;
    printf("\n1. Create an exam\n");
    printf("2. List exams\n");
    printf("3. Take an exam\n");
    printf("4. Quit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

void createExam(Exam *exam) {
    printf("\nEnter exam name: ");
    scanf("%s", exam->name);

    for (int i=0; i<MAX_QUESTIONS; i++) {
        printf("\nEnter question %d: ", i+1);
        scanf("%s", exam->questions[i].question);

        for (int j=0; j<MAX_ANSWER_CHOICE; j++) {
            printf("Enter choice %d: ", j+1);
            scanf("%s", exam->questions[i].choices[j]);
        }

        printf("Enter answer (1-%d): ", MAX_ANSWER_CHOICE);
        scanf("%d", &exam->questions[i].answer);

        // Decrement answer since arrays are indexed starting at 0
        exam->questions[i].answer--;
    }
}

void listExams(Exam *exams, int numExams) {
    if (numExams == 0) {
        printf("\nNo exams available\n");
    } else {
        printf("\n");
        for (int i=0; i<numExams; i++) {
            printf("%d. %s\n", i+1, exams[i].name);
        }
    }
}

int takeExam(Exam *exam) {
    int score = 0;
    printf("\nWelcome to the %s exam!\n", exam->name);

    for (int i=0; i<MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i+1, exam->questions[i].question);

        for (int j=0; j<MAX_ANSWER_CHOICE; j++) {
            printf("    %c: %s\n", 'A'+j, exam->questions[i].choices[j]);
        }

        char answer;
        do {
            printf("Enter your answer (A-D): ");
            scanf(" %c", &answer);
            answer = toupper(answer);

            if (answer < 'A' || answer > 'D') {
                printf("Invalid answer. Please enter A, B, C, or D.\n");
            }

        } while (answer < 'A' || answer > 'D');

        // Decrement answer since arrays are indexed starting at 0
        int userAnswer = answer - 'A';

        if (userAnswer == exam->questions[i].answer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %c.\n", 'A'+exam->questions[i].answer);
        }
    }

    return score;
}