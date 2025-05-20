//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int roll_number;
    int marks[3];
} Student;

void read_student_data(Student *student) {
    fflush(stdin);
    fgets(student->name, MAX_NAME_LEN, stdin);
    student->name[strcspn(student->name, "\n")] = '\0';

    scanf("%d", &student->roll_number);

    for (int i = 0; i < 3; i++) {
        scanf("%d", &student->marks[i]);
    }
}

void print_student_data(const Student *student) {
    printf("%s\nRoll Number: %d\n", student->name, student->roll_number);
    printf("Subject 1: %d\nSubject 2: %d\nSubject 3: %d\nTotal Marks: %d\n---\n", student->marks[0], student->marks[1], student->marks[2], student->marks[0] + student->marks[1] + student->marks[2]);
}

int calculate_total_marks(const Student *student) {
    return student->marks[0] + student->marks[1] + student->marks[2];
}

Student find_student_with_highest_marks(const Student students[], int num_students) {
    Student highest_marks_student = students[0];

    for (int i = 1; i < num_students; i++) {
        if (calculate_total_marks(&students[i]) > calculate_total_marks(&highest_marks_student)) {
            highest_marks_student = students[i];
        }
    }

    return highest_marks_student;
}

int main() {
    Student students[10];

    for (int i = 0; i < 10; i++) {
        read_student_data(&students[i]);
    }

    Student highest_marks_student = find_student_with_highest_marks(students, 10);
    print_student_data(&highest_marks_student);

    return 0;
}