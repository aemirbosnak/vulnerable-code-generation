//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100
#define MAX_SCORE 100

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[200];
    char options[MAX_OPTIONS][50];
    char answers[MAX_ANSWERS][50];
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];

void load_questions() {
    FILE *fp;
    char filename[50];
    int i = 0;

    for (i = 0; i < MAX_QUESTIONS; i++) {
        sprintf(filename, "question_%d.txt", i + 1);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            break;
        }

        fscanf(fp, "%s", questions[i].question);
        int j = 0;
        while (fscanf(fp, "%s", questions[i].options[j])!= EOF) {
            j++;
        }
        questions[i].correct_answer = j - 1; // 0-indexed
        fclose(fp);
    }
}

void load_students() {
    FILE *fp;
    char filename[50];
    int i = 0;

    sprintf(filename, "students.txt");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: No students found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", students[i].name, &students[i].score)!= EOF) {
        i++;
    }

    fclose(fp);
}

void take_exam() {
    int i, j, k, l;
    char answer[50];

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        scanf("%s", answer);
        l = strlen(answer) - 1;
        answer[l] = '\0'; // remove newline character

        for (k = 0; k < MAX_ANSWERS; k++) {
            if (strcmp(answer, questions[i].answers[k]) == 0) {
                students[k].score += (questions[i].correct_answer == k)? 1 : 0;
                break;
            }
        }
    }

    printf("\nExam results:\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

int main() {
    load_questions();
    load_students();
    take_exam();

    return 0;
}