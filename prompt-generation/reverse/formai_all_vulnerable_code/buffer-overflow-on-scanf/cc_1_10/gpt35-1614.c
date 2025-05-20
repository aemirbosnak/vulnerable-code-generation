//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
// Romeo and Juliet: A Phone Book Example Program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[30];
    char number[11];
} contact;

void add(contact **phonebook, int *size) {
    contact new_contact;
    printf("\n[Enter Contact's Name]\n> ");
    scanf(" %[^\n]s", new_contact.name);
    printf("[Enter Contact's Number]\n> ");
    scanf(" %s", new_contact.number);
    *size += 1;
    *phonebook = (contact*)realloc(*phonebook, (*size)*sizeof(contact));
    (*phonebook)[*size-1] = new_contact;
    printf("\n[New Contact Added]\n");
}

void search(contact *phonebook, int size) {
    char search_name[30];
    printf("\n[Enter Name to Search]\n> ");
    scanf(" %[^\n]s", search_name);
    for(int i=0; i<size; i++) {
        if(strcmp(search_name, phonebook[i].name) == 0) {
            printf("[Contact Found]\nName: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("[Contact Not Found]\n");
}

void display(contact *phonebook, int size) {
    printf("\n[Phone Book Contacts]\n");
    for(int i=0; i<size; i++) {
        printf("%d. Name: %s\n   Number: %s\n", i+1, phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    printf("[Scene: The streets of Verona]\n");
    printf("Romeo: Oh Juliet, my love, I have lost my phone book.\n");
    printf("Juliet: Fear not, my love. We shall create a new one together.\n");
    printf("Romeo: That would be most wonderful. Let us begin.\n\n");

    int size = 0;
    contact *phonebook = NULL;

    while(1) {
        printf("[Options]\n1. Add New Contact\n2. Search for Contact\n3. Display All Contacts\n4. Exit\n> ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add(&phonebook, &size);
                break;
            case 2:
                search(phonebook, size);
                break;
            case 3:
                display(phonebook, size);
                break;
            case 4:
                printf("\nRomeo: Thank you, my love. Our new phone book is perfect.\n");
                printf("[Scene: Romeo and Juliet embrace]\n");
                free(phonebook);
                return 0;
            default:
                printf("[Invalid Choice]\n");
                break;
        }
    }
}