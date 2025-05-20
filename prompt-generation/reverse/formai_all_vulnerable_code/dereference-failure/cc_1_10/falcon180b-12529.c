//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int roll_no;
}student;

void add_student(student *s) {
    printf("Enter the name of the student: ");
    scanf("%s", s->name);
    printf("Enter the roll number of the student: ");
    scanf("%d", &s->roll_no);
}

int main() {

    FILE *fp;
    student s[MAX_SIZE];
    int count = 0;
    char ch;
    int found = 0;
    int choice;

    fp = fopen("students.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while((ch = fgetc(fp))!= EOF) {
        if(ch == '\n') {
            count++;
        }
    }

    rewind(fp);

    if(count == 0) {
        printf("No students found in the file\n");
        exit(0);
    }

    printf("Enter the name of the student to search for: ");
    scanf("%s", s[0].name);

    while(fscanf(fp, "%s %d", s[0].name, &s[0].roll_no)!= EOF) {
        if(strcmp(s[0].name, s[count-1].name) == 0) {
            found = 1;
            break;
        }
        count++;
    }

    if(found == 1) {
        printf("Student found with roll number %d\n", s[count-1].roll_no);
    } else {
        printf("Student not found in the file\n");
    }

    fclose(fp);

    return 0;
}