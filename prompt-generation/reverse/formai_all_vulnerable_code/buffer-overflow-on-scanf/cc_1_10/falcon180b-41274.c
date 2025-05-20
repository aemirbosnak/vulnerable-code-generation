//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} contact;

contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_contacts].name);
    printf("Enter number: ");
    scanf("%s", phonebook[num_contacts].number);
    num_contacts++;
}

void delete_contact() {
    int index;
    printf("Enter contact index to delete: ");
    scanf("%d", &index);
    if(index >= 0 && index < num_contacts) {
        num_contacts--;
        for(int i=index; i<num_contacts; i++) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].number, phonebook[i+1].number);
        }
    }
    else {
        printf("Invalid contact index.\n");
    }
}

void search_contact() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    int index = -1;
    for(int i=0; i<num_contacts; i++) {
        if(strcmp(phonebook[i].name, search_name) == 0) {
            index = i;
            break;
        }
    }
    if(index >= 0) {
        printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
    }
    else {
        printf("Contact not found.\n");
    }
}

void display_phonebook() {
    printf("Phonebook:\n");
    for(int i=0; i<num_contacts; i++) {
        printf("%d. Name: %s   Number: %s\n", i+1, phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add contact\n2. Delete contact\n3. Search contact\n4. Display phonebook\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_phonebook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}