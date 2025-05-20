//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} contact;

int main() {
    int choice, count = 0;
    contact phonebook[MAX_ENTRIES];

    printf("Welcome to the Phonebook!\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display All Contacts\n");
    printf("4. Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= MAX_ENTRIES) {
                    printf("Phonebook is full!\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", phonebook[count].name);
                    printf("Enter phone number: ");
                    scanf("%s", phonebook[count].phone);
                    count++;
                }
                break;

            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);

                int found = 0;
                for(int i=0; i<count; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
                        found = 1;
                        break;
                    }
                }

                if(found == 0) {
                    printf("Contact not found!\n");
                }
                break;

            case 3:
                if(count == 0) {
                    printf("Phonebook is empty!\n");
                } else {
                    printf("Name\tPhone\n");
                    for(int i=0; i<count; i++) {
                        printf("%s\t%s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}