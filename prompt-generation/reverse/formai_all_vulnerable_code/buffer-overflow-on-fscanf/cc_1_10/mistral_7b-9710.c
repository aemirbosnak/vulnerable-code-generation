//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int roll_no;
    int marks;
} Student;

void read_students(Student students[], const char *filename) {
    FILE *file = fopen(filename, "r");
    Student temp_student;
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%[^,],%d,%d\n", temp_student.name, &temp_student.roll_no, &temp_student.marks) != EOF) {
        students[i] = temp_student;
        i++;
    }

    fclose(file);
}

void display_students(const Student students[], int num_students) {
    int i;

    printf("\n%-10s %-15s %-10s\n", "Roll No.", "Name", "Marks");
    printf("--------------------------------------------------------");

    for (i = 0; i < num_students; i++) {
        printf("\n%-10d %-15s %-10d", students[i].roll_no, students[i].name, students[i].marks);
    }
}

int search_student_by_rollno(const Student students[], int num_students, int roll_no) {
    int i;

    for (i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_no)
            return i;
    }

    return -1;
}

void sort_students(Student students[], int num_students) {
    int i, j, temp;

    for (i = 0; i < num_students - 1; i++) {
        for (j = 0; j < num_students - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j].marks;
                students[j].marks = students[j + 1].marks;
                students[j + 1].marks = temp;
            }
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    char filename[] = "students.txt";
    int num_students, i, roll_no, index;

    read_students(students, filename);
    num_students = sizeof(students) / sizeof(Student);

    display_students(students, num_students);

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll_no);

    index = search_student_by_rollno(students, num_students, roll_no);

    if (index != -1)
        printf("\nStudent found:\n%-15s %-10d %-10d", students[index].name, students[index].roll_no, students[index].marks);
    else
        printf("\nStudent not found.");

    sort_students(students, num_students);

    printf("\n\nSorted students:\n");
    display_students(students, num_students);

    return 0;
}