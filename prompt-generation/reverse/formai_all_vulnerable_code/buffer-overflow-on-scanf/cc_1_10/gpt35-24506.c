//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

void add_contact(struct contact*, int*);
void display_contact(struct contact*, int);
void search_contact(struct contact*, int);
void delete_contact(struct contact*, int*);

int main() {
    int choice = 0, count = 0;
    struct contact list[100];

    while(choice != 5) {
        printf("\n----C PHONE BOOK----\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(list, &count);
                break;
            case 2:
                display_contact(list, count);
                break;
            case 3:
                search_contact(list, count);
                break;
            case 4:
                delete_contact(list, &count);
                break;
            case 5:
                printf("Thank you for using C Phone Book!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void add_contact(struct contact* list, int* count) {
    printf("\nEnter name: ");
    scanf(" %[^\n]", list[*count].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", list[*count].phone);
    (*count)++;
    printf("\nContact added successfully!\n");
}

void display_contact(struct contact* list, int count) {
    if(count == 0) {
        printf("\nNo contacts found!\n");
    }
    else {
        printf("\n--CONTACTS--\n");
        for(int i=0; i<count; i++) {
            printf("%d. Name: %s\n", i+1, list[i].name);
            printf("   Phone: %s\n", list[i].phone);
        }
    }
}

void search_contact(struct contact* list, int count) {
    if(count == 0) {
        printf("\nNo contacts found!\n");
    }
    else {
        char name[50];
        printf("\nEnter name to search: ");
        scanf(" %[^\n]", name);
        int match = 0;
        for(int i=0; i<count; i++) {
            if(strcmp(list[i].name, name) == 0) {
                printf("\n--MATCH FOUND--\n");
                printf("Name: %s\n", list[i].name);
                printf("Phone: %s\n", list[i].phone);
                match = 1;
            }
        }
        if(match == 0) {
            printf("\nNo matching contact found!\n");
        }
    }
}

void delete_contact(struct contact* list, int* count) {
    if(*count == 0) {
        printf("\nNo contacts found!\n");
    }
    else {
        int index;
        printf("\nEnter index of contact to delete: ");
        scanf("%d", &index);
        if(index < 1 || index > *count) {
            printf("\nInvalid index!\n");
        }
        else {
            for(int i=index-1; i<*count-1; i++) {
                strcpy(list[i].name, list[i+1].name);
                strcpy(list[i].phone, list[i+1].phone);
            }
            (*count)--;
            printf("\nContact deleted successfully!\n");
        }
    }
}