//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

//Employee structure
struct employee{
    char name[20];
    int emp_id;
    float salary;
};

int main(){
    int choice, n=0, i=0;
    struct employee employees[50];
    FILE *fp;

    //Opening or Creating a binary file to store employee records
    fp = fopen("employees.bin", "ab+");
    if(fp == NULL){
        printf("Error in opening file!");
        exit(1);
    }

    //Loop to display Menu and take user input
    while(1){
        printf("\n\nMain Menu\n");
        printf("1. Add Employee Record\n");
        printf("2. Search Employee Record\n");
        printf("3. Delete Employee Record\n");
        printf("4. Display All Employee Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Switch case to handle user choice
        switch(choice){
            //Case 1 - Adding employee record
            case 1:
                printf("\nEnter employee name: ");
                scanf("%s", &employees[n].name);
                printf("Enter employee id: ");
                scanf("%d", &employees[n].emp_id);
                printf("Enter employee salary: ");
                scanf("%f", &employees[n].salary);
                fwrite(&employees[n], sizeof(struct employee), 1, fp);
                n++;
                printf("\nEmployee Record Added Successfully!");
                break;
            
            //Case 2 - Searching employee record
            case 2:
                printf("\nEnter employee id to search: ");
                int search_id;
                scanf("%d", &search_id);
                fseek(fp, 0, SEEK_SET);
                while(fread(&employees[i], sizeof(struct employee), 1, fp)){
                    if(employees[i].emp_id == search_id){
                        printf("\nEmployee Record Found!");
                        printf("\nName: %s", employees[i].name);
                        printf("\nEmployee id: %d", employees[i].emp_id);
                        printf("\nSalary: %.2f", employees[i].salary);
                        break;
                    }
                    i++;
                }
                if(i == n){
                    printf("\nEmployee Record Not Found!");
                }
                break;
            
            //Case 3 - Deleting employee record
            case 3:
                printf("\nEnter employee id to delete: ");
                int delete_id;
                scanf("%d", &delete_id);
                struct employee temp[50];
                fseek(fp, 0, SEEK_SET);
                i=0;
                while(fread(&employees[i], sizeof(struct employee), 1, fp)){
                    if(employees[i].emp_id == delete_id){
                        printf("\nEmployee Record Deleted Successfully!");
                    }
                    else{
                        fwrite(&employees[i], sizeof(struct employee), 1, fp);
                        i++;
                    }
                }
                n = i;
                break;
            
            //Case 4 - Displaying all employee records
            case 4:
                fseek(fp, 0, SEEK_SET);
                i=0;
                printf("\n\nAll Employee Records:\n");
                while(fread(&employees[i], sizeof(struct employee), 1, fp)){
                    printf("Name: %s\n", employees[i].name);
                    printf("Employee id: %d\n", employees[i].emp_id);
                    printf("Salary: %.2f\n", employees[i].salary);
                    printf("----------------------------\n");
                    i++;
                }
                if(i == 0){
                    printf("\nNo Records Found!");
                }
                break;
            
            //Case 5 - Exit
            case 5:
                fclose(fp);
                exit(0);
            
            //Default case - handle invalid input
            default:
                printf("\nInvalid Input! Try again...");
        }
    }
    return 0;
}