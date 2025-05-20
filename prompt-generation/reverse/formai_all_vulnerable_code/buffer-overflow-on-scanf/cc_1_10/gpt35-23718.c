//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include<stdio.h>
#include<string.h>

struct contact {
    char name[50];
    char phone_number[15];
};

// function to add a new contact to the phone book
void addContact(struct contact *p, int *numContacts) {
    printf("\nEnter name: ");
    scanf(" %[^\n]", p[*numContacts].name);
    printf("Enter phone number: ");
    scanf(" %s", p[*numContacts].phone_number);
    (*numContacts)++;
    printf("\nContact Added Successfully!\n\n");
}

// function to print the entire phone book
void printContacts(struct contact *p, int numContacts) {
    printf("\n\nPHONE BOOK\n\n");
    int i;
    for(i = 0; i < numContacts; i++) {
        printf("%s - %s\n", p[i].name, p[i].phone_number);
    }
}

// function to find a contact by name
void findContact(struct contact *p, int numContacts) {
    char name[50];
    printf("\nEnter name to search: ");
    scanf(" %[^\n]", name);
    int i, found = 0;
    for(i = 0; i < numContacts; i++) {
        if(strcmp(name, p[i].name) == 0) {
            printf("\n%s - %s\n", p[i].name, p[i].phone_number);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("\nContact not found!\n\n");
    }
}

// function to delete a contact by name
void deleteContact(struct contact *p, int *numContacts) {
    char name[50];
    printf("\nEnter name to delete: ");
    scanf(" %[^\n]", name);
    int i, found = 0;
    for(i = 0; i < *numContacts; i++) {
        if(strcmp(name, p[i].name) == 0) {
            found = 1;
            break;
        }
    }
    if(found == 1) {
        for(; i < *numContacts - 1; i++) {
            strcpy(p[i].name, p[i+1].name);
            strcpy(p[i].phone_number, p[i+1].phone_number);
        }
        (*numContacts)--;
        printf("\nContact Deleted Successfully!\n\n");
    }
    else {
        printf("\nContact not found!\n\n");
    }
}

int main() {
    struct contact phoneBook[100];
    int numContacts = 0;
    int choice;
    do {
        printf("PHONE BOOK APPLICATION\n");
        printf("1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Find Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                printContacts(phoneBook, numContacts);
                break;
            case 3:
                findContact(phoneBook, numContacts);
                break;
            case 4:
                deleteContact(phoneBook, &numContacts);
                break;
            case 5:
                printf("\nThank you for using the Phone Book Application!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    } while(choice != 5);
    return 0;
}