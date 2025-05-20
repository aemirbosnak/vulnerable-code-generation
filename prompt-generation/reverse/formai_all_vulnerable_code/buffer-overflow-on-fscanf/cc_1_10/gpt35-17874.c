//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of questions in the exam
#define MAX_QUESTIONS 20
// Max length of a question
#define MAX_Q_LEN 100
// Max number of choices for a question
#define MAX_CHOICES 5
// Max length of a choice
#define MAX_C_LEN 50
// Max length of an answer string
#define MAX_ANS_LEN 10

// Structure for a single question
typedef struct {
    char question[MAX_Q_LEN];
    char choices[MAX_CHOICES][MAX_C_LEN];
    char answer[MAX_ANS_LEN];
} Question;

// Structure for an exam
typedef struct {
    char name[MAX_Q_LEN];
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

// Load an exam from a file
void load_exam(Exam *exam, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file '%s'\n", filename);
        exit(1);
    }

    // Read the exam name
    fgets(exam->name, MAX_Q_LEN, fp);

    // Read the number of questions
    fscanf(fp, "%d\n", &exam->num_questions);

    // Read each question
    for (int i = 0; i < exam->num_questions; i++) {
        fgets(exam->questions[i].question, MAX_Q_LEN, fp);

        // Read each choice
        for (int j = 0; j < MAX_CHOICES; j++) {
            fgets(exam->questions[i].choices[j], MAX_C_LEN, fp);
        }

        // Read the correct answer
        fgets(exam->questions[i].answer, MAX_ANS_LEN, fp);
    }

    fclose(fp);
}

// Display an exam
void display_exam(const Exam *exam) {
    printf("--------------------------------------------------\n");
    printf("              %s\n", exam->name);
    printf("--------------------------------------------------\n\n");

    for (int i = 0; i < exam->num_questions; i++) {
        // Display the question
        printf("%d. %s\n", i+1, exam->questions[i].question);

        // Display the choices
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c) %s", j+'A', exam->questions[i].choices[j]);
        }
        printf("\n");
    }

    printf("--------------------------------------------------\n");
}

// Take an exam
void take_exam(const Exam *exam) {
    char choice[MAX_C_LEN];

    printf("--------------------------------------------------\n");
    printf("              %s\n", exam->name);
    printf("--------------------------------------------------\n\n");

    for (int i = 0; i < exam->num_questions; i++) {
        // Display the question
        printf("%d. %s\n", i+1, exam->questions[i].question);

        // Display the choices
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%c) %s", j+'A', exam->questions[i].choices[j]);
        }
        printf("\n");

        // Get the user's answer
        printf("Answer: ");
        fgets(choice, MAX_C_LEN, stdin);
        choice[strlen(choice)-1] = '\0'; // Remove the newline character

        // Check if the answer is correct
        if (strcmp(exam->questions[i].answer, choice) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s\n", exam->questions[i].answer);
        }

        printf("\n");
    }

    printf("--------------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s exam_file\n", argv[0]);
        exit(1);
    }

    Exam exam;
    load_exam(&exam, argv[1]);

    display_exam(&exam);

    take_exam(&exam);

    return 0;
}