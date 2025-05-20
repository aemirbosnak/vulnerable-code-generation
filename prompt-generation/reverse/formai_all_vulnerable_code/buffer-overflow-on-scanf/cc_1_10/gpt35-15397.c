//FormAI DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[20];
    int age;
} Person;

void print_menu() {
    printf("\n1. Add Person");
    printf("\n2. Search Person by ID");
    printf("\n3. Search Person by Name");
    printf("\n4. Display All Persons");
    printf("\n5. Exit");
}

int main() {
    Person database[MAX_SIZE];
    int count = 0;
    int choice, search_id, i;
    char search_name[20];

    printf("Welcome to the Person Database Simulation\n");

    do {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Add Person
                if(count < MAX_SIZE) {
                    Person p;
                    p.id = count + 1;
                    printf("\nEnter Person Name: ");
                    scanf("%s", p.name);
                    printf("\nEnter Person Age: ");
                    scanf("%d", &p.age);
                    database[count++] = p;
                    printf("\nPerson Added Successfully!");
                }
                else {
                    printf("\nDatabase Full, Cannot Add More Persons!");
                }
                break;
            case 2: // Search Person by ID
                printf("\nEnter ID to Search: ");
                scanf("%d", &search_id);
                for(i = 0; i < count; i++) {
                    if(database[i].id == search_id) {
                        printf("\nPerson Found!");
                        printf("\nID: %d, Name: %s, Age: %d\n", 
                                database[i].id, database[i].name, database[i].age);
                        break;
                    }
                }
                if(i == count) {
                    printf("\nPerson not Found!");
                }
                break;
            case 3: // Search Person by Name
                printf("\nEnter Name to Search: ");
                scanf("%s", search_name);
                for(i = 0; i < count; i++) {
                    if(strcmp(database[i].name, search_name) == 0) {
                        printf("\nPerson Found!");
                        printf("\nID: %d, Name: %s, Age: %d\n", 
                                database[i].id, database[i].name, database[i].age);
                        break;
                    }
                }
                if(i == count) {
                    printf("\nPerson not Found!");
                }
                break;
            case 4: // Display All Persons
                printf("\nAll Persons in Database are:\n");
                for(i = 0; i < count; i++) {
                    printf("\nID: %d, Name: %s, Age: %d\n", 
                            database[i].id, database[i].name, database[i].age);
                }
                break;
            case 5: // Exit
                printf("\nThank you for using the Person Database Simulation!");
                break;
            default:
                printf("\nInvalid Choice, Please Choose Again!");
        }
    } while(choice != 5);

    return 0;
}