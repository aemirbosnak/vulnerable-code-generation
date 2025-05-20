//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Student;

void initializeStudents(Student students[], int count);
void printStudents(const Student students[], int count);
int linearSearch(const Student students[], int count, int targetId);
int binarySearch(const Student students[], int left, int right, int targetId);
void sortStudents(Student students[], int count);

int main() {
    Student students[MAX_SIZE];
    int studentCount;

    printf("Enter number of students (max %d): ", MAX_SIZE);
    scanf("%d", &studentCount);

    if (studentCount > MAX_SIZE || studentCount < 1) {
        printf("Invalid number of students!\n");
        return 1;
    }

    initializeStudents(students, studentCount);
    printf("\nList of Students:\n");
    printStudents(students, studentCount);

    sortStudents(students, studentCount);
    printf("\nSorted List of Students:\n");
    printStudents(students, studentCount);

    int targetId;
    printf("\nEnter Student ID to search: ");
    scanf("%d", &targetId);

    int index = binarySearch(students, 0, studentCount - 1, targetId);
    if (index != -1) {
        printf("\nStudent found: ID = %d, Name = %s\n", students[index].id, students[index].name);
    } else {
        printf("\nStudent with ID %d not found.\n", targetId);
    }

    return 0;
}

void initializeStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        students[i].id = rand() % 100 + 1;  // Random ID between 1 and 100
        snprintf(students[i].name, MAX_NAME_LEN, "Student_%d", students[i].id);
    }
}

void printStudents(const Student students[], int count) {
    printf("%-10s%-20s\n", "Student ID", "Name");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d%-20s\n", students[i].id, students[i].name);
    }
}

int linearSearch(const Student students[], int count, int targetId) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == targetId) {
            return i;
        }
    }
    return -1;
}

void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int binarySearch(const Student students[], int left, int right, int targetId) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].id == targetId) {
            return mid;
        }

        if (students[mid].id < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}