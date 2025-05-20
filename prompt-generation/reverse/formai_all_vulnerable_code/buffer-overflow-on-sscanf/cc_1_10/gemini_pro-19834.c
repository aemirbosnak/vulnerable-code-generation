//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
typedef struct student {
    char name[50];
    char roll_no[10];
    int marks;
} student;

// Structure to store question information
typedef struct question {
    char question[100];
    char options[4][50];
    char answer;
} question;

// Function to read student information from a file
void read_students(student *students, int *num_students, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %s %d", students[i].name, students[i].roll_no, &students[i].marks);
        i++;
    }

    fclose(fp);
    *num_students = i;
}

// Function to read questions from a file
void read_questions(question *questions, int *num_questions, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char line[200];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %s %s %s %s %c", questions[i].question, questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3], &questions[i].answer);
        i++;
    }

    fclose(fp);
    *num_questions = i;
}

// Function to conduct the online examination
void conduct_examination(student *students, int num_students, question *questions, int num_questions) {
    int i, j;
    int score[num_students];

    for (i = 0; i < num_students; i++) {
        score[i] = 0;
        for (j = 0; j < num_questions; j++) {
            char answer;
            printf("%s\n", questions[j].question);
            for (int k = 0; k < 4; k++) {
                printf("%d. %s\n", k + 1, questions[j].options[k]);
            }
            scanf(" %c", &answer);
            if (answer == questions[j].answer) {
                score[i]++;
            }
        }
    }

    // Display the results of the examination
    printf("\nResults of the online examination:\n");
    for (i = 0; i < num_students; i++) {
        printf("%s %s %d\n", students[i].name, students[i].roll_no, score[i]);
    }
}

// Main function
int main() {
    // Read student information from a file
    student students[100];
    int num_students;
    read_students(students, &num_students, "students.txt");

    // Read questions from a file
    question questions[100];
    int num_questions;
    read_questions(questions, &num_questions, "questions.txt");

    // Conduct the online examination
    conduct_examination(students, num_students, questions, num_questions);

    return 0;
}