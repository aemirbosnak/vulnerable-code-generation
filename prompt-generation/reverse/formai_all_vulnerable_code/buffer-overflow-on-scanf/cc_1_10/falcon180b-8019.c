//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone_number[15];
} phone_book_entry;

int main() {
    char input[100];
    phone_book_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    do {
        printf("Welcome to the phone book!\n");
        printf("Please choose an option:\n");
        printf("A - Add an entry\n");
        printf("S - Search for an entry\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                printf("Enter the name of the person:\n");
                scanf("%s", input);
                printf("Enter the phone number:\n");
                scanf("%s", input);

                if(num_entries < MAX_ENTRIES) {
                    strcpy(entries[num_entries].name, input);
                    strcpy(entries[num_entries].phone_number, input);
                    num_entries++;
                } else {
                    printf("Phone book is full.\n");
                }
                break;

            case 'S':
                printf("Enter the name of the person to search for:\n");
                scanf("%s", input);

                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(entries[i].name, input) == 0) {
                        printf("Phone number for %s: %s\n", entries[i].name, entries[i].phone_number);
                    }
                }

                if(!strcmp(input, "")) {
                    printf("No such entry found.\n");
                }
                break;

            case 'Q':
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'Q');

    return 0;
}