#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Student;

void printStudent(Student *s) {
    printf("Name: %s\nAge: %d\n", s->name, s->age);
}

int main() {
    FILE *file;
    Student students[10];
    int choice, count = 0;

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= 10) {
                printf("Database is full!\n");
                continue;
            }
            file = fopen("students.txt", "a+");
            if (!file) {
                printf("Error opening file!\n");
                continue;
            }

            Student newStudent;
            printf("Enter name: ");
            fscanf(file, "%4s", newStudent.name); // Vulnerable line
            printf("Enter age: ");
            fscanf(file, "%d", &newStudent.age);

            fprintf(file, "%s %d\n", newStudent.name, newStudent.age);
            fclose(file);
            students[count++] = newStudent;
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                printStudent(&students[i]);
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
