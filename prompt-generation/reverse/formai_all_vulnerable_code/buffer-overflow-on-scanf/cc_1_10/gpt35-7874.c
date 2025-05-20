//FormAI DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact{
    char name[20];
    char email[30];
    char phone[15];
} Contact;

void add_contact(Contact **mail_list, int *num_contacts){
    *mail_list = (Contact *)realloc(*mail_list, (*num_contacts+1)*sizeof(Contact));
    printf("Enter name: ");
    scanf("%s", (*mail_list)[*num_contacts].name);
    printf("Enter email: ");
    scanf("%s", (*mail_list)[*num_contacts].email);
    printf("Enter phone: ");
    scanf("%s", (*mail_list)[*num_contacts].phone);
    *num_contacts += 1;
    printf("Contact added successfully!\n");
}

void view_contacts(Contact *mail_list, int num_contacts){
    printf("Contacts:\n");
    printf("%-20s | %-30s | %-15s \n", "NAME", "EMAIL", "PHONE");
    for(int i=0; i<num_contacts; i++){
        printf("%-20s | %-30s | %-15s \n", mail_list[i].name, mail_list[i].email, mail_list[i].phone);
    }
}

void delete_contact(Contact **mail_list, int *num_contacts){
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    for(int i=0; i<*num_contacts; i++){
        if(strcmp(name, (*mail_list)[i].name)==0){
            for(int j=i; j<(*num_contacts)-1; j++){
                (*mail_list)[j] = (*mail_list)[j+1];
            }
            *num_contacts -= 1;
            *mail_list = (Contact *)realloc(*mail_list, (*num_contacts)*sizeof(Contact));
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact could not be found!\n");
}

int main(){
    Contact *mail_list = NULL;
    int num_contacts = 0;
    int choice;
    while(1){
        printf("MENU\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Delete contact\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_contact(&mail_list, &num_contacts);
                break;
            case 2:
                view_contacts(mail_list, num_contacts);
                break;
            case 3:
                delete_contact(&mail_list, &num_contacts);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}