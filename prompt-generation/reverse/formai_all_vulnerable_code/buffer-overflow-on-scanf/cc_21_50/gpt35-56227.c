//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of database
#define MAX_SIZE 100

struct Record {
    int id;
    char name[20];
    int age;
};

struct Database {
    struct Record records[MAX_SIZE];
    int size;
};

int main() {
    struct Database database;
    database.size = 0;

    int choice;
    do {
        printf("*** Database Simulation ***\n");
        printf("1. Add Record\n");
        printf("2. Remove Record\n");
        printf("3. Update Record\n");
        printf("4. Search Record\n");
        printf("5. Display Database\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Record
                if (database.size >= MAX_SIZE) {
                    printf("Database is full!\n");
                } else {
                    struct Record record;

                    printf("Enter ID: ");
                    scanf("%d", &record.id);

                    printf("Enter Name: ");
                    scanf("%s", record.name);

                    printf("Enter Age: ");
                    scanf("%d", &record.age);

                    database.records[database.size] = record;
                    database.size++;

                    printf("Record added successfully!\n");
                }
                break;
            case 2: // Remove Record
                if (database.size <= 0) {
                    printf("Database is empty!\n");
                } else {
                    int id, index = -1;

                    printf("Enter ID: ");
                    scanf("%d", &id);

                    for (int i = 0; i < database.size; i++) {
                        if (database.records[i].id == id) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        printf("Record not found!\n");
                    } else {
                        for (int i = index; i < database.size - 1; i++) {
                            database.records[i] = database.records[i + 1];
                        }

                        database.records[database.size - 1].id = 0;
                        strcpy(database.records[database.size - 1].name, "");
                        database.records[database.size - 1].age = 0;
                        database.size--;

                        printf("Record removed successfully!\n");
                    }
                }
                break;
            case 3: // Update Record
                if (database.size <= 0) {
                    printf("Database is empty!\n");
                } else {
                    int id, index = -1;

                    printf("Enter ID: ");
                    scanf("%d", &id);

                    for (int i = 0; i < database.size; i++) {
                        if (database.records[i].id == id) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        printf("Record not found!\n");
                    } else {
                        struct Record record;

                        printf("Enter new ID: ");
                        scanf("%d", &record.id);

                        printf("Enter new Name: ");
                        scanf("%s", record.name);

                        printf("Enter new Age: ");
                        scanf("%d", &record.age);

                        database.records[index] = record;

                        printf("Record updated successfully!\n");
                    }
                }
                break;
            case 4: // Search Record
                if (database.size <= 0) {
                    printf("Database is empty!\n");
                } else {
                    int id, index = -1;

                    printf("Enter ID: ");
                    scanf("%d", &id);

                    for (int i = 0; i < database.size; i++) {
                        if (database.records[i].id == id) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        printf("Record not found!\n");
                    } else {
                        printf("ID: %d, Name: %s, Age: %d\n", database.records[index].id, database.records[index].name, database.records[index].age);
                    }
                }
                break;
            case 5: // Display Database
                if (database.size <= 0) {
                    printf("Database is empty!\n");
                } else {
                    printf("ID\tName\tAge\n");

                    for (int i = 0; i < database.size; i++) {
                        printf("%d\t%s\t%d\n", database.records[i].id, database.records[i].name, database.records[i].age);
                    }
                }
                break;
            case 0: // Exit
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    } while (choice != 0);

    printf("Thank you for using Database Simulation!\n");

    return 0;
}