//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct {
    char name[50];
    int phone[10];
    int count;
} person;

person phonebook[MAX];

int addcontact() {
    char name[50];
    int phone[10];
    int count = 0;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    for(int i=0; i<10; i++) {
        scanf("%d", &phone[i]);
        if(phone[i] == -1) {
            break;
        }
        count++;
    }
    for(int i=0; i<MAX; i++) {
        if(phonebook[i].count == 0) {
            strcpy(phonebook[i].name, name);
            for(int j=0; j<10; j++) {
                phonebook[i].phone[j] = phone[j];
            }
            phonebook[i].count = count;
            return TRUE;
        }
    }
    printf("Phonebook is full.\n");
    return FALSE;
}

int searchcontact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for(int i=0; i<MAX; i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            for(int j=0; j<phonebook[i].count; j++) {
                printf("Phone number %d: %d\n", j+1, phonebook[i].phone[j]);
            }
            return TRUE;
        }
    }
    printf("Contact not found.\n");
    return FALSE;
}

int deletecontact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for(int i=0; i<MAX; i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            for(int j=i; j<MAX-1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                for(int k=0; k<phonebook[j+1].count; k++) {
                    phonebook[j].phone[k] = phonebook[j+1].phone[k];
                }
                phonebook[j].count = phonebook[j+1].count;
            }
            phonebook[MAX-1].name[0] = '\0';
            phonebook[MAX-1].count = 0;
            return TRUE;
        }
    }
    printf("Contact not found.\n");
    return FALSE;
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addcontact();
                break;
            case 2:
                searchcontact();
                break;
            case 3:
                deletecontact();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);
    return 0;
}