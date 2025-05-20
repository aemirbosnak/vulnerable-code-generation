//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} student_t;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[MAX_CHOICES][MAX_ANSWER_LENGTH];
    int correct_choice;
} question_t;

void read_questions(question_t questions[]) {
    FILE *fp = fopen("questions.txt", "r");
    int i = 0;

    while (fscanf(fp, "%s\n", questions[i].question)!= EOF) {
        fscanf(fp, "%d\n", &questions[i].correct_choice);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fscanf(fp, "%s\n", questions[i].choices[j]);
        }
        i++;
    }

    fclose(fp);
}

void read_students(student_t students[]) {
    FILE *fp = fopen("students.txt", "r");
    int i = 0;

    while (fscanf(fp, "%s\n", students[i].name)!= EOF) {
        i++;
    }

    fclose(fp);
}

int main() {
    question_t questions[MAX_QUESTIONS];
    student_t students[MAX_STUDENTS];

    read_questions(questions);
    read_students(students);

    int num_students = 0;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    if (num_students > MAX_STUDENTS) {
        printf("Error: too many students.\n");
        return 1;
    }

    int num_correct_answers[MAX_STUDENTS];
    memset(num_correct_answers, 0, sizeof(num_correct_answers));

    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
    }

    for (int i = 0; i < num_students; i++) {
        printf("Student %s's score: %d\n", students[i].name, num_correct_answers[i]);
    }

    return 0;
}