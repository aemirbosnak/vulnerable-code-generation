//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float grades[5];
    float average;
} Student;

void calculate_average(Student *student) {
    float total = 0.0;
    for (int i = 0; i < 5; i++) {
        total += student->grades[i];
    }
    student->average = total / 5;
}

void display_student_info(const Student *student) {
    printf("Student ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->grades[i]);
    }
    printf("\nAverage: %.2f\n", student->average);
}

void sort_students_by_average(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void input_student_data(Student *student, int id) {
    student->id = id;
    printf("Enter name of student %d: ", id);
    scanf(" %[^\n]s", student->name);
    
    for (int i = 0; i < 5; i++) {
        printf("Enter grade %d for %s: ", i + 1, student->name);
        scanf("%f", &student->grades[i]);
    }
    calculate_average(student);
}

void display_all_students(const Student students[], int count) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < count; i++) {
        display_student_info(&students[i]);
        printf("\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int student_count = 0;
    char continue_input;

    do {
        if (student_count >= MAX_STUDENTS) {
            printf("Maximum student limit reached.\n");
            break;
        }
        input_student_data(&students[student_count], student_count + 1);
        student_count++;

        printf("Do you want to enter another student? (y/n): ");
        scanf(" %c", &continue_input);
    } while (continue_input == 'y' || continue_input == 'Y');

    sort_students_by_average(students, student_count);
    display_all_students(students, student_count);

    return 0;
}