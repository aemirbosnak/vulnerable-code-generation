//FormAI DATASET v1.0 Category: Phone Book ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[100];
};

int main() {
    int option;
    struct Contact *book = NULL;
    int size = 0;
    int max_size = 0;
    char temp[100];
    printf("Welcome to the C Phone Book!\n");
    printf("---------------------------\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                if(size == max_size) {
                    max_size += 10;
                    book = (struct Contact *)realloc(book, max_size*sizeof(struct Contact));
                    if(book == NULL) {
                        printf("Memory allocation failed.\n");
                        exit(1);
                    }
                }
                printf("\nEnter Contact Name: ");
                scanf("%s", book[size].name);
                printf("Enter Phone Number: ");
                scanf("%s", book[size].phone);
                printf("Enter Email Address: ");
                scanf("%s", book[size].email);
                size++;
                break;
            case 2:
                printf("\n---------------------------------\n");
                printf("|%-30s|%-20s|%-30s|\n", "Name", "Phone Number", "Email Address");
                printf("-----------------------------------\n");
                for(int i=0; i<size; i++) {
                    printf("|%-30s|%-20s|%-30s|\n", book[i].name, book[i].phone, book[i].email);
                }
                printf("----------------------------------\n");
                break;
            case 3:
                printf("\nEnter Contact Name to Search: ");
                scanf("%s", temp);
                for(int i=0; i<size; i++) {
                    if(strcasecmp(temp, book[i].name) == 0) {
                        printf("\n--------------------------------------\n");
                        printf("|%-30s|%-20s|%-30s|\n", "Name", "Phone Number", "Email Address");
                        printf("----------------------------------------\n");
                        printf("|%-30s|%-20s|%-30s|\n", book[i].name, book[i].phone, book[i].email);
                        printf("----------------------------------------\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("\nEnter Contact Name to Delete: ");
                scanf("%s", temp);
                int found = 0;
                for(int i=0; i<size; i++) {
                    if(strcasecmp(temp, book[i].name) == 0) {
                        found = 1;
                        for(int j=i; j<size-1; j++) {
                            strcpy(book[j].name, book[j+1].name);
                            strcpy(book[j].phone, book[j+1].phone);
                            strcpy(book[j].email, book[j+1].email);
                        }
                        size--;
                        if(size == max_size-10) {
                            max_size -= 10;
                            book = (struct Contact *)realloc(book, max_size*sizeof(struct Contact));
                        }
                        break;
                    }
                }
                if(found == 0) {
                    printf("\nContact not Found.\n");
                }
                else {
                    printf("\nContact Deleted.\n");
                }
                break;
            case 5:
                break;
            default:
                printf("\nInvalid Choice.\n");
                break;
        }
    } while(option != 5);
    free(book);
    return 0;
}