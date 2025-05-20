//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[30];
    int id;
    float cgpa;
};

int main() {
    int no_of_students = 0;
    printf("Enter the number of students: ");
    scanf("%d", &no_of_students);

    struct student *students = malloc(sizeof(struct student) * no_of_students);

    int choice;

    do {
        printf("\n------Welcome to Student Database Simulation------\n\n");
        printf("Choose an option from the menu below: \n");
        printf("1. Add a student\n");
        printf("2. Print database\n");
        printf("3. Search database\n");
        printf("4. Update database\n");
        printf("0. Exit\n\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter student details:\n");

            struct student temp;
            printf("Name: ");
            scanf("%s", temp.name);
            printf("ID: ");
            scanf("%d", &temp.id);
            printf("CGPA: ");
            scanf("%f", &temp.cgpa);

            students[no_of_students++] = temp;

            printf("Student added successfully!\n");
        }
        else if(choice == 2) {
            printf("\n------Printing student database------\n\n");
            printf("%-30s%-10s%-10s\n", "Name", "ID", "CGPA");

            for(int i=0; i<no_of_students; i++) {
                printf("%-30s%-10d%-10.2f\n", students[i].name, students[i].id, students[i].cgpa);
            }
        }
        else if(choice == 3) {
            printf("Enter student ID to search: ");
            int search_id;
            scanf("%d", &search_id);

            int found = 0;
            for(int i=0; i<no_of_students; i++) {
                if(students[i].id == search_id) {
                    printf("Student found:\n");
                    printf("%-30s%-10s%-10s\n", "Name", "ID", "CGPA");
                    printf("%-30s%-10d%-10.2f\n", students[i].name, students[i].id, students[i].cgpa);
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                printf("No student found with ID %d\n", search_id);
            } 
        }
        else if(choice == 4) {
            printf("Enter student ID to update: ");
            int update_id;
            scanf("%d", &update_id);

            int found = 0;
            for(int i=0; i<no_of_students; i++) {
                if(students[i].id == update_id) {
                    printf("Enter new details for student %s:\n", students[i].name);
                    printf("New name (leave blank to skip): ");
                    char new_name[30];
                    scanf("%s", new_name);
                    if(strlen(new_name) != 0) {
                        strcpy(students[i].name, new_name);
                    }

                    printf("New ID (enter 0 to skip): ");
                    int new_id;
                    scanf("%d", &new_id);
                    if(new_id != 0) {
                        students[i].id = new_id;
                    }

                    printf("New CGPA (enter 0.0 to skip): ");
                    float new_cgpa;
                    scanf("%f", &new_cgpa);
                    if(new_cgpa != 0.0) {
                        students[i].cgpa = new_cgpa;
                    }

                    printf("Student details updated successfully!\n");
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                printf("No student found with ID %d\n", update_id);
            }
        }
        else if(choice != 0) {
            printf("Invalid choice, please try again!\n");
        }

    } while(choice != 0);

    free(students);

    return 0;
}