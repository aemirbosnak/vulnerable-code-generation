//Falcon-180B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUM_COURSES 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int num_courses;
    int courses[MAX_NUM_COURSES];
    int grades[MAX_NUM_COURSES];
} Student;

void get_random_student(Student* student) {
    srand(time(NULL));
    student->age = rand() % 100;
    student->num_courses = rand() % MAX_NUM_COURSES;
    for (int i = 0; i < student->num_courses; i++) {
        student->courses[i] = rand() % MAX_NUM_COURSES;
        student->grades[i] = rand() % 101;
    }
}

void print_student(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Number of courses: %d\n", student->num_courses);
    for (int i = 0; i < student->num_courses; i++) {
        printf("Course %d: %d\n", student->courses[i], student->grades[i]);
    }
}

int main() {
    Student students[MAX_NUM_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        printf("Enter the name for student %d: ", i+1);
        scanf("%s", students[i].name);
        get_random_student(&students[i]);
    }

    printf("Student information:\n");
    for (int i = 0; i < num_students; i++) {
        print_student(&students[i]);
    }

    return 0;
}