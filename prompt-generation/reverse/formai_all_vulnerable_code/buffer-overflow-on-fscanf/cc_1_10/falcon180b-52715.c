//Falcon-180B DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void read_students(Student students[], int size) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%d %s %f", &students[count].id, students[count].name, &students[count].grade)!= EOF) {
        count++;
    }

    fclose(fp);
}

void write_students(Student students[], int size) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d %s %f\n", students[i].id, students[i].name, students[i].grade);
    }

    fclose(fp);
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

void calculate_average(Student students[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += students[i].grade;
    }

    printf("Average grade: %.2f\n", sum / size);
}

int main() {
    srand(time(NULL));

    Student students[MAX_SIZE];
    int size = rand() % MAX_SIZE + 1;

    for (int i = 0; i < size; i++) {
        students[i].id = i + 1;
        sprintf(students[i].name, "Student %d", i + 1);
        students[i].grade = rand() % 101;
    }

    read_students(students, size);
    sort_students(students, size);
    write_students(students, size);
    calculate_average(students, size);

    return 0;
}