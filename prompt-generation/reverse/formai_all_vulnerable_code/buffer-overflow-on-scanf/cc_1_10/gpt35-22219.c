//FormAI DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_SIZE 50

typedef struct _employee {
    int id;
    char name[MAX_NAME_SIZE];
    float salary;
} Employee;

typedef struct _record {
    Employee employee;
    char date[20];
} Record;

Record DB[MAX_RECORDS];
int total_records = 0;

void display_menu();
void add_employee();
void view_all_records();
void search_database();

int main() {
    srand(time(0));

    while (1) {
        display_menu();

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_employee(); break;
            case 2: view_all_records(); break;
            case 3: search_database(); break;
            case 4:
                printf("\nThank you for using our program!\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n#######################################################\n");
    printf("#                                                     #\n");
    printf("#        Welcome to the Cyberpunk Employee DB          #\n");
    printf("#                                                     #\n");
    printf("#######################################################\n");
    printf("#                                                     #\n");
    printf("#       1. Add Employee                               #\n");
    printf("#       2. View All Records                           #\n");
    printf("#       3. Search Database                            #\n");
    printf("#       4. Exit                                       #\n");
    printf("#                                                     #\n");
    printf("#######################################################\n");
}

void add_employee() {
    if (total_records < MAX_RECORDS) {
        Employee new_employee;
        printf("\nEnter employee name: ");
        scanf("%s", new_employee.name);
        new_employee.id = (rand() % 9000) + 1000; // 4-digit random ID
        printf("Enter employee salary: ");
        scanf("%f", &new_employee.salary);

        Record new_record;
        new_record.employee = new_employee;

        time_t now = time(0);
        strftime(new_record.date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

        DB[total_records++] = new_record;

        printf("\nEmployee added successfully!\n");
    } else {
        printf("\nCannot add more employees, database full.\n");
    }
}

void view_all_records() {
    printf("\nEmployee Records:\n");

    if (total_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    for (int i = 0; i < total_records; i++) {
        Employee employee = DB[i].employee;
        printf("%d %s %.2f %s\n", employee.id, employee.name, employee.salary, DB[i].date);
    }
}

void search_database() {
    printf("\nEnter employee ID to search for: ");

    int id, found = 0;
    scanf("%d", &id);

    for (int i = 0; i < total_records; i++) {
        if (DB[i].employee.id == id) {
            Employee employee = DB[i].employee;
            printf("\n%d %s %.2f %s\n", employee.id, employee.name, employee.salary, DB[i].date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo records found for ID %d\n", id);
    }
}