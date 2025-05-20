//FormAI DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[100];
    int age;
};

struct node {
    struct subscriber subscriber;
    struct node* next;
};

struct list {
    struct node* head;
};

void addSubscriber(struct list* lst) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Failed to allocate memory\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", new_node->subscriber.name);

    printf("Enter email: ");
    scanf("%s", new_node->subscriber.email);

    printf("Enter age: ");
    scanf("%d", &new_node->subscriber.age);

    new_node->next = NULL;

    if (lst->head == NULL) {
        lst->head = new_node;
    } else {
        struct node* ptr = lst->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    printf("\nSuccessfully added subscriber\n");
}

void displaySubscribers(struct list lst) {
    if (lst.head == NULL) {
        printf("\nNo subscribers in the list\n");
    } else {
        printf("\n============= Subscriber List =============\n");
        printf("%-25s %-30s %-10s\n", "Name", "Email", "Age");
        printf("--------------------------------------------\n");
        struct node* ptr = lst.head;
        while (ptr != NULL) {
            printf("%-25s %-30s %-10d\n", ptr->subscriber.name, ptr->subscriber.email, ptr->subscriber.age);
            ptr = ptr->next;
        }
        printf("============================================\n");
    }
}

void deleteSubscriber(struct list* lst, char* email) {
    if (lst->head == NULL) {
        printf("\nNo subscribers in the list\n");
        return;
    }

    struct node* ptr = lst->head;
    struct node* prev = NULL;
    while (ptr != NULL && strcmp(ptr->subscriber.email, email) != 0) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\nSubscriber with email '%s' not found\n", email);
        return;
    }

    if (prev == NULL) {
        lst->head = ptr->next;
    } else {
        prev->next = ptr->next;
    }

    free(ptr);

    printf("\nSuccessfully deleted subscriber with email '%s'\n", email);
}

void countSubscribers(struct list lst) {
    int count = 0;
    struct node* ptr = lst.head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    printf("\nThere are %d subscribers in the list\n", count);
}

int main() {
    struct list lst = { NULL };
    int choice;
    char email[100];

    printf("============== Mailing List Manager ==============\n");

    do {
        printf("\n1. Add Subscriber\n");
        printf("2. Display Subscribers\n");
        printf("3. Delete Subscriber\n");
        printf("4. Count Subscribers\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber(&lst);
                break;
            case 2:
                displaySubscribers(lst);
                break;
            case 3:
                printf("\nEnter email to delete: ");
                scanf("%s", email);
                deleteSubscriber(&lst, email);
                break;
            case 4:
                countSubscribers(lst);
                break;
            case 5:
                printf("\nExiting program\n");
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}