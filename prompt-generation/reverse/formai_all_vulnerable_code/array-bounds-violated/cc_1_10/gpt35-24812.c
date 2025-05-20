//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];
    char email[50];
} Contact;

typedef struct{
    Contact* contacts;
    int size;
    int capacity;
} ContactList;

void addContact(ContactList* list, Contact contact);
void deleteContact(ContactList* list, char* email);
void printContacts(ContactList* list);
void searchContact(ContactList* list, char* email);
void saveToFile(ContactList* list, char* fileName);
void loadFromFile(ContactList* list, char* fileName);

int main(){
    ContactList list;
    list.size = 0;
    list.capacity = 10;
    list.contacts = malloc(sizeof(Contact) * 10);

    //load from file if exists
    loadFromFile(&list, "contacts.txt");

    int choice;
    char temp[50];
    Contact c;

    do{
        printf("Welcome to the Mailing List Manager!\n");
        printf("1 - Add a Contact\n");
        printf("2 - Delete a Contact\n");
        printf("3 - Print All Contacts\n");
        printf("4 - Search for a Contact\n");
        printf("5 - Save to File\n");
        printf("6 - Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf("%s", temp);
                strcpy(c.name, temp);

                printf("Enter email: ");
                scanf("%s", temp);
                strcpy(c.email, temp);

                addContact(&list, c);

                printf("Contact added successfully!\n\n");
                break;

            case 2:
                printf("Enter email: ");
                scanf("%s", temp);
                deleteContact(&list, temp);
                break;

            case 3:
                printContacts(&list);
                break;

            case 4:
                printf("Enter email: ");
                scanf("%s", temp);
                searchContact(&list, temp);
                break;

            case 5:
                printf("Enter file name: ");
                scanf("%s", temp);
                saveToFile(&list, temp);
                printf("Contacts saved to file successfully!\n\n");
                break;

            case 6:
                printf("Exiting program...\n\n");
                break;

            default:
                printf("Invalid choice!\n\n");
        }
    }while(choice != 6);

    //save to file before exiting
    saveToFile(&list, "contacts.txt");

    free(list.contacts);

    return 0;
}

void addContact(ContactList* list, Contact contact){
    if(list->size == list->capacity){
        //need to resize the array
        list->capacity *= 2;
        list->contacts = realloc(list->contacts, sizeof(Contact) * list->capacity);
    }
    list->contacts[list->size++] = contact;
}

void deleteContact(ContactList* list, char* email){
    int index = -1;
    for(int i = 0; i < list->size; i++){
        if(strcmp(list->contacts[i].email, email) == 0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Contact not found!\n\n");
        return;
    }
    //shift all elements starting from index to the left
    for(int i = index + 1; i < list->size; i++){
        list->contacts[i-1] = list->contacts[i];
    }
    list->size--;
    printf("Contact deleted successfully!\n\n");
}

void printContacts(ContactList* list){
    if(list->size == 0){
        printf("No contacts found!\n\n");
        return;
    }
    printf("Contacts:\n");
    for(int i = 0; i < list->size; i++){
        printf("%d. Name: %s\n   Email: %s\n", i+1, list->contacts[i].name, list->contacts[i].email);
    }
    printf("\n");
}

void searchContact(ContactList* list, char* email){
    int index = -1;
    for(int i = 0; i < list->size; i++){
        if(strcmp(list->contacts[i].email, email) == 0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("Contact not found!\n\n");
        return;
    }
    printf("Contact found!\n");
    printf("Name: %s\nEmail: %s\n\n", list->contacts[index].name, list->contacts[index].email);
}

void saveToFile(ContactList* list, char* fileName){
    FILE* f = fopen(fileName, "w");
    if(f == NULL){
        printf("Error opening file!\n");
        return;
    }
    for(int i = 0; i < list->size; i++){
        fprintf(f, "%s;%s\n", list->contacts[i].name, list->contacts[i].email);
    }
    fclose(f);
}

void loadFromFile(ContactList* list, char* fileName){
    FILE* f = fopen(fileName, "r");
    if(f == NULL){
        return;
    }
    char line[100];
    char* name;
    char* email;
    while(fgets(line, 100, f) != NULL){
        //remove newline character at end of line
        line[strlen(line)-1] = '\0';

        //split line into name and email using ; delimiter
        name = strtok(line, ";");
        email = strtok(NULL, ";");

        Contact c;
        strcpy(c.name, name);
        strcpy(c.email, email);

        addContact(list, c);
    }
    fclose(f);
}