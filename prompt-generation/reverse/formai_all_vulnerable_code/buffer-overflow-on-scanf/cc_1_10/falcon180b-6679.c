//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct phonebook {
    char name[MAX];
    char number[MAX];
};

int main() {
    int choice, search;
    struct phonebook book[MAX];
    int count = 0;
    char name[MAX];
    char number[MAX];

    printf("Welcome to Phone Book\n");
    printf("---------------------------------\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display Phone Book\n");
    printf("4. Exit\n");
    printf("---------------------------------\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", book[count].name);
                printf("Enter Number: ");
                scanf("%s", book[count].number);
                count++;
                printf("Contact added successfully\n");
                break;

            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                search = 0;

                for(int i=0; i<count; i++) {
                    if(strcmp(name, book[i].name) == 0) {
                        printf("Name: %s\n", book[i].name);
                        printf("Number: %s\n", book[i].number);
                        search = 1;
                        break;
                    }
                }

                if(search == 0) {
                    printf("Contact not found\n");
                }
                break;

            case 3:
                printf("Phone Book:\n");
                for(int i=0; i<count; i++) {
                    printf("Name: %s\n", book[i].name);
                    printf("Number: %s\n", book[i].number);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}