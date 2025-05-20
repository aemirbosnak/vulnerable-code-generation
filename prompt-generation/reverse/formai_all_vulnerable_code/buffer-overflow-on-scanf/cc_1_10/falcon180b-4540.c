//Falcon-180B DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
#define MAX_COURSES 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int age;
} student_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int credit_hours;
} course_t;

void print_student(student_t* student) {
    printf("Name: %s\n", student->name);
    printf("ID: %d\n", student->id);
    printf("Age: %d\n", student->age);
}

void print_course(course_t* course) {
    printf("Name: %s\n", course->name);
    printf("ID: %d\n", course->id);
    printf("Credit Hours: %d\n", course->credit_hours);
}

int main() {
    int num_students, num_courses;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    printf("Enter the number of courses: ");
    scanf("%d", &num_courses);

    student_t students[MAX_STUDENTS];
    course_t courses[MAX_COURSES];

    for (int i = 0; i < num_students; i++) {
        printf("Enter information for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }

    for (int i = 0; i < num_courses; i++) {
        printf("Enter information for course %d:\n", i+1);
        printf("Name: ");
        scanf("%s", courses[i].name);
        printf("ID: ");
        scanf("%d", &courses[i].id);
        printf("Credit Hours: ");
        scanf("%d", &courses[i].credit_hours);
    }

    printf("Student Information:\n");
    for (int i = 0; i < num_students; i++) {
        print_student(&students[i]);
    }

    printf("\nCourse Information:\n");
    for (int i = 0; i < num_courses; i++) {
        print_course(&courses[i]);
    }

    return 0;
}