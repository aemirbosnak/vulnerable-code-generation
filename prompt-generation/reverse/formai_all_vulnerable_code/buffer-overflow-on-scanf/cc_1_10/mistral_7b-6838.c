//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;
void print_menu();
Contact contacts[MAX_CONTACTS];
int main() {
    int choice, index = 0;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (index < MAX_CONTACTS) {
                    printf("Enter contact name: ");
                    fgets(contacts[index].name, NAME_LENGTH, stdin);
                    contacts[index].name[strcspn(contacts[index].name, "\n")] = '\0';
                    printf("Enter contact phone number: ");
                    fgets(contacts[index].phone, PHONE_LENGTH, stdin);
                    contacts[index].phone[strcspn(contacts[index].phone, "\n")] = '\0';
                    index++;
                    printf("Contact added successfully!\n");
                } else {
                    printf("Phone book is full.\n");
                }
                break;
            case 2:
                if (index > 0) {
                    printf("Enter contact index to search: ");
                    int search_index;
                    scanf("%d", &search_index);
                    if (search_index >= 0 && search_index < index) {
                        printf("Name: %s\nPhone: %s\n", contacts[search_index].name, contacts[search_index].phone);
                    } else {
                        printf("Invalid contact index.\n");
                    }
                } else {
                    printf("Phone book is empty.\n");
                }
                break;
            case 3:
                if (index > 0) {
                    for (int i = 0; i < index; i++) {
                        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
                    }
                } else {
                    printf("Phone book is empty.\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
void print_menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add new contact\n");
    printf("2. Search contact by index\n");
    printf("3. Display all contacts\n");
    printf("4. Exit\n");
}