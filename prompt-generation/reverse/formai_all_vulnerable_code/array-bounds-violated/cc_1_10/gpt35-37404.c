//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include<stdio.h>
#include<string.h>

struct contact {
    char name[50];
    char address[100];
    char phone[15];
};

struct contact phonebook[100];
int size = 0;

void addContact() {
    printf("Enter name: ");
    fflush(stdin);
    fgets(phonebook[size].name, 50, stdin);
    phonebook[size].name[strlen(phonebook[size].name) - 1] = '\0';
    
    printf("Enter address: ");
    fflush(stdin);
    fgets(phonebook[size].address, 100, stdin);
    phonebook[size].address[strlen(phonebook[size].address) - 1] = '\0';
    
    printf("Enter phone number: ");
    fflush(stdin);
    fgets(phonebook[size].phone, 15, stdin);
    phonebook[size].phone[strlen(phonebook[size].phone) - 1] = '\0';
    
    size++;
}

void searchContact() {
    char searchName[50];
    int index = -1;
    
    printf("Enter name to search: ");
    fflush(stdin);
    fgets(searchName, 50, stdin);
    searchName[strlen(searchName) - 1] = '\0';
    
    for(int i = 0; i < size; i++) {
        if(strcmp(phonebook[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("Contact not found!\n");
    }
    else {
        printf("Name: %s\n", phonebook[index].name);
        printf("Address: %s\n", phonebook[index].address);
        printf("Phone number: %s\n", phonebook[index].phone);
    }
}

void displayPhonebook() {
    printf("Contacts in phonebook: \n\n");
    for(int i = 0; i < size; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Address: %s\n", phonebook[i].address);
        printf("Phone number: %s\n\n", phonebook[i].phone);
    }
}

void menu() {
    printf("\n1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Display Phonebook\n");
    printf("4. Exit\n");
}

int main() {
    int choice = 0;
    
    while(choice != 4) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                displayPhonebook();
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice! Try again.");
        }
    }
    
    return 0;
}