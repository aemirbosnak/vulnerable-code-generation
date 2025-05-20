//FormAI DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[50];
    int age;
};

struct maillist {
    struct subscriber subs[100];
    int count;
};

void addSubscriber(struct maillist *list, struct subscriber sub) {
    list->subs[list->count] = sub;
    list->count++;
}

void printList(struct maillist *list) {
    int i;
    printf("\n\n********** Mailing List **********");
    for (i = 0; i < list->count; i++) {
        printf("\nSubscriber Name: %s", list->subs[i].name);
        printf("\nSubscriber Email: %s", list->subs[i].email);
        printf("\nSubscriber Age: %d", list->subs[i].age);
        printf("\n");
    }
}

int main() {
    struct maillist list;
    list.count = 0;
    int choice, age;
    char name[50], email[50];

    printf("Welcome to our Mailing List Manager!\n\n");

    do {
        printf("\n\nWhat would you like to do?\n");
        printf("1) Add subscriber\n");
        printf("2) Print list\n");
        printf("3) Exit program\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                printf("Enter age: ");
                scanf("%d", &age);
                struct subscriber sub = { name, email, age };
                addSubscriber(&list, sub);
                printf("\n%s has been added to the mailing list!\n", name);
                break;

            case 2:
                printList(&list);
                break;

            case 3:
                printf("\nThank you for using our Mailing List Manager!\n\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}