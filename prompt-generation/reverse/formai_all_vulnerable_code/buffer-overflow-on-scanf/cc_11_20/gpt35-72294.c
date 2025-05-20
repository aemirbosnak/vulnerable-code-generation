//FormAI DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    int num_students = 0;
    struct Student* database = NULL;
    int choice;

    printf("Welcome to the Student Database Simulation!\n\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add a new student\n");
        printf("2. Remove a student\n");
        printf("3. View all students\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a new student
                num_students++;
                database = realloc(database, num_students * sizeof(struct Student));

                printf("\nEnter student's name: ");
                scanf("%s", database[num_students - 1].name);
                printf("Enter student's ID: ");
                scanf("%d", &database[num_students - 1].id);
                printf("Enter student's GPA: ");
                scanf("%f", &database[num_students - 1].gpa);

                printf("\nStudent added successfully!\n\n");
                break;

            case 2: // Remove a student
                if (num_students == 0) {
                    printf("\nNo students in the database.\n\n");
                    break;
                }

                int id_to_remove;
                printf("Enter the ID of the student to remove: ");
                scanf("%d", &id_to_remove);

                int found_index = -1;
                for (int i = 0; i < num_students; i++) {
                    if (database[i].id == id_to_remove) {
                        found_index = i;
                        break;
                    }
                }

                if (found_index == -1) {
                    printf("\nStudent not found.\n\n");
                    break;
                }

                for (int i = found_index; i < num_students - 1; i++) {
                    database[i] = database[i + 1];
                }
                num_students--;
                database = realloc(database, num_students * sizeof(struct Student));

                printf("\nStudent removed successfully!\n\n");
                break;

            case 3: // View all students
                printf("\n%-20s%-10s%-5s\n", "Name", "ID", "GPA");
                printf("---------------------------------------------\n");
                for (int i = 0; i < num_students; i++) {
                    printf("%-20s%-10d%-5.2f\n", database[i].name, database[i].id, database[i].gpa);
                }
                printf("\n");
                break;

            case 4: // Exit
                printf("\nThank you for using the Student Database Simulation!\n\n");
                exit(0);

            default: // Invalid choice
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}