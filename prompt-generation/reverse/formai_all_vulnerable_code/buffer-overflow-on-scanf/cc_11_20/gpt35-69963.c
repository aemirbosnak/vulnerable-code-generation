//FormAI DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 100

typedef struct {
    int id;
    char name[50];
    char occupation[50];
    int age;
} Person;

int main() {
    Person database[MAX_NAMES];
    int num_people = 0;

    printf("Welcome to our love database!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a person to the database\n");
        printf("2. Search for a person in the database\n");
        printf("3. Update a person's information\n");
        printf("4. Delete a person from the database\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        if(choice == 1) {
            printf("\nEnter the person's name: ");
            fgets(database[num_people].name, 50, stdin);
            database[num_people].name[strcspn(database[num_people].name, "\n")] = 0; // Remove newline character

            printf("Enter the person's occupation: ");
            fgets(database[num_people].occupation, 50, stdin);
            database[num_people].occupation[strcspn(database[num_people].occupation, "\n")] = 0;

            printf("Enter the person's age: ");
            scanf("%d", &database[num_people].age);
            database[num_people].id = num_people + 1;

            printf("\nAdded %s to the database with ID %d!\n", database[num_people].name, database[num_people].id);

            num_people++;
        } else if(choice == 2) {
            printf("\nEnter the person's name: ");
            char search_name[50];
            fgets(search_name, 50, stdin);
            search_name[strcspn(search_name, "\n")] = 0;

            int found = 0;

            for(int i = 0; i < num_people; i++) {
                if(strcmp(database[i].name, search_name) == 0) {
                    printf("\nWe found %s in the database!\n", search_name);
                    printf("ID: %d\n", database[i].id);
                    printf("Occupation: %s\n", database[i].occupation);
                    printf("Age: %d\n", database[i].age);

                    found = 1;
                    break;
                }
            }

            if(!found) {
                printf("\nSorry, we could not find %s in the database.\n", search_name);
            }
        } else if(choice == 3) {
            printf("\nEnter the ID of the person you want to update: ");
            int update_id;
            scanf("%d", &update_id);

            int found = 0;

            for(int i = 0; i < num_people; i++) {
                if(database[i].id == update_id) {
                    printf("\nWhat would you like to update?\n");
                    printf("1. Name\n");
                    printf("2. Occupation\n");
                    printf("3. Age\n");

                    int update_choice;
                    scanf("%d", &update_choice);
                    getchar(); // Consume newline character

                    if(update_choice == 1) {
                        printf("Enter the new name: ");
                        fgets(database[i].name, 50, stdin);
                        database[i].name[strcspn(database[i].name, "\n")] = 0;

                        printf("\nUpdated the name to %s for ID %d!\n", database[i].name, database[i].id);
                    } else if(update_choice == 2) {
                        printf("Enter the new occupation: ");
                        fgets(database[i].occupation, 50, stdin);
                        database[i].occupation[strcspn(database[i].occupation, "\n")] = 0;

                        printf("\nUpdated the occupation to %s for ID %d!\n", database[i].occupation, database[i].id);
                    } else if(update_choice == 3) {
                        printf("Enter the new age: ");
                        scanf("%d", &database[i].age);

                        printf("\nUpdated the age to %d for ID %d!\n", database[i].age, database[i].id);
                    } else {
                        printf("\nInvalid choice.\n");
                    }

                    found = 1;
                    break;
                }
            }

            if(!found) {
                printf("\nSorry, we could not find ID %d in the database.\n", update_id);
            }
        } else if(choice == 4) {
            printf("\nEnter the ID of the person you want to delete: ");
            int delete_id;
            scanf("%d", &delete_id);

            int found = 0;

            for(int i = 0; i < num_people; i++) {
                if(database[i].id == delete_id) {
                    printf("\nDeleting %s from the database...\n", database[i].name);

                    for(int j = i; j < num_people - 1; j++) {
                        database[j] = database[j+1];
                    }

                    num_people--;

                    found = 1;
                    break;
                }
            }

            if(!found) {
                printf("\nSorry, we could not find ID %d in the database.\n", delete_id);
            }
        } else if(choice == 5) {
            printf("\nThanks for using our love database. Don't forget to spread the love!\n");
            break;
        } else {
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}