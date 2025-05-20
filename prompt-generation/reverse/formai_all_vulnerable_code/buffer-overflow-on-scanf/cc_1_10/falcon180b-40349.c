//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber list[MAX_LIST_SIZE];
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    if (num_subscribers >= MAX_LIST_SIZE) {
        printf("Error: List is full.\n");
        return;
    }

    strcpy(list[num_subscribers].name, name);
    strcpy(list[num_subscribers].email, email);
    num_subscribers++;
}

void print_list() {
    printf("Name\tEmail\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s\t%s\n", list[i].name, list[i].email);
    }
}

void remove_subscriber(char *email) {
    for (int i = 0; i < num_subscribers; i++) {
        if (strcmp(list[i].email, email) == 0) {
            num_subscribers--;
            for (int j = i; j < num_subscribers; j++) {
                list[j] = list[j + 1];
            }
            break;
        }
    }
}

int main() {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];

    while (1) {
        printf("1. Add Subscriber\n2. Print List\n3. Remove Subscriber\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_subscriber(name, email);
            break;
        case 2:
            print_list();
            break;
        case 3:
            printf("Enter email: ");
            scanf("%s", email);
            remove_subscriber(email);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}