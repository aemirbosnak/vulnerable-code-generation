//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer1[MAX_ANSWER_LENGTH];
    char answer2[MAX_ANSWER_LENGTH];
    char answer3[MAX_ANSWER_LENGTH];
    char answer4[MAX_ANSWER_LENGTH];
    char correctAnswer;
} Question;

int main() {
    int numStudents, numQuestions;
    char filename[MAX_NAME_LENGTH];
    FILE *fp;
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        fscanf(fp, "%s", students[i].name);
        students[i].score = 0;
    }

    fclose(fp);

    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d:\n", i+1);
        fgets(questions[i].question, MAX_ANSWER_LENGTH, stdin);
        questions[i].question[strcspn(questions[i].question, "\n")] = '\0';

        printf("Enter answer 1:\n");
        fgets(questions[i].answer1, MAX_ANSWER_LENGTH, stdin);
        questions[i].answer1[strcspn(questions[i].answer1, "\n")] = '\0';

        printf("Enter answer 2:\n");
        fgets(questions[i].answer2, MAX_ANSWER_LENGTH, stdin);
        questions[i].answer2[strcspn(questions[i].answer2, "\n")] = '\0';

        printf("Enter answer 3:\n");
        fgets(questions[i].answer3, MAX_ANSWER_LENGTH, stdin);
        questions[i].answer3[strcspn(questions[i].answer3, "\n")] = '\0';

        printf("Enter answer 4:\n");
        fgets(questions[i].answer4, MAX_ANSWER_LENGTH, stdin);
        questions[i].answer4[strcspn(questions[i].answer4, "\n")] = '\0';

        printf("Enter the correct answer (A/B/C/D): ");
        scanf(" %c", &questions[i].correctAnswer);
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            char answer;
            fscanf(fp, "%c", &answer);

            if (answer == questions[j].correctAnswer) {
                students[i].score++;
            }
        }
    }

    fclose(fp);

    printf("Student scores:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}