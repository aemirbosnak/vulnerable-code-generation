//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record();
void delete_record();
void search_record();
void print_all_records();
void save_database();
void load_database();

int main() {
    int option = 0;
    while (option != 6) {
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Search Record\n");
        printf("4. Print All Records\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                print_all_records();
                break;
            case 5:
                save_database();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Database full. Cannot add more records.\n");
        return;
    }

    Record new_record;
    new_record.id = num_records + 1;

    printf("Enter name: ");
    scanf("%s", new_record.name);

    printf("Enter age: ");
    scanf("%d", &new_record.age);

    printf("Enter height: ");
    scanf("%f", &new_record.height);

    database[num_records] = new_record;
    num_records++;

    printf("Record added successfully.\n");
}

void delete_record() {
    int id_to_delete;
    printf("Enter id of record to delete: ");
    scanf("%d", &id_to_delete);

    int i, index_to_delete = -1;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id_to_delete) {
            index_to_delete = i;
            break;
        }
    }

    if (index_to_delete == -1) {
        printf("Record with id %d not found.\n", id_to_delete);
        return;
    }

    for (i = index_to_delete; i < num_records - 1; i++) {
        database[i] = database[i+1];
    }

    num_records--;

    printf("Record with id %d deleted successfully.\n", id_to_delete);
}

void search_record() {
    int id_to_search;
    printf("Enter id of record to search: ");
    scanf("%d", &id_to_search);

    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id_to_search) {
            printf("Record found:\n");
            printf("Id: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Height: %.2f\n", database[i].height);
            return;
        }
    }

    printf("Record with id %d not found.\n", id_to_search);
}

void print_all_records() {
    if (num_records == 0) {
        printf("Database is empty.\n");
        return;
    }

    int i;
    for (i = 0; i < num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("Id: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Height: %.2f\n", database[i].height);
    }
}

void save_database() {
    char filename[MAX_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int i;
    for (i = 0; i < num_records; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", database[i].id, database[i].name, database[i].age, database[i].height);
    }

    fclose(file);

    printf("Database saved successfully.\n");
}

void load_database() {
    char filename[MAX_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_NAME_LENGTH*3];
    while (fgets(line, sizeof(line), file)) {
        Record new_record;

        char* token = strtok(line, ",");
        new_record.id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(new_record.name, token);

        token = strtok(NULL, ",");
        new_record.age = atoi(token);

        token = strtok(NULL, ",");
        new_record.height = atof(token);

        database[num_records] = new_record;
        num_records++;
    }

    fclose(file);

    printf("Database loaded successfully.\n");
}