//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_STUDENTS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4

typedef struct {
    char name[50];
    int roll_no;
    int marks;
} Student;

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int correct_answer;
} Question;

int main() {
    int num_students, num_questions;
    char ch;
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    // Read student details
    for (int i = 0; i < num_students; i++) {
        printf("Student %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll no.: ");
        scanf("%d", &students[i].roll_no);
    }

    // Read question details
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d details:\n", i + 1);
        printf("Question: ");
        scanf("%s", questions[i].question);
        printf("Enter number of options: ");
        scanf("%d", &questions[i].correct_answer);
        for (int j = 0; j < questions[i].correct_answer; j++) {
            printf("Option %d: ", j + 1);
            scanf("%s", questions[i].options[j]);
        }
    }

    // Shuffle questions and options
    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < questions[i].correct_answer; j++) {
            int rand_index = rand() % questions[i].correct_answer;
            char temp_option[50];
            strcpy(temp_option, questions[i].options[j]);
            strcpy(questions[i].options[j], questions[i].options[rand_index]);
            strcpy(questions[i].options[rand_index], temp_option);
        }
    }

    // Print questions for each student
    for (int i = 0; i < num_students; i++) {
        printf("Questions for %s:\n", students[i].name);
        for (int j = 0; j < num_questions; j++) {
            printf("%s\n", questions[j].question);
            for (int k = 0; k < questions[j].correct_answer; k++) {
                printf("%d. %s\n", k + 1, questions[j].options[k]);
            }
        }
    }

    return 0;
}