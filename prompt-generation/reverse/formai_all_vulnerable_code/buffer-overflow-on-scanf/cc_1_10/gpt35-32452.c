//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact {  //structure to store contact details
    char name[50];
    char number[15];
};

int main() {
    struct contact* contacts; //pointer to array of contacts
    char input[10];
    int n, i;

    printf("Welcome to My Phone Book!\n");

    //get number of contacts
    printf("Enter number of contacts: ");
    scanf("%d", &n);

    //allocate memory for contacts
    contacts = (struct contact*)malloc(n * sizeof(struct contact));

    //get contact details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for contact %d\n", i+1);
        printf("Name: ");
        scanf("%s", contacts[i].name);
        printf("Number: ");
        scanf("%s", contacts[i].number);
    }

    //display contact details
    printf("\nYour Phone Book:\n");
    for (i = 0; i < n; i++) {
        printf("\nContact %d\n", i+1);
        printf("Name: %s\n", contacts[i].name);
        printf("Number: %s\n", contacts[i].number);
    }

    //search for a contact by name
    printf("\nDo you want to search for a contact? (y/n): ");
    scanf("%s", input);
    if(strcmp(input, "y") == 0) {
        char search_name[50];
        int found = 0;
        printf("\nEnter name to be searched: ");
        scanf("%s", search_name);
        for (i = 0; i < n; i++) {
            if(strcmp(search_name, contacts[i].name) == 0) {
                printf("\nContact found!\n");
                printf("Name: %s\n", contacts[i].name);
                printf("Number: %s\n", contacts[i].number);
                found = 1;
                break;
            }
        }
        if(found == 0) {
            printf("\nContact not found.\n");
        }
    }

    //free allocated memory
    free(contacts);

    printf("\nThank you for using My Phone Book!\n");

    return 0;
}