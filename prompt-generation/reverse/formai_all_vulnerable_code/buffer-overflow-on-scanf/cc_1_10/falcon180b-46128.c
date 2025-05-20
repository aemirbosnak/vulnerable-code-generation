//Falcon-180B DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Structure for a student
struct student {
    int id;
    char name[50];
    float grade;
};

void swap(struct student* a, struct student* b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    struct student* studentA = (struct student*)a;
    struct student* studentB = (struct student*)b;

    if (studentA->grade > studentB->grade)
        return 1;
    else if (studentA->grade < studentB->grade)
        return -1;
    else
        return 0;
}

void printStudents(struct student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct student students[size];

    printf("Enter student information:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    qsort(students, size, sizeof(struct student), compare);

    printf("\nSorted by grade in descending order:\n");
    printStudents(students, size);

    return 0;
}