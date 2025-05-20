//FormAI DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// declare a struct to represent each user in the mailing list
struct user {
    char name[30];
    char email[50];
    struct user *next;
};

// function declaration
struct user *create_user(char *name, char *email);
void add_user(struct user **head, struct user *new_user);
void print_list(struct user *head);
void delete_user(struct user **head, char *email);

int main() {
    struct user *head = NULL;
    char name[30], email[50], option;
    struct user *new_user = NULL;
    int choice;

    do {
        printf("\n\nMenu:\n");
        printf("1. Add user\n");
        printf("2. Delete user\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                
                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                new_user = create_user(name, email);
                add_user(&head, new_user);
                printf("User added!\n");
                break;
                
            case 2:
                printf("Enter email of the user to be deleted: ");
                fgets(email, sizeof(email), stdin);
                delete_user(&head, email);
                break;
            
            case 3:
                print_list(head);
                break;
            
            case 4:
                printf("Exiting..");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Press enter to continue..");
        getchar();
    } while(1);
}

// create a new user node
struct user *create_user(char *name, char *email) {
    struct user *new_user = (struct user*)malloc(sizeof(struct user));
    if(new_user == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(new_user->name, name);
    strcpy(new_user->email, email);
    new_user->next = NULL;
    return new_user;
}

// add a new user node to the mailing list
void add_user(struct user **head, struct user *new_user) {
    if(*head == NULL) {
        *head = new_user;
    }
    else {
        struct user *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_user;
    }
}

// print the entire mailing list
void print_list(struct user *head) {
    if(head == NULL) {
        printf("Mailing list is empty.\n");
    }
    else {
        printf("\nMailing list:\n");
        while(head != NULL) {
            printf("Name: %s", head->name);
            printf("Email: %s", head->email);
            head = head->next;
        }
    }
}

// delete a user node from the mailing list
void delete_user(struct user **head, char *email) {
    if(*head == NULL) {
        printf("Mailing list is empty. No user to delete.\n");
    }
    else {
        struct user *temp = *head, *prev = NULL;
        while(temp != NULL) {
            if(strcmp(temp->email, email) == 0) {
                if(prev == NULL) {
                    *head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                free(temp);
                printf("User deleted!\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        printf("User with email %s not found!\n", email);
    }
}