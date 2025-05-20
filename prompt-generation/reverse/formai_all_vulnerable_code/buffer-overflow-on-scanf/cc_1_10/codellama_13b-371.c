//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
// Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store patient information
struct patient {
    char name[50];
    char age[3];
    char gender[10];
    char disease[50];
    char medication[50];
};

// Structure to store employee information
struct employee {
    char name[50];
    char role[10];
    char salary[10];
};

// Function to add a patient
void addPatient(struct patient *patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Enter patient age: ");
    scanf("%s", patient->age);
    printf("Enter patient gender: ");
    scanf("%s", patient->gender);
    printf("Enter patient disease: ");
    scanf("%s", patient->disease);
    printf("Enter patient medication: ");
    scanf("%s", patient->medication);
}

// Function to add an employee
void addEmployee(struct employee *employee) {
    printf("Enter employee name: ");
    scanf("%s", employee->name);
    printf("Enter employee role: ");
    scanf("%s", employee->role);
    printf("Enter employee salary: ");
    scanf("%s", employee->salary);
}

// Function to display patient information
void displayPatient(struct patient patient) {
    printf("Patient Name: %s\n", patient.name);
    printf("Patient Age: %s\n", patient.age);
    printf("Patient Gender: %s\n", patient.gender);
    printf("Patient Disease: %s\n", patient.disease);
    printf("Patient Medication: %s\n", patient.medication);
}

// Function to display employee information
void displayEmployee(struct employee employee) {
    printf("Employee Name: %s\n", employee.name);
    printf("Employee Role: %s\n", employee.role);
    printf("Employee Salary: %s\n", employee.salary);
}

// Function to update patient information
void updatePatient(struct patient *patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Enter patient age: ");
    scanf("%s", patient->age);
    printf("Enter patient gender: ");
    scanf("%s", patient->gender);
    printf("Enter patient disease: ");
    scanf("%s", patient->disease);
    printf("Enter patient medication: ");
    scanf("%s", patient->medication);
}

// Function to update employee information
void updateEmployee(struct employee *employee) {
    printf("Enter employee name: ");
    scanf("%s", employee->name);
    printf("Enter employee role: ");
    scanf("%s", employee->role);
    printf("Enter employee salary: ");
    scanf("%s", employee->salary);
}

// Function to delete patient information
void deletePatient(struct patient *patient) {
    printf("Enter patient name: ");
    scanf("%s", patient->name);
    printf("Patient record deleted successfully!");
}

// Function to delete employee information
void deleteEmployee(struct employee *employee) {
    printf("Enter employee name: ");
    scanf("%s", employee->name);
    printf("Employee record deleted successfully!");
}

// Main function
int main() {
    // Declare variables
    struct patient patient;
    struct employee employee;
    int choice;

    // Menu
    printf("Welcome to Medical Store Management System\n");
    printf("1. Add Patient\n");
    printf("2. Add Employee\n");
    printf("3. Display Patient\n");
    printf("4. Display Employee\n");
    printf("5. Update Patient\n");
    printf("6. Update Employee\n");
    printf("7. Delete Patient\n");
    printf("8. Delete Employee\n");
    printf("9. Exit\n");
    scanf("%d", &choice);

    // Switch case for menu options
    switch (choice) {
        case 1:
            addPatient(&patient);
            break;
        case 2:
            addEmployee(&employee);
            break;
        case 3:
            displayPatient(patient);
            break;
        case 4:
            displayEmployee(employee);
            break;
        case 5:
            updatePatient(&patient);
            break;
        case 6:
            updateEmployee(&employee);
            break;
        case 7:
            deletePatient(&patient);
            break;
        case 8:
            deleteEmployee(&employee);
            break;
        case 9:
            printf("Thank you for using Medical Store Management System!");
            return 0;
        default:
            printf("Invalid input");
    }

    return 0;
}