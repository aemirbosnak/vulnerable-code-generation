//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int age;
};

void insert_record(struct student *db[], int *size);
void delete_record(struct student *db[], int *size);
void update_record(struct student *db[], int *size);
void search_record(struct student *db[], int *size);
void display_records(struct student *db[], int *size);

int main() {
    struct student *database[100];
    int size = 0;
    char choice;

    printf("Welcome to the Student Database Program\n\n");

    do {
        printf("[1] Insert Record\n");
        printf("[2] Delete Record\n");
        printf("[3] Update Record\n");
        printf("[4] Search Record\n");
        printf("[5] Display Records\n");
        printf("[6] Exit\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                insert_record(database, &size);
                break;
            case '2':
                delete_record(database, &size);
                break;
            case '3':
                update_record(database, &size);
                break;
            case '4':
                search_record(database, &size);
                break;
            case '5':
                display_records(database, &size);
                break;
            case '6':
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

        printf("\n");

    } while (choice != '6');

    return 0;
}

void insert_record(struct student *db[], int *size) {
    struct student *new_record = (struct student *) malloc(sizeof(struct student));

    printf("Enter the student's ID: ");
    scanf("%d", &(new_record->id));
    printf("Enter the student's name: ");
    scanf("%s", new_record->name);
    printf("Enter the student's age: ");
    scanf("%d", &(new_record->age));

    db[*size] = new_record;
    *size += 1;

    printf("Record inserted successfully!\n");
}

void delete_record(struct student *db[], int *size) {
    int id, i, found = 0;

    printf("Enter the ID of the student you want to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *size; i++) {
        if (db[i]->id == id) {
            free(db[i]);
            found = 1;
        }
        if (found && i != *size - 1) {
            db[i] = db[i + 1];
        }
    }

    if (found) {
        *size -= 1;
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found!\n");
    }
}

void update_record(struct student *db[], int *size) {
    int id, i, found = 0;

    printf("Enter the ID of the student you want to update: ");
    scanf("%d", &id);

    for (i = 0; i < *size; i++) {
        if (db[i]->id == id) {
            printf("Current name: %s\n", db[i]->name);
            printf("Enter new name: ");
            scanf("%s", db[i]->name);
            printf("Current age: %d\n", db[i]->age);
            printf("Enter new age: ");
            scanf("%d", &(db[i]->age));
            found = 1;
        }
    }

    if (found) {
        printf("Record updated successfully!\n");
    } else {
        printf("Record not found!\n");
    }
}

void search_record(struct student *db[], int *size) {
    int id, i, found = 0;

    printf("Enter the ID of the student you want to search: ");
    scanf("%d", &id);

    for (i = 0; i < *size; i++) {
        if (db[i]->id == id) {
            printf("ID: %d\n", db[i]->id);
            printf("Name: %s\n", db[i]->name);
            printf("Age: %d\n", db[i]->age);
            found = 1;
        }
    }

    if (!found) {
        printf("Record not found!\n");
    }
}

void display_records(struct student *db[], int *size) {
    int i;

    printf("ID\t\tName\t\tAge\n");

    for (i = 0; i < *size; i++) {
        printf("%d\t\t%s\t\t%d\n", db[i]->id, db[i]->name, db[i]->age);
    }
}