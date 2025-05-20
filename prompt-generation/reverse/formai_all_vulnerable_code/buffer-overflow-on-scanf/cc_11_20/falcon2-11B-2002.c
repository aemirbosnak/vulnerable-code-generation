//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4

typedef struct {
    char name[MAX_LENGTH];
    int roll_no;
    int total_marks;
    int marks_obtained;
    int questions_attempted;
    int answers[MAX_ANSWERS][MAX_LENGTH];
} Student;

typedef struct {
    char question[MAX_LENGTH];
    int correct_answer;
    int total_marks;
    int correct_answers;
    int total_questions;
    int questions[MAX_ANSWERS][MAX_LENGTH];
} Question;

int main() {
    Student students[MAX_QUESTIONS];
    Question questions[MAX_QUESTIONS];
    int n_questions = 0, n_students = 0;
    int choice, i, j;

    printf("Welcome to the online examination system!\n");
    printf("Enter the number of questions: ");
    scanf("%d", &n_questions);

    printf("Enter the number of students: ");
    scanf("%d", &n_students);

    for (i = 0; i < n_questions; i++) {
        printf("Enter question %d:\n", i+1);
        scanf("%s", questions[i].question);
        scanf("%d", &questions[i].total_marks);
        printf("Enter the correct answer:\n");
        scanf("%d", &questions[i].correct_answer);

        for (j = 0; j < MAX_ANSWERS; j++) {
            printf("Enter answer %d:\n", j+1);
            scanf("%s", questions[i].questions[j]);
        }
    }

    for (i = 0; i < n_students; i++) {
        printf("Enter student %d's name: ", i+1);
        scanf("%s", students[i].name);
        scanf("%d", &students[i].roll_no);
        students[i].total_marks = n_questions * questions[0].total_marks;
        students[i].marks_obtained = 0;
        students[i].questions_attempted = 0;

        for (j = 0; j < MAX_ANSWERS; j++) {
            students[i].answers[j][0] = '\0';
        }
    }

    printf("Enter the number of students who have taken the exam: ");
    scanf("%d", &n_students);

    for (i = 0; i < n_students; i++) {
        for (j = 0; j < MAX_ANSWERS; j++) {
            printf("Enter answer %d for student %d:\n", j+1, i+1);
            scanf("%s", students[i].answers[j]);
        }
        students[i].questions_attempted = MAX_ANSWERS;
        for (j = 0; j < MAX_ANSWERS; j++) {
            if (strcmp(students[i].answers[j], questions[j].questions[j]) == 0) {
                students[i].marks_obtained += questions[j].total_marks;
                break;
            }
        }
    }

    for (i = 0; i < n_students; i++) {
        printf("Student %d: %s\n", i+1, students[i].name);
        printf("Roll No.: %d\n", students[i].roll_no);
        printf("Total marks: %d\n", students[i].total_marks);
        printf("Marks obtained: %d\n", students[i].marks_obtained);
        printf("Questions attempted: %d\n", students[i].questions_attempted);

        for (j = 0; j < MAX_ANSWERS; j++) {
            printf("Answer %d: %s\n", j+1, students[i].answers[j]);
        }
    }

    printf("Thank you for using the online examination system!\n");

    return 0;
}