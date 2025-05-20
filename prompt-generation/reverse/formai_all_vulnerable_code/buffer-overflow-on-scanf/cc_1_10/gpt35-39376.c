//FormAI DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_CONTACTS 100

struct Contact{
    char name[30];
    char phone[20];
};

int main(){
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while(1){
        printf("Enter your choice:\n1. Add Contact\n2. Search Contact\n3. Display All Contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter phone number: ");
                scanf("%s", contacts[num_contacts].phone);
                num_contacts++;
                printf("Contact added successfully!\n");
                break;

            case 2:
                printf("Enter name to search: ");
                char name[30];
                scanf("%s", name);
                int found = 0;
                for(int i=0;i<num_contacts;i++){
                    if(strcmp(contacts[i].name, name) == 0){
                        printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("Contact not found!\n");
                break;

            case 3:
                for(int i=0;i<num_contacts;i++){
                    printf("Name: %s\nPhone: %s\n\n", contacts[i].name, contacts[i].phone);
                }
                break;

            case 4:
                printf("Thank you for using the phone book program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}