//Falcon-180B DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void addStudent(Student students[], int *size) {
    printf("Enter student name: ");
    scanf("%s", &(students[*size].name));
    printf("Enter student age: ");
    scanf("%d", &(students[*size].age));
    printf("Enter student grade: ");
    scanf("%f", &(students[*size].grade));
    (*size)++;
}

void displayStudents(Student students[], int size) {
    printf("Students:\n");
    for(int i = 0; i < size; i++) {
        printf("%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

int main() {
    int size = 0;
    Student students[MAX_SIZE];

    while(size < MAX_SIZE) {
        printf("\n1. Add student\n2. Display students\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &size);
                break;
            case 2:
                displayStudents(students, size);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}