//FormAI DATASET v1.0 Category: Online Examination System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to store exam details
struct exam_details{
    char exam_code[10];
    char exam_name[50];
    float exam_duration;
    int total_questions;
    float marks_per_question;
};

//structure to store student details
struct student_details{
    char name[50];
    char roll_number[10];
    char exam_code[10];
    float marks_obtained;
};

//function to take exam details input from user
void get_exam_details(struct exam_details *exam){
    printf("\nEnter Exam Details:\n");
    printf("Exam Code: ");
    scanf("%s",exam->exam_code);
    printf("Exam Name: ");
    scanf(" %[^\n]s",exam->exam_name);
    printf("Exam Duration(in hours): ");
    scanf("%f",&exam->exam_duration);
    printf("Total Questions: ");
    scanf("%d",&exam->total_questions);
    printf("Marks per Question: ");
    scanf("%f",&exam->marks_per_question);
}

//function to take student details input from user
void get_student_details(struct student_details *student){
    printf("\nEnter Student Details:\n");
    printf("Name: ");
    scanf(" %[^\n]s",student->name);
    printf("Roll Number: ");
    scanf("%s",student->roll_number);
    printf("Exam Code: ");
    scanf("%s",student->exam_code);
}

//function to display exam details
void display_exam_details(struct exam_details exam){
    printf("\nExam Details:\n");
    printf("Exam Code: %s\n",exam.exam_code);
    printf("Exam Name: %s\n",exam.exam_name);
    printf("Exam Duration: %.2f hours\n",exam.exam_duration);
    printf("Total Questions: %d\n",exam.total_questions);
    printf("Marks per Question: %.2f\n",exam.marks_per_question);
}

//function to display student details
void display_student_details(struct student_details student){
    printf("\nStudent Details:\n");
    printf("Name: %s\n",student.name);
    printf("Roll Number: %s\n",student.roll_number);
    printf("Exam Code: %s\n",student.exam_code);
}

//function to start exam
void start_exam(struct exam_details exam,struct student_details student){
    printf("\nExam Started!\n");
    int i;
    char answer[10];
    float marks = 0;
    for(i=1;i<=exam.total_questions;i++){
        printf("\nQuestion %d:\n",i);
        printf("What is the answer? ");
        scanf("%s",answer);
        if(strcmp(answer,"A")==0 || strcmp(answer,"a")==0){
            marks += exam.marks_per_question;
        }
        printf("Marks: %.2f\n",marks);
    }
    student.marks_obtained = marks;
}

//function to display result
void display_result(struct student_details student){
    printf("\nResult:\n");
    printf("Name: %s\n",student.name);
    printf("Roll Number: %s\n",student.roll_number);
    printf("Exam Code: %s\n",student.exam_code);
    printf("Marks Obtained: %.2f\n",student.marks_obtained);
}

int main(){
    struct exam_details exam;
    struct student_details student;

    get_exam_details(&exam);
    display_exam_details(exam);

    get_student_details(&student);
    display_student_details(student);

    start_exam(exam,student);
    display_result(student);

    return 0;
}