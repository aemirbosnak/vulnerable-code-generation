//FormAI DATASET v1.0 Category: Phone Book ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100
#define MAX_ENTRIES 100

struct Contact {
  char name[MAX_LENGTH];
  char phone_number[MAX_LENGTH];
};

struct Contact phone_book[MAX_ENTRIES];
int num_entries=0;

void display_menu(){
    printf("\n\t\tPhone Book Application\n\n");
    printf("1. Add Contact\n");
    printf("2. Show Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("0. Exit\n");
    printf("Enter choice (0-4):");
}

void add_contact(){
    if(num_entries >= MAX_ENTRIES){
        printf("\nPhone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter Name:");
    scanf("%[^\n]%*c", phone_book[num_entries].name);
    printf("Enter Phone Number:");
    scanf("%[^\n]%*c", phone_book[num_entries].phone_number);
    printf("\nContact added successfully.\n");
    num_entries++;
}

void show_contacts(){
    if(num_entries<=0){
        printf("\nNo Contacts Found.\n");
        return;
    }

    printf("\n\t\tContact List\n\n");
    printf("Name\t\t\tPhone Number\n");
    printf("------------------------------------------------\n");

    for(int i=0; i<num_entries; i++){
        printf("%-30s\t%-20s\n",phone_book[i].name, phone_book[i].phone_number);
    }
    printf("\n");
}

void search_contact(){
    if(num_entries<=0){
        printf("\nNo Contacts Found.\n");
        return;
    }

    char search_name[MAX_LENGTH];
    printf("Enter Name to Search:");
    scanf("%[^\n]%*c", search_name);

    for(int i=0; i<num_entries; i++){
        if(strcmp(search_name, phone_book[i].name) == 0){
            printf("\nContact Found.\n");
            printf("\tName : %s\n", phone_book[i].name);
            printf("\tPhone Number : %s\n", phone_book[i].phone_number);
            return;
        }
    }
    printf("\nNo Contacts Found with the given name.\n");
}

void delete_contact(){
    if(num_entries<=0){
        printf("\nNo Contacts Found.\n");
        return;
    }

    char delete_name[MAX_LENGTH];
    printf("Enter Name to Delete:");
    scanf("%[^\n]%*c", delete_name);

    for(int i=0; i<num_entries; i++){
        if(strcmp(delete_name, phone_book[i].name) == 0){
            for(int j=i; j<num_entries-1; j++){
                strcpy(phone_book[j].name, phone_book[j+1].name);
                strcpy(phone_book[j].phone_number, phone_book[j+1].phone_number);
            }
            printf("\nContact Deleted successfully.\n");
            num_entries--;
            return;
        }
    }
    printf("\nNo Contacts Found with the given name.\n");
}

int main(){
    int choice;

    printf("\n\t\tWelcome to Phone Book Application\n\n");

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice){
            case 1:
                add_contact();
                break;
            case 2:
                show_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 0:
                printf("\nExiting from Phone Book Application...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}