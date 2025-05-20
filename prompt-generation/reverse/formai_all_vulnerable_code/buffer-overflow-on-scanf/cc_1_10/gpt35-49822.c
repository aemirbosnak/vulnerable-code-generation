//FormAI DATASET v1.0 Category: Phone Book ; Style: paranoid
#include<stdio.h>
#include<string.h>

#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 12

//Structure to hold contact details
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
}Contact;

//Function to compare strings
int string_compare(char str1[], char str2[]) {
    int i=0, flag=0;

    while(str1[i]!='\0' && str2[i]!='\0') {
        if(str1[i]!=str2[i]) {
            flag=1;
            break;
        }
        i++;
    }

    if(flag==0 && str1[i]=='\0' && str2[i]=='\0')
        return 0;
    else
        return -1;
}

//Function to add a new contact to the phone book
void add_contact(Contact phone_book[], int n) {
    if(n==100) {
        printf("Phone book is full. Cannot add any more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phone_book[n].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[n].phone);

    printf("Contact added successfully.\n");
}

//Function to search for a contact in the phone book
void search_contact(Contact phone_book[], int n) {
    char search_name[MAX_NAME_LEN];
    int i, found=0;

    printf("Enter name to search for: ");
    scanf("%s", search_name);

    for(i=0; i<n; i++) {
        if(string_compare(phone_book[i].name, search_name)==0) {
            found=1;
            break;
        }
    }

    if(found==1)
        printf("Phone number of %s is %s.\n", search_name, phone_book[i].phone);
    else
        printf("Contact not found in phone book.\n");
}

int main() {
    Contact phone_book[100];
    int n=0;

    printf("Welcome to Paranoid Phone Book!\n\n");

    while(1) {
        printf("Enter 1 to add a new contact.\n");
        printf("Enter 2 to search for a contact.\n");
        printf("Enter 3 to exit.\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_contact(phone_book, n);
                    n++;
                    break;

            case 2: search_contact(phone_book, n);
                    break;

            case 3: printf("Exiting Paranoid Phone Book. Have a nice day!\n");
                    return 0;

            default: printf("Invalid choice. Please enter a valid choice.\n");
                     break;
        }
    }

    return 0;
}