//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    int choice, index = 0;
    struct Contact contacts[100];
    
    printf("*** Phone Book ***\n\n");
    
    do {
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n\n");
        
        printf("Select an option: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                printf("Name: ");
                scanf("%s", contacts[index].name);
                
                printf("Phone number (xxxx-xxxx): ");
                scanf("%s", contacts[index].phone);
                
                index++;
                printf("\nContact added successfully!\n\n");
                break;
                
            case 2:
                {
                    char searchName[50];
                    int found = 0;
                    
                    printf("Search Name: ");
                    scanf("%s", searchName);
                    printf("\n");
                    
                    for (int i = 0; i < index; i++) {
                        if (strcmp(contacts[i].name, searchName) == 0) {
                            printf("Contact found: %s, %s\n\n", contacts[i].name, contacts[i].phone);
                            found = 1;
                            break;
                        }
                    }
                    
                    if (!found)
                        printf("Contact not found.\n\n");
                }
                break;
                
            case 3:
                if (index == 0)
                    printf("There are no contacts to display.\n\n");
                else {
                    printf("Name\t\tPhone\n");
                    
                    for (int i = 0; i < index; i++)
                        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone);
                        
                    printf("\n");
                }
                
                break;
                
            case 4:
                printf("Goodbye!\n\n");
                break;
                
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while (choice != 4);
    
    return 0;
}