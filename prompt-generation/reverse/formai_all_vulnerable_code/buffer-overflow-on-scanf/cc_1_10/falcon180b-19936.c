//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct contact {
    char name[MAX];
    char phone[MAX];
};

int main() {
    int choice, i, j, n = 0;
    char search[MAX];
    struct contact book[MAX];

    printf("Welcome to the Phone Book!\n");

    while(1) {
        printf("\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the name of the contact: ");
                scanf("%s", book[n].name);
                printf("Enter the phone number of the contact: ");
                scanf("%s", book[n].phone);
                n++;
                break;

            case 2:
                printf("\nEnter the name to search: ");
                scanf("%s", search);
                for(i=0; i<n; i++) {
                    if(strcmp(search, book[i].name) == 0) {
                        printf("\nName: %s\nPhone: %s\n", book[i].name, book[i].phone);
                        break;
                    }
                }
                if(i == n) {
                    printf("\nNo contact found with this name.\n");
                }
                break;

            case 3:
                for(i=0; i<n; i++) {
                    printf("\nName: %s\nPhone: %s\n", book[i].name, book[i].phone);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}