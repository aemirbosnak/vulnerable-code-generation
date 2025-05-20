//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining Structure for Phonebook
typedef struct{
    char name[50];
    int phone_number;
    char address[100];
}phone_book;

//Function to Add Entry in Phonebook
void add_entry(phone_book *pb){
    int i=0;
    char ch;

    printf("Enter Name: ");
    scanf("%s",pb->name);

    printf("Enter Phone Number: ");
    scanf("%d",&pb->phone_number);

    printf("Enter Address: ");
    scanf("%s",pb->address);

    printf("\nEntry Added Successfully!\n");
}

//Function to Display Phonebook
void display_phonebook(phone_book *pb,int size){
    int i=0;

    printf("\nPhonebook:\n");
    printf("Name\tPhone Number\tAddress\n");

    for(i=0;i<size;i++){
        printf("%s\t%d\t%s\n",pb[i].name,pb[i].phone_number,pb[i].address);
    }
}

//Function to Search Entry in Phonebook
void search_entry(phone_book *pb,int size){
    char name[50];
    int i=0;

    printf("\nEnter Name to Search: ");
    scanf("%s",name);

    for(i=0;i<size;i++){
        if(strcmp(pb[i].name,name)==0){
            printf("\nEntry Found:\n");
            printf("Name: %s\n",pb[i].name);
            printf("Phone Number: %d\n",pb[i].phone_number);
            printf("Address: %s\n",pb[i].address);
        }
    }
}

//Main Function
int main(){
    int size=0;
    phone_book *pb=(phone_book*)malloc(sizeof(phone_book));

    do{
        printf("\n1. Add Entry\n2. Display Phonebook\n3. Search Entry\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&size);

        switch(size){
            case 1:
                add_entry(pb);
                break;
            case 2:
                display_phonebook(pb,size);
                break;
            case 3:
                search_entry(pb,size);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
        }
    }while(size!=4);

    return 0;
}