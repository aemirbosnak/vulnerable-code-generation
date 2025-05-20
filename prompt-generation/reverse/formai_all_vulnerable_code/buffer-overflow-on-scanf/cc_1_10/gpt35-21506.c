//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 50
#define MAX_ANSWERS 4
#define MAX_NAME_LENGTH 20

/* Struct for a single question */
typedef struct {
    char prompt[255];
    char answers[MAX_ANSWERS][255];
    int correct_answer;
} Question;

/* Global variables */
Question questions[MAX_QUESTIONS];
int num_questions = 0;
int total_points = 0;

/* Function prototypes */
void add_question();
void take_exam();

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];

    printf("Welcome to the C Online Examination System\n");

    /* Get student name */
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);

    /* Main menu */
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a question\n");
        printf("2. Take the exam\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                take_exam();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Function to add a question */
void add_question() {
    if (num_questions >= MAX_QUESTIONS) {
        printf("Sorry, but you have reached the maximum number of questions.\n");
        return;
    }

    Question q;

    /* Get prompt */
    printf("Enter the prompt for the question: ");
    getchar();
    fgets(q.prompt, 255, stdin);

    /* Get answers */
    printf("Enter the four possible answers:\n");
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. ", i + 1);
        fgets(q.answers[i], 255, stdin);
        if (q.answers[i][strlen(q.answers[i]) - 1] == '\n')
            q.answers[i][strlen(q.answers[i]) - 1] = '\0';
    }

    /* Get correct answer */
    printf("Which answer is correct (1-4)? ");
    scanf("%d", &q.correct_answer);
    q.correct_answer--;

    /* Add question to array */
    questions[num_questions++] = q;

    printf("Question added successfully!\n");
}

/* Function to take the exam */
void take_exam() {
    int points = 0;

    printf("\nYou will be presented with %d questions.\n", num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d/%d\n", i + 1, num_questions);
        printf("%s\n", questions[i].prompt);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice - 1 == questions[i].correct_answer) {
            printf("Correct!\n");
            points++;
        }
        else {
            printf("Incorrect!\n");
        }
    }

    printf("\nYou scored %d/%d on the exam.\n", points, num_questions);
    total_points += points;

    /* Determine if the student passed or failed */
    if (points >= (num_questions / 2)) {
        printf("Congratulations, you passed!\n");
    }
    else {
        printf("Sorry, you failed. Please study more and try again later.\n");
    }

    /* Ask if the student wants to retake the exam */
    char choice;
    printf("Would you like to retake the exam (y/n)? ");
    getchar();
    scanf("%c", &choice);
    if (tolower(choice) == 'y') {
        take_exam();
    }

    /* Print total score if the student is done taking the exam */
    printf("Your total score is %d/%d.\n", total_points, (num_questions * 5));
}