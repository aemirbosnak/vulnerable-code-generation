//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[100];
    int rollno;
    int marks[5];
    float avg;
} student;

void main() {
    int n, i, j, k;
    char ch;
    student s[100];

    printf("\nEnter number of students: ");
    scanf("%d", &n);

    printf("\nEnter details of %d students:\n", n);

    for (i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter roll number of student %s: ", s[i].name);
        scanf("%d", &s[i].rollno);

        for (j = 0; j < 5; j++) {
            printf("Enter marks in subject %d for student %s: ", j + 1, s[i].name);
            scanf("%d", &s[i].marks[j]);
        }

        s[i].avg = 0.0;
        for (k = 0; k < 5; k++) {
            s[i].avg += s[i].marks[k];
        }
        s[i].avg /= 5.0;
    }

    printf("\nName\tRoll No.\tMarks\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%d\t", s[i].name, s[i].rollno);

        for (j = 0; j < 5; j++) {
            printf("%d\t", s[i].marks[j]);
        }
        printf("\n");
    }

    printf("\nPress any key to exit.");
    scanf("%c", &ch);
}