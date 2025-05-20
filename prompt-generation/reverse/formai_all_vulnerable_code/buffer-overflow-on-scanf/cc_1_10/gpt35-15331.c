//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[15];
};

struct contact phoneBook[100];

int numContacts = 0;

void addContact() {
    printf("Enter Name: ");
    scanf("%s", &phoneBook[numContacts].name);
    printf("Enter Phone Number: ");
    scanf("%s", &phoneBook[numContacts].phone);
    printf("%s successfully added to the phone book!\n", phoneBook[numContacts].name);
    numContacts++;
}

void printPhoneBook() {
    printf("Phone Book:\n");
    for(int i=0; i<numContacts; i++) {
        printf("Name: %s\nPhone: %s\n\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

void searchContact() {
    char input[50];
    printf("Enter Name to Search: ");
    scanf("%s", input);
    for(int i=0; i<numContacts; i++) {
        if(strcmp(phoneBook[i].name, input) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("No match found for %s\n", input);
}

void deleteContact() {
    char input[50];
    printf("Enter Name to Delete: ");
    scanf("%s", input);
    for(int i=0; i<numContacts; i++) {
        if(strcmp(phoneBook[i].name, input) == 0) {
            printf("Deleting %s from phone book.\n", phoneBook[i].name);
            for(int j=i; j<numContacts-1; j++) {
                strcpy(phoneBook[j].name, phoneBook[j+1].name);
                strcpy(phoneBook[j].phone, phoneBook[j+1].phone);
            }
            numContacts--;
            return;
        }
    }
    printf("No match found for %s\n", input);
}

int main() {
    printf("Welcome to the Curious Phone Book!\n\n");

    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Add Contact\n");
        printf("2. Print Phone Book\n");
        printf("3. Search for Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                printPhoneBook();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("Thank you for using the Curious Phone Book.\n");
                break;
            default:
                printf("Invalid Choice. Please try again.\n");
                break;
        }

    } while(choice != 5);

    return 0;
}