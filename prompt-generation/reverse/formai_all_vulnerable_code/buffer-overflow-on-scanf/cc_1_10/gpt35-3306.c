//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 50

typedef struct password {
    char website[MAX_CHARACTERS];
    char username[MAX_CHARACTERS];
    char password[MAX_CHARACTERS];
    struct password *next;
} Password;

int menu();
void add_password(Password** head);
void view_passwords(Password* head);
void search_website(Password* head, char* website);
void search_username(Password* head, char* username);
void delete_password(Password** head, char* website);

int main() {
    Password* head = NULL;
    int option;

    while((option = menu())) {
        switch(option) {
            case 1: add_password(&head); break;
            case 2: view_passwords(head); break;
            case 3: {
                char website[MAX_CHARACTERS];
                printf("Enter website to search: ");
                scanf("%s", website);
                search_website(head, website);
                break;
            }
            case 4: {
                char username[MAX_CHARACTERS];
                printf("Enter username to search: ");
                scanf("%s", username);
                search_username(head, username);
                break;
            }
            case 5: {
                char website[MAX_CHARACTERS];
                printf("Enter website to delete: ");
                scanf("%s", website);
                delete_password(&head, website);
                break;
            }
            default: printf("Invalid option\n");
        }
    }

    Password *curr, *temp;
    curr = head;

    while(curr != NULL) {
        temp = curr->next;
        free(curr);
        curr = temp;
    }

    return 0;
}

int menu() {
    int option;

    printf("\nPASSWORD MANAGEMENT SYSTEM\n");
    printf("1. Add new password\n");
    printf("2. Display all passwords\n");
    printf("3. Search by website\n");
    printf("4. Search by username\n");
    printf("5. Delete by website\n");
    printf("0. Exit\n");

    scanf("%d", &option);

    return option;
}

void add_password(Password** head) {
    char website[MAX_CHARACTERS];
    char username[MAX_CHARACTERS];
    char password[MAX_CHARACTERS];

    printf("Enter website: ");
    scanf("%s", website);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    Password* new_password = (Password*) malloc(sizeof(Password));

    strcpy(new_password->website, website);
    strcpy(new_password->username, username);
    strcpy(new_password->password, password);
    new_password->next = NULL;

    if(*head == NULL) {
        *head = new_password;
    } else {
        Password* curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_password;
    }

    printf("\nNew password added successfully!\n");
}

void view_passwords(Password* head) {
    if(head == NULL) {
        printf("\nNo passwords stored currently\n");
    } else {
        Password* curr = head;
        while(curr != NULL) {
            printf("\nWebsite: %s\n", curr->website);
            printf("Username: %s\n", curr->username);
            printf("Password: %s\n", curr->password);
            curr = curr->next;
        }
    }
}

void search_website(Password* head, char* website) {
    if(head == NULL) {
        printf("\nNo passwords stored currently\n");
    } else {
        Password* curr = head;
        int count = 0;

        while(curr != NULL) {
            if(strcmp(curr->website, website) == 0) {
                printf("\nWebsite: %s\n", curr->website);
                printf("Username: %s\n", curr->username);
                printf("Password: %s\n", curr->password);
                count++;
            }
            curr = curr->next;
        }

        if(count == 0) {
            printf("\nNo passwords found for website '%s'\n", website);
        }
    }
}

void search_username(Password* head, char* username) {
    if(head == NULL) {
        printf("\nNo passwords stored currently\n");
    } else {
        Password* curr = head;
        int count = 0;

        while(curr != NULL) {
            if(strcmp(curr->username, username) == 0) {
                printf("\nWebsite: %s\n", curr->website);
                printf("Username: %s\n", curr->username);
                printf("Password: %s\n", curr->password);
                count++;
            }
            curr = curr->next;
        }

        if(count == 0) {
            printf("\nNo passwords found for username '%s'\n", username);
        }
    }
}

void delete_password(Password** head, char* website) {
    if(*head == NULL) {
        printf("\nNo passwords stored currently\n");
    } else {
        Password* curr = *head;
        Password* prev = NULL;
        int count = 0;

        while(curr != NULL) {
            if(strcmp(curr->website, website) == 0) {
                if(prev == NULL) {
                    *head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(curr);
                printf("\nPassword for website '%s' deleted successfully!\n", website);
                count++;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if(count == 0) {
            printf("\nNo passwords found for website '%s'\n", website);
        }
    }
}