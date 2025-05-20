//FormAI DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void add_contact();
void search_contact();
void delete_contact();
void display_all_contacts();

// contact structure
struct contact {
    char name[50];
    char phone_no[20];
    char email[100];
};

// global variables
int num_contacts = 0;
struct contact *phone_book;

int main() {
    int choice;
	
    // request user input
    printf("Welcome to the Ephemeral Phone Book!\n");
    printf("Please select one of the following options:\n");
    printf("1. Add contact\n");
    printf("2. Search for a contact\n");
    printf("3. Delete contact\n");
    printf("4. Display all contacts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // initialize phone book with 10 contacts
    phone_book = (struct contact*)malloc(10 * sizeof(struct contact));
    
    while(choice != 5) {
        switch(choice) {
            case 1:
                add_contact();
                break;
			case 2:
				search_contact();
				break;
			case 3:
				delete_contact();
				break;
			case 4:
				display_all_contacts();
				break;
			default:
				printf("Invalid choice!\n");
        }
		
        // request next user choice
        printf("Please select one of the following options:\n");
        printf("1. Add contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    
    // free memory allocated for phone_book
    free(phone_book);
    
    return 0;
}

// function for adding a new contact
void add_contact() {
	// check if phone_book is full
	if(num_contacts == 10) {
		printf("Phone book is full!\n");
		return;
	}
		
	// request input from user
	struct contact new_contact;
	printf("Enter name: ");
	getchar(); // clear input buffer
	fgets(new_contact.name, 50, stdin);
	printf("Enter phone number: ");
	fgets(new_contact.phone_no, 20, stdin);
	printf("Enter email: ");
	fgets(new_contact.email, 100, stdin);
	
	// add new contact to phone_book
	strcpy(phone_book[num_contacts].name, new_contact.name);
	strcpy(phone_book[num_contacts].phone_no, new_contact.phone_no);
	strcpy(phone_book[num_contacts].email, new_contact.email);
	num_contacts++;
	
	printf("Contact added successfully!\n");
}

// function to search for a contact
void search_contact() {
	// request input from user
	char search_name[50];
	printf("Enter name to search: ");
	getchar(); // clear input buffer
	fgets(search_name, 50, stdin);
	
	// search for contact in phone_book
	int i;
	for(i = 0; i < num_contacts; i++) {
		if(strcmp(phone_book[i].name, search_name) == 0) {
			printf("Name: %s", phone_book[i].name);
			printf("Phone number: %s", phone_book[i].phone_no);
			printf("Email: %s", phone_book[i].email);
			return;
		}
	}
	
	// contact not found
	printf("Contact not found!\n");
}

// function to delete a contact
void delete_contact() {
	// request input from user
	char del_name[50];
	printf("Enter name to delete: ");
	getchar(); // clear input buffer
	fgets(del_name, 50, stdin);
	
	// search for contact in phone_book
	int i;
	for(i = 0; i < num_contacts; i++) {
		if(strcmp(phone_book[i].name, del_name) == 0) {
			// delete contact from phone_book
			int j;
			for(j = i; j < num_contacts-1; j++) {
				phone_book[j] = phone_book[j+1];
			}
			num_contacts--;
			printf("Contact deleted successfully!\n");
			return;
		}
	}
	
	// contact not found
	printf("Contact not found!\n");
}

// function to display all contacts
void display_all_contacts() {
	int i;
	if(num_contacts == 0) {
		printf("Phone book is empty!\n");
		return;
	}
	for(i = 0; i < num_contacts; i++) {
		printf("Name: %s", phone_book[i].name);
		printf("Phone number: %s", phone_book[i].phone_no);
		printf("Email: %s\n", phone_book[i].email);
	}
}