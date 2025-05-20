//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student {
    int id;
    char name[50];
    float grade;
};

void read_students(struct student *students, int *count) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%d %s %f\n", &students[i].id, students[i].name, &students[i].grade)!= EOF) {
        i++;
    }

    *count = i;
    fclose(fp);
}

void write_students(struct student *students, int count) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %f\n", students[i].id, students[i].name, students[i].grade);
    }

    fclose(fp);
}

void sort_students(struct student *students, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[j].grade > students[i].grade) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void print_students(struct student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d %s %f\n", students[i].id, students[i].name, students[i].grade);
    }
}

int main() {
    struct student students[1000];
    int count = 0;

    read_students(students, &count);

    printf("Unsorted students:\n");
    print_students(students, count);

    sort_students(students, count);

    printf("\nSorted students by grade:\n");
    print_students(students, count);

    write_students(students, count);

    printf("\nSorted students written to file.\n");

    return 0;
}