//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_GRADES 5

typedef struct {
    char name[MAX_NAME_LEN];
    float grade[MAX_GRADES];
} student_t;

student_t get_student(void);
void display_student(student_t);
void calculate_average(student_t);
void display_average(student_t);

int main(void) {
    student_t student;

    do {
        student = get_student();
        calculate_average(student);
        display_average(student);
    } while (1);

    return 0;
}

student_t get_student(void) {
    char name;
    float grade[MAX_GRADES];

    printf("Enter name: ");
    scanf("%19s", name);

    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &grade[i]);
    }

    student_t new_student = { name, grade };

    return new_student;
}

void display_student(student_t student) {
    printf("Name: %s\n", student.name);
    for (int i = 0; i < MAX_GRADES; i++) {
        printf("Grade %d: %f\n", i + 1, student.grade[i]);
    }
}

void calculate_average(student_t student) {
    float total = 0;

    for (int i = 0; i < MAX_GRADES; i++) {
        total += student.grade[i];
    }

    student.grade[0] = total / MAX_GRADES;
}

void display_average(student_t student) {
    printf("Average: %f\n", student.grade[0]);
}