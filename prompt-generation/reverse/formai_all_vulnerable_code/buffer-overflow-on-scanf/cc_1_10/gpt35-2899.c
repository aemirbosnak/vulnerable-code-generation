//FormAI DATASET v1.0 Category: Phone Book ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact{
    char name[30];
    char phone[15];
};

void menu(){
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Edit Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Display All\n");
    printf("6. Exit\n");
}

void addContact(struct Contact *pb,int *count){
    printf("Enter contact name: ");
    scanf("%s",pb[*count].name);
    printf("Enter contact phone number: ");
    scanf("%s",pb[*count].phone);
    printf("Contact added successfully!\n");
    (*count)++;
}

void searchContact(struct Contact *pb,int *count){
    char searchname[30];
    printf("Enter a name to search: ");
    scanf("%s",searchname);
    int found = 0;
    for(int i=0;i<*count;i++){
        if(strcmp(searchname,pb[i].name) == 0){
            printf("Contact found\nName: %s\nPhone: %s\n",pb[i].name,pb[i].phone);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("No Contact with that name exists!\n");
    }
}

void editContact(struct Contact *pb,int *count){
    char editname[30];
    printf("Enter a name to edit: ");
    scanf("%s",editname);
    int found = 0;
    for(int i = 0;i<*count;i++){
        if(strcmp(editname,pb[i].name) == 0){
            printf("Enter new name: ");
            scanf("%s",pb[i].name);
            printf("Enter new phone number: ");
            scanf("%s",pb[i].phone);
            printf("Contact edited successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("No Contact with that name exists!\n");
    }
}

void deleteContact(struct Contact *pb,int *count){
    char deletename[30];
    printf("Enter a name to delete: ");
    scanf("%s",deletename);
    int found = 0;
    for(int i = 0;i<*count;i++){
        if(strcmp(deletename,pb[i].name) == 0){
            for(int j=i;j<*count-1;j++){
                pb[j]=pb[j+1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("No Contact with that name exists!\n");
    }
}

void displayAll(struct Contact *pb,int *count){
    if(*count == 0){
        printf("No Contacts available!\n");
    }
    else{
        printf("All Contacts:\n");
        for(int i=0;i<*count;i++){
            printf("Name: %s\nPhone: %s\n",pb[i].name,pb[i].phone);
        }
    }
}

int main(){
    struct Contact phonebook[100];
    int count = 0;
    int choice;
    do{
        menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addContact(phonebook,&count);
                break;
            case 2:
                searchContact(phonebook,&count);
                break;
            case 3:
                editContact(phonebook,&count);
                break;
            case 4:
                deleteContact(phonebook,&count);
                break;
            case 5:
                displayAll(phonebook,&count);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Input!\n");
        }
    }while(choice != 6);
    return 0;
}