//Falcon-180B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
} student_t;

int main() {
    int num_students;
    student_t students[MAX_STUDENTS];
    char filename[MAX_NAME_LENGTH];

    // Prompt user for number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Prompt user for filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Read students from file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d %f", students[i].name, &students[i].age, &students[i].gpa) == 3 && i < num_students) {
        i++;
    }
    fclose(fp);

    // Sort students by GPA
    for (i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[j].gpa > students[i].gpa) {
                student_t temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Print sorted list of students
    printf("Sorted list of students by GPA:\n");
    for (i = 0; i < num_students; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    return 0;
}