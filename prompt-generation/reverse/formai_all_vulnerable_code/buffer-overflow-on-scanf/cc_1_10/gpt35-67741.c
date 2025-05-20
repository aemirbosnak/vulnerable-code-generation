//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct record {
    int id;
    char name[20];
    int age;
};

void print_menu();
void add_record(struct record *database, int *size);
void remove_record(struct record *database, int *size, int id);
void search_record(struct record *database, int size, char *name);
void print_database(struct record *database, int size);

int main()
{
    struct record database[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_record(database, &size);
                break;
            case 2:
                printf("Enter the ID of the record to be removed: ");
                int id;
                scanf("%d", &id);
                remove_record(database, &size, id);
                break;
            case 3:
                printf("Enter name to search: ");
                char name[20];
                scanf("%s", name);
                search_record(database, size, name);
                break;
            case 4:
                print_database(database, size);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void print_menu()
{
    printf("\nMenu:\n");
    printf("1. Add record\n");
    printf("2. Remove record\n");
    printf("3. Search record\n");
    printf("4. Print database\n");
    printf("5. Exit\n");
}

void add_record(struct record *database, int *size)
{
    if (*size == MAX_SIZE){
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &database[*size].id);
    printf("Enter name: ");
    scanf("%s", database[*size].name);
    printf("Enter age: ");
    scanf("%d", &database[*size].age);

    *size += 1;
    printf("Record added successfully.\n");
}

void remove_record(struct record *database, int *size, int id)
{
    int i, j;
    for (i = 0; i < *size; i++){
        if (database[i].id == id) {
            for (j = i; j < *size - 1; j++) {
                database[j] = database[j+1];
            }
            *size -= 1;
            printf("Record removed successfully.\n");
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void search_record(struct record *database, int size, char *name)
{
    int i;
    for (i = 0; i < size; i++){
        if (strcmp(database[i].name, name) == 0){
            printf("Record found:\nID: %d\nName: %s\nAge: %d\n", database[i].id, database[i].name, database[i].age);
            return;
        }
    }
    printf("Record with name %s not found.\n", name);
}

void print_database(struct record *database, int size)
{
    if (size == 0){
        printf("The database is empty.\n");
        return;
    }

    printf("ID\tName\tAge\n");
    printf("-------------------------------\n");
    int i;
    for (i = 0; i < size; i++){
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
    printf("-------------------------------\n");
}