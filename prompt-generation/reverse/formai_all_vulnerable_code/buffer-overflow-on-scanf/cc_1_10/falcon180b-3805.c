//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for phone book
typedef struct{
    char name[50];
    int phone_number;
}PhoneBook;

//Function to add new contact
void addContact(){
    PhoneBook new_contact;
    FILE *fp;
    fp=fopen("phonebook.txt","a");
    if(fp==NULL){
        printf("File not found");
        exit(0);
    }
    printf("Enter name of the contact: ");
    scanf("%s",new_contact.name);
    printf("Enter phone number: ");
    scanf("%d",&new_contact.phone_number);
    fwrite(&new_contact,sizeof(new_contact),1,fp);
    fclose(fp);
    printf("Contact added successfully");
}

//Function to display all contacts
void displayContacts(){
    FILE *fp;
    PhoneBook contact;
    fp=fopen("phonebook.txt","r");
    if(fp==NULL){
        printf("File not found");
        exit(0);
    }
    while(fread(&contact,sizeof(contact),1,fp)!=0){
        printf("\nName: %s\nPhone number: %d",contact.name,contact.phone_number);
    }
    fclose(fp);
}

//Function to search for a contact
void searchContact(){
    FILE *fp;
    PhoneBook contact,search_contact;
    char search_name[50];
    int found=0;
    fp=fopen("phonebook.txt","r");
    if(fp==NULL){
        printf("File not found");
        exit(0);
    }
    printf("Enter name to search: ");
    scanf("%s",search_name);
    while(fread(&contact,sizeof(contact),1,fp)!=0){
        if(strcmp(contact.name,search_name)==0){
            printf("\nName: %s\nPhone number: %d",contact.name,contact.phone_number);
            found=1;
        }
    }
    if(found==0){
        printf("\nContact not found");
    }
    fclose(fp);
}

//Main function
int main(){
    int choice;
    while(1){
        printf("\n1.Add new contact");
        printf("\n2.Display all contacts");
        printf("\n3.Search for a contact");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}