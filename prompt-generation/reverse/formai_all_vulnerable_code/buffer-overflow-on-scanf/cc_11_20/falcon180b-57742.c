//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} contact;

int main() {
    int num_contacts = 0;
    contact phonebook[100];

    while(1) {
        printf("Enter 1 to add a contact, 2 to search a contact, 3 to delete a contact, 4 to display all contacts, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", phonebook[num_contacts].name);
                printf("Enter number: ");
                scanf("%s", phonebook[num_contacts].number);
                num_contacts++;
                break;

            case 2:
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);

                int found = 0;
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Contact not found.\n");
                break;

            case 3:
                printf("Enter name to delete: ");
                char del_name[MAX_NAME_LENGTH];
                scanf("%s", del_name);

                int del_index = -1;
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, del_name) == 0) {
                        del_index = i;
                        break;
                    }
                }

                if(del_index!= -1) {
                    num_contacts--;
                    for(int i=del_index; i<num_contacts; i++) {
                        strcpy(phonebook[i].name, phonebook[i+1].name);
                        strcpy(phonebook[i].number, phonebook[i+1].number);
                    }
                } else
                    printf("Contact not found.\n");
                break;

            case 4:
                printf("Name\tNumber\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("%s\t%s\n", phonebook[i].name, phonebook[i].number);
                }
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}