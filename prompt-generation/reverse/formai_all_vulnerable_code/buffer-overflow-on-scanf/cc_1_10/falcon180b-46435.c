//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
    float salary;
} Employee;

void extractMetadata(const char* fileName, Employee* employee) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* nameStart = strstr(line, "Name:");
        if (nameStart!= NULL) {
            char* nameEnd = strstr(nameStart, "\n");
            strncpy(employee->name, nameStart + strlen("Name:"), nameEnd - nameStart - strlen("Name:"));
        }

        char* ageStart = strstr(line, "Age:");
        if (ageStart!= NULL) {
            char* ageEnd = strstr(ageStart, "\n");
            employee->age = atoi(ageStart + strlen("Age:"));
        }

        char* salaryStart = strstr(line, "Salary:");
        if (salaryStart!= NULL) {
            char* salaryEnd = strstr(salaryStart, "\n");
            employee->salary = atof(salaryStart + strlen("Salary:"));
        }
    }

    fclose(file);
}

int main() {
    Employee employee;
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);

    extractMetadata(fileName, &employee);

    printf("Name: %s\n", employee.name);
    printf("Age: %d\n", employee.age);
    printf("Salary: %.2f\n", employee.salary);

    return 0;
}