//FormAI DATASET v1.0 Category: Phone Book ; Style: innovative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct person{
    char name[25];
    char phone[15];
};

int main(){
    int n;
    printf("Enter number of contacts: ");
    scanf("%d", &n);
    
    struct person* contacts = (struct person*)malloc(n * sizeof(struct person));
    
    // Adding contacts
    for(int i = 0; i < n; i++){
        printf("Adding contact %d\n", i+1);
        printf("Enter name: ");
        scanf("%s", contacts[i].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[i].phone);
    }
    
    // Displaying contacts
    printf("\nContacts List\n");
    printf("==============\n");
    for(int i = 0; i < n; i++){
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("======================\n");
    }
    
    // Searching for contact
    char search_name[25];
    printf("Enter the name of the person you want to find: ");
    scanf("%s", search_name);
    int found = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(search_name, contacts[i].name) == 0){
            printf("\n\nContact Found!!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("\n\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\n\nContact not Found :(\n\n");
    }
    
    // Freeing memory
    free(contacts);
    return 0;
}