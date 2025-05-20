//Falcon-180B DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_STUDENTS 100
#define MAX_GRADES 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int grades[MAX_GRADES];
    int num_grades;
} Student;

void read_students_from_file(const char* filename, Student* students, int num_students) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int num_lines_read = 0;
    while (fscanf(file, "%s %d %d\n", students[num_lines_read].name, &students[num_lines_read].grades[0], &students[num_lines_read].num_grades) == 3) {
        num_lines_read++;
        if (num_lines_read == num_students) {
            break;
        }
    }

    fclose(file);
}

void calculate_average_grade(Student* student, double* average_grade) {
    int sum = 0;
    for (int i = 0; i < student->num_grades; i++) {
        sum += student->grades[i];
    }
    *average_grade = (double) sum / student->num_grades;
}

int main() {
    Student students[MAX_NUM_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    if (scanf("%d", &num_students)!= 1 || num_students <= 0 || num_students > MAX_NUM_STUDENTS) {
        printf("Error: invalid number of students\n");
        return 1;
    }

    char filename[MAX_NAME_LENGTH];
    printf("Enter the name of the input file: ");
    if (scanf("%s", filename)!= 1 || strlen(filename) == 0) {
        printf("Error: invalid filename\n");
        return 1;
    }

    read_students_from_file(filename, students, num_students);

    printf("Student Name\tAverage Grade\n");
    for (int i = 0; i < num_students; i++) {
        double average_grade;
        calculate_average_grade(&students[i], &average_grade);
        printf("%s\t%.2f\n", students[i].name, average_grade);
    }

    return 0;
}