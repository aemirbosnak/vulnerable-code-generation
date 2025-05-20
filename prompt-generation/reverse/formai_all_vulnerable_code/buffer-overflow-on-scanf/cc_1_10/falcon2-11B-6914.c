//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    int id;
    char name[100];
};

void insert_student(struct student* students, int id, char* name) {
    students[id].id = id;
    strcpy(students[id].name, name);
}

void display_student(struct student* students, int id) {
    printf("ID: %d\n", students[id].id);
    printf("Name: %s\n", students[id].name);
}

int main() {
    struct student students[100];
    int num_students = 0;

    while (1) {
        printf("Enter the ID of the student (0 to exit): ");
        int id = scanf("%d", &id);

        if (id == 0) {
            break;
        }

        char name[100];
        printf("Enter the name of the student: ");
        fgets(name, sizeof(name), stdin);

        if (id >= 100) {
            printf("Student ID is out of range.\n");
            continue;
        }

        insert_student(students, id, name);
        num_students++;

        printf("Student inserted successfully.\n");
        printf("Total number of students: %d\n", num_students);

        printf("Do you want to insert another student? (y/n): ");
        char response;
        scanf(" %c", &response);

        if (response!= 'y') {
            break;
        }
    }

    for (int i = 0; i < num_students; i++) {
        display_student(students, i);
    }

    return 0;
}