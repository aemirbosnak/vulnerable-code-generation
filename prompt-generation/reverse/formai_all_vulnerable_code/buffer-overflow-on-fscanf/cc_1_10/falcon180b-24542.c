//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    char answer[MAX_CHOICES];
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];

void read_questions() {
    FILE *fp = fopen("questions.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s\n", questions[i].question)!= EOF) {
        i++;
    }
    fclose(fp);
}

void read_students() {
    FILE *fp = fopen("students.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s\n", students[i].name)!= EOF) {
        i++;
    }
    fclose(fp);
}

void write_results(char *filename) {
    FILE *fp = fopen(filename, "w");
    int i = 0;
    for (i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].name[0]!= '\0') {
            fprintf(fp, "%s: %d\n", students[i].name, students[i].score);
        }
    }
    fclose(fp);
}

int main() {
    int i, j, k, choice, correct = 0;
    char response[MAX_CHOICES];

    read_questions();
    read_students();

    printf("Welcome to the Online Examination System\n");
    printf("Enter your name: ");
    scanf("%s", students[0].name);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, questions[i].choices[j]);
        }
        printf("Enter your choice: ");
        scanf("%s", response);

        for (j = 0; j < MAX_CHOICES; j++) {
            if (strcmp(response, questions[i].answer[j]) == 0) {
                correct++;
                break;
            }
        }
    }

    printf("You got %d out of %d questions correct.\n", correct, MAX_QUESTIONS);
    write_results("results.txt");

    return 0;
}