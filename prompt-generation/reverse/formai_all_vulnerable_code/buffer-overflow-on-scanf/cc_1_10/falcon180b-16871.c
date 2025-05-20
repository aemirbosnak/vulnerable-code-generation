//Falcon-180B DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} student_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_students;
    student_t students[MAX_STUDENTS];
} course_t;

void read_students(course_t *course) {
    int i;
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter name and ID of student %d (name ID): ", i + 1);
        scanf("%s %d", course->students[i].name, &course->students[i].id);
    }
    course->num_students = i;
}

void read_courses(course_t courses[MAX_COURSES]) {
    int i;
    for (i = 0; i < MAX_COURSES; i++) {
        printf("Enter name of course %d: ", i + 1);
        scanf("%s", courses[i].name);
        read_students(&courses[i]);
    }
}

void display_courses(course_t courses[MAX_COURSES]) {
    int i;
    for (i = 0; i < MAX_COURSES; i++) {
        printf("Course %s:\n", courses[i].name);
        int j;
        for (j = 0; j < courses[i].num_students; j++) {
            printf("  %s (%d)\n", courses[i].students[j].name, courses[i].students[j].id);
        }
    }
}

int main() {
    course_t courses[MAX_COURSES];
    read_courses(courses);
    display_courses(courses);
    return 0;
}