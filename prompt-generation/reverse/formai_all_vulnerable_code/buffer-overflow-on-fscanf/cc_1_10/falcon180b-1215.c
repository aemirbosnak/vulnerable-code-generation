//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct student {
    char name[50];
    int roll;
    float marks;
};

void read_students(struct student students[]) {
    FILE *fp;
    int i = 0;

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %f\n", students[i].name, &students[i].roll, &students[i].marks)!= EOF) {
        i++;
    }

    fclose(fp);
}

void write_students(struct student students[]) {
    FILE *fp;
    int i;

    fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].roll, students[i].marks);
    }

    fclose(fp);
}

void sort_students(struct student students[]) {
    int i, j;
    struct student temp;

    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct student students[MAX];

    read_students(students);

    printf("Before sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s %d %f\n", students[i].name, students[i].roll, students[i].marks);
    }

    sort_students(students);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s %d %f\n", students[i].name, students[i].roll, students[i].marks);
    }

    write_students(students);

    return 0;
}