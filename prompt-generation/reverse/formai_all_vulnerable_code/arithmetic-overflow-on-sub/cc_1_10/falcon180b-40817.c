//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student {
    char name[50];
    int roll_no;
    int marks[5];
};

void add_student(struct student *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter roll number: ");
    scanf("%d", &s->roll_no);
    for (int i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}

void display_student(struct student s) {
    printf("Name: %s\n", s.name);
    printf("Roll number: %d\n", s.roll_no);
    printf("Marks:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: %d\n", i + 1, s.marks[i]);
    }
}

void sort_students(struct student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].marks[0] < arr[j + 1].marks[0]) {
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student arr[n];
    for (int i = 0; i < n; i++) {
        add_student(&arr[i]);
    }
    sort_students(arr, n);
    printf("Sorted students by first subject marks:\n");
    for (int i = 0; i < n; i++) {
        display_student(arr[i]);
    }
    return 0;
}