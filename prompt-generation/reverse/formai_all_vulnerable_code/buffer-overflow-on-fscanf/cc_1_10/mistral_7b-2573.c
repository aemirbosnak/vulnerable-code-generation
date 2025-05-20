//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define REC_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float grade;
} Student;

void readFile(FILE *file, Student students[MAX_SIZE]) {
    int i = 0;

    while (fscanf(file, "%[^,],%d,%f\n", students[i].name, &students[i].age, &students[i].grade) != EOF) {
        i++;
    }
}

void writeFile(FILE *file, Student students[MAX_SIZE], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s,%d,%.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

int main() {
    FILE *file;
    Student students[MAX_SIZE];
    int numStudents = 0;

    file = fopen("student.txt", "r");

    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    readFile(file, students);
    fclose(file);

    printf("Student Records:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s (%d years old) - Grade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    printf("\nAdd a new student record:\n");
    printf("Name: ");
    scanf("%s", students[numStudents].name);
    printf("Age: ");
    scanf("%d", &students[numStudents].age);
    students[numStudents].grade = 0; // Initialize grade to 0

    file = fopen("student.txt", "a");

    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        exit(1);
    }

    writeFile(file, students, numStudents + 1);
    fclose(file);

    printf("New student record added.\n");

    return 0;
}