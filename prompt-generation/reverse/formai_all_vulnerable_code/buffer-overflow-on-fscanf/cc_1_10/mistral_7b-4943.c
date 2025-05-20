//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Student {
    int roll_number;
    char name[30];
    float marks;
} Student;

void readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    Student students[MAX_SIZE];
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    while (fscanf(file, "%d %s %f", &students[i].roll_number, students[i].name, &students[i].marks) != EOF) {
        i++;
    }

    fclose(file);

    printf("\nData from file:\n");
    for (int j = 0; j < i; j++) {
        printf("Roll Number: %d\n", students[j].roll_number);
        printf("Name: %s\n", students[j].name);
        printf("Marks: %.2f\n", students[j].marks);
        printf("\n");
    }
}

void writeFile(const char *fileName, Student student) {
    FILE *file = fopen(fileName, "a");

    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(file, "%d %s %.2f\n", student.roll_number, student.name, student.marks);
    fclose(file);

    printf("Data written to file successfully.\n");
}

int main() {
    Student newStudent = {11, "John Doe", 85.5};

    readFile("students.txt");

    writeFile("students.txt", newStudent);

    return 0;
}