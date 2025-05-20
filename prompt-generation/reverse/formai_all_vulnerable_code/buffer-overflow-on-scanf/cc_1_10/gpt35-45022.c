//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    struct Contact phoneBook[100];
    int numContacts = 0;
    char choice;

    do {
        printf("C Phone Book\n");
        printf("-------------\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                printf("Enter name: ");
                scanf("%s", phoneBook[numContacts].name);
                printf("Enter phone number: ");
                scanf("%s", phoneBook[numContacts].phone);
                numContacts++;
                break;
            }
            case '2': {
                char searchName[50];
                printf("Enter name to search for: ");
                scanf("%s", searchName);

                int found = 0;

                for (int i = 0; i < numContacts; i++) {
                    if (strcmp(searchName, phoneBook[i].name) == 0) {
                        printf("%s's phone number is %s\n", phoneBook[i].name, phoneBook[i].phone);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("%s not found in phone book\n", searchName);
                }

                break;
            }
            case '3': {
                printf("All Contacts\n");
                printf("-------------\n");
                for (int i = 0; i < numContacts; i++) {
                    printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
                }
                break;
            }
            case '4': {
                printf("Thank you for using C Phone Book!");
                break;
            }
            default: {
                printf("Invalid choice, please try again.");
                break;
            }
        }

        printf("\n");

    } while (choice != '4');

    return 0;
}