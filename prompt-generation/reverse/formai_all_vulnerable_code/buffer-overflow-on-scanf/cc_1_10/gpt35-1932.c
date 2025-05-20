//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student { // define student structure
    int id;
    char name[50];
    double gpa;
};

typedef struct Student Student; // create alias for Student structure

int menu(); // function prototype for menu

int main() {
    int choice;
    Student student;
    FILE *file;

    file = fopen("students.bin", "ab+"); // open or create students file

    if (file == NULL) { // check if file was opened successfully
        printf("Error opening file!\n");
        exit(1);
    }

    do { // loop through menu options until user chooses to exit
        choice = menu();

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &(student.id));
                printf("Enter student name: ");
                scanf("%s", student.name);
                printf("Enter student GPA: ");
                scanf("%lf", &(student.gpa));

                fwrite(&student, sizeof(Student), 1, file); // write student data to file
                printf("Student added successfully!\n");

                break;

            case 2:
                printf("Enter student ID to search: ");
                scanf("%d", &(student.id));

                fseek(file, 0, SEEK_SET); // go to beginning of file

                while (fread(&student, sizeof(Student), 1, file) != 0) { // search for student in file
                    if (student.id == student.id) {
                        printf("Student found!\n");
                        printf("ID: %d\nName: %s\nGPA: %lf\n", student.id, student.name, student.gpa);
                        break;
                    }
                }

                if (feof(file)) {
                    printf("Student not found!\n");
                }
                
                break;

            case 3:
                fseek(file, 0, SEEK_SET); // go to beginning of file

                while (fread(&student, sizeof(Student), 1, file) != 0) { // print all students in file
                    printf("ID: %d\nName: %s\nGPA: %lf\n", student.id, student.name, student.gpa);
                }

                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    fclose(file);

    return 0;
}

int menu() { // print menu and get user's choice
    int choice;

    printf("1. Add student\n");
    printf("2. Search for student\n");
    printf("3. Print all students\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}