//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct subscriber {
    char email[MAX];
    int age;
};

struct mailingList {
    struct subscriber subscribers[MAX];
    int num_subscribers;
};

void addSubscriber(struct mailingList *list, char email[MAX], int age);
void removeSubscriber(struct mailingList *list, char email[MAX]);
void printMailingList(struct mailingList *list);

int main() {
    struct mailingList list = { .num_subscribers = 0 };
    int choice;
    char email[MAX];
    int age;
    
    do {
        printf("\nWelcome to the Mailing List Manager!\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. Print Mailing List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter email to add: ");
                scanf("%s", email);
                printf("Enter age: ");
                scanf("%d", &age);
                addSubscriber(&list, email, age);
                break;
            case 2:
                printf("\nEnter email to remove: ");
                scanf("%s", email);
                removeSubscriber(&list, email);
                break;
            case 3:
                printf("\nMailing List:\n");
                printMailingList(&list);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid Choice. Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}

void addSubscriber(struct mailingList *list, char email[MAX], int age) {
    if(list->num_subscribers >= MAX) {
        printf("\nMailing list is full. Cannot add subscriber.\n");
        return;
    }
    
    for(int i=0; i<list->num_subscribers; i++) {
        if(strcmp(list->subscribers[i].email, email) == 0) {
            printf("\nSubscriber already exists in the mailing list.\n");
            return;
        }
    }
    
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].age = age;
    list->num_subscribers++;
    
    printf("\nSubscriber added successfully to the mailing list.\n");
}

void removeSubscriber(struct mailingList *list, char email[MAX]) {
    for(int i=0; i<list->num_subscribers; i++) {
        if(strcmp(list->subscribers[i].email, email) == 0) {
            for(int j=i; j<list->num_subscribers-1; j++) {
                strcpy(list->subscribers[j].email, list->subscribers[j+1].email);
                list->subscribers[j].age = list->subscribers[j+1].age;
            }
            list->num_subscribers--;
            printf("\nSubscriber removed successfully from the mailing list.\n");
            return;
        }
    }
    
    printf("\nSubscriber not found in the mailing list.\n");
} 

void printMailingList(struct mailingList *list) {
    if(list->num_subscribers == 0) {
        printf("\nMailing list is empty.\n");
        return;
    }
    
    printf("\nEmail\t\t\tAge\n");
    printf("------------------------\n");
    
    for(int i=0; i<list->num_subscribers; i++) {
        printf("%s\t\t%d\n", list->subscribers[i].email, list->subscribers[i].age);
    }
}