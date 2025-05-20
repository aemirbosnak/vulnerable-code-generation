//FormAI DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data Structures for Examination System
struct question_t {
    char question[1000];
    char options[4][100];
    char correct_answer;
};

struct student_t {
    char name[100];
    int score;
};

// Function to load questions from file
void load_questions(struct question_t *questions, int num_questions, char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    for (int i=0; i<num_questions; i++) {
        fgets(questions[i].question, 1000, fp);
        for (int j=0; j<4; j++) {
            fgets(questions[i].options[j], 100, fp);
        }
        fscanf(fp, "%c\n", &questions[i].correct_answer);
    }
    fclose(fp);
}

// Function to display question and options
void display_question(struct question_t question) {
    printf("%s\n", question.question);
    for (int i=0; i<4; i++) {
        printf("%c) %s", 'A'+i, question.options[i]);
    }
}

// Function to get user's answer from input
char get_user_answer() {
    char answer;
    printf("Your answer (A/B/C/D): ");
    scanf("%c", &answer);
    getchar();
    return answer;
}

// Function to check user's answer
bool check_answer(struct question_t question, char user_answer) {
    return (toupper(question.correct_answer) == toupper(user_answer));
}

// Function to start exam
void start_exam(struct question_t *questions, int num_questions) {
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    char name[100];
    scanf("%s", name);
    struct student_t student;
    strcpy(student.name, name);
    student.score = 0;
    for (int i=0; i<num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        display_question(questions[i]);
        char user_answer = get_user_answer();
        if (check_answer(questions[i], user_answer)) {
            printf("Correct!\n");
            student.score++;
        }
        else {
            printf("Incorrect!\n");
        }
    }
    printf("\n\n%s's final score: %d/%d\n", student.name, student.score, num_questions);
}

// Main function
int main() {
    int num_questions = 5;
    struct question_t questions[num_questions];
    char *filename = "questions.txt";
    load_questions(questions, num_questions, filename);
    start_exam(questions, num_questions);
    return 0;
}