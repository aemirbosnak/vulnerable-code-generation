//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structure of a contact
struct contact{
    char name[100];
    char phone[100];
    char email[100];
};

int main()
{
    struct contact contacts[10]; //Allowing 10 contacts
    int num_contacts = 0;
    
    //Adding Contacts
    printf("Add Contact: \n");
    printf("Name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Phone: ");
    scanf("%s", contacts[num_contacts].phone);
    printf("Email: ");
    scanf("%s", contacts[num_contacts].email);
    num_contacts++;
    
    //Displaying all Contacts
    printf("All Contacts:\n");
    for(int i = 0; i < num_contacts; i++)
    {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
    
    //Calling a contact
    printf("Call Contact: \n");
    printf("Name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Phone: ");
    scanf("%s", contacts[num_contacts].phone);
    
    //Simulating a call
    printf("Calling %s...\n", contacts[num_contacts].name);
    printf("Contact Called!\n");
    
    //Deleting a contact
    printf("Delete Contact: \n");
    printf("Name: ");
    scanf("%s", contacts[num_contacts].name);
    num_contacts--;
    
    //Displaying all Contacts after deletion
    printf("All Contacts:\n");
    for(int i = 0; i < num_contacts; i++)
    {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
    
    //Simulating a call after deletion
    printf("Calling %s...\n", contacts[num_contacts].name);
    printf("Contact Deleted!\n");
    
    //Adding a new contact
    printf("Add Contact: \n");
    printf("Name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Phone: ");
    scanf("%s", contacts[num_contacts].phone);
    printf("Email: ");
    scanf("%s", contacts[num_contacts].email);
    num_contacts++;
    
    //Displaying all Contacts after new addition
    printf("All Contacts:\n");
    for(int i = 0; i < num_contacts; i++)
    {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
    
    //Simulating a call after new addition
    printf("Calling %s...\n", contacts[num_contacts].name);
    printf("Contact Called!\n");
    
    return 0;
}