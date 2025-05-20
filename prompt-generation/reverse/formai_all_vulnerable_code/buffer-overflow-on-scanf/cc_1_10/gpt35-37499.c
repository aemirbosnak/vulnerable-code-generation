//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
    int age;
};

struct Contact phonebook[MAX_CONTACTS];

int num_contacts = 0;

int add_contact(char *name, char *phone_number, int age) {
    if(num_contacts == MAX_CONTACTS) {
        printf("Phonebook is full!\n");
        return 0;
    }
    strcpy(phonebook[num_contacts].name, name);
    strcpy(phonebook[num_contacts].phone_number, phone_number);
    phonebook[num_contacts].age = age;
    num_contacts++;
    return 1;
}

int remove_contact(char *name) {
    int i, found = 0;
    for(i=0;i<num_contacts;i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("%s not found in phonebook.\n", name);
        return 0;
    }
    for(;i<num_contacts-1;i++) {
        strcpy(phonebook[i].name, phonebook[i+1].name);
        strcpy(phonebook[i].phone_number, phonebook[i+1].phone_number);
        phonebook[i].age = phonebook[i+1].age;
    }
    num_contacts--;
    printf("%s removed from phonebook.\n", name);
    return 1;
}

int find_contact(char *name) {
    int i, found = 0;
    for(i=0;i<num_contacts;i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            found = 1;
            printf("%s: %s (%d years old)\n", phonebook[i].name, phonebook[i].phone_number, phonebook[i].age);
        }
    }
    if(!found) {
        printf("%s not found in phonebook.\n", name);
        return 0;
    }
    return 1;
}

void display_contacts() {
    int i;
    for(i=0;i<num_contacts;i++) {
        printf("%s: %s (%d years old)\n", phonebook[i].name, phonebook[i].phone_number, phonebook[i].age);
    }
    printf("-----------------------\n");
}

int main() {
    char name[50], phone_number[20];
    int age, choice;
    while(1) {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Find contact\n");
        printf("4. Display all contacts\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone_number);
                printf("Enter age: ");
                scanf("%d", &age);
                if(add_contact(name, phone_number, age)) {
                    printf("%s added to phonebook.\n", name);
                }
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_contact(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                find_contact(name);
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                printf("Quitting phonebook.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}