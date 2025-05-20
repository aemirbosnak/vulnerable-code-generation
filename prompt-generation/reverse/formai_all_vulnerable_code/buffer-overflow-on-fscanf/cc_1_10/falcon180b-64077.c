//Falcon-180B DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void read_students(Student students[], int size) {
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int count = 0;

    while (fscanf(file, "%s %d %f\n", students[count].name, &students[count].age, &students[count].grade)!= EOF) {
        count++;
    }

    fclose(file);
}

void write_students(Student students[], int size) {
    FILE *file = fopen("students.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    fclose(file);
}

void sort_students(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (students[j].grade > students[i].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    Student students[100];
    int size = 0;

    read_students(students, 100);
    size = sizeof(students) / sizeof(students[0]);

    sort_students(students, size);

    write_students(students, size);

    return 0;
}