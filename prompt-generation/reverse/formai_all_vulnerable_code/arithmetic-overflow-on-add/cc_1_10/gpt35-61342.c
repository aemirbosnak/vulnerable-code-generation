//FormAI DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
    char name[50], rollno[20], grade[2];
    int marks[5], totalMarks, per;
}stud[100];

void getResult(int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        stud[i].per = (stud[i].totalMarks / 5);
        if(stud[i].per >= 90 && stud[i].per <= 100)
            strcpy(stud[i].grade, "A+");
        else if(stud[i].per >= 80 && stud[i].per < 90)
            strcpy(stud[i].grade, "A");
        else if(stud[i].per >= 70 && stud[i].per < 80)
            strcpy(stud[i].grade, "B");
        else if(stud[i].per >= 60 && stud[i].per < 70)
            strcpy(stud[i].grade, "C");
        else if(stud[i].per >= 50 && stud[i].per < 60)
            strcpy(stud[i].grade, "D");
        else if(stud[i].per >= 40 && stud[i].per < 50)
            strcpy(stud[i].grade, "E");
        else
            strcpy(stud[i].grade, "F");
    }
}

void printResult(int n) {
    int i, j;
    printf("\n\nName\tRoll No.\tSubject 1\tSubject 2\tSubject 3\tSubject 4\tSubject 5\tTotal Marks\tPercentage\tGrade\n\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%s\t\t", stud[i].name, stud[i].rollno);
        for(j = 0; j < 5; j++)
            printf("%d\t\t", stud[i].marks[j]);
        printf("%d\t\t", stud[i].totalMarks);
        printf("%d\t\t", stud[i].per);
        printf("%s\n", stud[i].grade);
    }
}

int main() {
    int i, j, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the details of student %d:\n", i+1);
        printf("Enter the name of the student: ");
        scanf("%s", &stud[i].name);
        printf("Enter the roll no. of the student: ");
        scanf("%s", &stud[i].rollno);
        printf("Enter the marks for subject 1: ");
        scanf("%d", &stud[i].marks[0]);
        printf("Enter the marks for subject 2: ");
        scanf("%d", &stud[i].marks[1]);
        printf("Enter the marks for subject 3: ");
        scanf("%d", &stud[i].marks[2]);
        printf("Enter the marks for subject 4: ");
        scanf("%d", &stud[i].marks[3]);
        printf("Enter the marks for subject 5: ");
        scanf("%d", &stud[i].marks[4]);
        stud[i].totalMarks = stud[i].marks[0] + stud[i].marks[1] + stud[i].marks[2] + stud[i].marks[3] + stud[i].marks[4];
    }

    getResult(n);
    printResult(n);

    return 0;
}