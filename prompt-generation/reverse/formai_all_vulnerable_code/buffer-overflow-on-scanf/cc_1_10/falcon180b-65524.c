//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    char answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

void read_questions(Question questions[]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error opening questions file!\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        strcpy(questions[i].question, line);
        i++;
    }

    fclose(fp);
}

void read_choices(Question questions[], int num_questions) {
    FILE *fp;
    char line[100];
    int i, j;

    for (i = 0; i < num_questions; i++) {
        fp = fopen(questions[i].question, "r");

        if (fp == NULL) {
            printf("Error opening question file %s!\n", questions[i].question);
            exit(1);
        }

        j = 0;

        while (fgets(line, 100, fp)!= NULL) {
            strcpy(questions[i].choices[j], line);
            j++;
        }

        fclose(fp);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions, num_students, i, j, correct_answers;
    char filename[100];
    Student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    read_questions(questions);
    read_choices(questions, num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++) {
        printf("Enter student name %d: ", i+1);
        scanf("%s", students[i].name);
    }

    printf("Enter the correct answers (separated by spaces): ");
    scanf("%s", filename);

    FILE *fp;
    char line[100];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening correct answers file!\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        questions[atoi(line)-1].answer = tolower(line[0]);
    }

    fclose(fp);

    for (i = 0; i < num_students; i++) {
        correct_answers = 0;

        for (j = 0; j < num_questions; j++) {
            if (tolower(students[i].name[0]) == questions[j].answer) {
                correct_answers++;
            }
        }

        printf("Student %s got %d out of %d correct answers.\n", students[i].name, correct_answers, num_questions);
    }

    return 0;
}