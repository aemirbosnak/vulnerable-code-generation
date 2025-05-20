//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void print_person(Person p) {
    printf("%d | %s | %d\n", p.id, p.name, p.age);
}

void print_database(Person *db, int length) {
    printf("ID | Name | Age\n");
    printf("-----------------\n");
    for (int i = 0; i < length; i++) {
        print_person(db[i]);
    }
    printf("\n");
}

int add_person(Person *db, int length, Person p) {
    int id = length + 1;
    p.id = id;

    db = realloc(db, sizeof(Person) * (length + 1));
    if (db == NULL) {
        printf("Error: Could not allocate memory\n");
        return length;
    }

    db[length] = p;
    printf("Added person with ID %d\n", id);
    return length + 1;
}

int remove_person(Person *db, int length, int id) {
    for (int i = 0; i < length; i++) {
        if (db[i].id == id) {
            for (int j = i; j < length - 1; j++) {
                db[j] = db[j + 1];
            }
            db = realloc(db, sizeof(Person) * (length - 1));
            if (db == NULL) {
                printf("Error: Could not allocate memory\n");
                return length;
            }
            printf("Removed person with ID %d\n", id);
            return length - 1;
        }
    }
    printf("Error: Could not find person with ID %d\n", id);
    return length;
}

int main() {
    Person *db = malloc(sizeof(Person));
    int length = 0;
    int choice, id;
    char name[20];
    int age;

    while(1) {
        printf("Welcome to the Database simulation program.\n");
        printf("What would you like to do?\n");
        printf("1. Print database\n");
        printf("2. Add a person\n");
        printf("3. Remove a person\n");
        printf("4. Quit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_database(db, length);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                Person p = {0, "", 0};
                strcpy(p.name, name);
                p.age = age;
                length = add_person(db, length, p);
                break;
            case 3:
                printf("Enter ID of person to remove: ");
                scanf("%d", &id);
                length = remove_person(db, length, id);
                break;
            case 4:
                printf("Thank you for using the Database simulation program.\n");
                free(db);
                exit(0);
            default:
                printf("Error: Invalid selection\n");
                break;
        }

        printf("\n");
    }
}