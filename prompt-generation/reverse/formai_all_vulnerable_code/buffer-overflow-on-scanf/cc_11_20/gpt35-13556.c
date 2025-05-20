//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char mobile_number[20];
    char email[50];
} contact;

int main() {
    int choice, i, n = 0;
    contact *book = malloc(n * sizeof(contact));
    while (1) {
        printf("\nC Phone Book");
        printf("\n1. Add a contact");
        printf("\n2. View all contacts");
        printf("\n3. Search for a contact");
        printf("\n4. Delete a contact");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter contact name: ");
                scanf("%s", book[n].name);
                printf("Enter mobile number: ");
                scanf("%s", book[n].mobile_number);
                printf("Enter email address: ");
                scanf("%s", book[n].email);
                n++;
                book = realloc(book, n * sizeof(contact));
                printf("\nContact added successfully!\n");
                break;
            case 2:
                printf("\nContacts:\n");
                for (i = 0; i < n; i++) {
                    printf("Name: %s\n", book[i].name);
                    printf("Mobile Number: %s\n", book[i].mobile_number);
                    printf("Email address: %s\n\n", book[i].email);
                }
                break;
            case 3:
                printf("\nEnter name to search for: ");
                char search_name[50];
                scanf("%s", search_name);
                for (i = 0; i < n; i++) {
                    if (strcmp(book[i].name, search_name) == 0) {
                        printf("\nContact found!\n\n");
                        printf("Name: %s\n", book[i].name);
                        printf("Mobile Number: %s\n", book[i].mobile_number);
                        printf("Email address: %s\n", book[i].email);
                        break;
                    }
                }
                if (i == n) {
                    printf("\nContact not found!\n");
                }
                break;
            case 4:
                printf("\nEnter name to delete: ");
                char delete_name[50];
                scanf("%s", delete_name);
                for (i = 0; i < n; i++) {
                    if (strcmp(book[i].name, delete_name) == 0) {
                        for (int j=i; j<n; j++) {
                            strcpy(book[j].name, book[j+1].name);
                            strcpy(book[j].mobile_number, book[j+1].mobile_number);
                            strcpy(book[j].email, book[j+1].email);
                        }
                        n--;
                        book = realloc(book, n * sizeof(contact));
                        printf("\nContact deleted successfully!\n");
                        break;
                    }
                }
                if (i == n) {
                    printf("\nContact not found!\n");
                }
                break;
            case 5:
                printf("\nExiting the program...\n");
                free(book);
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}