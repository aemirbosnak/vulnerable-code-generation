//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define the structure of the data to be searched
typedef struct {
    int id;
    char name[20];
    int age;
    float grade;
} Student;

// Function to compare two students based on their IDs
int compare(const void *a, const void *b) {
    Student *studentA = (Student *) a;
    Student *studentB = (Student *) b;

    if (studentA->id < studentB->id) {
        return -1;
    } else if (studentA->id > studentB->id) {
        return 1;
    } else {
        return 0;
    }
}

// Function to search for a student with a specific ID
Student *binarySearch(Student *students, int size, int targetID) {
    qsort(students, size, sizeof(Student), compare);

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (students[mid].id == targetID) {
            return &students[mid];
        } else if (students[mid].id < targetID) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return NULL;
}

int main() {
    Student students[MAX];
    int size = 0;

    // Read data from a file and store it in an array
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    while (fscanf(file, "%d %s %d %f", &students[size].id, students[size].name, &students[size].age, &students[size].grade) == 4) {
        size++;
    }

    fclose(file);

    // Sort the array using the ID as the key
    qsort(students, size, sizeof(Student), compare);

    // Search for a student with a specific ID
    int targetID = 123;
    Student *result = binarySearch(students, size, targetID);

    if (result == NULL) {
        printf("Student with ID %d not found.\n", targetID);
    } else {
        printf("Student with ID %d found:\n", result->id);
        printf("Name: %s\n", result->name);
        printf("Age: %d\n", result->age);
        printf("Grade: %.2f\n", result->grade);
    }

    return 0;
}