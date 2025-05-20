//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include<stdio.h>
#include<string.h>

//Defining a structure to hold contact information
struct contact {
    char name[20];
    char phone[15];
};

//Function to add a contact
void add_contact(struct contact phonebook[], int *count) {
    printf("\nEnter the Name: ");
    scanf("%s", phonebook[*count].name);
    printf("Enter the Phone Number: ");
    scanf("%s", phonebook[*count].phone);
    (*count)++;
}

//Function to display all contacts
void display_contacts(struct contact phonebook[], int count) {
    if(count == 0) {
        printf("\nNo contacts found\n");
    } else {
        printf("\nContacts in the Phonebook\n");
        printf("---------------------------\n");
        for(int i=0; i<count; i++) {
            printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].phone);
        }
        printf("---------------------------\n");
    }
}

//Function to search for a contact
void search_contact(struct contact phonebook[], int count) {
    char name[20];
    int found = 0;
    printf("\nEnter the Name to Search: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("\nContact not found\n");
    }
}

int main() {
    struct contact phonebook[50];   //Array of structures to hold contacts
    int count = 0;  //Counter to keep track of number of contacts
    
    while(1) {
        printf("\n***** C PHONEBOOK *****\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search for Contact\n");
        printf("4. Exit\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_contact(phonebook, &count);
                    break;
            case 2: display_contacts(phonebook, count);
                    break;
            case 3: search_contact(phonebook, count);
                    break;
            case 4: printf("\nExiting the Phonebook\n\n");
                    return 0;
            default: printf("\nInvalid choice\n");
        }
    }
    
    return 0;
}