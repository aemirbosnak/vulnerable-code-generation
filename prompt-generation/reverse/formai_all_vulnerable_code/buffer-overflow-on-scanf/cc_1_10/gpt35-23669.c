//FormAI DATASET v1.0 Category: Phone Book ; Style: multivariable
// C Phone Book Example Program

#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    char phone[12];
    char email[50];
};

int main() {
    struct Person contacts[10];
    int choice, i, j;
    char search[50];
    do {
        printf("Phone Book Menu\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display All Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", &contacts[i].name);
                printf("Enter Phone Number: ");
                scanf("%s", &contacts[i].phone);
                printf("Enter Email: ");
                scanf("%s", &contacts[i].email);
                i++;
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", &search);
                for(j=0;j<i;j++) {
                    if(strcmp(contacts[j].name,search)==0) {
                        printf("Name: %s\tPhone: %s\tEmail: %s\n",contacts[j].name,contacts[j].phone,contacts[j].email);
                        break;
                    }
                }
                if(j==i)
                    printf("Contact not found\n");
                break;
            case 3:
                printf("All Contacts\n");
                for(j=0;j<i;j++)
                    printf("Name: %s\tPhone: %s\tEmail: %s\n",contacts[j].name,contacts[j].phone,contacts[j].email);
                break;
            case 4:
                printf("Exiting Phone Book\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while(choice!=4);
    return 0;
}