//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int marks;
} Student;

void welcome_message() {
    printf("\n-----------------------------------------------\n");
    printf("|             Romantic Exam System            |\n");
    printf("|--------------------------------------------|\n");
}

void input_student_details(Student *student) {
    printf("\nEnter student name: ");
    scanf("%s", student->name);
    printf("Enter student marks: ");
    scanf("%d", &student->marks);
}

void display_student_details(Student student) {
    printf("\nStudent Name: %s", student.name);
    printf("\nMarks Obtained: %d", student.marks);
}

int check_love_level(Student student) {
    int love_level;

    if (student.marks >= 90) {
        love_level = 10;
        printf("\nYou have scored an A+ and I have fallen deeply in love with you!\n");
    } else if (student.marks >= 80) {
        love_level = 8;
        printf("\nYou have scored B and I like you a lot!\n");
    } else if (student.marks >= 70) {
        love_level = 5;
        printf("\nYou have scored C and I think you are nice!\n");
    } else {
        love_level = 1;
        printf("\nYou have failed and I am sorry for wasting my time on you!\n");
    }

    return love_level;
}

int main() {
    Student student;
    int love_level;

    welcome_message();
    input_student_details(&student);
    check_love_level(student);
    love_level = check_love_level(student);
    display_student_details(student);

    return 0;
}