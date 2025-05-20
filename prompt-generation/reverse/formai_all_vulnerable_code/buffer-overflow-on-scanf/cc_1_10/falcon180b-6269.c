//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Defining the structure of the phone book
struct Phonebook{
    char Name[50];
    char Phone[15];
};

//Function to add a new contact to the phone book
void AddContact(struct Phonebook *phonebook, int size){
    printf("\nEnter the name of the contact: ");
    scanf("%s", phonebook[size].Name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", phonebook[size].Phone);
}

//Function to display all the contacts in the phone book
void DisplayContacts(struct Phonebook *phonebook, int size){
    printf("\nThe contacts in the phone book are:\n");
    for(int i=0; i<size; i++){
        printf("\nName: %s\nPhone Number: %s\n", phonebook[i].Name, phonebook[i].Phone);
    }
}

//Function to search for a contact in the phone book
void SearchContact(struct Phonebook *phonebook, int size){
    char searchname[50];
    printf("\nEnter the name of the contact to search: ");
    scanf("%s", searchname);
    for(int i=0; i<size; i++){
        if(strcmp(phonebook[i].Name, searchname) == 0){
            printf("\nThe contact %s was found in the phone book.\n", searchname);
            printf("Phone Number: %s\n", phonebook[i].Phone);
        }
    }
    if(strcmp(searchname, "")!= 0){
        printf("\nThe contact %s was not found in the phone book.\n", searchname);
    }
}

//Function to delete a contact from the phone book
void DeleteContact(struct Phonebook *phonebook, int size){
    char delname[50];
    printf("\nEnter the name of the contact to delete: ");
    scanf("%s", delname);
    for(int i=0; i<size; i++){
        if(strcmp(phonebook[i].Name, delname) == 0){
            for(int j=i; j<size-1; j++){
                phonebook[j] = phonebook[j+1];
            }
            size--;
            printf("\nThe contact %s was deleted from the phone book.\n", delname);
        }
    }
    if(strcmp(delname, "")!= 0){
        printf("\nThe contact %s was not found in the phone book.\n", delname);
    }
}

//Main function
int main(){
    struct Phonebook phonebook[200];
    int size=0;
    int choice;
    do{
        printf("\nPhone Book\n");
        printf("1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                AddContact(phonebook, size);
                size++;
                break;
            case 2:
                DisplayContacts(phonebook, size);
                break;
            case 3:
                SearchContact(phonebook, size);
                break;
            case 4:
                DeleteContact(phonebook, size);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    }while(choice!= 5);
    return 0;
}