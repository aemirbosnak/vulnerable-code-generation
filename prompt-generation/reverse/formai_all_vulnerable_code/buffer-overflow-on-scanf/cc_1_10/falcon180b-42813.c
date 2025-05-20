//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: modular
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100

struct contact{
    char name[MAX];
    char phone[20];
};

void addcontact(struct contact *book, int n){
    printf("\nEnter the name of the contact: ");
    scanf("%s", book[n].name);
    printf("\nEnter the phone number of the contact: ");
    scanf("%s", book[n].phone);
    printf("\nContact added successfully!\n");
}

void searchcontact(struct contact *book, int n, char *name){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(book[i].name, name) == 0){
            printf("\nName: %s\nPhone: %s", book[i].name, book[i].phone);
            break;
        }
    }
    if(i == n){
        printf("\nContact not found!");
    }
}

void deletecontact(struct contact *book, int n){
    printf("\nEnter the name of the contact to be deleted: ");
    char name[MAX];
    scanf("%s", name);
    int i;
    for(i=0;i<n;i++){
        if(strcmp(book[i].name, name) == 0){
            printf("\nContact deleted successfully!");
            memset(book[i].name, '\0', strlen(book[i].name));
            memset(book[i].phone, '\0', strlen(book[i].phone));
            break;
        }
    }
    if(i == n){
        printf("\nContact not found!");
    }
}

void display(struct contact *book, int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nName: %s\nPhone: %s", book[i].name, book[i].phone);
    }
}

int main(){
    struct contact book[MAX];
    int n=0, choice;
    while(1){
        printf("\n\nPhone Book\n");
        printf("\n1. Add contact\n2. Search contact\n3. Delete contact\n4. Display all contacts\n5. Exit");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(n == MAX){
                    printf("\nPhone book is full!");
                }else{
                    addcontact(book, n);
                    n++;
                }
                break;
            case 2:
                printf("\nEnter the name of the contact to be searched: ");
                char name[MAX];
                scanf("%s", name);
                searchcontact(book, n, name);
                break;
            case 3:
                printf("\nEnter the name of the contact to be deleted: ");
                char delname[MAX];
                scanf("%s", delname);
                deletecontact(book, n);
                break;
            case 4:
                display(book, n);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}