//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10

typedef struct {
    int id;
    char name[20];
    int age;
    char address[50];
} Person;

void add_person(Person *database, int *count);
void search_person(Person *database, int count);
void display_database(Person *database, int count);

int main() {

    Person database[MAX_SIZE];
    int count = 0;
    int option = 0;

    do {
        printf("\n1. Add Person\n2. Search Person\n3. Display Database\n4. Exit\n\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_person(database, &count);
                break;
            case 2:
                search_person(database, count);
                break;
            case 3:
                display_database(database, count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while(option != 4);

    return 0;
}

void add_person(Person *database, int *count) {

    if(*count == MAX_SIZE) {
        printf("Database is full. Can't add more people.\n");
        return;
    }

    printf("\nEnter Person ID: ");
    scanf("%d", &database[*count].id);

    printf("Enter Person Name: ");
    scanf("%s", database[*count].name);

    printf("Enter Person Age: ");
    scanf("%d", &database[*count].age);

    printf("Enter Person Address: ");
    scanf("%s", database[*count].address);

    printf("\nPerson added successfully!\n");
    (*count)++;
}

void search_person(Person *database, int count) {

    int id = 0;
    printf("\nEnter Person ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(database[i].id == id) {
            printf("\nPerson found!\nID: %d\tName: %s\tAge: %d\tAddress: %s\n", database[i].id, database[i].name, database[i].age, database[i].address);
            return;
        }
    }
    printf("Person not found in database.\n");
}

void display_database(Person *database, int count) {

    printf("\nID\tName\tAge\tAddress\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%s\n", database[i].id, database[i].name, database[i].age, database[i].address);
    }
}