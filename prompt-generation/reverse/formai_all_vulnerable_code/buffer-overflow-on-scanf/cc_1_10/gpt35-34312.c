//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int id;
    char name[30];
    int age;
    float salary;
};

void searchByName(struct employee *employees, int count, char *query) {
    int matchFound = 0;
    for(int i=0; i<count; i++) {
        if(strstr(employees[i].name, query)) {
            printf("%d | %s | %d | %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
            matchFound = 1;
        }
    }
    if(!matchFound) printf("No matching records found.\n");
}

void searchByAge(struct employee *employees, int count, int age) {
    int matchFound = 0;
    for(int i=0; i<count; i++) {
        if(employees[i].age == age) {
            printf("%d | %s | %d | %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
            matchFound = 1;
        }
    }
    if(!matchFound) printf("No matching records found.\n");
}

int main() {
    struct employee employees[5] = {
        { 100, "John Doe", 30, 50000.00 },
        { 101, "Jane Smith", 25, 40000.00 },
        { 102, "Michael Jackson", 32, 60000.00 },
        { 103, "William Shakespeare", 45, 70000.00 },
        { 104, "Emily Bronte", 28, 55000.00 }
    };
    int choice;
    do {
        printf("Choose an option:\n1. Search by Name\n2. Search by Age\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char query[30];
                printf("Enter a name to search:\n");
                scanf("%s", query);
                searchByName(employees, 5, query);
                break;
            }
            case 2: {
                int age;
                printf("Enter an age to search:\n");
                scanf("%d", &age);
                searchByAge(employees, 5, age);
                break;
            }
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);
    return 0;
}