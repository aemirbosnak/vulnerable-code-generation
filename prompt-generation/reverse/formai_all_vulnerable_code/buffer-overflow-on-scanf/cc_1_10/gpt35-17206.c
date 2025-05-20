//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int age;
    float gpa;
} Student;

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student* students = malloc(num_students * sizeof(Student));
    memset(students, 0, num_students * sizeof(Student));

    FILE* fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < num_students; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter student %d age: ", i + 1);
        scanf("%d", &students[i].age);

        printf("Enter student %d GPA: ", i + 1);
        scanf("%f", &students[i].gpa);

        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    fclose(fp);

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    Student* read_students = malloc(num_students * sizeof(Student));
    memset(read_students, 0, num_students * sizeof(Student));

    for (int i = 0; i < num_students; i++) {
        fscanf(fp, "%s%d%f", read_students[i].name, &read_students[i].age, &read_students[i].gpa);
    }

    fclose(fp);

    printf("Here are the students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s is %d years old and has a GPA of %.2f\n", read_students[i].name, read_students[i].age, read_students[i].gpa);
    }

    free(students);
    free(read_students);

    return 0;
}