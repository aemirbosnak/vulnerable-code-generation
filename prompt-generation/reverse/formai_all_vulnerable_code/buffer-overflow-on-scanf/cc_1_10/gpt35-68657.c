//FormAI DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include<stdlib.h>
#include<stdio.h>

struct contact{
    char name[50];
    long int phone_num;
};

int main(){
    int choice = 0, i, num_contacts, found = 0;
    struct contact *pb;
    char search_name[50];
    
    printf("***PHONE BOOK APPLICATION***\n");
    printf("Enter the number of contacts you want to add: ");
    scanf("%d", &num_contacts);
    
    //allocate memory for contact array
    pb = malloc(num_contacts * sizeof(struct contact));
    
    //get input for each contact
    for(i=0; i<num_contacts; i++){
        printf("Enter name for contact %d: ", i+1);
        scanf("%s", pb[i].name);
        printf("Enter phone number for contact %d: ", i+1);
        scanf("%ld", &pb[i].phone_num);
    }
    
    //menu for options
    while(choice != 3){
        printf("\nWhat would you like to do?\n");
        printf("1. List all contacts\n");
        printf("2. Search for a contact by name\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                //list all contacts
                printf("\nCONTACT LIST:\n");
                for(i=0; i<num_contacts; i++){
                    printf("%-25s%ld\n", pb[i].name, pb[i].phone_num);
                }
                break;
            case 2:
                //search for contact by name
                printf("\nEnter name to search for: ");
                scanf("%s", search_name);
                for(i=0; i<num_contacts; i++){
                    if(strcmp(search_name, pb[i].name) == 0){
                        printf("\n%s's phone number is %ld\n", pb[i].name, pb[i].phone_num);
                        found = 1;
                        break;
                    }
                }
                if(found == 0){
                    printf("\n%s not found in phone book\n", search_name);
                }
                found = 0;
                break;
            case 3:
                //exit
                printf("\nExiting phone book application...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    
    //free memory allocated for pb
    free(pb);
    
    return 0;
}