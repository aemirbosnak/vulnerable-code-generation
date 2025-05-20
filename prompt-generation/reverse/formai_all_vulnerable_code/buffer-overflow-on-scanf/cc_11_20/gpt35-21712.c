//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char name[20];
    char department[20];
    float salary;
} Employee;

int main(){
    FILE *fp;
    char filename[20] = "employee_data.dat";
    Employee emp;
    int option;
    
    while(1){
        printf("\n------------------------\n");
        printf("Menu: \n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display All Employees\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &option);
        printf("------------------------\n");

        switch(option){
            case 1: // Adding a new employee
                fp = fopen(filename, "ab+");
                printf("Enter Employee ID: ");
                scanf("%d", &emp.id);
                printf("Enter Employee Name: ");
                scanf("%s", emp.name);
                printf("Enter Department Name: ");
                scanf("%s", emp.department);
                printf("Enter Salary: ");
                scanf("%f", &emp.salary);
                fwrite(&emp, sizeof(Employee), 1, fp);
                printf("Employee Details Added Successfully!\n");
                fclose(fp);
                break;
                
            case 2: // Deleting an employee
                fp = fopen(filename, "rb+");
                int id;
                printf("Enter Employee ID to be Deleted: ");
                scanf("%d", &id);
                while(fread(&emp, sizeof(Employee), 1, fp)){
                    if(emp.id == id){
                        fseek(fp, -sizeof(Employee), SEEK_CUR);
                        emp.id = -1;
                        fwrite(&emp, sizeof(Employee), 1, fp);
                        printf("Employee with ID %d has been deleted successfully\n", id);
                        break;
                    }
                }
                fclose(fp);
                break;
                
            case 3: // Searching for an employee
                fp = fopen(filename, "rb");
                int search_id;
                printf("Enter Employee ID to be Searched: ");
                scanf("%d", &search_id);
                int found = 0;
                while(fread(&emp, sizeof(Employee), 1, fp)){
                    if(emp.id == search_id){
                        found = 1;
                        printf("\nEmployee Details: \n");
                        printf("ID: %d\n", emp.id);
                        printf("Name: %s\n", emp.name);
                        printf("Department Name: %s\n", emp.department);
                        printf("Salary: %.2f\n", emp.salary);
                        printf("------------------------\n");
                        break;
                    }
                }
                if(!found){
                    printf("Employee with ID %d not Found!\n", search_id);
                }
                fclose(fp);
                break;
                
            case 4: // Displaying all employees
                fp = fopen(filename, "rb");
                printf("\nAll Employee Details: \n");
                printf("------------------------\n");
                while(fread(&emp, sizeof(Employee), 1, fp)){
                    if(emp.id != -1){
                        printf("ID: %d\n", emp.id);
                        printf("Name: %s\n", emp.name);
                        printf("Department Name: %s\n", emp.department);
                        printf("Salary: %.2f\n", emp.salary);
                        printf("------------------------\n");
                    }
                }
                fclose(fp);
                break;
                
            case 5: // Exiting the program
                printf("Exiting the Program...\n");
                exit(0);
                break;
                
            default:
                printf("Please enter a valid option!\n");
                break;
        }
    }
    return 0;
}