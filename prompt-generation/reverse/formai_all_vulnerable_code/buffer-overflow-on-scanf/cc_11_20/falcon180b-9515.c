//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_BOOK_ENTRIES 1000

typedef struct {
    char name[50];
    char phone_number[20];
} PhoneBookEntry;

int main() {
    PhoneBookEntry phone_book[MAX_PHONE_BOOK_ENTRIES];
    int num_entries = 0;

    char option;

    do {
        printf("Welcome to the Medieval Phone Book!\n");
        printf("Please choose an option:\n");
        printf("A: Add a new entry\n");
        printf("S: Search for an entry\n");
        printf("Q: Quit\n");
        scanf("%c", &option);

        switch(option) {
            case 'A':
            case 'a':
                if(num_entries >= MAX_PHONE_BOOK_ENTRIES) {
                    printf("Phone book is full. Please delete an entry before adding a new one.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", phone_book[num_entries].name);
                    printf("Enter phone number: ");
                    scanf("%s", phone_book[num_entries].phone_number);
                    num_entries++;
                    printf("Entry added successfully!\n");
                }
                break;
            case 'S':
            case's':
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);

                int found = 0;
                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(phone_book[i].name, search_name) == 0) {
                        printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("Entry not found.\n");
                }
                break;
            case 'Q':
            case 'q':
                printf("Thank you for using the Medieval Phone Book!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while(option!= 'Q' && option!= 'q');

    return 0;
}