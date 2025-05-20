//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[30];
    int age;
    float gpa;
} Student;

typedef struct Index {
    char name[30];
    int offset;
} Index;

Student* read_student(int id, char* name, int age, float gpa) {
    Student* student = (Student*)malloc(sizeof(Student));
    student->id = id;
    strcpy(student->name, name);
    student->age = age;
    student->gpa = gpa;
    return student;
}

Index* create_index(char* name, int offset) {
    Index* index = (Index*)malloc(sizeof(Index));
    strcpy(index->name, name);
    index->offset = offset;
    return index;
}

void put(Student** students, Index** indices, char* name, int count) {
    // adding new student
    int id;
    char sname[30];
    int age;
    float gpa;
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Name: ");
    scanf("%s", sname);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter GPA: ");
    scanf("%f", &gpa);
    students[count] = read_student(id, sname, age, gpa);
    // adding to indices
    int indexCount = count;
    while (indexCount > 0 && strcmp(name, indices[indexCount-1]->name) < 0) {
        indices[indexCount] = indices[indexCount-1];
        indexCount--;
    }
    indices[indexCount] = create_index(name, count);
}

int search(Index** indices, char* name, int count) {
    // binary search on indices
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (strcmp(name, indices[mid]->name) == 0) {
            return indices[mid]->offset;
        } else if (strcmp(name, indices[mid]->name) < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void display(Student** students, int count) {
    for (int i=0; i<count; i++) {
        printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", students[i]->id, students[i]->name, students[i]->age, students[i]->gpa);
    }
}

int main() {
    // initialize database
    Student* students[100];
    Index* indices[100];
    int count = 0;

    // menu
    int choice = -1;
    while (choice != 4) {
        printf("\n1. New Student\n2. Search by Name\n3. Display All\n4. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Name for Indexing: ");
                char name[30];
                scanf("%s", name);
                put(students, indices, name, count);
                count++;
                break;
            case 2:
                printf("Enter Name to Search: ");
                char searchName[30];
                scanf("%s", searchName);
                int offset = search(indices, searchName, count);
                if (offset != -1) {
                    printf("Student Found: \n");
                    printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", students[offset]->id, students[offset]->name, students[offset]->age, students[offset]->gpa);
                } else {
                    printf("Student Not Found!\n");
                }
                break;
            case 3:
                display(students, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    // free memory
    for (int i=0; i<count; i++) {
        free(students[i]);
        free(indices[i]);
    }
    return 0;
}