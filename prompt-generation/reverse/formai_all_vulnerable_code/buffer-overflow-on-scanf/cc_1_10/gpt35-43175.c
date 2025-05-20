//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[30];
    long int phone_number;
} contact;

int main() {

    int i, n, choice;
    char search[30];

    printf("Enter the number of contacts you want to add:");
    scanf("%d", &n);

    contact *contacts = (contact*)malloc(n * sizeof(contact));

    // loop for taking input from user
    for(i = 0; i < n; i++) {
        printf("\n%s", "Enter Contact name:");
        scanf("%s", contacts[i].name);
        printf("%s", "Enter Phone Number:");
        scanf("%ld", &contacts[i].phone_number);
    }

    // display all contacts
    printf("\nAll Contacts:");
    for(i = 0; i < n; i++) {
        printf("\nName: %s\t\tPhone Number: %ld", contacts[i].name, contacts[i].phone_number);
    }

    // search contacts
    printf("\nDo you want to search any contact?(1 for yes, 0 for no)");
    scanf("%d", &choice);

    while(choice == 1) {
        printf("%s", "\nSearch Contact:");
        scanf("%s", search);
        for(i = 0; i < n; i++) {
            if(strcmp(search, contacts[i].name) == 0) {
                printf("\n%s\t\t%ld\n", contacts[i].name, contacts[i].phone_number);
                break;
            }
        }
        if(i == n) {
            printf("\n%s", "Invalid Search!");
        }
        printf("\nDo you want to search any contact?(1 for yes, 0 for no)");
        scanf("%d", &choice);
    }

    free(contacts);

    return 0;
}