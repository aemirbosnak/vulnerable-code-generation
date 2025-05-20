//FormAI DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[50];
    char phone_number[15];
    char email[50];
} Contact;

int main(){
    int option; // to hold user selected option
    int num_of_contacts = 0; // to hold the current number of contacts in phone book
    
    // allocate memory for maximum of 100 contacts
    Contact *phone_book = (Contact*) malloc(100 * sizeof(Contact));
    
    while(1){
        printf("\n\t\t\t\tPHONE BOOK\n\n");
        printf("\t\tSelect an option below:\n");
        printf("\t\t1. Add new contact\n");
        printf("\t\t2. Search contacts by name\n");
        printf("\t\t3. Search contacts by phone number\n");
        printf("\t\t4. View all contacts\n");
        printf("\t\t5. Exit\n\n");
        
        printf("\t\tEnter your choice: ");
        
        scanf("%d", &option);
        getchar(); // consume the newline character left in buffer by scanf
        
        switch(option){
            case 1: // add contact
                printf("\n\t\tADD A NEW CONTACT\n\n");
                
                // prompt user for contact details
                printf("\t\tEnter name: ");
                fgets(phone_book[num_of_contacts].name, 50, stdin);
                phone_book[num_of_contacts].name[strcspn(phone_book[num_of_contacts].name, "\n")] = 0; // remove newline character added by fgets
                
                printf("\t\tEnter phone number: ");
                fgets(phone_book[num_of_contacts].phone_number, 15, stdin);
                phone_book[num_of_contacts].phone_number[strcspn(phone_book[num_of_contacts].phone_number, "\n")] = 0;
                
                printf("\t\tEnter email: ");
                fgets(phone_book[num_of_contacts].email, 50, stdin);
                phone_book[num_of_contacts].email[strcspn(phone_book[num_of_contacts].email, "\n")] = 0;
                
                printf("\n\t\tContact added successfully!\n\n");
                num_of_contacts++;
                break;
                
            case 2: // search by name
                printf("\n\t\tSEARCH CONTACTS BY NAME\n\n");
                
                // prompt user for name to search for
                char search_name[50];
                printf("\t\tEnter name to search for: ");
                fgets(search_name, 50, stdin);
                search_name[strcspn(search_name, "\n")] = 0;
                
                // search contacts for matching names
                printf("\n\t\tMatching contacts:\n\n");
                int found = 0;
                for(int i=0; i<num_of_contacts; i++){
                    if(strstr(phone_book[i].name, search_name) != NULL){
                        printf("\t\tName: %s\n", phone_book[i].name);
                        printf("\t\tPhone number: %s\n", phone_book[i].phone_number);
                        printf("\t\tEmail: %s\n\n", phone_book[i].email);
                        found = 1;
                    }
                }
                
                if(!found){
                    printf("\t\tNo matching contacts found.\n\n");
                }
                break;
                
            case 3: // search by phone number
                printf("\n\t\tSEARCH CONTACTS BY PHONE NUMBER\n\n");
                
                // prompt user for phone number to search for
                char search_phone[15];
                printf("\t\tEnter phone number to search for: ");
                fgets(search_phone, 15, stdin);
                search_phone[strcspn(search_phone, "\n")] = 0;
                
                // search contacts for matching phone numbers
                printf("\n\t\tMatching contacts:\n\n");
                found = 0;
                for(int i=0; i<num_of_contacts; i++){
                    if(strcmp(phone_book[i].phone_number, search_phone) == 0){
                        printf("\t\tName: %s\n", phone_book[i].name);
                        printf("\t\tPhone number: %s\n", phone_book[i].phone_number);
                        printf("\t\tEmail: %s\n\n", phone_book[i].email);
                        found = 1;
                    }
                }
                
                if(!found){
                    printf("\t\tNo matching contacts found.\n\n");
                }
                break;
                
            case 4: // view all contacts
                printf("\n\t\tALL CONTACTS\n\n");
                
                // loop through and print all contacts
                for(int i=0; i<num_of_contacts; i++){
                    printf("\t\tName: %s\n", phone_book[i].name);
                    printf("\t\tPhone number: %s\n", phone_book[i].phone_number);
                    printf("\t\tEmail: %s\n\n", phone_book[i].email);
                }
                break;
            
            case 5: // exit program
                printf("\n\t\tTHANK YOU FOR USING PHONE BOOK.\n\n");
                free(phone_book); // release allocated memory
                exit(0);
                
            default: // invalid option selected
                printf("\n\t\tInvalid option. Please try again.\n\n");
                break;
        }
    }
    return 0;
}