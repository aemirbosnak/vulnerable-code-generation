//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char address[50];
} Person;

int main() {
    FILE *fptr;
    int choice;
    Person p;

    do {
        printf("\n========== Menu ==========\n");
        printf("1. Add a new person\n");
        printf("2. Display all persons\n");
        printf("3. Search persons by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fptr = fopen("persons.txt", "ab");
                if (fptr == NULL) {
                    printf("Error opening file\n");
                    exit(1);
                }

                printf("\nEnter details of person:\n");
                printf("Name: ");
                scanf("%s", p.name);
                printf("Age: ");
                scanf("%d", &p.age);
                printf("Address: ");
                scanf("%s", p.address);

                fwrite(&p, sizeof(p), 1, fptr);
                printf("\nPerson added successfully!\n");
                fclose(fptr);
                break;

            case 2:
                fptr = fopen("persons.txt", "rb");
                if (fptr == NULL) {
                    printf("Error opening file\n");
                    exit(1);
                }

                printf("\n========== All Persons ==========\n");
                printf("Name\tAge\tAddress\n");
                while (fread(&p, sizeof(p), 1, fptr)) {
                    printf("%s\t%d\t%s\n", p.name, p.age, p.address);
                }
                fclose(fptr);
                break;

            case 3:
                fptr = fopen("persons.txt", "rb");
                if (fptr == NULL) {
                    printf("Error opening file\n");
                    exit(1);
                }

                char searchName[20];
                int found = 0;
                printf("\nEnter name to search: ");
                scanf("%s", searchName);

                while (fread(&p, sizeof(p), 1, fptr)) {
                    if (strcmp(p.name, searchName) == 0) {
                        printf("\n%s\t%d\t%s\n", p.name, p.age, p.address);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("No person with name '%s' found\n", searchName);
                }
                fclose(fptr);
                break;

            case 4:
                printf("\nExiting program!\n");
                break;

            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}