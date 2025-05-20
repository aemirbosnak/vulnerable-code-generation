//FormAI DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 20

struct Contact {
    char name[20];
    char phone[15];
};

int main() {
    struct Contact phonebook[MAX_CONTACTS];
    int size = 0;

    printf("Welcome to the post-apocalyptic phone book!");

    while(1) {
        int choice;
        printf("\n\nOptions:\n1. Add a contact\n2. Search for a contact\n3. Display all contacts\n4. Exit\n\nChoice: ");
        scanf("%d", &choice);
        getchar(); //remove trailing newline

        switch(choice) {
            case 1:
                if(size < MAX_CONTACTS) {
                    printf("\nName: ");
                    fgets(phonebook[size].name, 20, stdin); //get name including spaces
                    phonebook[size].name[strcspn(phonebook[size].name, "\n")] = 0; //remove trailing newline
                    printf("Phone: ");
                    fgets(phonebook[size].phone, 15, stdin); //get phone number
                    phonebook[size].phone[strcspn(phonebook[size].phone, "\n")] = 0; //remove trailing newline
                    size++;
                } else {
                    printf("\nSorry, the phone book is full.\n");
                }
                break;
            case 2:
                if(size > 0) {
                    char search[20];
                    printf("\nEnter name to search: ");
                    fgets(search, 20, stdin); //get name to search
                    search[strcspn(search, "\n")] = 0; //remove trailing newline

                    int found = 0;
                    for(int i=0; i<size; i++) {
                        if(strcmp(phonebook[i].name, search) == 0) {
                            printf("\nName: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
                            found = 1;
                            break;
                        }
                    }

                    if(!found) {
                        printf("\nSorry, contact not found.\n");
                    }

                } else {
                    printf("\nSorry, the phone book is empty.\n");
                }
                break;
            case 3:
                if(size > 0) {
                    printf("\nContact list:\n");
                    for(int i=0; i<size; i++) {
                        printf("\nName: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                } else {
                    printf("\nSorry, the phone book is empty.\n");
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option\n");
        }
    }

    return 0;
}