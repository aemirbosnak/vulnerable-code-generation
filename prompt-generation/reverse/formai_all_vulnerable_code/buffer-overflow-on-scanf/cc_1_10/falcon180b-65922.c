//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int roll_no;
    int marks;
} STUDENT;

void swap(STUDENT *a, STUDENT *b) {
    STUDENT temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    STUDENT *stu_a = (STUDENT *)a;
    STUDENT *stu_b = (STUDENT *)b;
    return strcmp(stu_a->name, stu_b->name);
}

int main() {
    int n, i, j, choice;
    char ch;
    STUDENT students[MAX_SIZE];
    FILE *fp;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the details of %d students:\n", n);
    for(i=0; i<n; i++) {
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("\nSorted by Name:\n");
    qsort(students, n, sizeof(STUDENT), compare);
    for(i=0; i<n; i++) {
        printf("%s %d %d\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    printf("\nDo you want to sort by Roll No? (y/n): ");
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y') {
        printf("\nSorted by Roll No:\n");
        qsort(students, n, sizeof(STUDENT), compare);
        for(i=0; i<n; i++) {
            printf("%s %d %d\n", students[i].name, students[i].roll_no, students[i].marks);
        }
    }

    printf("\nDo you want to sort by Marks? (y/n): ");
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y') {
        printf("\nSorted by Marks:\n");
        qsort(students, n, sizeof(STUDENT), compare);
        for(i=0; i<n; i++) {
            printf("%s %d %d\n", students[i].name, students[i].roll_no, students[i].marks);
        }
    }

    return 0;
}