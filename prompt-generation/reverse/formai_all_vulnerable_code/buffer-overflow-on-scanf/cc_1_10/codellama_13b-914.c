//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

struct mailing_list {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int main() {
    struct mailing_list list[MAX_LIST_SIZE];
    int list_size = 0;

    // Add some members to the list
    list[list_size++] = (struct mailing_list) {
        .name = "John Doe",
        .email = "johndoe@example.com"
    };
    list[list_size++] = (struct mailing_list) {
        .name = "Jane Doe",
        .email = "janedoe@example.com"
    };

    // Display the list
    printf("Mailing list:\n");
    for (int i = 0; i < list_size; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }

    // Add a new member to the list
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    printf("Enter a new name and email: ");
    scanf("%s %s", name, email);
    list[list_size++] = (struct mailing_list) {
        .name = name,
        .email = email
    };

    // Display the updated list
    printf("Updated mailing list:\n");
    for (int i = 0; i < list_size; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }

    return 0;
}