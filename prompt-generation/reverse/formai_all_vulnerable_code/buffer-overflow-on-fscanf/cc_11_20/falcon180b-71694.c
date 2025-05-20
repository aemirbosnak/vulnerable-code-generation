//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    FILE *fp;
    struct student stu[SIZE];
    int n = 0;
    char ch;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("File not found!");
        exit(0);
    }

    // Reading data from file
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            n++;
        }
    }
    rewind(fp);

    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %d %f", stu[i].name, &stu[i].roll, &stu[i].marks);
    }

    fclose(fp);
    printf("Data read from file:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\nRoll: %d\nMarks: %.2f\n", stu[i].name, stu[i].roll, stu[i].marks);
    }

    // Sorting data in ascending order of roll numbers
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stu[i].roll > stu[j].roll) {
                struct student temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }

    // Writing sorted data to file
    fp = fopen("sorted_students.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %.2f\n", stu[i].name, stu[i].roll, stu[i].marks);
    }
    fclose(fp);

    printf("Data written to file:\n");
    fp = fopen("sorted_students.txt", "r");
    if (fp == NULL) {
        printf("File not found!");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %d %.2f", stu[i].name, &stu[i].roll, &stu[i].marks);
    }
    fclose(fp);

    return 0;
}