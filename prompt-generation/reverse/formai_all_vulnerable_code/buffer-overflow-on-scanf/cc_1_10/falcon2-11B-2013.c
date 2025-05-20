//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct exam
{
    char name[100];
    int total_marks;
    int total_questions;
    char* paper[100];
    int* correct_answers[100];
    int* wrong_answers[100];
};

struct student
{
    char name[100];
    int total_marks;
    int total_questions;
    char* paper[100];
    int* correct_answers[100];
    int* wrong_answers[100];
};

struct scoreboard
{
    int total_marks;
    int total_students;
    struct student* students[100];
};

void read_exam_paper(struct exam* exam)
{
    printf("Enter exam paper name: ");
    scanf("%s", exam->name);
    printf("Enter total marks: ");
    scanf("%d", &exam->total_marks);
    printf("Enter total questions: ");
    scanf("%d", &exam->total_questions);
    printf("Enter paper: ");
    for (int i = 0; i < exam->total_questions; i++)
    {
        char paper[100];
        scanf("%s", paper);
        exam->paper[i] = paper;
    }
}

void read_student_details(struct student* student)
{
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter total marks: ");
    scanf("%d", &student->total_marks);
    printf("Enter total questions: ");
    scanf("%d", &student->total_questions);
    printf("Enter paper: ");
    for (int i = 0; i < student->total_questions; i++)
    {
        char paper[100];
        scanf("%s", paper);
        student->paper[i] = paper;
    }
}

void read_exam_scores(struct scoreboard* scoreboard)
{
    printf("Enter total marks: ");
    scanf("%d", &scoreboard->total_marks);
    printf("Enter total students: ");
    scanf("%d", &scoreboard->total_students);
    for (int i = 0; i < scoreboard->total_students; i++)
    {
        struct student* student = (struct student*)malloc(sizeof(struct student));
        read_student_details(student);
        scoreboard->students[i] = student;
    }
}

void write_exam_scores(struct scoreboard* scoreboard)
{
    printf("Exam scores:\n");
    for (int i = 0; i < scoreboard->total_students; i++)
    {
        printf("Student: %s\n", scoreboard->students[i]->name);
        printf("Total marks: %d\n", scoreboard->students[i]->total_marks);
        printf("Total questions: %d\n", scoreboard->students[i]->total_questions);
        printf("Paper:\n");
        for (int j = 0; j < scoreboard->students[i]->total_questions; j++)
        {
            printf("Question %d: %s\n", j+1, scoreboard->students[i]->paper[j]);
        }
        printf("Correct answers:\n");
        for (int j = 0; j < scoreboard->students[i]->total_questions; j++)
        {
            printf("Question %d: %s\n", j+1, scoreboard->students[i]->correct_answers[j]);
        }
        printf("Wrong answers:\n");
        for (int j = 0; j < scoreboard->students[i]->total_questions; j++)
        {
            printf("Question %d: %s\n", j+1, scoreboard->students[i]->wrong_answers[j]);
        }
    }
}

int main()
{
    struct exam exam;
    read_exam_paper(&exam);
    struct student student;
    read_student_details(&student);
    struct scoreboard scoreboard;
    read_exam_scores(&scoreboard);
    write_exam_scores(&scoreboard);
    return 0;
}