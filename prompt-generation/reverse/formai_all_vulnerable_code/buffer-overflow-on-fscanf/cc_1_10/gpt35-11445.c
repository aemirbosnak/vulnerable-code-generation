//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.txt"     // define file name

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void writeData(Employee employees[], int numEmployees);
void readData();

int main() {
    Employee employees[] = {        // initialize some employee data
        {"John Smith", 30, 50000.00},
        {"Jane Doe", 25, 45000.00},
        {"Bob Johnson", 40, 65000.00},
        {"Sara Lee", 35, 55000.00}
    };
    int numEmployees = sizeof(employees) / sizeof(employees[0]);    // get number of employees
    
    writeData(employees, numEmployees);    // write employee data to file
    readData();    // read employee data from file
    
    return 0;
}

// function to write employee data to file
void writeData(Employee employees[], int numEmployees) {
    FILE *fp;
    fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", FILENAME);
        exit(1);
    }
    // loop through employees array and write each employee to file
    for (int i = 0; i < numEmployees; i++) {
        fprintf(fp, "%s %d %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }
    printf("Employee data written to file %s\n", FILENAME);
    fclose(fp);    // close file
}

// function to read employee data from file
void readData() {
    FILE *fp;
    char name[50];
    int age;
    float salary;
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", FILENAME);
        exit(1);
    }
    printf("Employee data read from file %s\n", FILENAME);
    // loop through file and read each employee
    while (fscanf(fp, "%s %d %f", name, &age, &salary) != EOF) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", name, age, salary);
    }
    fclose(fp);    // close file
}