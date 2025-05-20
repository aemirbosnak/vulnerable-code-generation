//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

struct employee {  
    int id;  
    char name[20];  
    float salary;  
};  
  
int main() {  
    int choice, numEmp, empID, found = 0;  
    FILE *fp;  
    struct employee emp[100];  
      
    printf("Enter the number of employees: ");  
    scanf("%d", &numEmp);  
      
    fp = fopen("employee.txt", "w+");  
    if(fp == NULL) {  
        printf("Unable to open file\n");  
        exit(1);  
    }  
      
    for(int i=0; i<numEmp; i++) {  
        printf("\nEnter the ID of employee %d: ", i+1);  
        scanf("%d", &emp[i].id);  
        printf("Enter the name of employee %d: ", i+1);  
        scanf("%s", emp[i].name);  
        printf("Enter the salary of employee %d: ", i+1);  
        scanf("%f", &emp[i].salary);  
        fwrite(&emp[i], sizeof(struct employee), 1, fp);  
    }  
    fclose(fp);    
      
    while(1) {  
        printf("\nEnter the operation you want to perform:\n1-Search by ID\n2-Display all records\n3-Exit\n\n");  
        scanf("%d", &choice);  
          
        switch(choice) {  
            case 1:  
                printf("\nEnter the ID of the employee you want to search: ");  
                scanf("%d", &empID);  
                fp = fopen("employee.txt", "r");  
                if(fp == NULL) {  
                    printf("Unable to open file\n");  
                    exit(1);  
                }  
                for(int i=0; i<numEmp; i++) {  
                    fread(&emp[i], sizeof(struct employee), 1, fp);  
                    if(emp[i].id == empID) {  
                        printf("\nRecord found!\nID: %d\nName: %s\nSalary: %.2f\n", emp[i].id, emp[i].name, emp[i].salary);  
                        found = 1;  
                    }  
                }  
                if(found == 0) {  
                    printf("\nRecord not found\n");  
                }  
                fclose(fp);  
                break;  
                  
            case 2:  
                fp = fopen("employee.txt", "r");  
                if(fp == NULL) {  
                    printf("Unable to open file\n");  
                    exit(1);  
                }  
                for(int i=0; i<numEmp; i++) {  
                    fread(&emp[i], sizeof(struct employee), 1, fp);  
                    printf("\nEmployee %d\nID: %d\nName: %s\nSalary: %.2f\n", i+1, emp[i].id, emp[i].name, emp[i].salary);  
                }  
                fclose(fp);  
                break;  
                  
            case 3:  
                exit(0);  
                  
            default:  
                printf("\nInvalid choice\n");  
                break;  
        }  
    }  
    return 0;  
}