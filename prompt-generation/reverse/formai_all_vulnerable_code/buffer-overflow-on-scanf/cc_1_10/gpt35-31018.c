//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include<stdio.h>
#include<string.h>
#define MAX 100

struct node {
    char email[MAX];
    struct node *next;
};

typedef struct node NODE;

NODE *head = NULL; // head of the linked list

void add_email() {
    NODE *new_node, *ptr;
    char email[MAX];

    printf("\nEnter email address: ");
    scanf("%s", email);

    new_node = (NODE *)malloc(sizeof(NODE));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
        printf("\nEmail added to mailing list successfully!");
        return;
    }

    ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    printf("\nEmail added to mailing list successfully!");
}

void view_list() {
    NODE *ptr;

    if(head == NULL) {
        printf("\nMailing list is empty!");
        return;
    }

    printf("\nMailing List:\n");
    ptr = head;
    while(ptr != NULL) {
        printf("%s\n", ptr->email);
        ptr = ptr->next;
    }
}

void delete_email() {
    NODE *ptr, *prev;
    char email[MAX];
    int flag = 0;

    if(head == NULL) {
        printf("\nMailing list is already empty!");
        return;
    }

    printf("\nEnter email to be deleted: ");
    scanf("%s", email);

    ptr = head;
    while(ptr != NULL) {
        if(strcmp(ptr->email, email) == 0) {
            if(ptr == head) {
                head = ptr->next;
            }
            else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("\nEmail deleted from mailing list successfully!");
            flag = 1;
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if(flag != 1) {
        printf("\nEmail not found in mailing list!");
    }
}

void main() {
    int option;
    printf("*************** Mailing List Manager *****************\n");

    while(1) {
        printf("\nOptions:\n");
        printf("1. Add email address to mailing list\n");
        printf("2. View mailing list\n");
        printf("3. Delete email address from mailing list\n");
        printf("4. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_email();
                break;
            case 2:
                view_list();
                break;
            case 3:
                delete_email();
                break;
            case 4:
                printf("\nGoodbye!");
                exit(0);
            default:
                printf("\nInvalid option!");
        }
    }
}