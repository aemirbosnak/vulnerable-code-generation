//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 5

typedef struct {
    char name[50];
    int age;
    float grades[3];
    float average_grade;
} Student;

void calculate_average(Student students[MAX_STUDENTS], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += students[i].average_grade;
    }
    printf("Average grade: %.2f\n", sum / size);
}

void print_students(Student students[MAX_STUDENTS], int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Grades: ");
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n");
        students[i].average_grade = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3.0;
    }
}

int main() {
    Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter student %d age: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter student %d grades:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);
        }
    }

    print_students(students, MAX_STUDENTS);
    calculate_average(students, MAX_STUDENTS);

    return 0;
}