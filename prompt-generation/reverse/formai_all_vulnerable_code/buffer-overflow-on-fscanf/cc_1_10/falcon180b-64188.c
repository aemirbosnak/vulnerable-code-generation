//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    int correct_answer;
} question;

void read_questions(question questions[], int num_questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open questions file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", questions[i].question)!= EOF) {
        int num_options = 0;
        while (num_options < MAX_OPTIONS && fscanf(fp, "%s", questions[i].options[num_options])!= EOF) {
            num_options++;
        }
        questions[i].correct_answer = num_options;
        i++;
    }

    fclose(fp);
}

void read_students(student students[], int num_students) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open students file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", students[i].name)!= EOF) {
        i++;
    }

    fclose(fp);
}

int main() {
    question questions[MAX_QUESTIONS];
    student students[MAX_STUDENTS];

    int num_questions, num_students;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    read_questions(questions, num_questions);
    read_students(students, num_students);

    int i, j, k;
    for (i = 0; i < num_questions; i++) {
        for (j = 0; j < num_students; j++) {
            students[j].score = 0;
            printf("\n%s: ", students[j].name);
        }

        printf("\n%s\n", questions[i].question);
        for (k = 0; k < questions[i].correct_answer; k++) {
            printf("%d. %s\n", k+1, questions[i].options[k]);
        }

        int choice;
        scanf("%d", &choice);
        if (choice == questions[i].correct_answer) {
            for (k = 0; k < num_students; k++) {
                if (students[k].name[0] == '\0') {
                    strcpy(students[k].name, "Student");
                }
                students[k].score++;
            }
        }
    }

    printf("\nScores:\n");
    for (i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}