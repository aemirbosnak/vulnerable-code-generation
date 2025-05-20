//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include<stdio.h>
#include<string.h>

struct phonebook {
    char name[50];
    char phone_num[20];
};

// Function to add a new contact to the phonebook
void add_contact(struct phonebook *pb, int size) {
    getchar(); // Consume newline from previous input
    printf("Enter contact name: ");
    fgets(pb[size].name, 50, stdin);
    pb[size].name[strcspn(pb[size].name, "\n")] = 0; // Remove trailing newline from input
    printf("Enter phone number: ");
    fgets(pb[size].phone_num, 20, stdin);
    pb[size].phone_num[strcspn(pb[size].phone_num, "\n")] = 0; // Remove trailing newline from input
    printf("Contact added successfully!\n");
}

// Function to search for a contact in the phonebook
void search_contact(struct phonebook *pb, int size) {
    getchar(); // Consume newline from previous input
    printf("Enter name to search: ");
    char search_name[50];
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = 0; // Remove trailing newline from input
    int found = 0;
    for(int i = 0; i < size; i++) {
        if(strcmp(pb[i].name, search_name) == 0) {
            printf("Contact found!\nName: %sPhone: %s\n", pb[i].name, pb[i].phone_num);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found.\n");
    }
}

// Function to display all contacts in the phonebook
void display_all_contacts(struct phonebook *pb, int size) {
    printf("Contacts:\n");
    for(int i = 0; i < size; i++) {
        printf("%s\t%s\n", pb[i].name, pb[i].phone_num);
    }
}

int main() {
    printf("Welcome to My Phone Book\n");

    struct phonebook pb[50];
    int size = 0;

    while(1) {
        printf("Choose an option:\n1. Add new contact\n2. Search contact\n3. Display all contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(pb, size);
                size++;
                break;
            case 2:
                search_contact(pb, size);
                break;
            case 3:
                display_all_contacts(pb, size);
                break;
            case 4:
                printf("Exiting Phone Book. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}