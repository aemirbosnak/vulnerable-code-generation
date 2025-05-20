//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} contact;

int main() {
    int num_contacts = 0, choice;
    contact phone_book[100];

    do {
        system("clear");
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", phone_book[num_contacts].name);
                printf("Enter Number: ");
                scanf("%s", phone_book[num_contacts].number);
                num_contacts++;
                break;

            case 2:
                printf("Enter Name to Search: ");
                char search_name[MAX_NAME_LEN];
                scanf("%s", search_name);

                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phone_book[i].name, search_name) == 0) {
                        printf("Name: %s\nNumber: %s\n", phone_book[i].name, phone_book[i].number);
                    }
                }

                break;

            case 3:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }

        printf("\n");
    } while(1);

    return 0;
}