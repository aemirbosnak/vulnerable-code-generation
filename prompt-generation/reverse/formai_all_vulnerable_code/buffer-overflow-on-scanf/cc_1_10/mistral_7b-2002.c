//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 50

typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void create_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    printf("Enter name: ");
    fgets(database[num_records].name, RECORD_SIZE, stdin);
    database[num_records].name[strcspn(database[num_records].name, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &database[num_records].age);

    printf("Enter salary: ");
    scanf("%f", &database[num_records].salary);

    num_records++;
}

void read_record(int index) {
    if (index < 0 || index >= num_records) {
        printf("Invalid index.\n");
        return;
    }

    printf("\nRecord %d:\n", index + 1);
    printf("Name: %s\n", database[index].name);
    printf("Age: %d\n", database[index].age);
    printf("Salary: %.2f\n", database[index].salary);
}

void update_record(int index) {
    if (index < 0 || index >= num_records) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new name: ");
    fgets(database[index].name, RECORD_SIZE, stdin);
    database[index].name[strcspn(database[index].name, "\n")] = '\0';

    printf("Enter new age: ");
    scanf("%d", &database[index].age);

    printf("Enter new salary: ");
    scanf("%f", &database[index].salary);
}

void delete_record(int index) {
    if (index < 0 || index >= num_records) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < num_records - 1; i++) {
        database[i] = database[i + 1];
    }

    num_records--;
}

void menu() {
    printf("\nDatabase Simulation Menu:\n");
    printf("1. Create Record\n");
    printf("2. Read Record\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int index;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_record();
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                read_record(index);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                update_record(index);
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                delete_record(index);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}