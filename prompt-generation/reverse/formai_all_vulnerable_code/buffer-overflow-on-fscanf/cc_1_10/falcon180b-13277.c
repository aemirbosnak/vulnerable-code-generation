//Falcon-180B DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 30
#define MAX_ID_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int age;
    float gpa;
} student_t;

void read_students(student_t students[]) {
    FILE *fp = fopen("students.txt", "r");
    int count = 0;

    while (fscanf(fp, "%s %s %d %f\n", students[count].name, students[count].id, &students[count].age, &students[count].gpa) == 4) {
        count++;
    }

    fclose(fp);
}

void write_students(student_t students[]) {
    FILE *fp = fopen("students.txt", "w");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i].name[0]!= '\0') {
            fprintf(fp, "%s %s %d %f\n", students[i].name, students[i].id, students[i].age, students[i].gpa);
        }
    }

    fclose(fp);
}

void sort_students(student_t students[]) {
    for (int i = 0; i < MAX_STUDENTS - 1; i++) {
        for (int j = i + 1; j < MAX_STUDENTS; j++) {
            if (students[j].gpa > students[i].gpa) {
                student_t temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    student_t students[MAX_STUDENTS];

    read_students(students);
    sort_students(students);
    write_students(students);

    return 0;
}