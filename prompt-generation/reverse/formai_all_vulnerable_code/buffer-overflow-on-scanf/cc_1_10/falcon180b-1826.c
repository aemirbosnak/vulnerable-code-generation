//Falcon-180B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float grade;
} Student;

void read_students(Student students[], int n) {
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %d %f\n", students[i].name, &students[i].age, &students[i].grade)!= EOF) {
        i++;
    }

    fclose(file);
}

void write_students(Student students[], int n) {
    FILE *file = fopen("students.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %d %f\n", students[i].name, students[i].age, students[i].grade);
    }

    fclose(file);
}

void sort_students(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[j].grade > students[i].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    read_students(students, n);

    printf("Students before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    sort_students(students, n);

    printf("\nStudents after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    write_students(students, n);

    return 0;
}