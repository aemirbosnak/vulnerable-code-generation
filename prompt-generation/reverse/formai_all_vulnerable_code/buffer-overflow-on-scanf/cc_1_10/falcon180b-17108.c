//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_EMPLOYEES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char position[MAX_NAME_LENGTH];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void readEmployeesFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file \"%s\"\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Employee e;
        int fieldsRead = sscanf(line, "%s %d %s %f", e.name, &e.age, e.position, &e.salary);
        if (fieldsRead == 4) {
            strcpy(employees[numEmployees].name, e.name);
            employees[numEmployees].age = e.age;
            strcpy(employees[numEmployees].position, e.position);
            employees[numEmployees].salary = e.salary;
            numEmployees++;
        } else {
            printf("Error: Invalid input on line %d of file \"%s\"\n", numEmployees+1, filename);
        }
    }

    fclose(fp);
}

void writeEmployeesToFile(char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file \"%s\" for writing\n", filename);
        exit(1);
    }

    for (int i = 0; i < numEmployees; i++) {
        fprintf(fp, "%s %d %s %.2f\n", employees[i].name, employees[i].age, employees[i].position, employees[i].salary);
    }

    fclose(fp);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    readEmployeesFromFile(filename);

    printf("\nEnter the name of the output file: ");
    scanf("%s", filename);

    writeEmployeesToFile(filename);

    printf("\nDone.\n");
    return 0;
}