//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

int main() {
    entry_t phonebook[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char search_name[50];
    
    do {
        printf("Phone Book\n");
        printf("=========\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Display all entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        
        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", phonebook[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", phonebook[num_entries].phone);
                num_entries++;
                printf("Entry added successfully.\n");
                break;
                
            case '2':
                printf("Enter name to search: ");
                scanf("%s", search_name);
                
                for(int i=0; i<num_entries; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;
                
            case '3':
                printf("Enter name to delete: ");
                scanf("%s", search_name);
                
                for(int i=0; i<num_entries; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        strcpy(phonebook[i].name, "");
                        strcpy(phonebook[i].phone, "");
                        printf("Entry deleted successfully.\n");
                    }
                }
                break;
                
            case '4':
                printf("Phone Book\n");
                printf("=========\n");
                for(int i=0; i<num_entries; i++) {
                    if(phonebook[i].name[0]!= '\0') {
                        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
                    }
                }
                break;
                
            case '5':
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '5');
    
    return 0;
}