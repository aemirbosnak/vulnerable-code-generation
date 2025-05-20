//FormAI DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int age;
    float salary;
} Employee;

int main() {
    FILE *fp;
    int choice, i, n;
    char ch;

    fp = fopen("employee.txt", "w");

    if (fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee emp[n];

    for (i = 0; i < n; i++) {
        printf("Enter employee %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Age: ");
        scanf("%d", &emp[i].age);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    fwrite(emp, sizeof(Employee), n, fp);

    fclose(fp);

    printf("File created and saved successfully\n");

    printf("\nDo you want to view the details of employees? (y/n): ");
    scanf("%s", &ch);

    if (ch == 'y' || ch == 'Y') {
        fp = fopen("employee.txt", "r");

        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        Employee emp_data;

        printf("\n%-10s%-10s%-10s\n", "Name", "Age", "Salary");
        printf("--------------------------------\n");

        while (fread(&emp_data, sizeof(Employee), 1, fp)) {
            printf("%-10s%-10d%-10.2f\n", emp_data.name, emp_data.age, emp_data.salary);
        }

        fclose(fp);
    }

    printf("\nDo you want to delete the file? (y/n): ");
    scanf("%s", &ch);

    if (ch == 'y' || ch == 'Y') {
        if (remove("employee.txt") == 0) {
            printf("File deleted successfully!\n");
        } else {
            printf("Unable to delete the file!\n");
        }
    } else {
        printf("Exiting the program!\n");
    }

    return 0;
}