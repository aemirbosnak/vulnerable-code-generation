//MISTRAL-7B DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#define NUM_STUDENTS 5
#define NUM_SUBJECTS 3

typedef struct {
    char name[20];
    float grades[NUM_SUBJECTS];
} Student;

void get_student_data(Student students[NUM_STUDENTS]);
void print_student_data(Student student);
float calculate_average_grade(Student student);

int main() {
    Student students[NUM_STUDENTS];

    printf("Enter data for %d students:\n", NUM_STUDENTS);
    get_student_data(students);

    printf("\nStudent Data:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        print_student_data(students[i]);
        printf("Average Grade: %.2f\n", calculate_average_grade(students[i]));
    }

    return 0;
}

void get_student_data(Student students[NUM_STUDENTS]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter %d subject grades for student %s:\n", NUM_SUBJECTS, students[i].name);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            scanf("%f", &students[i].grades[j]);
        }
    }
}

void print_student_data(Student student) {
    printf("\nName: %s\n", student.name);
    printf("Subject Grades: [");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%.2f, ", student.grades[i]);
    }
    printf("\b]");
}

float calculate_average_grade(Student student) {
    float sum = 0.0;

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        sum += student.grades[i];
    }

    return sum / NUM_SUBJECTS;
}