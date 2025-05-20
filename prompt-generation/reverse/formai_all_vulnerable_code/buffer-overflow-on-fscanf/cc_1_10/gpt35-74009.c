//FormAI DATASET v1.0 Category: File handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// function to write data into file
void writeData(FILE *fp){
    char name[20], dept[20];
    int age;
    double salary;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter department: ");
    scanf("%s", dept);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter salary: ");
    scanf("%lf", &salary);

    fprintf(fp, "%s %s %d %.2lf\n", name, dept, age, salary);
}

//function to read and display data from file
void readData(FILE *fp){
    char name[20], dept[20];
    int age;
    double salary;

    printf("%-20s %-20s %-10s %-10s\n", "Name", "Department", "Age", "Salary");

    while(fscanf(fp, "%s %s %d %lf\n", name, dept, &age, &salary) != EOF){
        printf("%-20s %-20s %-10d %-10.2lf\n", name, dept, age, salary);
    }
}

int main(){
    FILE *fp = NULL;

    int ch;

    fp = fopen("employee.txt", "a+");

    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    do{
        printf("\n1. Write data\n2. Read data\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                writeData(fp);
                break;

            case 2:
                readData(fp);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(ch != 3);

    fclose(fp);

    return 0;
}