//Falcon-180B DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp;
    Employee emp;
    char query[100];
    char filename[100] = "employees.txt";

    // Open the database file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening the database file.\n");
        return 1;
    }

    // Read the first record
    fseek(fp, 0, SEEK_SET);
    fread(&emp, sizeof(Employee), 1, fp);

    // Display the first record
    printf("Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %.2f\n\n", emp.salary);

    // Prompt the user for a query
    printf("Enter a query (e.g. 'name = John'): ");
    scanf("%s", query);

    // Perform the query
    char *token = strtok(query, " ");
    while (token!= NULL) {
        if (strcmp(token, "name") == 0) {
            char *name = strtok(NULL, " ");
            while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                if (strcmp(emp.name, name) == 0) {
                    printf("Name: %s\n", emp.name);
                    printf("Age: %d\n", emp.age);
                    printf("Salary: %.2f\n\n", emp.salary);
                }
            }
        } else if (strcmp(token, "age") == 0) {
            int age = atoi(strtok(NULL, " "));
            while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                if (emp.age == age) {
                    printf("Name: %s\n", emp.name);
                    printf("Age: %d\n", emp.age);
                    printf("Salary: %.2f\n\n", emp.salary);
                }
            }
        } else if (strcmp(token, "salary") == 0) {
            float salary = atof(strtok(NULL, " "));
            while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
                if (emp.salary == salary) {
                    printf("Name: %s\n", emp.name);
                    printf("Age: %d\n", emp.age);
                    printf("Salary: %.2f\n\n", emp.salary);
                }
            }
        }
        token = strtok(NULL, " ");
    }

    // Close the database file
    fclose(fp);

    return 0;
}