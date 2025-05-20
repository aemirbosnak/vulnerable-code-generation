//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
/* C Mailing List Manager - by Ken Thompson style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct to hold mailing list data */
struct mailing_list {
    char name[100];
    char email[100];
};

/* function to print mailing list */
void print_mailing_list(struct mailing_list* list, int size) {
    printf("Mailing List:\n");
    for(int i=0;i<size;i++) {
        printf("%d. %s <%s>\n", i+1, list[i].name, list[i].email);
    }
}

/* function to add new contact to mailing list */
void add_contact(struct mailing_list* list, int* size) {
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    printf("Enter email: ");
    scanf("%s", list[*size].email);
    (*size)++;
}

/* function to remove contact from mailing list */
void remove_contact(struct mailing_list* list, int* size) {
    int index;
    printf("Enter index of contact to remove: ");
    scanf("%d", &index);
    if(index < 1 || index > *size) {
        printf("Invalid index!\n");
    } else {
        for(int i=index-1;i<*size-1;i++) {
            list[i] = list[i+1];
        }
        (*size)--;
    }
}

/* main function */
int main() {
    struct mailing_list list[10];
    int size = 0;
    char choice;
    do {
        printf("\n\n");
        printf("C Mailing List Manager\n");
        printf("======================\n");
        printf("1. View Mailing List\n");
        printf("2. Add Contact\n");
        printf("3. Remove Contact\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                print_mailing_list(list, size);
                break;
            case '2':
                add_contact(list, &size);
                break;
            case '3':
                remove_contact(list, &size);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != '4');

    return 0;
}