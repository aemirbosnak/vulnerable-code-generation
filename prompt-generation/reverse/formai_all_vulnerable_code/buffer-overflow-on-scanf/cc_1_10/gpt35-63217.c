//FormAI DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
    char name[50];
    char phone_number[20];
};

int main() {
    int n, i, choice;
    struct PhoneBook *pb;  // pointer to an array of PhoneBook structures
    
    printf("Enter the number of entries: ");
    scanf("%d", &n);
    
    // dynamically allocate memory for the PhoneBook array
    pb = (struct PhoneBook*) malloc(n * sizeof(struct PhoneBook));
    
    // get input for the PhoneBook array
    for(i = 0; i < n; i++) {
        printf("Entry %d:\n", i+1);
        printf("Name: ");
        scanf("%s", pb[i].name);
        printf("Phone number: ");
        scanf("%s", pb[i].phone_number);
    }
    
    // display the PhoneBook array
    printf("\n\nYour phone book entries:\n");
    for(i = 0; i < n; i++) {
        printf("Entry %d:\n", i+1);
        printf("Name: %s\n", pb[i].name);
        printf("Phone number: %s\n", pb[i].phone_number);
    }
    
    // ask user if they want to search for a name in the PhoneBook
    printf("\nDo you want to search for a name? (1 for Yes/0 for No): ");
    scanf("%d", &choice);
    if(choice == 1) {
        char search_name[50];
        int found = 0;
        
        printf("Enter the name to search for: ");
        scanf("%s", search_name);
        
        for(i = 0; i < n; i++) {
            if(strcmp(search_name, pb[i].name) == 0) {
                printf("%s's phone number is %s\n", pb[i].name, pb[i].phone_number);
                found = 1;
                break;
            }
        }
        
        if(!found) {
            printf("%s not found in your phone book\n", search_name);
        }
    }
    
    // free dynamically allocated memory
    free(pb);
    
    return 0;
}