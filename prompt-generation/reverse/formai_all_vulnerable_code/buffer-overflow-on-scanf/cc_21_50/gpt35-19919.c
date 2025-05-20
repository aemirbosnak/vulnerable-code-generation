//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
};

int main() {
    struct contact phone_book[100];
    int num_contacts = 0;
    int choice;

    while (1) {
        printf("\n");
        printf("Phone Book Program\n");
        printf("1. Add a Contact\n");
        printf("2. Search for a Contact\n");
        printf("3. Modify a Contact\n");
        printf("4. Delete a Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // Add a Contact
                if (num_contacts == 100) {
                    printf("Phone book is full!\n");
                    break;
                }
                printf("\nEnter Name: ");
                scanf("%s", phone_book[num_contacts].name);
                printf("Enter Phone Number: ");
                scanf("%s", phone_book[num_contacts].phone);
                num_contacts++;
                printf("Contact Added Successfully!\n");
                break;

            case 2: // Search for a Contact
                if (num_contacts == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                char search_name[50];
                printf("\nEnter Name to Search: ");
                scanf("%s", search_name);
                int i, found = 0;
                for (i = 0; i < num_contacts; i++) {
                    if (strcmp(search_name, phone_book[i].name) == 0) {
                        printf("Name: %s\nPhone Number: %s\n", phone_book[i].name, phone_book[i].phone);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found!\n");
                }
                break;

            case 3: // Modify a Contact
                if (num_contacts == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                char modify_name[50];
                printf("\nEnter Name to Modify: ");
                scanf("%s", modify_name);
                int j, found_modify = 0;
                for (j = 0; j < num_contacts; j++) {
                    if (strcmp(modify_name, phone_book[j].name) == 0) {
                        printf("Enter New Phone Number: ");
                        scanf("%s", phone_book[j].phone);
                        found_modify = 1;
                        printf("Contact Modified Successfully!\n");
                        break;
                    }
                }
                if (!found_modify) {
                    printf("Contact not found!\n");
                }
                break;

            case 4: // Delete a Contact
                if (num_contacts == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                char delete_name[50];
                printf("\nEnter Name to Delete: ");
                scanf("%s", delete_name);
                int k, found_delete = 0;
                for (k = 0; k < num_contacts; k++) {
                    if (strcmp(delete_name, phone_book[k].name) == 0) {
                        int l;
                        for (l = k; l < num_contacts - 1; l++) {
                            strcpy(phone_book[l].name, phone_book[l + 1].name);
                            strcpy(phone_book[l].phone, phone_book[l + 1].phone);
                        }
                        num_contacts--;
                        found_delete = 1;
                        printf("Contact Deleted Successfully!\n");
                        break;
                    }
                }
                if (!found_delete) {
                    printf("Contact not found!\n");
                }
                break;

            case 5: // Display All Contacts
                if (num_contacts == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                printf("\n");
                printf("Name\t| Phone Number \n");
                int m;
                for (m = 0; m < num_contacts; m++) {
                    printf("%s\t| %s\n", phone_book[m].name, phone_book[m].phone);
                }
                break;

            case 6: // Exit
                printf("Thank you for using Phone Book Program!\n");
                exit(0);

            default: // Invalid Choice
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}