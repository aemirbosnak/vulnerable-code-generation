//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[50];
    int age;
    float salary;
};

int main() {

    int choice, count = 0, i, employeeId;
    struct employee emp;
    FILE *fptr;

    while(1) {
        printf("\n1. Add an employee\n2. View employee details\n3. Delete an employee\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                fptr = fopen("employees.txt", "a");
                if(fptr == NULL) {
                    printf("\nError in file opening");
                    exit(1);
                }

                printf("\nEnter employee name: ");
                scanf("%s", emp.name);
                printf("Enter employee age: ");
                scanf("%d", &emp.age);
                printf("Enter employee salary: ");
                scanf("%f", &emp.salary);

                fwrite(&emp, sizeof(emp), 1, fptr);
                fclose(fptr);
                count++;
                break;
            
            case 2:
                fptr = fopen("employees.txt", "r");
                if(fptr == NULL) {
                    printf("\nError in file opening");
                    exit(1);
                }

                printf("\nEnter employee ID to view details: ");
                scanf("%d", &employeeId);
                fseek(fptr, (employeeId-1)*sizeof(emp), SEEK_SET);
                fread(&emp, sizeof(emp), 1, fptr);

                printf("\nName: %s \nAge: %d \nSalary: %.2f", emp.name, emp.age, emp.salary);
                fclose(fptr);
                break;

            case 3:
                fptr = fopen("employees.txt", "r");
                if(fptr == NULL) {
                    printf("\nError in file opening");
                    exit(1);
                }
                FILE *temp = fopen("temp.txt", "w");
                printf("\nEnter employee ID to delete record: ");
                scanf("%d", &employeeId);

                for(i=1; i<=count; i++) {
                    fread(&emp, sizeof(emp), 1, fptr);
                    if(i != employeeId) {
                        fwrite(&emp, sizeof(emp), 1, temp);
                    }
                }
                fclose(fptr);
                fclose(temp);
                remove("employees.txt");
                rename("temp.txt", "employees.txt");
                printf("\nRecord deleted successfully!");
                count--;
                break;

            case 4:
                printf("\nProgram exited successfully\n");
                exit(0);
            
            default:
                printf("\nInvalid choice.");
        }
    }

    return 0;
}