//FormAI DATASET v1.0 Category: Phone Book ; Style: careful
#include<stdio.h>
#include<string.h>
#define MAX 100

struct PhoneBook{
    char name[30];
    char number[15];
    char email[25];
};
typedef struct PhoneBook Book;

int main(){
    Book contacts[MAX];
    int numOfContacts = 0;
    int option;

    while(1){
        printf("---- Phone Book ----\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option){
            case 1:{
                printf("---- Add Contact ----\n");
                printf("Enter Name: ");
                scanf("%s", contacts[numOfContacts].name);
                printf("Enter Number: ");
                scanf("%s", contacts[numOfContacts].number);
                printf("Enter Email: ");
                scanf("%s", contacts[numOfContacts].email);
                numOfContacts++;
                printf("Contact added successfully!\n");
                break;
            }
            case 2:{
                if(numOfContacts == 0){
                    printf("No Contacts Found!\n");
                }
                else{
                    printf("---- All Contacts (%d) ----\n", numOfContacts);
                    for(int i=0;i<numOfContacts;i++){
                        printf("[%d]\n",i+1);
                        printf("Name: %s\n", contacts[i].name);
                        printf("Number: %s\n", contacts[i].number);
                        printf("Email: %s\n", contacts[i].email);
                    }
                }
                break;
            }
            case 3:{
                if(numOfContacts == 0){
                    printf("No Contacts Found!\n");
                }
                else{
                    char searchName[30];
                    printf("---- Search Contact ----\n");
                    printf("Enter Name: ");
                    scanf("%s", searchName);
                    int found=0;
                    for(int i=0;i<numOfContacts;i++){
                        if(strcmp(contacts[i].name, searchName) == 0){
                            found=1;
                            printf("Contact Found!\n");
                            printf("Name: %s\n", contacts[i].name);
                            printf("Number: %s\n", contacts[i].number);
                            printf("Email: %s\n", contacts[i].email);
                        }
                    }
                    if(!found){
                        printf("Contact Not Found!\n");
                    }
                }
                break;
            }
            case 4:{
                if(numOfContacts == 0){
                    printf("No Contacts Found!\n");
                }
                else{
                    char deleteName[30];
                    printf("---- Delete Contact ----\n");
                    printf("Enter Name: ");
                    scanf("%s", deleteName);
                    int found=0;
                    for(int i=0;i<numOfContacts;i++){
                        if(strcmp(contacts[i].name, deleteName) == 0){
                            found=1;
                            for(int j=i;j<numOfContacts-1;j++){
                                strcpy(contacts[j].name, contacts[j+1].name);
                                strcpy(contacts[j].number, contacts[j+1].number);
                                strcpy(contacts[j].email, contacts[j+1].email);                         
                            }
                            numOfContacts--;
                            printf("Contact Deleted Successfully\n");
                            break;
                        }
                    }
                    if(!found){
                        printf("Contact Not Found!\n");
                    }
                }
                break;
            }
            case 5:{
                printf("Exiting Phone Book...\n");
                return 0;
            }
            default:{
                printf("Invalid Option! Please Try Again\n");
                break;
            }
        }
    }
    return 0;
}