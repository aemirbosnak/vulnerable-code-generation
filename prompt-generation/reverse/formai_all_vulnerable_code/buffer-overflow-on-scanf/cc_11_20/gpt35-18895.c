//FormAI DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <string.h>

struct contact {
    char name[30];
    char phone[15];
    char email[50];
    char address[100];
};

int main() {
    // Initialize contacts array
    struct contact contacts[50];

    // Initialize variables for input validation
    int name_valid, phone_valid, email_valid, address_valid;
    
    // Initialize paranoid variables
    int is_secret_agent, is_under_surveillance, is_being_tapped;
    
    // Prompt for number of contacts to add
    printf("Enter number of contacts to add: ");
    int num_contacts;
    scanf("%d", &num_contacts);
    getchar();  // Consume newline character
    
    // Loop through number of contacts to add
    for (int i = 0; i < num_contacts; i++) {
        // Ask for contact information while validating input
        do {
            printf("Enter contact name: ");
            fgets(contacts[i].name, 30, stdin);
            name_valid = strlen(contacts[i].name) > 1;
        } while (!name_valid);
        
        do {
            printf("Enter contact phone: ");
            fgets(contacts[i].phone, 15, stdin);
            phone_valid = strlen(contacts[i].phone) == 14 && 
                          contacts[i].phone[3] == '-' && 
                          contacts[i].phone[7] == '-';
        } while (!phone_valid);
        
        do {
            printf("Enter contact email: ");
            fgets(contacts[i].email, 50, stdin);
            email_valid = strlen(contacts[i].email) > 1;
        } while (!email_valid);
        
        do {
            printf("Enter contact address: ");
            fgets(contacts[i].address, 100, stdin);
            address_valid = strlen(contacts[i].address) > 1;
        } while (!address_valid);
        
        // Ask paranoid questions
        printf("Are you a secret agent? (1 for yes, 0 for no): ");
        scanf("%d", &is_secret_agent);
        getchar();  // Consume newline character
        
        printf("Are you currently under surveillance? (1 for yes, 0 for no): ");
        scanf("%d", &is_under_surveillance);
        getchar();  // Consume newline character
        
        printf("Do you think your phone is being tapped? (1 for yes, 0 for no): ");
        scanf("%d", &is_being_tapped);
        getchar();  // Consume newline character
        
        // Print confirmation message
        printf("\nContact added successfully.\n");
        if (is_secret_agent && is_under_surveillance && is_being_tapped) {
            printf("We will take extra precautions to keep this contact information safe.\n\n");
        } else {
            printf("We will keep this contact information safe to the best of our abilities.\n\n");
        }
    }
    
    // Display contacts
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("\nName: %s", contacts[i].name);
        printf("Phone: %s", contacts[i].phone);
        printf("Email: %s", contacts[i].email);
        printf("Address: %s\n", contacts[i].address);
    }

    return 0;
}