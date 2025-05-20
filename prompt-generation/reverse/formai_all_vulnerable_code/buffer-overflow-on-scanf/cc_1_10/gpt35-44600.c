//FormAI DATASET v1.0 Category: Database simulation ; Style: ultraprecise
// Example database simulation program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
    int id;
    char name[30];
    int age;
    float salary;
};

// Function to add employee to database
void add_employee(struct employee emp, FILE *fp) {
    fwrite(&emp, sizeof(emp), 1, fp);
}

// Function to print all employees in database
void print_all_employees(FILE *fp) {
    struct employee emp;
    rewind(fp); // Move file pointer to beginning of file
    printf("Employee Details:\n\n");
    while(fread(&emp, sizeof(emp), 1, fp) == 1) {
        printf("ID: %d\n", emp.id);
        printf("Name: %s\n", emp.name);
        printf("Age: %d\n", emp.age);
        printf("Salary: %.2f\n\n", emp.salary);
    }
}

// Function to search for employee by ID
void search_employee(int id, FILE *fp) {
    struct employee emp;
    rewind(fp);
    while(fread(&emp, sizeof(emp), 1, fp) == 1) {
        if(emp.id == id) {
            printf("Employee Details:\n\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Salary: %.2f\n\n", emp.salary);
            return;
        }
    }
    printf("Employee with ID %d not found!\n", id);
}

// Function to update employee details by ID
void update_employee(int id, FILE *fp) {
    struct employee emp;
    rewind(fp);
    int found = 0;
    while(fread(&emp, sizeof(emp), 1, fp) == 1) {
        if(emp.id == id) {
            printf("Employee Details:\n\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Salary: %.2f\n\n", emp.salary);
            printf("Enter updated details:\n");
            printf("Name: ");
            scanf("%s", emp.name);
            printf("Age: ");
            scanf("%d", &emp.age);
            printf("Salary: ");
            scanf("%f", &emp.salary);
            fseek(fp, ftell(fp)-sizeof(emp), SEEK_SET); // Move file pointer to current position - size of employee structure
            fwrite(&emp, sizeof(emp), 1, fp); // Overwrite existing details with updated details
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Employee with ID %d not found!\n", id);
    else
        printf("Employee details updated successfully!\n");
}

// Function to delete employee by ID
void delete_employee(int id, FILE *fp) {
    struct employee emp;
    FILE *temp_fp = fopen("temp.dat", "wb");
    rewind(fp);
    while(fread(&emp, sizeof(emp), 1, fp) == 1) {
        if(emp.id != id) {
            fwrite(&emp, sizeof(emp), 1, temp_fp); // Write all employees except the one to be deleted to temporary file
        }
    }
    fclose(fp);
    fclose(temp_fp);
    remove("database.dat");
    rename("temp.dat", "database.dat"); // Rename temporary file to original file
    printf("Employee with ID %d deleted successfully!\n", id);
}

int main() {
    FILE *fp;
    fp = fopen("database.dat", "ab+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    int choice, id;
    struct employee emp;
    
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Add employee\n");
        printf("2. Print all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Update employee details by ID\n");
        printf("5. Delete employee by ID\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter employee details:\n");
                printf("ID: ");
                scanf("%d", &emp.id);
                printf("Name: ");
                scanf("%s", emp.name);
                printf("Age: ");
                scanf("%d", &emp.age);
                printf("Salary: ");
                scanf("%f", &emp.salary);
                add_employee(emp, fp);
                printf("Employee added successfully!\n");
                break;
            case 2:
                print_all_employees(fp);
                break;
            case 3:
                printf("Enter employee ID to search: ");
                scanf("%d", &id);
                search_employee(id, fp);
                break;
            case 4:
                printf("Enter employee ID to update: ");
                scanf("%d", &id);
                update_employee(id, fp);
                break;
            case 5:
                printf("Enter employee ID to delete: ");
                scanf("%d", &id);
                delete_employee(id, fp);
                break;
            case 6:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}