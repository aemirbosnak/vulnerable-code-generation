//FormAI DATASET v1.0 Category: Phone Book ; Style: active
#include<stdio.h>
#include<string.h>

struct contact{
    char name[50];
    long int phone_number;
};

void add_contact(struct contact phone_book[], int *num_contacts){
    printf("Please enter the contact name: ");
    scanf("%s", phone_book[*num_contacts].name);
    printf("Please enter the contact's phone number: ");
    scanf("%ld", &phone_book[*num_contacts].phone_number);
    (*num_contacts)++;
}

void print_contacts(struct contact phone_book[], int num_contacts){
    printf("\n%s\t%s\n", "Name", "Phone Number");
    for(int i=0;i<num_contacts;i++){
        printf("%s\t%ld\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

void search_contact(struct contact phone_book[], int num_contacts){
    char search_name[50];
    printf("Enter the name of the contact: ");
    scanf("%s", search_name);
    for(int i=0;i<num_contacts;i++){
        if(strcmp(phone_book[i].name, search_name)==0){
            printf("\n%s\t%s\n", "Name", "Phone Number");
            printf("%s\t%ld\n", phone_book[i].name, phone_book[i].phone_number);
            return;
        }
    }
    printf("Contact not found!\n");
}

int main(){
    struct contact phone_book[100];
    int num_contacts=0, choice;
    while(1){
        printf("\nWelcome to the phone book!\n");
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_contact(phone_book, &num_contacts);
                    break;
            case 2: print_contacts(phone_book, num_contacts);
                    break;
            case 3: search_contact(phone_book, num_contacts);
                    break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}