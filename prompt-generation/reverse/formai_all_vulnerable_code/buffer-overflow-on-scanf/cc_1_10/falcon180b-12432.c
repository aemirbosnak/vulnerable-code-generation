//Falcon-180B DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int roll_no;
    float marks;
} student;

void read_students(student *students, int num_students) {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < num_students; i++) {
        fscanf(fp, "%s %d %f", students[i].name, &students[i].roll_no, &students[i].marks);
    }
    fclose(fp);
}

void write_students(student *students, int num_students) {
    FILE *fp;
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "%s %d %f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
    fclose(fp);
}

void display_students(student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

void sort_students(student *students, int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = i + 1; j < num_students; j++) {
            if (students[j].marks > students[i].marks) {
                student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    student students[MAX_SIZE];
    int num_students;
    
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    
    read_students(students, num_students);
    display_students(students, num_students);
    sort_students(students, num_students);
    display_students(students, num_students);
    
    return 0;
}