//FormAI DATASET v1.0 Category: Data mining ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A struct definition to store employee information
struct Employee{
    char emp_id[10];
    char emp_name[50];
    float emp_salary;
};

// Function to read employee data from file and store it into an array of structs
int readEmployeeData (struct Employee *emp_array){

    FILE *emp_file;
    emp_file = fopen("employee_data.txt", "r");

    if (emp_file == NULL){
        printf("Error: Unable to open file\n");
        return -1;
    }

    int i = 0;
    while (fscanf(emp_file, "%s %s %f", emp_array[i].emp_id , emp_array[i].emp_name, &emp_array[i].emp_salary)!= EOF){
        i++;
    }
    fclose(emp_file);
    return i;
 }

// Function to calculate average salary of employees
float calculateAverageSalary(struct Employee *emp_array, int n){

    float sum = 0;
    for (int i = 0; i < n; i++){
        sum += emp_array[i].emp_salary;
    }

    return sum/n;
}

// Function to print the details of employees whose salary is below average
void printBelowAverageSalaryEmployees(struct Employee *emp_array, int n, float avg_salary){
    printf("List of employees whose salary is below average:\n");

    for (int i = 0; i < n ; i++){
        if (emp_array[i].emp_salary < avg_salary){
            printf("%s %s %f\n", emp_array[i].emp_id, emp_array[i].emp_name, emp_array[i].emp_salary);
        }  
    }
}

int main(){

    struct Employee emp_array[100];
    int count = readEmployeeData(emp_array);

    if (count == -1){
        return 1;
    }

    float avg_salary = calculateAverageSalary(emp_array, count);
    printBelowAverageSalaryEmployees(emp_array, count, avg_salary);

    return 0;
}