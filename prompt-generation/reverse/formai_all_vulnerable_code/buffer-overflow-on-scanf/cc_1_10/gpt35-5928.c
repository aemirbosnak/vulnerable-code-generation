//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* structure to hold contact information */
struct contact {
    char name[50];
    char phone[15];
    char email[50];
};
typedef struct contact Contact;

/* function prototypes */
void add_contact(Contact *p, int *n);
void delete_contact(Contact *p, int *n);
void search_contact(Contact *p, int n);
void display_all_contacts(Contact *p, int n);

/* main program */
int main() {
    Contact phonebook[100];
    int n = 0, choice;
    
    printf("Welcome to your C Phone Book!\n");
    
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a new contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        
        scanf("%d", &choice);
        getchar(); /* to clear the input buffer */
        
        switch(choice) {
            case 1:
                add_contact(phonebook, &n);
                break;
            case 2:
                delete_contact(phonebook, &n);
                break;
            case 3:
                search_contact(phonebook, n);
                break;
            case 4:
                display_all_contacts(phonebook, n);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

/* function to add a new contact to the phone book */
void add_contact(Contact *p, int *n) {
    /* get input from user */
    printf("Enter name: ");
    fgets(p[*n].name, 50, stdin);
    p[*n].name[strcspn(p[*n].name, "\n")] = 0; /* remove the newline character */
    
    printf("Enter phone number: ");
    fgets(p[*n].phone, 15, stdin);
    p[*n].phone[strcspn(p[*n].phone, "\n")] = 0;
    
    printf("Enter email: ");
    fgets(p[*n].email, 50, stdin);
    p[*n].email[strcspn(p[*n].email, "\n")] = 0;
    
    /* increment the number of contacts */
    (*n)++;
    printf("%s has been added to your phone book.\n", p[*n-1].name);
}

/* function to delete a contact from the phone book */
void delete_contact(Contact *p, int *n) {
    char name[50];
    int i, j;
    
    printf("Enter name of contact to delete: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; /* remove the newline character */
    
    /* find the contact in the phone book */
    for(i=0; i<*n; i++) {
        if(strcmp(p[i].name, name) == 0) {
            break;
        }
    }
    
    if(i == *n) {
        printf("Contact not found.\n");
        return;
    }
    
    /* shift the remaining contacts up one position in the array */
    for(j=i; j<*n-1; j++) {
        strcpy(p[j].name, p[j+1].name);
        strcpy(p[j].phone, p[j+1].phone);
        strcpy(p[j].email, p[j+1].email);
    }
    
    /* decrement the number of contacts */
    (*n)--;
    printf("%s has been deleted from your phone book.\n", name);
}

/* function to search for a contact in the phone book */
void search_contact(Contact *p, int n) {
    char name[50];
    int i;
    
    printf("Enter name of contact to search for: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; /* remove the newline character */
    
    /* find the contact in the phone book */
    for(i=0; i<n; i++) {
        if(strcmp(p[i].name, name) == 0) {
            printf("%s\nPhone: %s\nEmail: %s\n", p[i].name, p[i].phone, p[i].email);
            return;
        }
    }
    
    printf("Contact not found.\n");
}

/* function to display all contacts in the phone book */
void display_all_contacts(Contact *p, int n) {
    int i;
    
    if(n == 0) {
        printf("Your phone book is empty.\n");
        return;
    }
    
    printf("Contacts in your phone book:\n");
    for(i=0; i<n; i++) {
        printf("%s\nPhone: %s\nEmail: %s\n", p[i].name, p[i].phone, p[i].email);
    }
    printf("Total contacts: %d\n", n);
}