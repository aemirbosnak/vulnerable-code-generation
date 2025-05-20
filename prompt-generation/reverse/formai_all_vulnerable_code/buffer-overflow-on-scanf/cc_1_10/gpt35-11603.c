//FormAI DATASET v1.0 Category: Database querying ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char occupation[20];
    int age;
    int salary;
} Employee;

int main() {
    FILE *fp;
    Employee emp;
    char filename[] = "cyberpunk_database.txt";
    char search[20];
    int found = 0;
    
    // Creating and Writing Data to File
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error creating database.");
        return 1;
    }
    
    strcpy(emp.name, "John Doe");
    strcpy(emp.occupation, "Hacker");
    emp.age = 30;
    emp.salary = 50000;
    fwrite(&emp, sizeof(Employee), 1, fp);
    
    strcpy(emp.name, "Mary Smith");
    strcpy(emp.occupation, "Corpo");
    emp.age = 40;
    emp.salary = 100000;
    fwrite(&emp, sizeof(Employee), 1, fp);
    
    fclose(fp);
    
    // Querying Data from File
    printf("Search for an employee by name: ");
    scanf("%s", search);
    
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening database.");
        return 1;
    }
    
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (strcmp(emp.name, search) == 0) {
            printf("%s, %s, %d, %d", emp.name, emp.occupation, emp.age, emp.salary);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No employee found with name %s.", search);
    }
    
    fclose(fp);
    
    return 0;
}