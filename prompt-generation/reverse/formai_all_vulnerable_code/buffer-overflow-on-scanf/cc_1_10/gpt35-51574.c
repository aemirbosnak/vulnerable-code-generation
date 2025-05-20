//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include<stdio.h>
#include<string.h>
#define MAX 100

struct PhoneBook{
    char name[20];
    char number[15];
};

typedef struct PhoneBook PB;

int count = 0;

void add_contact(PB *book){
    printf("\nPlease enter the name of the contact: ");
    scanf("%s", book[count].name);

    printf("Please enter the phone number of the contact: ");
    scanf("%s", book[count].number);
  
    printf("Successfully added contact %s.\n", book[count].name);
    count++;
}

void display_contacts(PB *book){
    if(count == 0){
        printf("\nPhonebook is empty.\n");
        return;
    }

    printf("\nCurrent Contacts:\n");

    for(int i=0; i<count; i++){
        printf("%s\t%s\n", book[i].name, book[i].number);
    }
}

void search_contact(PB *book){
    char name[20];
    printf("\nEnter the name of the contact to search: ");
    scanf("%s", name);
  
    for(int i=0; i<count; i++){
        if(strcmp(book[i].name, name) == 0){
            printf("\nContact Found:\n");
            printf("%s\t%s\n", book[i].name, book[i].number);
            return;
        }
    }

    printf("\nContact not found.\n");
}

int main(){
    PB book[MAX];
    int choice;

    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_contact(book);
                break;

            case 2:
                display_contacts(book);
                break;

            case 3:
                search_contact(book);
                break;

            case 4:
                printf("\nExiting the program.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}