//Falcon-180B DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student
struct student {
    char name[50];
    int age;
    float grade;
};

// Function to read students data from a file
void readStudents(struct student students[], FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s %d %f\n", students[i].name, &students[i].age, &students[i].grade)!= EOF) {
        i++;
    }
    rewind(fp);
}

// Function to write students data to a file
void writeStudents(struct student students[], int size, FILE *fp) {
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }
}

// Function to sort students by age
void sortStudentsByAge(struct student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[i].age > students[j].age) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to sort students by grade
void sortStudentsByGrade(struct student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[i].grade > students[j].grade) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    FILE *fp;
    struct student students[100];
    int size = 0;

    // Open the file
    fp = fopen("students.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Read students data from the file
    readStudents(students, fp);

    // Sort students by age
    sortStudentsByAge(students, size);

    // Write sorted students data to the file
    writeStudents(students, size, fp);

    // Sort students by grade
    sortStudentsByGrade(students, size);

    // Write sorted students data to the file
    writeStudents(students, size, fp);

    // Close the file
    fclose(fp);

    return 0;
}