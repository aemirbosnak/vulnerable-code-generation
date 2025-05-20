//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for mailing list
struct mailingList {
    char name[50];
    char email[50];
    struct mailingList *next;
};

typedef struct mailingList List;

// Function to create a new node
List *createNode(char *name, char *email) {
    List *node = (List *) malloc(sizeof(List));
    if(node == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    } else {
        strcpy(node->name, name);
        strcpy(node->email, email);
        node->next = NULL;
        return node;
    }
}

// Function to add a new subscriber
List *subscribe(List *head) {
    char email[50], name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your email address: ");
    scanf("%s", email);

    // Check if email already exists
    List *temp = head;
    while(temp != NULL) {
        if(strcmp(temp->email, email) == 0) {
            printf("Email already exists!\n");
            return head;
        }
        temp = temp->next;
    }

    List *node = createNode(name, email);
    if(head == NULL) {
        head = node;
    } else {
        List *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    printf("Subscribed successfully!\n");
    return head;
}

// Function to remove a subscriber
List *unsubscribe(List *head) {
    if(head == NULL) {
        printf("No subscribers to unsubscribe!\n");
        return head;
    }

    char email[50];
    printf("Enter your email address: ");
    scanf("%s", email);

    if(strcmp(head->email, email) == 0) {
        List *temp = head;
        head = head->next;
        free(temp);
        printf("Unsubscribed successfully!\n");
        return head;
    }

    List *temp1 = head, *temp2;
    while(temp1 != NULL && strcmp(temp1->email, email) != 0) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if(temp1 == NULL) {
        printf("Email does not exist!\n");
    } else {
        temp2->next = temp1->next;
        free(temp1);
        printf("Unsubscribed successfully!\n");
    }
    return head;
}

// Function to display all subscribers
void display(List *head) {
    if(head == NULL) {
        printf("No subscribers!\n");
    } else {
        printf("Name\t\tEmail\n---------------------\n");
        List *temp = head;
        while(temp != NULL) {
            printf("%s\t%s\n", temp->name, temp->email);
            temp = temp->next;
        }
    }
}

int main() {
    List *head = NULL;
    int choice;

    while(1) {
        printf("\n1. Subscribe\n2. Unsubscribe\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = subscribe(head);
                break;
            case 2:
                head = unsubscribe(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
}