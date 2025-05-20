//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: real-life
/*
 * C Online Examination System
 *
 * A program that allows users to take online exams and track their progress.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 10

// Structure to represent a question
struct question {
    char question[256];
    char answer[256];
};

// Structure to represent a user's answers
struct answers {
    int question_num;
    char answer[256];
};

// Structure to represent a user's results
struct results {
    int score;
    int num_questions;
    int num_correct;
};

// Function to read a question from a file
struct question read_question(FILE *fp) {
    struct question q;
    fscanf(fp, "%s", q.question);
    fscanf(fp, "%s", q.answer);
    return q;
}

// Function to read a user's answers from a file
struct answers read_answers(FILE *fp) {
    struct answers a;
    fscanf(fp, "%d", &a.question_num);
    fscanf(fp, "%s", a.answer);
    return a;
}

// Function to calculate the score for a user
int calculate_score(struct answers *a, struct question *q, int num_questions) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (strcmp(a[i].answer, q[i].answer) == 0) {
            score++;
        }
    }
    return score;
}

// Function to print the results for a user
void print_results(struct results *r) {
    printf("Your score is %d out of %d.\n", r->score, r->num_questions);
    printf("You got %d questions correct.\n", r->num_correct);
}

int main() {
    // Open the question file
    FILE *fp_questions = fopen("questions.txt", "r");
    if (fp_questions == NULL) {
        printf("Error opening questions file.\n");
        return 1;
    }

    // Open the answers file
    FILE *fp_answers = fopen("answers.txt", "r");
    if (fp_answers == NULL) {
        printf("Error opening answers file.\n");
        return 1;
    }

    // Read the questions from the file
    struct question q[MAX_QUESTIONS];
    int num_questions = 0;
    while (!feof(fp_questions)) {
        q[num_questions] = read_question(fp_questions);
        num_questions++;
    }

    // Read the answers from the file
    struct answers a[MAX_ANSWERS];
    int num_answers = 0;
    while (!feof(fp_answers)) {
        a[num_answers] = read_answers(fp_answers);
        num_answers++;
    }

    // Calculate the score
    struct results r;
    r.score = calculate_score(a, q, num_questions);
    r.num_questions = num_questions;
    r.num_correct = r.score;

    // Print the results
    print_results(&r);

    // Close the files
    fclose(fp_questions);
    fclose(fp_answers);

    return 0;
}