//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

int main() {
    struct contact phonebook[100]; // array of 100 contacts
    int num_contacts = 0; // number of contacts in phonebook
    int choice;

    while(1) {
        printf("Phone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search for Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_contacts >= 100) {
                    printf("Phone book is full!\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", phonebook[num_contacts].name);
                printf("Enter phone number: ");
                scanf("%s", phonebook[num_contacts].phone);
                num_contacts++;
                printf("Contact added!\n");
                break;
            case 2:
                if(num_contacts == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                printf("All Contacts:\n");
                for(int i = 0; i < num_contacts; i++) {
                    printf("%s\t%s\n", phonebook[i].name, phonebook[i].phone);
                }
                break;
            case 3:
                if(num_contacts == 0) {
                    printf("Phone book is empty!\n");
                    break;
                }
                char search_name[50];
                printf("Enter name to search for: ");
                scanf("%s", search_name);
                int found_flag = 0;
                for(int i = 0; i < num_contacts; i++) {
                    if(strcmp(search_name, phonebook[i].name) == 0) {
                        printf("Found contact:\n%s\t%s\n", phonebook[i].name, phonebook[i].phone);
                        found_flag = 1;
                    }
                }
                if(!found_flag) {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}