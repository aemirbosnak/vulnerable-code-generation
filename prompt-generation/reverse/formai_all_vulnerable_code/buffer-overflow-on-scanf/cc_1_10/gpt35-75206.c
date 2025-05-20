//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int main() {
    int numContacts;
    printf("Enter the number of contacts you would like to store: ");
    scanf("%d", &numContacts);
    
    Contact* contacts = (Contact*) malloc(numContacts * sizeof(Contact));
    
    printf("Please enter the contact information:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Contact %d:\n", i+1);
        printf("Name: ");
        scanf("%s", contacts[i].name);
        printf("Phone: ");
        scanf("%s", contacts[i].phone);
        printf("\n");
    }
    
    printf("The contacts you entered are:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
    
    char searchName[MAX_NAME_LENGTH];
    printf("Enter a name to search for: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("%s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No contact found for name: %s\n", searchName);
    }
    
    free(contacts);
    
    return 0;
}