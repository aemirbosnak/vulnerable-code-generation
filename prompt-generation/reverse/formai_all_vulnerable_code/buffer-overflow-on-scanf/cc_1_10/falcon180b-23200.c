//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int roll_no;
    int marks[5];
    int total_marks;
    float percentage;
} Student;

void add_student(Student *students, int num_students) {
    int choice;
    printf("Enter choice:\n1. Add student\n2. Print list of students\n3. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        if (num_students == MAX_SIZE) {
            printf("List is full. Cannot add more students.\n");
        } else {
            printf("Enter student name: ");
            scanf("%s", students[num_students].name);
            printf("Enter roll number: ");
            scanf("%d", &students[num_students].roll_no);

            printf("Enter marks for subject 1: ");
            scanf("%d", &students[num_students].marks[0]);
            printf("Enter marks for subject 2: ");
            scanf("%d", &students[num_students].marks[1]);
            printf("Enter marks for subject 3: ");
            scanf("%d", &students[num_students].marks[2]);
            printf("Enter marks for subject 4: ");
            scanf("%d", &students[num_students].marks[3]);
            printf("Enter marks for subject 5: ");
            scanf("%d", &students[num_students].marks[4]);

            students[num_students].total_marks = 0;
            for (int i = 0; i < 5; i++) {
                students[num_students].total_marks += students[num_students].marks[i];
            }
            students[num_students].percentage = (float) students[num_students].total_marks / 500.0 * 100.0;
            num_students++;
        }
    } else if (choice == 2) {
        printf("List of students:\n");
        for (int i = 0; i < num_students; i++) {
            printf("%s (%d) - Total marks: %d - Percentage: %.2f\n", students[i].name, students[i].roll_no, students[i].total_marks, students[i].percentage);
        }
    } else if (choice == 3) {
        exit(0);
    }
}

int main() {
    Student students[MAX_SIZE];
    int num_students = 0;

    while (1) {
        add_student(students, num_students);
    }

    return 0;
}