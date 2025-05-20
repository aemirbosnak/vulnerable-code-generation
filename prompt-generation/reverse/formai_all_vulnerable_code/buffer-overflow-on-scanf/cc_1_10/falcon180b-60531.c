//Falcon-180B DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function to compare two students based on their grades
int compareGrades(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;

    if (studentA->grade > studentB->grade) {
        return 1;
    } else if (studentA->grade < studentB->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print a student's information
void printStudent(const Student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grade: %.2f\n\n", student->grade);
}

// Function to read students from a file
void readStudentsFromFile(char *filename, Student *students, int maxStudents) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int numStudents = 0;

    while (fscanf(file, "%s %d %.2f", students[numStudents].name, &students[numStudents].age, &students[numStudents].grade) == 3) {
        numStudents++;

        if (numStudents == maxStudents) {
            break;
        }
    }

    fclose(file);
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student *students = malloc(sizeof(Student) * numStudents);

    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    readStudentsFromFile(filename, students, numStudents);

    qsort(students, numStudents, sizeof(Student), compareGrades);

    printf("Sorted students by grade:\n");

    for (int i = 0; i < numStudents; i++) {
        printStudent(&students[i]);
    }

    free(students);

    return 0;
}