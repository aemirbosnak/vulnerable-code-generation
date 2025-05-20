//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 100

typedef struct{
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct{
    char subject[MAX_SUBJECTS];
    Contact* contacts;
    int num_contacts;
} MailingList;

void addContact(MailingList* list, char* name, char* email){
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    list->contacts = (Contact*)realloc(list->contacts, sizeof(Contact)*(list->num_contacts+1));
    list->contacts[list->num_contacts] = *newContact;
    list->num_contacts++;
}

int main(){
    MailingList* list = (MailingList*)malloc(sizeof(MailingList));
    list->num_contacts = 0;
    list->contacts = NULL;

    char choice;
    do{
        printf("Mailing List Manager\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Send Email\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice){
            case '1':
                printf("Enter Name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                printf("Enter Email: ");
                char email[MAX_EMAIL_LENGTH];
                scanf("%s", email);

                addContact(list, name, email);
                break;

            case '2':
                printf("Enter Email to Remove: ");
                char emailToRemove[MAX_EMAIL_LENGTH];
                scanf("%s", emailToRemove);

                int i;
                for(i=0; i<list->num_contacts; i++){
                    if(strcmp(list->contacts[i].email, emailToRemove) == 0){
                        list->contacts = (Contact*)realloc(list->contacts, sizeof(Contact)*(list->num_contacts-1));
                        list->num_contacts--;
                        break;
                    }
                }
                break;

            case '3':
                printf("Enter Subject: ");
                char subject[MAX_SUBJECTS];
                scanf("%s", subject);

                int j;
                for(j=0; j<list->num_contacts; j++){
                    printf("%s (%s)\n", list->contacts[j].name, list->contacts[j].email);
                }

                break;

            case '4':
                free(list->contacts);
                free(list);
                exit(0);

            default:
                printf("Invalid Choice\n");
        }

    }while(choice!= '4');

    return 0;
}