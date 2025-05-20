//FormAI DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_CHOICES 4
#define MAX_NAME_LENGTH 20

int score = 0;

struct question {
    char q[256];
    char choices[MAX_CHOICES][256];
    int correct_choice;
} questions[MAX_QUESTIONS];

void read_questions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[256];
    int current_question = 0, current_choice = 0;
    int correct_choice = -1;
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '#') {
            if (current_choice != 0) {
                questions[current_question].correct_choice = correct_choice;
                correct_choice = -1;
            }
            current_question++;
            current_choice = 0;
            strcpy(questions[current_question].q, line + 1);
        } else if (line[0] == '*') {
            correct_choice = current_choice;
            strcpy(questions[current_question].choices[current_choice++], line + 1);
        } else {
            strcpy(questions[current_question].choices[current_choice++], line);
        }
    }
    questions[current_question].correct_choice = correct_choice;
    fclose(fp);
}

void ask_question(int question_number) {
    printf("%s\n", questions[question_number].q);
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%c) %s", 'A' + i, questions[question_number].choices[i]);
    }
    printf("Your answer: ");
    char choice;
    scanf(" %c", &choice);
    if (choice >= 'A' && choice < 'A' + MAX_CHOICES) {
        if (choice - 'A' == questions[question_number].correct_choice) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong!\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s, to the online exam!\n", name);
    read_questions();
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        ask_question(i);
    }
    printf("Your final score is %d/%d.\n", score, MAX_QUESTIONS);
    return 0;
}