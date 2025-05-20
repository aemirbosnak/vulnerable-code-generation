//Falcon-180B DATASET v1.0 Category: File handling ; Style: retro
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void write_to_file(Employee emp[], int size) {
    FILE *fp;
    fp = fopen("employees.txt", "w");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    for(int i=0; i<size; i++) {
        fprintf(fp, "Name: %s\nAge: %d\nSalary: %.2f\n\n", emp[i].name, emp[i].age, emp[i].salary);
    }
    fclose(fp);
    printf("Data written to file successfully!");
}

void read_from_file(Employee emp[], int size) {
    FILE *fp;
    fp = fopen("employees.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    for(int i=0; i<size; i++) {
        fscanf(fp, "Name: %s\nAge: %d\nSalary: %.2f\n", emp[i].name, &emp[i].age, &emp[i].salary);
    }
    fclose(fp);
    printf("Data read from file successfully!");
}

int main() {
    Employee emp[5];
    int size = sizeof(emp)/sizeof(emp[0]);
    for(int i=0; i<size; i++) {
        printf("Enter the details of employee %d:\n", i+1);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Age: ");
        scanf("%d", &emp[i].age);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    write_to_file(emp, size);
    read_from_file(emp, size);
    return 0;
}