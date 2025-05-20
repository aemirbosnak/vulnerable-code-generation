//FormAI DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

int main() {
    int num_students, choice, i;
    float total = 0;
    Student* students = NULL;

    printf("How many students are there in the class? ");
    scanf("%d", &num_students);

    students = (Student*)malloc(num_students * sizeof(Student));

    if (students == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    for (i = 0; i < num_students; i++) {
        printf("Enter student #%d ID: ", i+1);
        scanf("%d", &(students[i].id));
        printf("Enter student #%d name: ", i+1);
        scanf("%s", &(students[i].name));
        printf("Enter student #%d grade: ", i+1);
        scanf("%f", &(students[i].grade));
        total += students[i].grade;
    }

    printf("\nMENU:\n");
    printf("1) Print all students\n");
    printf("2) Print the average grade\n");
    printf("3) Exit\n");
    do {
        printf("Choice [1-3]: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nList of students:\n");
                printf("ID\tName\tGrade\n");
                for (i = 0; i < num_students; i++) {
                    printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
                }
                printf("\n");
                break;
            case 2:
                printf("\nThe average grade is %.2f.\n\n", total/num_students);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);

    free(students);

    return 0;
}