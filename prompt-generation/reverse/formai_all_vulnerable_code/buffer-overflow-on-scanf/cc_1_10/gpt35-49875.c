//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[15];
} Contact;

void add_contact(Contact *pb, int *size);
void view_contact(Contact *pb, int *size);
void search_contact(Contact *pb, int *size);
void delete_contact(Contact *pb, int *size);

int main() {
    Contact pb[1000];
    int size = 0;
    int option;

    do {
        printf("Welcome to the Phone Book!\n");
        printf("Please select an option:\n");
        printf("1. Add a contact\n");
        printf("2. View contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                add_contact(pb, &size);
                break;
            case 2:
                view_contact(pb, &size);
                break;
            case 3:
                search_contact(pb, &size);
                break;
            case 4:
                delete_contact(pb, &size);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }

        printf("\n");

    } while(option != 5);

    return 0;
}

void add_contact(Contact *pb, int *size) {
    printf("Please enter the name of the contact: ");
    scanf("%s", pb[*size].name);

    printf("Please enter the phone number of the contact: ");
    scanf("%s", pb[*size].number);

    (*size)++;
}

void view_contact(Contact *pb, int *size) {
    if(*size == 0) {
        printf("Phone book is empty.\n");
    } else {
        printf("Contacts:\n");
        for(int i = 0; i < *size; i++) {
            printf("%d. %s - %s\n", i+1, pb[i].name, pb[i].number);
        }
    }
}

void search_contact(Contact *pb, int *size) {
    if(*size == 0) {
        printf("Phone book is empty.\n");
    } else {
        char name[50];
        printf("Please enter the name you want to search for: ");
        scanf("%s", name);

        for(int i = 0; i < *size; i++) {
            if(strcmp(name, pb[i].name) == 0) {
                printf("%s - %s\n", pb[i].name, pb[i].number);
                return;
            }
        }

        printf("Contact not found.\n");
    }
}

void delete_contact(Contact *pb, int *size) {
    if(*size == 0) {
        printf("Phone book is empty.\n");
    } else {
        char name[50];
        printf("Please enter the name of the contact you want to delete: ");
        scanf("%s", name);

        for(int i = 0; i < *size; i++) {
            if(strcmp(name, pb[i].name) == 0) {
                for(int j = i; j < *size-1; j++) {
                    strcpy(pb[j].name, pb[j+1].name);
                    strcpy(pb[j].number, pb[j+1].number);
                }
                (*size)--;
                printf("Contact deleted successfully.\n");
                return;
            }
        }

        printf("Contact not found.\n");
    }
}