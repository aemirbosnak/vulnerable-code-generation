//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <string.h>

struct PhoneBook {
    char name[100];
    char phoneNumber[20];
};

struct PhoneBook phoneBook[10];

int main() {
    int choice, num;
    char name[100], phoneNumber[20];

    printf("Phone Book Menu:\n");
    printf("1. Add entry\n");
    printf("2. Delete entry\n");
    printf("3. Display entries\n");
    printf("4. Search entry\n");
    printf("5. Quit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);

                strcpy(phoneBook[num].name, name);
                strcpy(phoneBook[num].phoneNumber, phoneNumber);
                num++;
                break;
            case 2:
                printf("\nEnter name to delete: ");
                scanf("%s", name);

                for (int i = 0; i < num; i++) {
                    if (strcmp(phoneBook[i].name, name) == 0) {
                        printf("\nDeleting entry for %s\n", name);
                        strcpy(phoneBook[i].name, "");
                        strcpy(phoneBook[i].phoneNumber, "");
                        break;
                    }
                }
                break;
            case 3:
                printf("\nDisplaying entries:\n");

                for (int i = 0; i < num; i++) {
                    printf("\nName: %s\nPhone Number: %s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                }
                break;
            case 4:
                printf("\nEnter name to search: ");
                scanf("%s", name);

                for (int i = 0; i < num; i++) {
                    if (strcmp(phoneBook[i].name, name) == 0) {
                        printf("\nPhone number for %s: %s\n", name, phoneBook[i].phoneNumber);
                        break;
                    }
                }
                break;
            case 5:
                printf("\nThank you for using the Phone Book program!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}