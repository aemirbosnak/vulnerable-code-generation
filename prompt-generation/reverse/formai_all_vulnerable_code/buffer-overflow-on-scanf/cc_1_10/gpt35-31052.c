//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    float gpa;
    bool is_enrolled;
} Student;

int get_num_students() {
    int num_students;

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    return num_students;
}

void get_student_data(Student* student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student GPA: ");
    scanf("%f", &student->gpa);

    student->is_enrolled = true;
}

void print_student(Student student) {
    printf("Name: %s\n", student.name);
    printf("GPA: %f\n", student.gpa);
    printf("Enrolled: %s\n", student.is_enrolled ? "Yes" : "No");
}

void print_students(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student #%d:\n", i + 1);
        print_student(students[i]);
    }
}

void save_students(Student students[], int num_students, char* filename) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    fprintf(fp, "Name,GPA,Enrolled\n");

    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s,%f,%s\n", students[i].name, students[i].gpa, students[i].is_enrolled ? "Yes" : "No");
    }

    fclose(fp);

    printf("Successfully saved %d students to %s\n", num_students, filename);
}

int main() {
    int num_students = get_num_students();

    if (num_students > MAX_STUDENTS) {
        printf("Error: Maximum number of students is %d\n", MAX_STUDENTS);
        return 1;
    }

    Student students[MAX_STUDENTS];

    for (int i = 0; i < num_students; i++) {
        printf("Enter data for student #%d:\n", i + 1);
        get_student_data(&students[i]);
    }

    print_students(students, num_students);

    char filename[MAX_NAME_LEN];
    printf("Enter filename to save student data: ");
    scanf("%s", filename);

    save_students(students, num_students, filename);

    return 0;
}