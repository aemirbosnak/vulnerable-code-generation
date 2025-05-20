//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[100];
    int roll_no;
    int marks;
} student;

int main() {
    int n, i, j, choice;
    student students[100];
    char filename[100];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the name, roll number and marks of each student:\n");
    for (i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll No.: ");
        scanf("%d", &students[i].roll_no);

        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("Enter the filename to save the data: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot create file.\n");
        exit(1);
    }

    fprintf(fp, "Name\tRoll No.\tMarks\n");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s\t%d\t%d\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    fclose(fp);

    printf("Data saved to file.\n");

    printf("Enter 1 to display the data.\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Name\tRoll No.\tMarks\n");
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: Cannot open file.\n");
            exit(1);
        }

        while (fscanf(fp, "%s\t%d\t%d", students[i].name, &students[i].roll_no, &students[i].marks)!= EOF) {
            printf("%s\t%d\t%d\n", students[i].name, students[i].roll_no, students[i].marks);
            i++;
        }

        fclose(fp);
    }

    return 0;
}