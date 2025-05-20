//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    float marks;
};

struct student *add_student(struct student *s) {
    struct student *temp = (struct student *)malloc(sizeof(struct student));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter student name: ");
    scanf("%s", temp->name);
    printf("Enter student roll number: ");
    scanf("%d", &temp->roll_no);
    printf("Enter student marks: ");
    scanf("%f", &temp->marks);
    s = temp;
    return s;
}

void display_students(struct student *s) {
    printf("Student Name: %s\n", s->name);
    printf("Roll Number: %d\n", s->roll_no);
    printf("Marks: %f\n", s->marks);
}

void delete_student(struct student *s) {
    free(s);
    s = NULL;
}

int main() {
    struct student *s = NULL;
    int choice = 0;

    while (choice!= 5) {
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Delete student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                s = add_student(s);
                break;
            case 2:
                if (s!= NULL) {
                    display_students(s);
                } else {
                    printf("No students to display\n");
                }
                break;
            case 3:
                if (s!= NULL) {
                    printf("Enter student roll number to delete: ");
                    scanf("%d", &s->roll_no);
                    delete_student(s);
                } else {
                    printf("No students to delete\n");
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}