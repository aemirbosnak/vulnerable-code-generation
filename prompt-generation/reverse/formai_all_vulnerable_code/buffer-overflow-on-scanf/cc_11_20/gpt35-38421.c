//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int age;
} Student;

int main() {
    int choice, id, i, flag, count = 0;
    Student *students = NULL;

    printf("Welcome to the Student Database Simulation!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a Student\n");
        printf("2. Search for a Student\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count++;
                printf("\nEnter Student ID: ");
                scanf("%d", &id);

                flag = 0;
                for (i = 0; i < count - 1; i++) {
                    if (students[i].id == id) {
                        printf("Student with ID %d already exists in the database!\n", id);
                        flag = 1;
                        count--;
                        break;
                    }
                }

                if (flag == 0) {
                    students = (Student*) realloc(students, sizeof(Student) * count);

                    students[count - 1].id = id;

                    printf("Enter Student Name: ");
                    getchar();
                    fgets(students[count - 1].name, 30, stdin);

                    printf("Enter Student Age: ");
                    scanf("%d", &students[count - 1].age);

                    printf("Student with ID %d has been added to the database!\n", id);
                }
                break;

            case 2:
                printf("\nEnter Student ID to Search: ");
                scanf("%d", &id);

                flag = 0;
                for (i = 0; i < count; i++) {
                    if (students[i].id == id) {
                        printf("Student %d: %s - %d years old\n", students[i].id, students[i].name, students[i].age);
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    printf("Student with ID %d not found!\n", id);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo Students found in the Database!\n");
                }
                else {
                    printf("\nList of Students:\n");
                    for (i = 0; i < count; i++) {
                        printf("%d: %s - %d years old\n", students[i].id, students[i].name, students[i].age);
                    }
                }
                break;

            case 4:
                printf("\nThank you for using the Student Database Simulation!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
                break;
        }
    } while (choice != 4);

    free(students);
    return 0;
}