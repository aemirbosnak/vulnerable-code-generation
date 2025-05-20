//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 50
#define MAX_CHAR 50

typedef struct {
    char name[MAX_CHAR];
    int roll_no;
    int marks;
} Student;

typedef struct {
    char question[MAX_CHAR];
    char answer[MAX_CHAR];
    int mark;
} Question;

Student students[MAX_STUDENTS];
Question questions[MAX_QUESTIONS];
int num_students = 0, num_questions = 0;

void register_student() {
    if (num_students >= MAX_STUDENTS) {
        printf("Maximum students limit reached!\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", students[num_students].name);
    printf("Enter student roll number: ");
    scanf("%d", &students[num_students].roll_no);
    num_students++;
}

void add_question() {
    if (num_questions >= MAX_QUESTIONS) {
        printf("Maximum questions limit reached!\n");
        return;
    }
    printf("Enter question: ");
    scanf("%s", questions[num_questions].question);
    printf("Enter answer: ");
    scanf("%s", questions[num_questions].answer);
    printf("Enter marks: ");
    scanf("%d", &questions[num_questions].mark);
    num_questions++;
}

void display_question_paper() {
    int i;
    printf("\nQuestion Paper\n");
    for (i = 0; i < num_questions; i++) {
        printf("\n%d. %s\nQ: %s\nA: ", i + 1, questions[i].question, questions[i].question);
        scanf("%s", questions[i].answer);
    }
}

void calculate_marks() {
    int i, j, student_marks[MAX_STUDENTS] = {0};
    for (i = 0; i < num_students; i++) {
        for (j = 0; j < num_questions; j++) {
            if (strcmp(students[i].name, questions[j].answer) == 0) {
                student_marks[i] += questions[j].mark;
            }
        }
    }
    FILE *fp;
    fp = fopen("marks.txt", "w");
    for (i = 0; i < num_students; i++) {
        fprintf(fp, "%s %d\n", students[i].name, student_marks[i]);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\nOnline Examination System\n1. Register Student\n2. Add Question\n3. Display Question Paper\n4. Calculate Marks\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                register_student();
                break;
            case 2:
                add_question();
                break;
            case 3:
                display_question_paper();
                calculate_marks();
                break;
            case 4:
                calculate_marks();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}