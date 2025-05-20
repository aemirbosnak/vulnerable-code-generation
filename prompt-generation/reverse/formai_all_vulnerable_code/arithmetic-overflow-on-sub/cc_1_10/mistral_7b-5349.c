//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 1000
#define MIN_NUM 0
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;
void swap(Student* a, Student* b) {
    Student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(Student arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j].gpa < arr[min_idx].gpa) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}
int main() {
    srand(time(NULL));
    Student students[MAX_SIZE];
    int i, n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("\nStudent Data Entry:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i+1);
        scanf("%d", &students[i].id);
        scanf("%s", students[i].name);
        students[i].gpa = (float) rand() / RAND_MAX * 10 + MIN_NUM;
    }
    printf("\nStudent Data Before Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ID = %d, Name = %s, GPA = %.2f\n", i+1, students[i].id, students[i].name, students[i].gpa);
    }
    selectionSort(students, n);
    printf("\nStudent Data After Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ID = %d, Name = %s, GPA = %.2f\n", i+1, students[i].id, students[i].name, students[i].gpa);
    }
    return 0;
}