//FormAI DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[20];
    int age;
    float salary;
};

void writeToFile() {
    int numEmployees;
    FILE *fp;

    fp = fopen("employee.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    fflush(stdin);

    for (int i = 0; i < numEmployees; i++) {
        struct employee emp;
        printf("Enter employee name: ");
        gets(emp.name);
        fflush(stdin);

        printf("Enter employee age: ");
        scanf("%d", &emp.age);
        fflush(stdin);

        printf("Enter employee salary: ");
        scanf("%f", &emp.salary);
        fflush(stdin);

        fwrite(&emp, sizeof(emp), 1, fp);
    }

    fclose(fp);
}

void readFromFile() {
    FILE *fp;
    struct employee emp;

    fp = fopen("employee.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\nRead employees from file: \n");

    while (fread(&emp, sizeof(emp), 1, fp)) {
        printf("Name: %s | Age: %d | Salary: %.2f\n", emp.name, emp.age, emp.salary);
    }

    fclose(fp);
}

int main() {
    writeToFile();
    readFromFile();

    return 0;
}