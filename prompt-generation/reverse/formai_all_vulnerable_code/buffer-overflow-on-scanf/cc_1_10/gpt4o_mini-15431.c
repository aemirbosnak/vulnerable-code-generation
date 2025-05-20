//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function prototypes
Student* createStudents(int count);
void inputStudentData(Student* students, int count);
void displayStudents(Student* students, int count);
void freeMemory(Student* students);

int main() {
    int studentCount;
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);

    // Allocate memory for students
    Student* students = createStudents(studentCount);
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Input student data
    inputStudentData(students, studentCount);

    // Display student data
    printf("\nStudent Details:\n");
    displayStudents(students, studentCount);

    // Free allocated memory
    freeMemory(students);

    return EXIT_SUCCESS;
}

Student* createStudents(int count) {
    // Allocate memory for an array of students
    Student* students = (Student*)malloc(count * sizeof(Student));
    return students;
}

void inputStudentData(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for student %d: ", i + 1);
        getchar(); // consume the newline left by previous input
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline

        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }
}

void displayStudents(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s, Age: %d, Grade: %.2f\n",
               i + 1, students[i].name, students[i].age, students[i].grade);
    }
}

void freeMemory(Student* students) {
    free(students); // Free the allocated memory
}