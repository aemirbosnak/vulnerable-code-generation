//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_LIST_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_LIST_LENGTH];
    int count;
} MailingList;

void initializeList(MailingList* list){
    list->count = 0;
}

void addContact(MailingList* list, char* name, char* email){
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.email, email);
    list->contacts[list->count++] = newContact;
}

void printContacts(MailingList* list){
    int i;
    for(i=0; i<list->count; i++){
        printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void quitProgram(){
    printf("Thank you for using this surreal mailing list manager. Goodbye!\n");
    exit(0);
}

void handleInput(char* input, MailingList* list){
    if(strcmp(input, "quit") == 0){
        quitProgram();
    }
    else if(strcmp(input, "list") == 0){
        printContacts(list);
    }
    else{
        char name[MAX_NAME_LENGTH];
        char email[MAX_EMAIL_LENGTH];
        printf("Please enter the name of the contact: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        printf("Please enter the email of the contact: ");
        fgets(email, MAX_EMAIL_LENGTH, stdin);
        addContact(list, name, email);
        printf("New contact added to list.\n");
    }
}

int main(){
    char input[MAX_EMAIL_LENGTH];
    MailingList list;
    initializeList(&list);
    printf("Welcome to the Surrealist Mailing List Manager.\n");
    while(1){
        printf("Please enter a command: ");
        fgets(input, MAX_EMAIL_LENGTH, stdin);
        input[strlen(input)-1] = '\0';
        handleInput(input, &list);
    }
    return 0;
}