//FormAI DATASET v1.0 Category: Phone Book ; Style: sophisticated
#include<stdio.h>
#include<string.h>

struct Contact {
    char name[30];
    char email[50];
    long phone;
};

void addContact(struct Contact c[], int *n) {
    printf("Enter Name: ");
    scanf("%s", c[*n].name);
    printf("Enter Email: ");
    scanf("%s", c[*n].email);
    printf("Enter Phone: ");
    scanf("%ld", &c[*n].phone);
    (*n)++;
    printf("Contact added successfully!\n");
}

void displayAllContacts(struct Contact c[], int n) {
    if(n==0) {
        printf("No Contacts Found.\n");
        return;
    }
    printf("Name       Email                 Phone\n");
    printf("-------------------------------------------\n");
    for(int i=0;i<n;i++) {
        printf("%-10s %-20s %ld\n", c[i].name, c[i].email, c[i].phone);
    }
}

void searchContact(struct Contact c[], int n) {
    char name[30];
    printf("Enter Name to Search: ");
    scanf("%s", name);
    for(int i=0;i<n;i++) {
        if(strcmp(c[i].name, name)==0) {
            printf("Name       Email                 Phone\n");
            printf("-------------------------------------------\n");
            printf("%-10s %-20s %ld\n", c[i].name, c[i].email, c[i].phone);
            return;
        }
    }
    printf("Contact Not Found!\n");
}

void deleteContact(struct Contact c[], int *n) {
    char name[30];
    printf("Enter Name to Delete: ");
    scanf("%s", name);
    for(int i=0;i<*n;i++) {
        if(strcmp(c[i].name, name)==0) {
            for(int j=i+1;j<*n;j++) {
                strcpy(c[j-1].name, c[j].name);
                strcpy(c[j-1].email, c[j].email);
                c[j-1].phone = c[j].phone;
            }
            (*n)--;
            printf("Contact Deleted Successfully!\n");
            return;
        }
    }
    printf("Contact Not Found!\n");
}

int main() {
    struct Contact contacts[100];
    int n=0;
    int choice;
    while(1) {
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addContact(contacts, &n);
                break;
            case 2:
                displayAllContacts(contacts, n);
                break;
            case 3:
                searchContact(contacts, n);
                break;
            case 4:
                deleteContact(contacts, &n);
                break;
            case 5:
                printf("Thank You for Using the Phone Book!\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}