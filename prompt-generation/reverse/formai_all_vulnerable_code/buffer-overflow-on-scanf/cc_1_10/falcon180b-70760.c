//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

int main() {
    int choice;
    char email[MAX_EMAIL_LEN];
    Contact contacts[100];
    int num_contacts = 0;

    do {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. View contacts\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].email, email) == 0) {
                        for(int j=i; j<num_contacts-1; j++) {
                            strcpy(contacts[j].name, contacts[j+1].name);
                            strcpy(contacts[j].email, contacts[j+1].email);
                        }
                        num_contacts--;
                        break;
                    }
                }
                break;
            case 3:
                printf("Contacts:\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("%s (%s)\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}