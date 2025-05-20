//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_ANSWERS 10

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int answer;
} Question;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];

int main() {
    int num_questions, num_students, i, j, k;
    char filename[50];
    FILE *fp;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the number of options: ");
        scanf("%d", &questions[i].answer);

        for (j = 0; j < questions[i].answer; j++) {
            printf("Enter option %d: ", j+1);
            scanf("%s", questions[i].options[j]);
        }
    }

    printf("Enter the filename for the student answers: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (i = 0; i < num_students; i++) {
        fscanf(fp, "%s", students[i].name);

        for (j = 0; j < num_questions; j++) {
            fscanf(fp, "%d", &students[i].score + j * MAX_ANSWERS);
        }
    }

    fclose(fp);

    for (i = 0; i < num_students; i++) {
        printf("\nStudent: %s\n", students[i].name);

        for (j = 0; j < num_questions; j++) {
            printf("Question %d: %d/%d\n", j+1, students[i].score + j * MAX_ANSWERS, questions[j].answer);
        }
    }

    return 0;
}