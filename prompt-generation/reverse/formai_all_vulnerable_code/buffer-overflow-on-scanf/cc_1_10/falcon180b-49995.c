//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_ADDR_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDR_LEN];
} Contact;

Contact contacts[100];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter address: ");
    scanf("%s", contacts[num_contacts].address);
    num_contacts++;
}

void remove_contact() {
    printf("Enter name to remove: ");
    scanf("%s", contacts[num_contacts - 1].name);
    num_contacts--;
}

void update_contact() {
    printf("Enter name to update: ");
    scanf("%s", contacts[num_contacts - 1].name);
    printf("Enter new address: ");
    scanf("%s", contacts[num_contacts - 1].address);
}

void print_contacts() {
    printf("Name\tAddress\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].address);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n2. Remove contact\n3. Update contact\n4. Print contacts\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                update_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}