//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int id;
    char name[50];
    int age;
    char city[50];
} entry_t;

entry_t database[MAX_ENTRIES];
int num_entries = 0;

void add_entry()
{
    entry_t new_entry;

    printf("Enter new entry information:\n");
    printf("ID: ");
    scanf("%d", &new_entry.id);

    printf("Name: ");
    scanf("%s", new_entry.name);

    printf("Age: ");
    scanf("%d", &new_entry.age);

    printf("City: ");
    scanf("%s", new_entry.city);

    database[num_entries] = new_entry;
    num_entries++;

    printf("Entry added successfully!\n");
}

void search_entry()
{
    int id;

    printf("Enter ID to search for: ");
    scanf("%d", &id);

    for (int i = 0; i < num_entries; i++) {
        if (database[i].id == id) {
            printf("Entry found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("City: %s\n", database[i].city);
            return;
        }
    }

    printf("Entry with ID %d not found.\n", id);
}

void list_entries()
{
    printf("DATABASE ENTRIES:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("ID: %d\n", database[i].id);
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("City: %s\n\n", database[i].city);
    }
}

void save_database()
{
    FILE *fp;

    fp = fopen("database.dat", "wb");

    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    fwrite(database, sizeof(entry_t), num_entries, fp);

    fclose(fp);

    printf("Database saved to file.\n");
}

void load_database()
{
    FILE *fp;

    fp = fopen("database.dat", "rb");

    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    num_entries = 0;

    while (fread(&database[num_entries], sizeof(entry_t), 1, fp) != 0) {
        num_entries++;
    }

    fclose(fp);

    printf("Database loaded from file.\n");
}

int main()
{
    int choice;

    load_database();

    while (1) {
        printf("\nDATABASE MENU:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. List entries\n");
        printf("4. Save database\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                list_entries();
                break;
            case 4:
                save_database();
                break;
            case 5:
                save_database();
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}