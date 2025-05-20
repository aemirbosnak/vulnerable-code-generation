//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
/* This program reads and stores student information in a file by using C file handling. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    FILE *fp;
    Student student;
    char fn[50];
    int choice;
    int count = 0;

    printf("Enter the file name: ");
    scanf("%s", fn);

    fp = fopen(fn, "rb");
    if(fp == NULL) {
        printf("File not found. Creating a new file.\n");
        fp = fopen(fn, "wb");
        if(fp == NULL) {
            printf("Cannot create file.\n");
            exit(1);
        }
    }
    else {
        while(fread(&student, sizeof(Student), 1, fp) == 1) {
            printf("%s\t%d\t%.2f\n", student.name, student.age, student.gpa);
            count++;
        }
        fclose(fp);
        printf("\n%d records found.\n", count);
    }

    printf("\n1. Add a Student\n2. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    fp = fopen(fn, "ab");
    if(fp == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while(choice == 1) {
        printf("Enter name: ");
        scanf("%s", student.name);
        printf("Enter age: ");
        scanf("%d", &student.age);
        printf("Enter GPA: ");
        scanf("%f", &student.gpa);

        fwrite(&student, sizeof(Student), 1, fp);
        printf("\n%s has been added to the file.\n", student.name);

        count++;

        printf("\n1. Add a Student\n2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    fclose(fp);
    printf("\n%d records written to file.\n", count);

    return 0;
}