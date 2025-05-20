//FormAI DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct contact{ 
    char name[25]; 
    char phone_no[15]; 
    char email[30]; 
    char address[50]; 
}; 

int main(){ 
    int n;
    printf("How many contacts do you want to add?\n"); 
    scanf("%d", &n); 
    struct contact *p=(struct contact*)malloc(n*sizeof(struct contact)); // Dynamically allocating memory for contacts 
    for(int i=0;i<n;i++){ 
        printf("Enter the contact details of contact %d:\n",i+1); 
        printf("Name: "); 
        scanf("%s", (p+i)->name); 
        printf("Phone Number: "); 
        scanf("%s", (p+i)->phone_no); 
        printf("Email: "); 
        scanf("%s",(p+i)->email); 
        printf("Address:"); 
        scanf("%s",(p+i)->address); 
    } 
    printf("\n\nList of Contacts\n"); // Displaying the List of Contacts 
    for(int i=0;i<n;i++){ 
        printf("Contact %d\n",(i+1)); 
        printf("Name: %s\n",(p+i)->name); 
        printf("Phone Number: %s\n",(p+i)->phone_no); 
        printf("Email: %s\n",(p+i)->email); 
        printf("Address: %s\n",(p+i)->address); 
    } 

    char search[25]; 
    printf("Enter the name you want to search for:"); // Searching for a Name 
    scanf("%s",search); 
    for(int i=0;i<n;i++){ 
        if(strcmp(search,(p+i)->name)==0){ 
            printf("Contact %d\n",(i+1)); 
            printf("Name: %s\n",(p+i)->name); 
            printf("Phone Number: %s\n",(p+i)->phone_no); 
            printf("Email: %s\n",(p+i)->email); 
            printf("Address: %s\n",(p+i)->address); 
            break; 
        } 
        else{ 
            printf("Contact not found!\n"); 
            break; 
        } 
    } 
    return 0; 
}