//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

void createTable(){
    FILE *db_file = fopen("employees.db", "wb");
    if(db_file == NULL) {
        printf("Unable to create database file!");
        exit(1);
    }
    struct Employee emp;
    for(int id=1; id<=5; id++){
        emp.id = id;
        printf("Enter Name of Employee #%d: ",id);
        scanf("%s", emp.name);
        printf("Enter Age of Employee #%d: ",id);
        scanf("%d", &emp.age);
        printf("Enter Salary of Employee #%d: ",id);
        scanf("%f", &emp.salary);
        fwrite(&emp, sizeof(struct Employee), 1, db_file);
    }
    fclose(db_file);
}

void displayTable(){
    FILE *db_file = fopen("employees.db", "rb");
    if(db_file == NULL) {
        printf("Unable to open database file!");
        exit(1);
    }
    struct Employee emp;
    printf("ID\tName\t\tAge\tSalary\n");
    while(fread(&emp, sizeof(struct Employee), 1, db_file)){
        printf("%d\t%s\t\t%d\t%.2f\n", emp.id, emp.name, emp.age, emp.salary);
    }
    fclose(db_file);
}

void searchTable(int id){
    FILE *db_file = fopen("employees.db", "rb");
    if(db_file == NULL) {
        printf("Unable to open database file!");
        exit(1);
    }
    struct Employee emp;
    while(fread(&emp, sizeof(struct Employee), 1, db_file)){
        if(emp.id == id){
            printf("ID\tName\t\tAge\tSalary\n");
            printf("%d\t%s\t\t%d\t%.2f\n", emp.id, emp.name, emp.age, emp.salary);
            fclose(db_file);
            return;
        }
    }
    fclose(db_file);
    printf("No employee found with ID: %d", id);
}

int main(){
    createTable();
    displayTable();
    searchTable(2);
    return 0;
}