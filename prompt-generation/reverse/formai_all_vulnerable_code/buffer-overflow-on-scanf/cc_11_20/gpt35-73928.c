//FormAI DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    int choice, count = 0;
    struct Contact *phoneBook = NULL;

    do {
        printf("\n---PHONE BOOK APPLICATION---\n1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Update Contact\n5. Delete Contact\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count++;
                phoneBook = (struct Contact *) realloc(phoneBook, count * sizeof(struct Contact));
                printf("\n---ADDING A NEW CONTACT---\n");
                printf("\nEnter name: ");
                scanf(" %[^\n]s", phoneBook[count - 1].name);
                printf("Enter phone number: ");
                scanf(" %s", phoneBook[count - 1].phone);
                printf("Contact added successfully!");
                break;
            case 2:
                printf("\n---DISPLAYING ALL CONTACTS---\n");
                for (int i = 0; i < count; i++) {
                    printf("%d. Name: %s \n   Phone: %s", i + 1, phoneBook[i].name, phoneBook[i].phone); 
                }
                break;
            case 3:
                printf("\n---SEARCHING A CONTACT---\n");
                char searchName[50];
                int found = 0;
                printf("Enter name to search: ");
                scanf(" %[^\n]s", searchName);
                for (int i = 0; i < count; i++) {
                    if (strcmp(phoneBook[i].name, searchName) == 0) {
                        printf("Contact found!\nName: %s \nPhone: %s", phoneBook[i].name, phoneBook[i].phone);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found!");
                }
                break;
            case 4:
                printf("\n---UPDATING A CONTACT---\n");
                char updateName[50];
                int updated = 0;
                printf("Enter name to update: ");
                scanf(" %[^\n]s", updateName);
                for (int i = 0; i < count; i++) {
                    if (strcmp(phoneBook[i].name, updateName) == 0) {
                        printf("Contact found!\n");
                        printf("Enter new phone number: ");
                        scanf(" %s", phoneBook[i].phone);
                        printf("Contact updated successfully!");
                        updated = 1;
                        break;
                    }
                }
                if (!updated) {
                    printf("Contact not found!");
                }
                break;
            case 5:
                printf("\n---DELETING A CONTACT---\n");
                char deleteName[50];
                int deleted = 0;
                printf("Enter name to delete: ");
                scanf(" %[^\n]s", deleteName);
                for (int i = 0; i < count; i++) {
                    if (strcmp(phoneBook[i].name, deleteName) == 0) {
                        for (int j = i; j < count; j++) {
                            strcpy(phoneBook[j].name, phoneBook[j+1].name);
                            strcpy(phoneBook[j].phone, phoneBook[j+1].phone);
                        }
                        count--;
                        phoneBook = (struct Contact *) realloc(phoneBook, count * sizeof(struct Contact));
                        printf("Contact deleted successfully!");
                        deleted = 1;
                        break;
                    }
                }
                if (!deleted) {
                    printf("Contact not found!");
                }
                break;
            case 6:
                printf("\n---THANK YOU FOR USING PHONE BOOK APPLICATION---\n");
                break;
            default:
                printf("Invalid choice, please try again.");
        }
    } while (choice != 6);

    free(phoneBook);
    return 0;
}