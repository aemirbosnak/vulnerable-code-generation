//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fptr;
    struct employee e1, e2, e3;
    int choice, emp_id;

    // Opening the file in binary write mode
    fptr = fopen("employees.dat", "wb");

    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Writing three employee records to the file
    e1.id = 1;
    strcpy(e1.name, "John");
    e1.salary = 5000;

    e2.id = 2;
    strcpy(e2.name, "Jane");
    e2.salary = 6000;

    e3.id = 3;
    strcpy(e3.name, "Dave");
    e3.salary = 4500;

    fwrite(&e1, sizeof(e1), 1, fptr);
    fwrite(&e2, sizeof(e2), 1, fptr);
    fwrite(&e3, sizeof(e3), 1, fptr);

    fclose(fptr);

    // Opening the file in binary read mode
    fptr = fopen("employees.dat", "rb");

    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Reading employee records from the file
    printf("\n1. Display employee details\n2. Edit employee details\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter employee id to display details: ");
            scanf("%d", &emp_id);

            fseek(fptr, (emp_id-1)*sizeof(struct employee), SEEK_SET);
            fread(&e1, sizeof(e1), 1, fptr);

            printf("\nEmployee id: %d\n", e1.id);
            printf("Employee name: %s\n", e1.name);
            printf("Employee salary: %.2f\n", e1.salary);

            break;

        case 2:
            printf("\nEnter employee id to edit details: ");
            scanf("%d", &emp_id);

            fseek(fptr, (emp_id-1)*sizeof(struct employee), SEEK_SET);
            fread(&e1, sizeof(e1), 1, fptr);

            printf("\nEnter new name: ");
            scanf("%s", &e1.name);

            printf("Enter new salary: ");
            scanf("%f", &e1.salary);

            fseek(fptr, (emp_id-1)*sizeof(struct employee), SEEK_SET);
            fwrite(&e1, sizeof(e1), 1, fptr);

            printf("\nEmployee details updated successfully!");

            break;

        case 3:
            printf("\nExiting...");

            break;

        default:
            printf("\nInvalid choice!");

            break;
    }

    fclose(fptr);

    return 0;
}