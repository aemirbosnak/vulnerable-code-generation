//Falcon-180B DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about each student
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to read data from a file and store it in an array of structs
void readFromFile(FILE *fp, Student students[], int *numStudents) {
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Split the line into fields
        char *token = strtok(line, ",");
        strcpy(students[*numStudents].name, token);
        students[*numStudents].age = atoi(strtok(NULL, ","));
        students[*numStudents].gpa = atof(strtok(NULL, ","));
        (*numStudents)++;
    }
}

// Function to write data to a file
void writeToFile(FILE *fp, Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(fp, "%s,%d,%.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

// Function to sort an array of structs by GPA
void sortByGPA(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[j].gpa > students[i].gpa) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("students.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("sorted_students.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        exit(1);
    }

    int numStudents = 0;
    Student students[100];
    readFromFile(inputFile, students, &numStudents);

    // Sort the array by GPA
    sortByGPA(students, numStudents);

    // Write the sorted data to the output file
    writeToFile(outputFile, students, numStudents);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}