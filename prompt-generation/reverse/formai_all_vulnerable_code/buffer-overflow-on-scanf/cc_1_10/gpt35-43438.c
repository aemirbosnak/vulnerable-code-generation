//FormAI DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>

struct contact {
    char name[50];
    char number[20];
};

int main() {
    struct contact phoneBook[100];
    int count = 0;
    char choice = ' ';
    printf("Welcome to the Cyberpunk Phone Book!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("A) Add a new contact\n");
        printf("B) View all contacts\n");
        printf("C) Search for a contact\n");
        printf("D) Exit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
                printf("Enter the name of the contact:\n");
                scanf(" %[^\n]s", phoneBook[count].name);
                printf("Enter the phone number of the contact:\n");
                scanf(" %s", phoneBook[count].number);
                printf("Contact added successfully!\n");
                count++;
                break;
            case 'B':
                printf("Number of contacts: %d\n", count);
                for(int i = 0; i < count; i++) {
                    printf("%s : %s\n", phoneBook[i].name, phoneBook[i].number);
                }
                break;
            case 'C':
                printf("Enter the name of the contact you want to find:\n");
                char search[50];
                scanf(" %[^\n]s", search);
                for(int i = 0; i < count; i++) {
                    if(strcmp(phoneBook[i].name, search) == 0) {
                        printf("%s : %s\n", phoneBook[i].name, phoneBook[i].number);
                        break;
                    }
                    if(i == count-1) printf("Contact not found!\n");
                }
                break;
            case 'D':
                printf("Exiting Cyberpunk Phone Book...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 'D');

    return 0;
}