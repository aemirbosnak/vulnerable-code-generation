//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct contact{
    char name[50];
    int phone_number;
};

void add_contact(struct contact contacts[],int size){
    char name[50];
    int phone_number;

    printf("Enter the name of the contact: ");
    scanf("%s",name);
    printf("Enter the phone number of the contact: ");
    scanf("%d",&phone_number);

    strcpy(contacts[size].name,name);
    contacts[size].phone_number = phone_number;
    printf("\nContact added successfully!");
}

void search_contact(struct contact contacts[],int size){
    char name[50];

    printf("\nEnter the name of the contact to search: ");
    scanf("%s",name);

    for(int i=0;i<size;i++){
        if(strcmp(contacts[i].name,name) == 0){
            printf("\nName: %s",contacts[i].name);
            printf("\nPhone Number: %d",contacts[i].phone_number);
        }
    }
}

void delete_contact(struct contact contacts[],int size){
    char name[50];

    printf("\nEnter the name of the contact to delete: ");
    scanf("%s",name);

    for(int i=0;i<size;i++){
        if(strcmp(contacts[i].name,name) == 0){
            contacts[i] = contacts[size-1];
            size--;
            printf("\nContact deleted successfully!");
            break;
        }
    }
}

void display_contacts(struct contact contacts[],int size){
    printf("\nName\t\tPhone Number\n");
    for(int i=0;i<size;i++){
        printf("%s\t\t%d\n",contacts[i].name,contacts[i].phone_number);
    }
}

int main(){
    struct contact contacts[MAX];
    int size = 0;

    while(1){
        printf("\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Display Contacts\n5. Exit\n");
        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(size == MAX){
                    printf("\nPhone book is full!");
                }
                else{
                    add_contact(contacts,size);
                    size++;
                }
                break;

            case 2:
                search_contact(contacts,size);
                break;

            case 3:
                delete_contact(contacts,size);
                break;

            case 4:
                display_contacts(contacts,size);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}