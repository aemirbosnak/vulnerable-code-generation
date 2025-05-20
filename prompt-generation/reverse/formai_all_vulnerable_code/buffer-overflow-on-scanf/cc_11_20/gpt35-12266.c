//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    float cgpa;
};

int main() {
    struct student s[100];
    int choice, count = 0, i = 0, id;
    float cgpa;
    char name[50];

    while(1) {
        printf("\n********** C Database Simulation **********\n");
        printf("1. Add student\n");
        printf("2. Search student by ID\n");
        printf("3. Search student by name\n");
        printf("4. Display all students\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add student
                printf("\nEnter student name: ");
                scanf("%s", s[count].name);
                printf("Enter student ID: ");
                scanf("%d", &s[count].id);
                printf("Enter student CGPA: ");
                scanf("%f", &s[count].cgpa);
                count++;
                printf("Student added successfully!\n");
                break;

            case 2: // Search student by ID
                printf("\nEnter student ID: ");
                scanf("%d", &id);

                for(i=0; i<count; i++) {
                    if(s[i].id == id) {
                        printf("\nStudent found!\n");
                        printf("ID: %d, Name: %s, CGPA: %.2f\n", s[i].id, s[i].name, s[i].cgpa);
                        break;
                    }
                }
                if(i == count) {
                    printf("Student with ID %d not found!\n", id);
                }
                break;

            case 3: // Search student by name
                printf("\nEnter student name: ");
                scanf("%s", name);

                for(i=0; i<count; i++) {
                    if(strcmp(s[i].name, name) == 0) {
                        printf("\nStudent found!\n");
                        printf("ID: %d, Name: %s, CGPA: %.2f\n", s[i].id, s[i].name, s[i].cgpa);
                        break;
                    }
                }
                if(i == count) {
                    printf("Student with name %s not found!\n", name);
                }
                break;

            case 4: // Display all students
                printf("\nTotal number of students: %d\n", count);
                for(i=0; i<count; i++) {
                    printf("ID: %d, Name: %s, CGPA: %.2f\n", s[i].id, s[i].name, s[i].cgpa);
                }
                break;

            case 5: // Exit
                printf("\nThank you for using C Database Simulation!\n");
                return EXIT_SUCCESS;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
}