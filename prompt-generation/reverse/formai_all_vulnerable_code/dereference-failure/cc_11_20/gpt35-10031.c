//FormAI DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    FILE *streamIn, *streamOut;
    Employee *employees, *recoveredEmployees;
    int numEmployees, i;
    
    // Open input file
    streamIn = fopen("employees.dat", "rb");
    if (!streamIn) {
        perror("Error opening input file");
        return 1;
    }
    
    // Get number of employees in file
    fseek(streamIn, 0, SEEK_END);
    numEmployees = ftell(streamIn) / sizeof(Employee);
    rewind(streamIn);
    
    // Allocate memory for employees array
    employees = malloc(numEmployees * sizeof(Employee));
    if (!employees) {
        perror("Error allocating memory for employees");
        return 1;
    }
    
    // Read employees from file into array
    if (fread(employees, sizeof(Employee), numEmployees, streamIn) != numEmployees) {
        perror("Error reading employees from file");
        return 1;
    }
    
    // Close input file
    fclose(streamIn);
    
    // Output employee data to console
    printf("Employee data:\n");
    for (i = 0; i < numEmployees; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    
    // Simulate data corruption
    strcpy(employees[0].name, "CORRUPTED");
    
    // Open output file
    streamOut = fopen("recovered.dat", "wb");
    if (!streamOut) {
        perror("Error opening output file");
        return 1;
    }
    
    // Allocate memory for recovered employees array
    recoveredEmployees = malloc(numEmployees * sizeof(Employee));
    if (!recoveredEmployees) {
        perror("Error allocating memory for recovered employees");
        return 1;
    }
    
    // Recover data from original file
    for (i = 0; i < numEmployees; i++) {
        fseek(streamIn, i * sizeof(Employee), SEEK_SET);
        if (fread(recoveredEmployees + i, sizeof(Employee), 1, streamIn) != 1) {
            perror("Error reading employee from file");
            return 1;
        }
    }
    
    // Close input file
    fclose(streamIn);
    
    // Output recovered employee data to console
    printf("\nRecovered employee data:\n");
    for (i = 0; i < numEmployees; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", recoveredEmployees[i].id, recoveredEmployees[i].name, recoveredEmployees[i].salary);
    }
    
    // Write recovered data to output file
    if (fwrite(recoveredEmployees, sizeof(Employee), numEmployees, streamOut) != numEmployees) {
        perror("Error writing employees to output file");
        return 1;
    }
    
    // Close output file
    fclose(streamOut);
    
    // Free memory
    free(employees);
    free(recoveredEmployees);
    
    return 0;
}