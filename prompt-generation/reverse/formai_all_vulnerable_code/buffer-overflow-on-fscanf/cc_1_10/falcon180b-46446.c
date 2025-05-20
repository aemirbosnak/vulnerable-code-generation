//Falcon-180B DATASET v1.0 Category: File handling ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float salary;
} Employee;

void read_data(FILE *fp, Employee *emp) {
    fscanf(fp, "%s %d %f", emp->name, &emp->age, &emp->salary);
}

void write_data(FILE *fp, Employee *emp) {
    fprintf(fp, "%s %d %f\n", emp->name, emp->age, emp->salary);
}

void sort_by_age(Employee *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].age > arr[j].age) {
                Employee temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort_by_salary(Employee *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].salary > arr[j].salary) {
                Employee temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    char filename[MAX_SIZE];
    int choice, n;
    Employee emp[MAX_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    n = ftell(fp) / sizeof(Employee);
    fseek(fp, 0, SEEK_SET);

    printf("Enter the number of records to be added: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        read_data(fp, &emp[i]);
    }

    fclose(fp);

    printf("Enter the choice:\n1. Sort by age\n2. Sort by salary\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sort_by_age(emp, n);
            break;
        case 2:
            sort_by_salary(emp, n);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(0);
    }

    for (int i = 0; i < n; i++) {
        write_data(fp, &emp[i]);
    }

    fclose(fp);

    printf("Sorted data written to the file.\n");

    return 0;
}