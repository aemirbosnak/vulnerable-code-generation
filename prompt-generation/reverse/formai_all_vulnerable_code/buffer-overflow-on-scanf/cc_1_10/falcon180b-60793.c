//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

struct contact{
    char name[30];
    char number[15];
};

void add_contact(struct contact contacts[],int size);
void display_contact(struct contact contacts[],int size);
void search_contact(struct contact contacts[],int size);

int main(){
    struct contact contacts[MAX];
    int size=0;

    char choice;
    do{
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n2. Display Contact\n3. Search Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c",&choice);

        switch(choice){
            case '1':
                add_contact(contacts,size);
                break;
            case '2':
                display_contact(contacts,size);
                break;
            case '3':
                search_contact(contacts,size);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!='4');

    return 0;
}

void add_contact(struct contact contacts[],int size){
    char name[30],number[15];

    printf("\nEnter name: ");
    scanf("%s",name);

    printf("Enter number: ");
    scanf("%s",number);

    strcpy(contacts[size].name,name);
    strcpy(contacts[size].number,number);

    size++;

    printf("\nContact added successfully!\n");
}

void display_contact(struct contact contacts[],int size){
    if(size==0){
        printf("\nNo contacts found!\n");
        return;
    }

    printf("\nName\t\tNumber\n");
    for(int i=0;i<size;i++){
        printf("%s\t\t%s\n",contacts[i].name,contacts[i].number);
    }
}

void search_contact(struct contact contacts[],int size){
    char name[30];

    printf("\nEnter name to search: ");
    scanf("%s",name);

    for(int i=0;i<size;i++){
        if(strcmp(contacts[i].name,name)==0){
            printf("\nName: %s\nNumber: %s\n",contacts[i].name,contacts[i].number);
            return;
        }
    }

    printf("\nContact not found!\n");
}