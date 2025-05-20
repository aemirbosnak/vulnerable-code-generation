//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    int choice;
    int count = 0;
    struct Person database[100];

    while (1) {
        printf("Main Menu\n");
        printf("1. Add person\n");
        printf("2. Find person by name\n");
        printf("3. Find person by age\n");
        printf("4. Print database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the person: ");
                scanf("%s", database[count].name);
                printf("Enter the age of the person: ");
                scanf("%d", &database[count].age);
                count++;
                break;
            case 2:
                printf("Enter the name of the person you want to find: ");
                char name[50];
                scanf("%s", name);
                for (int i = 0; i < count; i++) {
                    if (strcmp(database[i].name, name) == 0) {
                        printf("Name: %s, Age: %d\n", database[i].name, database[i].age);
                    }
                }
                break;
            case 3:
                printf("Enter the age of the person you want to find: ");
                int age;
                scanf("%d", &age);
                for (int i = 0; i < count; i++) {
                    if (database[i].age == age) {
                        printf("Name: %s, Age: %d\n", database[i].name, database[i].age);
                    }
                }
                break;
            case 4:
                for (int i = 0; i < count; i++) {
                    printf("Name: %s, Age: %d\n", database[i].name, database[i].age);
                }
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}