//Falcon-180B DATASET v1.0 Category: Educational ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student
typedef struct {
    char name[50];
    int age;
    float GPA;
} Student;

// Function to read students from a file
void readStudents(FILE* file, Student* students, int maxStudents) {
    int i = 0;
    while (fscanf(file, "%s %d %f", students[i].name, &students[i].age, &students[i].GPA) == 3) {
        i++;
        if (i >= maxStudents) {
            break;
        }
    }
}

// Function to write students to a file
void writeStudents(FILE* file, Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %f\n", students[i].name, students[i].age, students[i].GPA);
    }
}

// Function to sort students by GPA
void sortStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[j].GPA > students[i].GPA) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to calculate the average GPA of students
float calculateAverageGPA(Student* students, int numStudents) {
    float sum = 0;
    for (int i = 0; i < numStudents; i++) {
        sum += students[i].GPA;
    }
    return sum / numStudents;
}

int main() {
    // Initialize variables
    FILE* inputFile = fopen("students.txt", "r");
    FILE* outputFile = fopen("sorted_students.txt", "w");
    Student students[100];
    int numStudents = 0;

    // Read students from input file
    readStudents(inputFile, students, 100);
    numStudents = fscanf(inputFile, "%*[^\n]");
    fclose(inputFile);

    // Sort students by GPA
    sortStudents(students, numStudents);

    // Calculate the average GPA
    float averageGPA = calculateAverageGPA(students, numStudents);

    // Write students to output file
    writeStudents(outputFile, students, numStudents);
    fprintf(outputFile, "Average GPA: %.2f\n", averageGPA);
    fclose(outputFile);

    return 0;
}