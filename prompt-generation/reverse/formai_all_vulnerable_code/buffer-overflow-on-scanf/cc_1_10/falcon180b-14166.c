//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    float grade;
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    if (studentA->age > studentB->age) {
        return 1;
    } else if (studentA->age < studentB->age) {
        return -1;
    } else {
        return 0;
    }
}

void sort(Student *students, int numStudents) {
    qsort(students, numStudents, sizeof(Student), compare);
}

int main() {
    int numStudents;
    scanf("%d", &numStudents);

    Student *students = (Student *)malloc(numStudents * sizeof(Student));

    for (int i = 0; i < numStudents; i++) {
        students[i].name = (char *)malloc(MAX_SIZE * sizeof(char));
        scanf("%s", students[i].name);
        scanf("%d", &students[i].age);
        scanf("%f", &students[i].grade);
    }

    sort(students, numStudents);

    printf("Sorted by age:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    free(students);
    return 0;
}