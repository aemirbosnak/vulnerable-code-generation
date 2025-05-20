//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void clear_stdin(void) {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void print_header(void) {
    printf("ID\tName\tAge\n");
    printf("================================\n");
}

void print_person(Person person) {
    printf("%d\t%s\t%d\n", person.id, person.name, person.age);
}

void print_database(Person *database, int num_records) {
    print_header();
    for (int i = 0; i < num_records; ++i) {
        print_person(database[i]);
    }
    printf("\n");
}

int search_database(Person *database, int num_records, int id) {
    for (int i = 0; i < num_records; ++i) {
        if (database[i].id == id) {
            return i;
        }
    }
    return -1;  // not found
}

void add_person(Person *database, int *num_records) {
    if (*num_records == MAX_RECORDS) {
        printf("Database is full.\n\n");
        return;
    }

    Person person;
    printf("Enter ID: ");
    scanf("%d", &person.id);
    clear_stdin();

    if (search_database(database, *num_records, person.id) != -1) {
        printf("ID already exists.\n\n");
        return;
    }

    printf("Enter name: ");
    fgets(person.name, 20, stdin);
    person.name[strlen(person.name)-1] = '\0';  // remove newline character

    printf("Enter age: ");
    scanf("%d", &person.age);
    clear_stdin();

    database[*num_records] = person;
    ++(*num_records);

    printf("Added new person.\n\n");
}

void delete_person(Person *database, int *num_records, int id) {
    int index = search_database(database, *num_records, id);
    if (index == -1) {
        printf("Person not found.\n\n");
        return;
    }

    // move all subsequent records one position towards the beginning
    for (int i = index; i < *num_records - 1; ++i) {
        database[i] = database[i+1];
    }

    --(*num_records);

    printf("Deleted person.\n\n");
}

void modify_person(Person *database, int num_records, int id) {
    int index = search_database(database, num_records, id);
    if (index == -1) {
        printf("Person not found.\n\n");
        return;
    }

    printf("Enter new name: ");
    fgets(database[index].name, 20, stdin);
    database[index].name[strlen(database[index].name)-1] = '\0';  // remove newline character

    printf("Enter new age: ");
    scanf("%d", &database[index].age);
    clear_stdin();

    printf("Modified person.\n\n");
}

int main() {
    Person database[MAX_RECORDS];
    int num_records = 0;

    char choice;
    int id;

    do {
        printf("Enter your choice:\n");
        printf("1. Print database\n");
        printf("2. Add person\n");
        printf("3. Delete person\n");
        printf("4. Modify person\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%c", &choice);
        clear_stdin();

        switch (choice) {
            case '1':
                print_database(database, num_records);
                break;
            case '2':
                add_person(database, &num_records);
                break;
            case '3':
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                clear_stdin();
                delete_person(database, &num_records, id);
                break;
            case '4':
                printf("Enter ID to modify: ");
                scanf("%d", &id);
                clear_stdin();
                modify_person(database, num_records, id);
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    } while (choice != '5');

    return 0;
}