//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
} entry_t;

int main() {
    entry_t phonebook[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char search_name[50];

    printf("Welcome to the phone book!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("A)dd a new entry\n");
        printf("S)earch for an entry\n");
        printf("E)xit\n");
        printf("Choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
            case 'a':
                printf("\nEnter the name: ");
                scanf("%s", phonebook[num_entries].name);
                printf("Enter the phone number: ");
                scanf("%s", phonebook[num_entries].phone);
                num_entries++;
                printf("\nEntry added successfully.\n");
                break;

            case 'S':
            case's':
                printf("\nEnter the name to search for: ");
                scanf("%s", search_name);

                for(int i=0; i<num_entries; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("\nName: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;

            case 'E':
            case 'e':
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice!= 'E' && choice!= 'e');

    return 0;
}