//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 200

struct student {
    char name[50];
    int roll_no;
    float marks;
};

void add_student(struct student *students, int *num_students) {
    printf("Enter the name of the student: ");
    scanf("%s", (*num_students == 0)? students[0].name : students[*num_students - 1].name);
    printf("Enter the roll number of the student: ");
    scanf("%d", &students[*num_students].roll_no);
    printf("Enter the marks of the student: ");
    scanf("%f", &students[*num_students].marks);
    (*num_students)++;
}

void display_students(struct student *students, int num_students) {
    printf("\nName\tRoll Number\tMarks\n");
    for(int i = 0; i < num_students; i++) {
        printf("%s\t%d\t%.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

void sort_students(struct student *students, int num_students) {
    for(int i = 0; i < num_students - 1; i++) {
        for(int j = i + 1; j < num_students; j++) {
            if(students[j].marks > students[i].marks) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void save_to_file(struct student *students, int num_students, char *filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "Name\tRoll Number\tMarks\n");
    for(int i = 0; i < num_students; i++) {
        fprintf(fp, "%s\t%d\t%.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
    fclose(fp);
    printf("Data saved to file %s\n", filename);
}

void load_from_file(struct student *students, int *num_students, char *filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    char line[200];
    while(fgets(line, 200, fp)!= NULL) {
        sscanf(line, "%s\t%d\t%.2f", students[*num_students].name, &students[*num_students].roll_no, &students[*num_students].marks);
        (*num_students)++;
    }
    fclose(fp);
    printf("Data loaded from file %s\n", filename);
}

int main() {
    struct student students[SIZE];
    int num_students = 0;

    add_student(students, &num_students);
    add_student(students, &num_students);
    add_student(students, &num_students);
    add_student(students, &num_students);

    display_students(students, num_students);

    sort_students(students, num_students);

    save_to_file(students, num_students, "students.txt");

    load_from_file(students, &num_students, "students.txt");

    display_students(students, num_students);

    return 0;
}