//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp;
    char filename[] = "employees.txt";
    Employee employees[MAX_RECORDS];
    int num_records = 0;    

    // Write records to file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        exit(1);
    }
    printf("Enter records for employees. Type 'exit' to stop.\n");
    while (1) {
        if (num_records >= MAX_RECORDS) {
            printf("Maximum number of records reached.\n");
            break;      
        }
        Employee e;
        printf("Enter name (50 characters or less): ");
        scanf("%s", e.name);
        if (strcmp(e.name, "exit") == 0) {
            break;
        }
        printf("Enter age: ");
        scanf("%d", &e.age);
        printf("Enter salary: ");
        scanf("%f", &e.salary);
        fwrite(&e, sizeof(Employee), 1, fp);
        num_records++;
    }
    fclose(fp);

    // Read records from file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        exit(1);
    }
    int i = 0;
    while (fread(&employees[i], sizeof(Employee), 1, fp)) {
        i++;
    }
    num_records = i;
    fclose(fp);

    // Print records
    printf("Found %d records.\n", num_records);
    printf("%-20s %-10s %-10s\n", "Name", "Age", "Salary");
    for (i = 0; i < num_records; i++) {
        printf("%-20s %-10d %-10.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    return 0;
}