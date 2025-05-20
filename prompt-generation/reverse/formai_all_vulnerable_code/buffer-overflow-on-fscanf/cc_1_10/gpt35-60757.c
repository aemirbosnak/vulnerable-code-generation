//FormAI DATASET v1.0 Category: Mailing list manager ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct {
    char name[30];
    char email[50];
}Contact;

void Add_Contact(Contact *pContacts, int *pIndex);
void List_Contacts(Contact *pContacts, int *pIndex);
void Delete_Contact(Contact *pContacts, int *pIndex);
void Find_Contact(Contact *pContacts, int *pIndex);
void Save_Contacts(Contact *pContacts, int *pIndex);
void Load_Contacts(Contact *pContacts, int *pIndex);

int main()
{
    int choice, contactsIndex = 0;
    Contact *contacts = (Contact *) malloc(MAX * sizeof(Contact));
    
    do {
        printf("\n----------Mailing List Manager-----------\n");
        printf("1. Add a Contact\n");
        printf("2. List all Contacts\n");
        printf("3. Delete a Contact\n");
        printf("4. Find a Contact\n");
        printf("5. Save Contacts to file\n");
        printf("6. Load Contacts from file\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1:
                Add_Contact(contacts, &contactsIndex);
                break;
            
            case 2:
                List_Contacts(contacts, &contactsIndex);
                break;
                
            case 3:
                Delete_Contact(contacts, &contactsIndex);
                break;
                
            case 4:
                Find_Contact(contacts, &contactsIndex);
                break;
                
            case 5:
                Save_Contacts(contacts, &contactsIndex);
                break;
                
            case 6:
                Load_Contacts(contacts, &contactsIndex);
                break;
                
            case 7:
                printf("\nGoodbye!\n");
                break;
            
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
    } while(choice != 7);
    
    return 0;
}

// Add a new contact to the list
void Add_Contact(Contact *pContacts, int *pIndex) {
    if(*pIndex >= MAX) {
        printf("\nError: Contact list is full. Please delete some contacts to add more.\n");
        return;
    }
    
    printf("\nEnter name: ");
    scanf("%s", pContacts[*pIndex].name);
    printf("Enter email: ");
    scanf("%s", pContacts[*pIndex].email);
    
    printf("\nContact added successfully!\n");
    (*pIndex)++;
}

// List all contacts in the list
void List_Contacts(Contact *pContacts, int *pIndex) {
    if(*pIndex == 0) {
        printf("\nNo contacts found.\n");
        return;
    }
    
    printf("\nContacts:\n");
    
    for(int i = 0; i < *pIndex; i++) {
        printf("%d. %s (%s)\n", i+1, pContacts[i].name, pContacts[i].email);
    }
}

// Delete a contact from the list
void Delete_Contact(Contact *pContacts, int *pIndex) {
    if(*pIndex == 0) {
        printf("\nNo contacts found to delete.\n");
        return;
    }
    
    int indexToDelete;
    printf("\nEnter index of contact to delete: ");
    scanf("%d", &indexToDelete);
    
    if(indexToDelete < 1 || indexToDelete > *pIndex) {
        printf("\nInvalid index.\n");
        return;
    }
    
    for(int i = indexToDelete-1; i < *pIndex-1; i++) {
        strcpy(pContacts[i].name, pContacts[i+1].name);
        strcpy(pContacts[i].email, pContacts[i+1].email);
    }
    
    (*pIndex)--;
    printf("\nContact deleted successfully!\n");
}

// Find a contact in the list by email
void Find_Contact(Contact *pContacts, int *pIndex) {
    if(*pIndex == 0) {
        printf("\nNo contacts found.\n");
        return;
    }
    
    char email[MAX];
    printf("\nEnter email: ");
    scanf("%s", email);
    
    for(int i = 0; i < *pIndex; i++) {
        if(strcmp(pContacts[i].email, email) == 0) {
            printf("\nContact found:\n");
            printf("Name: %s\nEmail: %s\n", pContacts[i].name, pContacts[i].email);
            return;
        }
    }
    
    printf("\nContact not found.\n");
}

// Save all contacts to file
void Save_Contacts(Contact *pContacts, int *pIndex) {
    if(*pIndex == 0) {
        printf("\nNo contacts found to save.\n");
        return;
    }
    
    FILE *file = fopen("contacts.txt", "w");
    
    if(file == NULL) {
        printf("\nError: Unable to open file for writing.\n");
        return;
    }
    
    for(int i = 0; i < *pIndex; i++) {
        fprintf(file, "%s,%s\n", pContacts[i].name, pContacts[i].email);
    }
    
    fclose(file);
    printf("\nContacts saved to file successfully!\n");
}

// Load contacts from file
void Load_Contacts(Contact *pContacts, int *pIndex) {
    FILE *file = fopen("contacts.txt", "r");
    
    if(file == NULL) {
        printf("\nNo contacts file found.\n");
        return;
    }
    
    char name[MAX], email[MAX];
    char *token;
    int i = 0;
    
    while(fscanf(file, "%[^,],%s\n", name, email) != EOF) {
        token = strtok(email, "\r");
        strcpy(pContacts[i].name, name);
        strcpy(pContacts[i].email, token);
        i++;
        (*pIndex)++;
    }
    
    fclose(file);
    printf("\nContacts loaded from file successfully!\n");
}