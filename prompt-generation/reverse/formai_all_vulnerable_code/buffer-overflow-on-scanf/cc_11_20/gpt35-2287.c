//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include<stdio.h>
#include<string.h>

struct PhoneBook {
    char name[50];
    char phone[15];
};
typedef struct PhoneBook PB;

int main(){
    int choice = 0;
    int index = 0;
    PB contacts[100]; // array of phonebook entries
    printf("*** Phone Book ***\n");
    while(choice != 4){
        printf("\nOptions:\n1. Add a contact \n2. Search for a contact\n3. Display all contacts\n4. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", contacts[index].name);
                printf("Enter Phone Number: ");
                scanf("%s", contacts[index].phone);
                index++;
                break;
            case 2:
                printf("\nEnter Name to search for: ");
                char searchName[50];
                scanf("%s", searchName);
                for(int i = 0; i < index; i++){
                    if(strcmp(searchName, contacts[i].name) == 0){
                        printf("Contact Found:\nName: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone);
                        break;
                    }
                    if(i == (index - 1)){
                        printf("Contact not found\n");
                    }
                }
                break;
            case 3:
                if(index == 0){
                    printf("\nNo contacts found\n");
                } else {
                    printf("\nAll Contacts:\n");
                    for(int i = 0; i < index; i++){
                        printf("Name: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone);
                    }
                }
                break;
            case 4:
                printf("\nExiting program\n");
                break;
            default:
                printf("\nInvalid choice, try again\n");
        }
    }

    return 0;
}