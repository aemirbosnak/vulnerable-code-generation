//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *username = "admin";
    char *password = "password";
    char *student_name = "John Doe";
    char *exam_name = "Math";
    int student_marks = 80;
    int max_marks = 100;

    printf("Welcome to the Online Examination System!\n");
    printf("Username: ");
    scanf("%s", username);

    if (strcmp(username, "admin")!= 0) {
        printf("Invalid username. Access denied.\n");
        return 0;
    }

    printf("Password: ");
    scanf("%s", password);

    if (strcmp(password, "password")!= 0) {
        printf("Invalid password. Access denied.\n");
        return 0;
    }

    printf("Enter student name: ");
    scanf("%s", student_name);

    if (strcmp(student_name, "John Doe")!= 0) {
        printf("Invalid student name. Access denied.\n");
        return 0;
    }

    printf("Enter exam name: ");
    scanf("%s", exam_name);

    if (strcmp(exam_name, "Math")!= 0) {
        printf("Invalid exam name. Access denied.\n");
        return 0;
    }

    printf("Enter student marks: ");
    scanf("%d", &student_marks);

    if (student_marks < 0 || student_marks > max_marks) {
        printf("Invalid marks. Access denied.\n");
        return 0;
    }

    printf("Congratulations! You have successfully passed the examination!\n");
    printf("Student name: %s\n", student_name);
    printf("Exam name: %s\n", exam_name);
    printf("Student marks: %d\n", student_marks);

    return 0;
}