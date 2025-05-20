//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    char name[30];
} Student;

// Function to compare two students (for sorting)
int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return (studentA->key - studentB->key);
}

// Function to print student details
void printStudents(Student students[], int size) {
    printf("\nSorted student list:\n");
    printf("Key\tName\n");
    printf("---------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\n", students[i].key, students[i].name);
    }
}

// Function to enter student details
void enterStudents(Student students[], int *size) {
    printf("Enter the number of students (max %d): ", MAX_SIZE);
    scanf("%d", size);
    
    if (*size > MAX_SIZE || *size < 1) {
        printf("Invalid number of students! Please enter a number between 1 and %d.\n", MAX_SIZE);
        exit(1);
    }

    for (int i = 0; i < *size; i++) {
        printf("Enter details for student %d\n", i + 1);
        printf("Key: ");
        scanf("%d", &students[i].key);
        printf("Name: ");
        scanf("%s", students[i].name);
    }
}

// Function to sort students using qsort
void sortStudents(Student students[], int size) {
    qsort(students, size, sizeof(Student), compare);
}

int main() {
    Student students[MAX_SIZE];
    int size = 0;

    // Enter student details
    enterStudents(students, &size);
    
    // Sort the students
    sortStudents(students, size);
    
    // Print sorted students
    printStudents(students, size);

    return 0;
}