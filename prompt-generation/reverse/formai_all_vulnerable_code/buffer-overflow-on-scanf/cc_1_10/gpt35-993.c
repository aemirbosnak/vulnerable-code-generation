//FormAI DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber{
    char name[50];
    char email[50];
    struct subscriber *next;
}head, *tail;

void add_subscriber(){
    struct subscriber *new_subscriber = (struct subscriber*)malloc(sizeof(struct subscriber));
    printf("Enter subscriber name: ");
    scanf("%s", new_subscriber->name);
    printf("Enter subscriber email: ");
    scanf("%s", new_subscriber->email);

    if(head.next == NULL){
        head.next = new_subscriber;
        tail = new_subscriber;
    } else{
        tail->next = new_subscriber;
        tail = new_subscriber;
    }
    printf("%s has been added to the mailing list.\n", new_subscriber->name);
}

void view_subscribers(){
    if(head.next == NULL){
        printf("There are no subscribers yet.\n");
    } else{
        struct subscriber *current = head.next;
        int count = 1;
        while(current != NULL){
            printf("%d. Name: %s, Email: %s\n", count, current->name, current->email);
            current = current->next;
            count++;
        }
    }
}

void delete_subscriber(){
    if(head.next == NULL){
        printf("There are no subscribers yet.\n");
    } else{
        char email_to_delete[50];
        printf("Enter the email of the subscriber you want to delete: ");
        scanf("%s", email_to_delete);

        struct subscriber *current = head.next;
        struct subscriber *previous = &head;

        while(current != NULL){
            if(strcmp(current->email, email_to_delete) == 0){
                previous->next = current->next;
                if(current == tail){
                    tail = previous;
                }
                printf("%s has been deleted from the mailing list.\n", current->name);
                free(current);
                return;
            }
            previous = current;
            current = current->next;
        }
        printf("Subscriber with email %s not found.\n", email_to_delete);
    }
}

int main(){
    memset(&head, 0, sizeof(head));
    int choice = 0;

    printf("Welcome to the Futuristic Mailing List Manager!\n");

    while(choice != 4){
        printf("\n1. Add Subscriber\n2. View Subscribers\n3. Delete Subscriber\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_subscriber();
                break;
            case 2:
                view_subscribers();
                break;
            case 3:
                delete_subscriber();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}