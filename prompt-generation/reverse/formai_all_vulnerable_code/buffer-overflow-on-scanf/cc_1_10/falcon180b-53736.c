//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define MAX_STUDENTS 100
#define PASS_MARK 50

typedef struct {
    char name[50];
    int roll_no;
    int marks;
} Student;

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer;
} Question;

void generate_question(Question *q) {
    int i;
    for (i = 0; i < MAX_OPTIONS; i++) {
        sprintf(q->options[i], "Option %d", i + 1);
    }
    q->answer = 'A';
}

int main() {
    int num_students, num_questions, i, j, k, max_marks = 0;
    char ch;
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    printf("Enter student details:\n");
    for (i = 0; i < num_students; i++) {
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No.: ");
        scanf("%d", &students[i].roll_no);
    }

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter question details:\n");
    for (i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
        printf("Question %d: %s\n", i + 1, questions[i].question);
    }

    printf("Exam started...\n");
    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n%s\n", i + 1, questions[i].question);
        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &ch);
        if (ch == questions[i].answer) {
            students[0].marks++;
        }
    }

    printf("Exam ended...\n");
    printf("Student Name\tRoll No.\tMarks\n");
    for (i = 0; i < num_students; i++) {
        printf("%s\t%d\t%d\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}