//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYES 100

/* Define the structure for an employee */
struct Employee {
    int id;
    char name[20];
    int age;
};

/* Define the structure for an index node */
struct IndexNode {
    int id;
    int offset;
};

/* Define the structure for an index */
struct Index {
    int count;
    struct IndexNode nodes[MAX_EMPLOYES];
};

/* Utility function to generate a unique ID for each employee */
int generateID() {
    static int id = 1;
    return id++;
}

/* Function to add a new employee to the database */
void addEmployee(struct Employee* emp, FILE* fp) {
    /* Generate a unique ID */
    emp->id = generateID();

    /* Write the employee to the end of the file and record the offset */
    fseek(fp, 0, SEEK_END);
    int offset = ftell(fp);
    fwrite(emp, sizeof(struct Employee), 1, fp);

    /* Add an index entry for the employee */
    fseek(fp, 0, SEEK_SET);
    struct Index index;
    fread(&index, sizeof(struct Index), 1, fp);
    index.nodes[index.count].id = emp->id;
    index.nodes[index.count].offset = offset;
    index.count++;
    fseek(fp, 0, SEEK_SET);
    fwrite(&index, sizeof(struct Index), 1, fp);

    printf("Employee added successfully!\n");
}

/* Function to search for an employee by ID */
void searchEmployee(int id, FILE* fp) {
    /* Read the index from the file */
    fseek(fp, 0, SEEK_SET);
    struct Index index;
    fread(&index, sizeof(struct Index), 1, fp);

    /* Search the index for the employee */
    int i;
    for (i = 0; i < index.count; i++) {
        if (index.nodes[i].id == id) {
            /* Found the employee, seek to their record and print their info */
            fseek(fp, index.nodes[i].offset, SEEK_SET);
            struct Employee emp;
            fread(&emp, sizeof(struct Employee), 1, fp);
            printf("Employee found: id=%d, name=%s, age=%d\n", emp.id, emp.name, emp.age);
            return;
        }
    }

    printf("Employee not found!\n");
}

/* Entry point for the program */
int main(int argc, char* argv[]) {
    /* Open the database file */
    FILE* fp = fopen("employee.db", "r+b");

    /* If the file doesn't exist, create it and initialize the index */
    if (fp == NULL) {
        fp = fopen("employee.db", "w+b");
        struct Index index = {0};
        fwrite(&index, sizeof(struct Index), 1, fp);
    }

    /* Loop to read user commands */
    char cmd[10];
    while (1) {
        printf("Enter a command (add, search, exit): ");
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            /* Prompt the user for employee info */
            struct Employee emp;
            printf("Enter employee name: ");
            scanf("%s", emp.name);
            printf("Enter employee age: ");
            scanf("%d", &emp.age);

            /* Add the employee to the database */
            addEmployee(&emp, fp);
        }
        else if (strcmp(cmd, "search") == 0) {
            /* Prompt the user for an employee ID to search for */
            int id;
            printf("Enter employee ID to search for: ");
            scanf("%d", &id);

            /* Search for the employee */
            searchEmployee(id, fp);
        }
        else if (strcmp(cmd, "exit") == 0) {
            /* Clean up and exit program */
            fclose(fp);
            return 0;
        }
        else {
            printf("Invalid command!\n");
        }
    }
}