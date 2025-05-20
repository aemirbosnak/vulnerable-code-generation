//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100

// Student structure
typedef struct student {
    char name[MAX_NAME_LEN];
    int roll_no;
    float cgpa;
} Student;

// Function to generate random roll number
int generate_roll_no() {
    return rand() % 1000 + 1;
}

// Function to read student data from a file
void read_students_from_file(Student students[], char file_name[]) {
    FILE *fp;
    int i = 0;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%[^,],%d,%f", students[i].name, &students[i].roll_no, &students[i].cgpa) != EOF) {
        i++;
    }

    fclose(fp);
}

// Function to display student details
void display_student(Student student) {
    printf("Name: %s\n", student.name);
    printf("Roll No: %d\n", student.roll_no);
    printf("CGPA: %.2f\n", student.cgpa);
    printf("\n");
}

// Function to sort students based on CGPA
void sort_students(Student students[], int num_students) {
    Student temp;
    int i, j;

    for (i = 0; i < num_students - 1; i++) {
        for (j = 0; j < num_students - i - 1; j++) {
            if (students[j].cgpa < students[j + 1].cgpa) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Student students[MAX_STUDENTS];
    int num_students = 0;

    // Reading students data from a file
    char file_name[] = "students.csv";
    read_students_from_file(students, file_name);

    // Adding a new student
    Student new_student;
    strcpy(new_student.name, "John Doe");
    new_student.roll_no = generate_roll_no();
    new_student.cgpa = 3.8;

    students[num_students++] = new_student;

    // Displaying all students
    printf("Students Data:\n");
    for (int i = 0; i < num_students; i++) {
        display_student(students[i]);
    }

    // Sorting students based on CGPA
    sort_students(students, num_students);

    // Displaying top 3 students with highest CGPA
    printf("\nTop 3 Students:\n");
    for (int i = 0; i < 3 && i < num_students; i++) {
        display_student(students[i]);
    }

    return 0;
}