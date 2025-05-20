//FormAI DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float gpa;
};

int main()
{
    int option = 0;
    int num_students = 0;
    struct student *students = NULL;

    while (option != 5) {
        printf("Choose an option from below:\n");
        printf("1. Add a new student\n");
        printf("2. View students by ID\n");
        printf("3. View students by name\n");
        printf("4. View students by GPA\n");
        printf("5. Quit\n");

        scanf("%d", &option);

        switch (option) {
            case 1: // Add a new student
                num_students++;
                students = realloc(students, sizeof(struct student) * num_students);

                printf("Enter the student's ID: ");
                scanf("%d", &students[num_students-1].id);

                printf("Enter the student's name: ");
                scanf("%s", &students[num_students-1].name);
                fflush(stdin);

                printf("Enter the student's GPA: ");
                scanf("%f", &students[num_students-1].gpa);

                printf("New student added!\n\n");
                break;

            case 2: // View students by ID
                if (num_students == 0) {
                    printf("No students found.\n\n");
                    break;
                }

                printf("Enter the student's ID: ");
                int id_to_find;
                scanf("%d", &id_to_find);

                for (int i = 0; i < num_students; i++) {
                    if (students[i].id == id_to_find) {
                        printf("\nID: %d\nName: %s\nGPA: %.2f\n\n", students[i].id, students[i].name, students[i].gpa);
                        break;
                    } else {
                        printf("Student not found.\n\n");
                        break;
                    }
                }
                break;

            case 3: // View students by name
                if (num_students == 0) {
                    printf("No students found.\n\n");
                    break;
                }

                printf("Enter the student's name: ");
                char name_to_find[50];
                scanf("%s", &name_to_find);
                fflush(stdin);

                for (int i = 0; i < num_students; i++) {
                    if (strcmp(students[i].name, name_to_find) == 0) {
                        printf("\nID: %d\nName: %s\nGPA: %.2f\n\n", students[i].id, students[i].name, students[i].gpa);
                        break;
                    } else {
                        printf("Student not found.\n\n");
                        break;
                    }
                }
                break;

            case 4: // View students by GPA
                if (num_students == 0) {
                    printf("No students found.\n\n");
                    break;
                }

                printf("Enter the minimum GPA: ");
                float min_gpa;
                scanf("%f", &min_gpa);

                for (int i = 0; i < num_students; i++) {
                    if (students[i].gpa >= min_gpa) {
                        printf("\nID: %d\nName: %s\nGPA: %.2f\n\n", students[i].id, students[i].name, students[i].gpa);
                    }
                }
                break;

            case 5: // Quit
                printf("Thank you for using the student database!\n\n");
                break;

            default:
                printf("Invalid option. Try again.\n\n");
                break;
        }
    }

    free(students);
    return 0;
}