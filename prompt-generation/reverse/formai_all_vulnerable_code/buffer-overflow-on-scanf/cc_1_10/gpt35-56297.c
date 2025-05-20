//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include<stdio.h>
#include<stdlib.h>

struct employee{
    char name[50];
    int age;
    float salary;
};

int main(){
    struct employee emp[50];
    int n, i;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    //Getting employee details
    for(i=0; i<n; i++){
        printf("\nDetails of employee %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", &emp[i].name);
        printf("Enter age: ");
        scanf("%d", &emp[i].age);
        printf("Enter salary: ");
        scanf("%f", &emp[i].salary);
    }

    //Creating and writing to file
    FILE *fp;
    char filename[] = "employee_details.txt";
    fp = fopen(filename, "w");

    if(fp == NULL){
        printf("Error while opening file.\n");
        exit(1);
    }

    fprintf(fp, "\t\t\tEmployee Details\n\n");
    fprintf(fp, "Name\t\tAge\t\tSalary\n");

    for(i=0; i<n; i++){
        fprintf(fp, "%s\t\t%d\t\t%.2f\n", emp[i].name, emp[i].age, emp[i].salary);
    }

    fclose(fp);

    //Reading from file and printing
    char ch;
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error while opening file.\n");
        exit(1);
    }

    printf("\n\t\t\tEmployee Details from File\n\n");
    ch = fgetc(fp);
    while(ch != EOF){
        printf("%c", ch);
        ch = fgetc(fp);
    }

    fclose(fp);

    return 0;
}