//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

int main() {

    FILE *file_pointer;
    Student students[100];
    int num_students = 0;
    char file_name[50];

    // ask user for file name
    printf("Enter the name of the file to read from: ");
    scanf("%s", file_name);

    // attempt to open file
    file_pointer = fopen(file_name, "r");

    // check if file is valid
    if (file_pointer == NULL) {
        printf("Error: unable to open file %s.\n", file_name);
        return 1;
    }

    // read data from file and populate student array
    printf("Reading data from file %s...\n", file_name);
    while (!feof(file_pointer)) {
        fscanf(file_pointer, "%s %d %f", students[num_students].name, &students[num_students].id, &students[num_students].gpa);
        num_students++;
    }

    // close file
    fclose(file_pointer);

    // print number of students read
    printf("Read %d student records from file %s.\n", num_students, file_name);

    // main program loop
    while (1) {
        int choice;

        // print menu options
        printf("\nChoose an option\n");
        printf("1. View all student records\n");
        printf("2. Add a new student record\n");
        printf("3. Update a student record\n");
        printf("4. Delete a student record\n");
        printf("5. Exit\n");

        // get user choice
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                // print all student records
                printf("\nAll student records\n");
                printf("Name\t\tID\tGPA\n");
                for (int i = 0; i < num_students; i++) {
                    printf("%-15s %08d %.1f\n", students[i].name, students[i].id, students[i].gpa);
                }
                break;

            case 2:
                // add a new student record
                printf("\nAdd a new student record\n");

                // make sure there is space in the array
                if (num_students >= 100) {
                    printf("Error: maximum number of students already reached.\n");
                    break;
                }

                // get user input for new record
                printf("Enter student name: ");
                scanf("%s", students[num_students].name);
                printf("Enter student ID: ");
                scanf("%d", &students[num_students].id);
                printf("Enter student GPA: ");
                scanf("%f", &students[num_students].gpa);

                // increment number of students
                num_students++;
                printf("Added new student record.\n");
                break;

            case 3:
                // update a student record
                printf("\nUpdate a student record\n");

                // make sure there are existing records
                if (num_students == 0) {
                    printf("Error: no student records exist.\n");
                    break;
                }

                // get user input for student ID
                int update_id;
                printf("Enter student ID to update: ");
                scanf("%d", &update_id);

                // search for student by ID
                int found = 0;
                for (int i = 0; i < num_students; i++) {
                    if (students[i].id == update_id) {
                        // update student record
                        printf("Enter new student name: ");
                        scanf("%s", students[i].name);
                        printf("Enter new student GPA: ");
                        scanf("%f", &students[i].gpa);
                        printf("Updated student record.\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Error: no student record found with ID %d.\n", update_id);
                }
                break;

            case 4:
                // delete a student record
                printf("\nDelete a student record\n");

                // make sure there are existing records
                if (num_students == 0) {
                    printf("Error: no student records exist.\n");
                    break;
                }

                // get user input for student ID
                int delete_id;
                printf("Enter student ID to delete: ");
                scanf("%d", &delete_id);

                // search for student by ID
                int delete_index = -1;
                for (int i = 0; i < num_students; i++) {
                    if (students[i].id == delete_id) {
                        delete_index = i;
                        break;
                    }
                }

                if (delete_index != -1) {
                    // shift remaining elements to fill gap
                    for (int i = delete_index + 1; i < num_students; i++) {
                        strcpy(students[i-1].name, students[i].name);
                        students[i-1].id = students[i].id;
                        students[i-1].gpa = students[i].gpa;
                    }
                    num_students--;
                    printf("Deleted student record.\n");
                } else {
                    printf("Error: no student record found with ID %d.\n", delete_id);
                }
                break;

            case 5:
                // exit program
                printf("\nExiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}