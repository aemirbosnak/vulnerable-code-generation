//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[100];
} Contact;

int main() {
    int choice, i;
    Contact mailing_list[100];
    int num_contacts = 0;

    while(1) {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n2. Remove contact\n3. Display contacts\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", mailing_list[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", mailing_list[num_contacts].email);
                num_contacts++;
                break;
            case 2:
                printf("Enter name of contact to remove: ");
                scanf("%s", mailing_list[num_contacts].name);
                for(i = num_contacts - 1; i >= 0; i--) {
                    if(strcmp(mailing_list[i].name, mailing_list[num_contacts].name) == 0) {
                        strcpy(mailing_list[i].name, "");
                        strcpy(mailing_list[i].email, "");
                        num_contacts--;
                    }
                }
                break;
            case 3:
                printf("Mailing List:\n");
                for(i = 0; i < num_contacts; i++) {
                    if(strcmp(mailing_list[i].name, "")!= 0) {
                        printf("%s - %s\n", mailing_list[i].name, mailing_list[i].email);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}