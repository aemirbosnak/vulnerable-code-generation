//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include<stdio.h>
#include<string.h>

typedef struct {
    char name[50];
    char phone_num[12];
} Contact;

void add_contact(Contact[], int *);
void search_contact(Contact[], int);
void view_all_contacts(Contact[], int);
void delete_contact(Contact[], int *);

int main() {
    Contact phonebook[100];
    int num_contacts = 0;
    int choice;

    do {
        printf("\n---- PHONE BOOK APPLICATION ----\n");
        printf("1.Add Contact\n");
        printf("2.Search Contact\n");
        printf("3.View All Contacts\n");
        printf("4.Delete Contact\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(phonebook, &num_contacts);
                break;
            case 2:
                search_contact(phonebook, num_contacts);
                break;
            case 3:
                view_all_contacts(phonebook, num_contacts);
                break;
            case 4:
                delete_contact(phonebook, &num_contacts);
                break;
            case 5:
                printf("\nThank you for using Phone Book Application.\n");
                break;
            default:
                printf("\nInvalid choice. Please choose option between 1-5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void add_contact(Contact contacts[], int *num_contacts) {
    Contact new_contact;

    printf("Enter the name: ");
    fflush(stdin);
    gets(new_contact.name);

    printf("Enter the phone number: ");
    fflush(stdin);
    gets(new_contact.phone_num);

    contacts[*num_contacts] = new_contact;
    *num_contacts += 1;

    printf("\nContact added successfully!\n");
}

void search_contact(Contact contacts[], int num_contacts) {
    char name[50];
    int contact_found = 0;

    printf("\nEnter the name to search: ");
    fflush(stdin);
    gets(name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("\nContact Details:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_num);
            contact_found = 1;
            break;
        }
    }

    if (!contact_found) {
        printf("\nContact not found!\n");
    }
}

void view_all_contacts(Contact contacts[], int num_contacts) {
    if (num_contacts > 0) {
        printf("\n--------- ALL CONTACTS ---------\n");
        for (int i = 0; i < num_contacts; i++) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_num);
            printf("--------------------------\n");
        }
    }
    else {
        printf("\nNo contacts available!\n");
    }
}

void delete_contact(Contact contacts[], int *num_contacts) {
    char name[50];
    int contact_found = 0;
    int delete_pos;

    printf("\nEnter the name to delete: ");
    fflush(stdin);
    gets(name);

    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            contact_found = 1;
            delete_pos = i;
            break;
        }
    }

    if (contact_found) {
        for (int i = delete_pos; i < (*num_contacts)-1; i++) {
            contacts[i] = contacts[i+1];  
        }
        *num_contacts -= 1;

        printf("\nContact deleted successfully!\n");
    }
    else {
        printf("\nContact not found!\n");
    }
}