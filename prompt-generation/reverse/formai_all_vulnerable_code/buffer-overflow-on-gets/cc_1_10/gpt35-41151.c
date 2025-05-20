//FormAI DATASET v1.0 Category: Phone Book ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contactlist{
    char name[50];
    char number[15];
};

void addcontact(struct contactlist list[], int n) {

    for(int i=0;i<n;i++) {
        printf("\nAdding contact %d:\n",i+1);
        printf("Enter the name: ");
        fflush(stdin);
        gets(list[i].name);
        printf("Enter the phone number: ");
        fflush(stdin);
        gets(list[i].number);
    }
}

void display(struct contactlist list[], int n) {

    printf("\nContacts in phone book:\n");
    for(int i=0;i<n;i++){
        printf("\nContact %d:\n",i+1);
        printf("Name: %s\n",list[i].name);
        printf("Phone Number: %s\n",list[i].number);
    }
}

void search(struct contactlist list[], int n, char name[]) {

    int flag = 0;
    printf("\nSearching for contact: %s\n",name);
    for(int i=0;i<n;i++) {
        if(strcmp(name,list[i].name) == 0) {
            flag = 1;
            printf("\nContact found!\n");
            printf("Name: %s\n",list[i].name);
            printf("Phone Number: %s\n",list[i].number);
            break;
        }
    }
    if(flag == 0) {
        printf("\nContact not found!\n");
    }
}

int main() {

    int n,ch;
    char searchname[50];
    printf("Enter the number of contacts you want to add: ");
    scanf("%d",&n);

    struct contactlist list[n];
    do {
        printf("\n1. Add a Contact\n2. Display All Contacts\n3. Search a Contact\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: addcontact(list,n);
                    break;

            case 2: display(list,n);
                    break;

            case 3: fflush(stdin);
                    printf("\nEnter the name of the contact you want to search: ");
                    gets(searchname);
                    search(list,n,searchname);
                    break;

            case 4: exit(0);
                    break;

            default: printf("\nInvalid choice!\n");
                     break;
        }
    }while(ch!=4);

    return 0;
}