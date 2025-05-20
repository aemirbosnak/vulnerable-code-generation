//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    float gpa;
} Student;

void readStudentsFromFile(const char *filename, Student students[], int size);
void writeStudentsToFile(const char *filename, Student students[], int size);

int main() {
    Student students[10];
    char filename[50] = "students.txt";

    readStudentsFromFile(filename, students, 10);

    printf("Students data read from file:\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    writeStudentsToFile(filename, students, 10);

    printf("\nStudents data written to file.\n");

    return 0;
}

void readStudentsFromFile(const char *filename, Student students[], int size) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%d %s %f", &students[i].id, students[i].name, &students[i].gpa);
    }

    fclose(file);
}

void writeStudentsToFile(const char *filename, Student students[], int size) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    fclose(file);
}