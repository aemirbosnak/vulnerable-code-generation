//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <string.h>

struct PhoneBook {
    char name[100];
    char phoneNumber[15];
};

void printPhoneBook() {
    struct PhoneBook phoneBook;
    phoneBook.name[0] = '\0';
    phoneBook.phoneNumber[0] = '\0';
    
    printf("Phone Book:\n");
    printf("Name: %s\n", phoneBook.name);
    printf("Phone Number: %s\n", phoneBook.phoneNumber);
}

void addEntry() {
    struct PhoneBook phoneBook;
    char name[100];
    char phoneNumber[15];
    
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Phone Number: ");
    scanf("%s", phoneNumber);
    
    strcpy(phoneBook.name, name);
    strcpy(phoneBook.phoneNumber, phoneNumber);
    
    printf("Entry added successfully!\n");
}

int main() {
    struct PhoneBook phoneBook;
    phoneBook.name[0] = '\0';
    phoneBook.phoneNumber[0] = '\0';
    
    while (1) {
        printf("1. Print Phone Book\n2. Add Entry\n3. Quit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printPhoneBook();
                break;
            case 2:
                addEntry();
                break;
            case 3:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}