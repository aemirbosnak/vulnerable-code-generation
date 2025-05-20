//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct contact{
    char name[30];
    char phone[15];
};

void add_contact(struct contact *book, int index, char *name, char *phone){
    strcpy(book[index].name, name);
    strcpy(book[index].phone, phone);
}

void display_contact(struct contact *book, int index){
    printf("\nName: %s", book[index].name);
    printf("\nPhone: %s", book[index].phone);
}

void search_contact(struct contact *book, int index, char *name){
    int i;
    for(i=0; i<MAX; i++){
        if(strcmp(book[i].name, name) == 0){
            display_contact(book, i);
            break;
        }
    }
}

void delete_contact(struct contact *book, int index){
    printf("\nEnter the name of the contact you want to delete: ");
    char name[30];
    scanf("%s", name);
    int i;
    for(i=0; i<MAX; i++){
        if(strcmp(book[i].name, name) == 0){
            memset(&book[i], 0, sizeof(book[i]));
            printf("\n%s deleted successfully!", name);
            break;
        }
    }
}

int main(){
    struct contact book[MAX];
    int choice, index;

    do{
        printf("\n\n\t\tPhone Book\n");
        printf("\n1. Add Contact");
        printf("\n2. Display Contact");
        printf("\n3. Search Contact");
        printf("\n4. Delete Contact");
        printf("\n5. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the name: ");
                char name[30];
                scanf("%s", name);
                printf("Enter the phone number: ");
                char phone[15];
                scanf("%s", phone);
                add_contact(book, index, name, phone);
                break;

            case 2:
                printf("\nEnter the index of the contact: ");
                scanf("%d", &index);
                display_contact(book, index);
                break;

            case 3:
                printf("\nEnter the name of the contact: ");
                char search_name[30];
                scanf("%s", search_name);
                search_contact(book, index, search_name);
                break;

            case 4:
                printf("\nEnter the index of the contact: ");
                scanf("%d", &index);
                delete_contact(book, index);
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=5);

    return 0;
}