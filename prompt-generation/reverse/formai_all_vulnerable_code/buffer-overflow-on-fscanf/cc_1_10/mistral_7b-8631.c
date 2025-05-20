//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_NUM 100
#define SIZE 10

struct Student {
    char name[SIZE];
    int roll_no;
    float marks;
};

void readFile(const char *filename, struct Student students[MAX_NUM]) {
    int i = 0;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%[^,],%d,%f\n", students[i].name, &students[i].roll_no, &students[i].marks) != EOF) {
        i++;
    }

    fclose(fp);
}

void writeFile(const char *filename, const struct Student students[MAX_NUM]) {
    int i;
    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAX_NUM; i++) {
        fprintf(fp, "%s,%d,%.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    fclose(fp);
}

void searchStudent(const struct Student students[MAX_NUM], int roll_no) {
    int i;

    for (i = 0; i < MAX_NUM; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Student found:\nName: %s\nRoll No: %d\nMarks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    char filename[] = "students.csv";
    struct Student students[MAX_NUM];
    int roll_no;

    readFile(filename, students);

    printf("Enter roll number to search for a student: ");
    scanf("%d", &roll_no);

    searchStudent(students, roll_no);

    printf("Do you want to update the student record? (y/n)\n");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y') {
        printf("Enter new name: ");
        scanf("%s", students[0].name);
        printf("Enter new roll number: ");
        scanf("%d", &students[0].roll_no);
        printf("Enter new marks: ");
        scanf("%f", &students[0].marks);

        writeFile(filename, students);
        printf("Student record updated successfully.\n");
    }

    return 0;
}