//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 3

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][15];
    int num_numbers;
} Contact;

int main() {
    Contact phonebook[100];
    int num_contacts = 0;

    while(1) {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_contacts >= 100) {
                    printf("Phone book is full.\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", phonebook[num_contacts].name);
                printf("Enter number 1: ");
                scanf("%s", phonebook[num_contacts].numbers[0]);
                num_contacts++;
                break;

            case 2:
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);
                int i;
                for(i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("Name: %s\n", phonebook[i].name);
                        int j;
                        for(j=0; j<phonebook[i].num_numbers; j++) {
                            printf("Number %d: %s\n", j+1, phonebook[i].numbers[j]);
                        }
                    }
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}