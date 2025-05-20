//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD 20

typedef struct {
    char name[MAX_FIELD];
    int age;
    float height;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void print_menu() {
    printf("----------------------\n");
    printf("| Database Simulation |\n");
    printf("----------------------\n");
    printf("| 1. Insert record   |\n");
    printf("| 2. Delete record   |\n");
    printf("| 3. Search record   |\n");
    printf("| 4. Display all     |\n");
    printf("| 5. Quit            |\n");
    printf("----------------------\n");
}

void insert_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", database[num_records].name);
    printf("Enter age: ");
    scanf("%d", &database[num_records].age);
    printf("Enter height: ");
    scanf("%f", &database[num_records].height);
    num_records++;
}

void delete_record() {
    char name[MAX_FIELD];
    int i;
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j + 1];
            }
            num_records--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void search_record() {
    char name[MAX_FIELD];
    int i;
    printf("Enter name to search: ");
    scanf("%s", name);
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Height: %.2f\n", database[i].height);
            return;
        }
    }
    printf("Record not found.\n");
}

void display_all() {
    int i;
    printf("----------------------\n");
    printf("| Database Content   |\n");
    printf("----------------------\n");
    for (i = 0; i < num_records; i++) {
        printf("|------------------|\n");
        printf("| Name: %s         |\n", database[i].name);
        printf("| Age: %d           |\n", database[i].age);
        printf("| Height: %.2f     |\n", database[i].height);
    }
    printf("----------------------\n");
}

int main() {
    int choice;
    print_menu();
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                display_all();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        print_menu();
    }
    return 0;
}