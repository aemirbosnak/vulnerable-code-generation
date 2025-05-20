//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    int roll_no;
    int marks[5];
    float avg;
} student;

void add_student(student *s) {
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter roll number: ");
    scanf("%d", &s->roll_no);
    for(int i=0;i<5;i++) {
        printf("Enter marks for subject %d: ", i+1);
        scanf("%d", &s->marks[i]);
    }
    s->avg = (float)s->marks[0]+s->marks[1]+s->marks[2]+s->marks[3]+s->marks[4]/5;
}

void display_student(student s) {
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.roll_no);
    printf("Average Marks: %.2f\n", s.avg);
}

void sort_students(student *s, int n, char sort_by) {
    switch(sort_by) {
        case 'n':
            for(int i=0;i<n-1;i++) {
                for(int j=0;j<n-i-1;j++) {
                    if(strcmp(s[j].name, s[j+1].name)>0) {
                        student temp = s[j];
                        s[j] = s[j+1];
                        s[j+1] = temp;
                    }
                }
            }
            break;
        case 'r':
            for(int i=0;i<n-1;i++) {
                for(int j=0;j<n-i-1;j++) {
                    if(s[j].roll_no > s[j+1].roll_no) {
                        student temp = s[j];
                        s[j] = s[j+1];
                        s[j+1] = temp;
                    }
                }
            }
            break;
        case'm':
            for(int i=0;i<n-1;i++) {
                for(int j=0;j<n-i-1;j++) {
                    if(s[j].avg > s[j+1].avg) {
                        student temp = s[j];
                        s[j] = s[j+1];
                        s[j+1] = temp;
                    }
                }
            }
            break;
        default:
            printf("Invalid sort option!\n");
            break;
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    student *s = (student*)malloc(n*sizeof(student));
    for(int i=0;i<n;i++) {
        add_student(&s[i]);
    }
    char sort_by;
    printf("Sort by (n)ame, (r)oll number, or (m)arks: ");
    scanf(" %c", &sort_by);
    sort_students(s, n, sort_by);
    printf("Sorted list of students:\n");
    for(int i=0;i<n;i++) {
        display_student(s[i]);
    }
    return 0;
}