//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

struct contact{
    char name[50];
    char number[15];
};

struct contact phonebook[MAX];
int count = 0;

void addContact(){
    printf("\nEnter name: ");
    scanf("%s",phonebook[count].name);

    printf("\nEnter number: ");
    scanf("%s",phonebook[count].number);

    count++;
    printf("\nContact added successfully!");
}

void display(){
    printf("\n\nName\tNumber");
    for(int i=0;i<count;i++){
        printf("\n%s\t%s",phonebook[i].name,phonebook[i].number);
    }
}

void search(){
    char search_name[50];
    printf("\nEnter name to search: ");
    scanf("%s",search_name);

    for(int i=0;i<count;i++){
        if(strcmp(phonebook[i].name,search_name) == 0){
            printf("\n\nName: %s",phonebook[i].name);
            printf("\nNumber: %s",phonebook[i].number);
        }
    }
}

void deleteContact(){
    char delete_name[50];
    printf("\nEnter name to delete: ");
    scanf("%s",delete_name);

    for(int i=0;i<count;i++){
        if(strcmp(phonebook[i].name,delete_name) == 0){
            for(int j=i;j<count-1;j++){
                strcpy(phonebook[j].name,phonebook[j+1].name);
                strcpy(phonebook[j].number,phonebook[j+1].number);
            }
            count--;
            printf("\n\nContact deleted successfully!");
            break;
        }
    }
}

int main(){
    int choice;

    do{
        printf("\n\nPhonebook Menu");
        printf("\n1. Add Contact");
        printf("\n2. Display Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Delete Contact");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addContact();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                printf("\n\nExiting...\n");
                break;

            default:
                printf("\n\nInvalid choice! Try again...");
        }
    }while(choice!= 5);

    return 0;
}