//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct {
    char name[20];
    int age;
    float salary;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record(char* name, int age, float salary) {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    strcpy(database[num_records].name, name);
    database[num_records].age = age;
    database[num_records].salary = salary;
    num_records++;
}

void display_records() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }

    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%d\t%.2f\n", database[i].name, database[i].age, database[i].salary);
    }
}

void search_record(char* name) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Salary: %.2f\n", database[i].salary);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    char choice;
    do {
        printf("\n*** Retro Database ***\n");
        printf("A - Add record\n");
        printf("D - Display records\n");
        printf("S - Search record\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter name: ");
                scanf("%s", database[num_records].name);
                printf("Enter age: ");
                scanf("%d", &database[num_records].age);
                printf("Enter salary: ");
                scanf("%f", &database[num_records].salary);
                break;
            case 'D':
                display_records();
                break;
            case 'S':
                printf("Enter name to search: ");
                scanf("%s", database[num_records].name);
                search_record(database[num_records].name);
                break;
            case 'Q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}