//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[50];
    int age;
    float salary;
} Employee;

// Function to read employee details from file
void readFile(Employee* emp, int* n){
    FILE* fptr;
    fptr = fopen("employees.txt", "r");
    if(fptr == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    int i = 0;
    while(fscanf(fptr, "%s %d %f\n", emp[i].name, &emp[i].age, &emp[i].salary) != EOF){
        i++;
    }
    *n = i;

    fclose(fptr);
}

// Function to write employee details to file
void writeFile(Employee* emp, int n){
    FILE* fptr;
    fptr = fopen("employees.txt", "w");
    if(fptr == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for(int i=0; i<n; i++){
        fprintf(fptr, "%s %d %f\n", emp[i].name, emp[i].age, emp[i].salary);
    }

    fclose(fptr);
}

int main(){
    Employee emp[10];
    int n = 0;

    // Read employee details from file
    readFile(emp, &n);

    // Modify employee details
    emp[0].age = 30;
    emp[0].salary = 5000.0;

    // Write employee details to file
    writeFile(emp, n);

    printf("Employee details updated successfully!\n");

    return 0;
}