//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 20
#define MAX_PHONENUM_LEN 15

// define a structure for storing the phone book
struct phone_book{
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONENUM_LEN];
}pb;

// function to add a new contact to the phone book
void add_contact(struct phone_book *pb, int *n){
    printf("\nEnter the name: ");
    scanf("%s", pb[*n].name);
    printf("Enter the phone number: ");
    scanf("%s", pb[*n].phone_num);

    (*n)++; // increment the size of the phone book
}

// function to search for a contact in the phone book
void search_contact(struct phone_book *pb, int n){
    char query[MAX_NAME_LEN];
    int found = 0;

    printf("\nEnter the name to search: ");
    scanf("%s", query);

    for(int i = 0; i < n; i++){
        if(strcmp(pb[i].name, query) == 0){ // name matched
            printf("\nContact details for %s:\nPhone Number: %s\n", pb[i].name, pb[i].phone_num);
            found = 1; // flag indicating contact found
            break;
        }
    }

    if(!found){ // contact not found
        printf("\nContact not found!\n");
    }
}

// function to print all contacts in the phone book
void print_contacts(struct phone_book *pb, int n){
    printf("\nAll Contacts:\n");

    for(int i = 0; i < n; i++){
        printf("%d. %s - %s\n", i+1, pb[i].name, pb[i].phone_num);
    }
}

// main function
int main(){
    int n = 0; // number of contacts in the phone book
    int choice;

    struct phone_book *pb = malloc(n * sizeof(struct phone_book)); 

    while(1){
        printf("\n\n\nC Phone Book\n\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Print all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                add_contact(pb, &n);  
                break;

            case 2:
                search_contact(pb, n);
                break;

            case 3:
                print_contacts(pb, n);
                break;

            case 4:
                free(pb);
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}