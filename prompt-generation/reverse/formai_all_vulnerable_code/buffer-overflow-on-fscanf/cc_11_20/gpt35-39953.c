//FormAI DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    int age;
    float gpa;
};

int main() {
    int choice, i, n, found = 0, id;
    struct student s;
    FILE *fp;

    // start screen
    printf("\n\t\tWelcome to Retro C Database Simulation\n\n");
    printf("\nPress 1 to add student\n");
    printf("Press 2 to display all students\n");
    printf("Press 3 to search for a student\n");
    printf("Press 4 to delete a student\n");
    printf("Press 0 to exit\n");

    // main loop
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // add student
                fp = fopen("students.txt", "a");
                printf("\nAdding student\n");

                printf("Enter ID: ");
                scanf("%d", &s.id);

                printf("Enter name: ");
                scanf("%s", s.name);

                printf("Enter age: ");
                scanf("%d", &s.age);

                printf("Enter GPA: ");
                scanf("%f", &s.gpa);

                fprintf(fp, "%d %s %d %f\n", s.id, s.name, s.age, s.gpa);
                fclose(fp);
                break;

            case 2:
                // display all students
                printf("\nDisplaying all students\n");
                fp = fopen("students.txt", "r");
                if (fp != NULL) {
                    while (fscanf(fp, "%d %s %d %f", &s.id, s.name, &s.age, &s.gpa) != EOF) {
                        printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", s.id, s.name, s.age, s.gpa);
                    }
                    fclose(fp);
                }
                else {
                    printf("Error: File not found\n");
                }
                break;

            case 3:
                // search for student
                printf("\nSearching for student\n");
                fp = fopen("students.txt", "r");
                printf("Enter ID: ");
                scanf("%d", &id);

                while (fscanf(fp, "%d %s %d %f", &s.id, s.name, &s.age, &s.gpa) != EOF) {
                    if (s.id == id) {
                        printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", s.id, s.name, s.age, s.gpa);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Student with ID %d not found\n", id);
                }
                fclose(fp);
                break;

            case 4:
                // delete student
                printf("\nDeleting student\n");
                fp = fopen("students.txt", "r");
                FILE *temp = fopen("temp.txt", "w");
                printf("Enter ID: ");
                scanf("%d", &id);

                while (fscanf(fp, "%d %s %d %f", &s.id, s.name, &s.age, &s.gpa) != EOF) {
                    if (s.id != id) {
                        fprintf(temp, "%d %s %d %f\n", s.id, s.name, s.age, s.gpa);
                    }
                    else {
                        found = 1;
                    }
                }
                fclose(fp);
                fclose(temp);

                if (found) {
                    remove("students.txt");
                    rename("temp.txt", "students.txt");
                    printf("Student with ID %d deleted\n", id);
                }
                else {
                    remove("temp.txt");
                    printf("Student with ID %d not found\n", id);
                }
                break;

            case 0:
                // exit program
                printf("\nExiting program\n");
                exit(0);

            default:
                // handle invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}