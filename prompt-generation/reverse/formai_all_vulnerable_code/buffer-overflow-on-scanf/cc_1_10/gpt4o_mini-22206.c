//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float grade;
} Student;

void inputStudents(Student students[], int count);
void printStudents(const Student students[], int count);
int compareStudents(const void *a, const void *b);
void sortStudents(Student students[], int count);

int main() {
    int studentCount = 0;
    Student students[MAX_STUDENTS];

    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &studentCount);
    
    if (studentCount > MAX_STUDENTS || studentCount <= 0) {
        fprintf(stderr, "Invalid number of students.\n");
        return EXIT_FAILURE;
    }

    inputStudents(students, studentCount);
    printf("\nStudents before sorting:\n");
    printStudents(students, studentCount);
    
    sortStudents(students, studentCount);
    
    printf("\nStudents after sorting by grade and then by name:\n");
    printStudents(students, studentCount);

    return EXIT_SUCCESS;
}

void inputStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name); // Read string with spaces
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }
}

void printStudents(const Student students[], int count) {
    printf("%-30s %-5s %-5s\n", "Name", "Age", "Grade");
    printf("%-30s %-5s %-5s\n", "------------------------------", "------", "-----");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-5d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

int compareStudents(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;

    if (studentA->grade != studentB->grade) {
        return (studentA->grade < studentB->grade) ? 1 : -1; // Sort in descending order
    } else {
        return strcmp(studentA->name, studentB->name); // Sort by name in ascending order
    }
}

void sortStudents(Student students[], int count) {
    qsort(students, count, sizeof(Student), compareStudents);
}