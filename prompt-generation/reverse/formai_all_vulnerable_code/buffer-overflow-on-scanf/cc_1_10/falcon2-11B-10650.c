//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} PhoneBookEntry;

PhoneBookEntry phoneBook[10]; // 10 entries max

int main(void) {
    int i, choice;

    printf("Phone Book\n\n");

    // Create a Phone Book
    for (i = 0; i < 10; i++) {
        phoneBook[i].name[0] = '\0';
        phoneBook[i].number[0] = '\0';
    }

    while (1) {
        printf("Enter 1 to add a contact\n");
        printf("Enter 2 to display all contacts\n");
        printf("Enter 3 to search a contact\n");
        printf("Enter 4 to modify a contact\n");
        printf("Enter 5 to delete a contact\n");
        printf("Enter 6 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a contact
                printf("Enter the name: ");
                scanf("%s", phoneBook[i].name);
                printf("Enter the number: ");
                scanf("%s", phoneBook[i].number);
                break;

            case 2: // Display all contacts
                printf("\nAll Contacts:\n");
                for (i = 0; i < 10; i++) {
                    printf("%d - %s - %s\n", i + 1, phoneBook[i].name, phoneBook[i].number);
                }
                break;

            case 3: // Search for a contact
                printf("Enter the name to search: ");
                scanf("%s", phoneBook[i].name);
                printf("Enter the number to search: ");
                scanf("%s", phoneBook[i].number);
                break;

            case 4: // Modify a contact
                printf("Enter the name to modify: ");
                scanf("%s", phoneBook[i].name);
                printf("Enter the new number: ");
                scanf("%s", phoneBook[i].number);
                break;

            case 5: // Delete a contact
                printf("Enter the name to delete: ");
                scanf("%s", phoneBook[i].name);
                break;

            case 6: // Exit
                exit(0);
                break;

            default:
                printf("Invalid Choice, try again\n");
        }
    }

    return 0;
}