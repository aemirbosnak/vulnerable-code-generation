//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int age;
    float gpa;
} Student;

void allocateStudents(Student **students, int count) {
    *students = (Student *)malloc(count * sizeof(Student));
    if (*students == NULL) {
        perror("Failed to allocate memory for students");
        exit(EXIT_FAILURE);
    }
}

void inputStudentDetails(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for student %d:\n", i + 1);
        
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n"); // Remove newline character
        
        printf("Age: ");
        scanf("%d", &students[i].age);
        
        printf("GPA: ");
        scanf("%f", &students[i].gpa);
        getchar(); // Consume newline character leftover from scanf
    }
}

void printStudentDetails(const Student *students, int count) {
    printf("\n--- Student Details ---\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("--------------------------\n");
    }
}

void freeStudents(Student *students) {
    free(students);
}

int main() {
    int studentCount = 0;

    printf("Enter the number of students: ");
    scanf("%d", &studentCount);
    getchar(); // Consume the newline character left after scanf

    Student *students = NULL;

    allocateStudents(&students, studentCount);
    inputStudentDetails(students, studentCount);
    printStudentDetails(students, studentCount);
    freeStudents(students);

    return 0;
}