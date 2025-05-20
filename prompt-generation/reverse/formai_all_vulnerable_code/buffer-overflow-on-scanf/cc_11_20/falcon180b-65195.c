//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_NUM_LEN 16

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} contact;

int main() {
    int choice, found = 0;
    char search_name[MAX_NAME_LEN];
    contact phonebook[100];
    int num_contacts = 0;

    system("clear");
    printf("*** Cyberpunk Phonebook ***\n");

    while(1) {
        system("clear");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_contacts >= 100) {
                    printf("Phonebook is full.\n");
                } else {
                    printf("Enter name: ");
                    scanf(" %[^\n]s", phonebook[num_contacts].name);
                    printf("Enter number: ");
                    scanf(" %[^\n]s", phonebook[num_contacts].number);
                    num_contacts++;
                    printf("Contact added.\n");
                }
                break;
            case 2:
                printf("Enter name to search: ");
                scanf(" %[^\n]s", search_name);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                        found = 1;
                    }
                }
                if(found == 0) {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                printf("Phonebook:\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}