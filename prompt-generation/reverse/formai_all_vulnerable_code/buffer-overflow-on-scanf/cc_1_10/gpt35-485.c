//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber email_list[MAX_EMAILS];
int num_subscribers = 0;

void add_subscriber() {
    Subscriber new_sub;
    printf("Enter subscriber name: ");
    fgets(new_sub.name, MAX_NAME_LEN, stdin);
    printf("Enter subscriber email: ");
    fgets(new_sub.email, MAX_EMAIL_LEN, stdin);
    email_list[num_subscribers++] = new_sub;
    printf("%s has been added to the email list!\n", new_sub.name);
}

void remove_subscriber() {
    char search_name[MAX_NAME_LEN];
    printf("Enter the name of the subscriber you wish to remove: ");
    fgets(search_name, MAX_NAME_LEN, stdin);
    int i, found = 0;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(search_name, email_list[i].name) == 0) {
            printf("Removing %s from the email list.\n", email_list[i].name);
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < num_subscribers - 1; j++) {
            email_list[j] = email_list[j + 1];
        }
        num_subscribers--;
    } else {
        printf("Subscriber not found.\n");
    }
}

void print_list() {
    printf("CURRENT EMAIL LIST:\n");
    printf("%-20s %-30s\n\n", "NAME", "EMAIL");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%-20s %-30s\n", email_list[i].name, email_list[i].email);
    }
    printf("\n");
}

int main() {
    int choice = 0;
    while (choice != 4) {
        printf("******MAILING LIST MANAGER******\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline left by scanf
        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                remove_subscriber();
                break;
            case 3:
                print_list();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}