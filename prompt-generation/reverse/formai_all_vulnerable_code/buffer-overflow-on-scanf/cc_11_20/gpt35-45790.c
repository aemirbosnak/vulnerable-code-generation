//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Employee{
    int empId;
    char empName[20];
    char empDept[20];
}emp;

int main(){

    FILE *fptr;

    int ch, empCount=0;
    int empId;
    char empName[20], empDept[20];
    char fileName[20];

    printf("Enter file name: ");
    scanf("%s", fileName);

    fptr = fopen(fileName, "rb+");
    if(fptr == NULL){
        fptr = fopen(fileName, "wb+");
        if(fptr == NULL){
            printf("Unable to open file %s", fileName);
            return 0;
        }
    }

    empCount = fread(&emp, sizeof(struct Employee), 1, fptr);
    while(1){

        printf("\nEmployee Database\n");
        printf("-----------------------------\n");
        printf("1) Add new employee\n");
        printf("2) Search for an employee by ID\n");
        printf("3) Display all employees\n");
        printf("4) Modify an employee's information\n");
        printf("5) Delete an employee\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("\nEnter employee ID: ");
                scanf("%d", &empId);
                printf("Enter employee name: ");
                scanf("%s", empName);
                printf("Enter employee department: ");
                scanf("%s", empDept);
                emp.empId = empId;
                strcpy(emp.empName, empName);
                strcpy(emp.empDept, empDept);
                fseek(fptr, 0, SEEK_END);
                fwrite(&emp, sizeof(struct Employee), 1, fptr);
                empCount++;
                break;
            case 2:
                printf("\nEnter employee ID to search: ");
                scanf("%d", &empId);
                fseek(fptr, 0, SEEK_SET);
                while(fread(&emp, sizeof(struct Employee), 1, fptr) == 1){
                    if(emp.empId == empId){
                        printf("\nEmployee found!\n");
                        printf("ID: %d\n", emp.empId);
                        printf("Name: %s\n", emp.empName);
                        printf("Department: %s\n", emp.empDept);
                        break;
                    }
                }
                if(feof(fptr)){
                    printf("\nEmployee not found!\n");
                }
                break;
            case 3:
                if(empCount == 0){
                    printf("\nNo employees found!\n");
                }
                fseek(fptr, 0, SEEK_SET);
                printf("\n--- Employee List ---\n");
                printf("|   ID    |   Name  |   Department  |\n");
                printf("|---------|---------|---------------|\n");
                while(fread(&emp, sizeof(struct Employee), 1, fptr) == 1){
                    printf("|%9d|%9s|%15s|\n", emp.empId, emp.empName, emp.empDept);
                }
                break;
            case 4:
                printf("\nEnter employee ID to modify: ");
                scanf("%d", &empId);
                fseek(fptr, 0, SEEK_SET);
                while(fread(&emp, sizeof(struct Employee), 1, fptr) == 1){
                    if(emp.empId == empId){
                        printf("\nEnter new employee name: ");
                        scanf("%s", empName);
                        printf("Enter new employee department: ");
                        scanf("%s", empDept);
                        strcpy(emp.empName, empName);
                        strcpy(emp.empDept, empDept);
                        fseek(fptr, -sizeof(struct Employee), SEEK_CUR);
                        fwrite(&emp, sizeof(struct Employee), 1, fptr);
                        printf("\nEmployee information updated!\n");
                        break;
                    }
                }
                if(feof(fptr)){
                    printf("\nEmployee not found!\n");
                }
                break;
            case 5:
                printf("\nEnter employee ID to delete: ");
                scanf("%d", &empId);
                FILE *temp = fopen("temp.dat", "wb");
                fseek(fptr, 0, SEEK_SET);
                while(fread(&emp, sizeof(struct Employee), 1, fptr) == 1){
                    if(emp.empId != empId){
                        fwrite(&emp, sizeof(struct Employee), 1, temp);
                    }
                }
                fclose(fptr);
                fclose(temp);
                remove(fileName);
                rename("temp.dat", fileName);
                fptr = fopen(fileName, "rb+");
                empCount--;
                printf("\nEmployee deleted!\n");
                break;
            case 6:
                fclose(fptr);
                return 0;
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}