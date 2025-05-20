//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

struct mailing_list {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int main() {
    int list_size = 0;
    struct mailing_list list[MAX_LIST_SIZE];

    // Prompt user for list size
    printf("Enter the size of the mailing list: ");
    scanf("%d", &list_size);

    // Initialize list with empty entries
    for (int i = 0; i < list_size; i++) {
        strcpy(list[i].name, "");
        strcpy(list[i].email, "");
    }

    // Prompt user for list entries
    printf("Enter the names and email addresses for the mailing list:\n");
    for (int i = 0; i < list_size; i++) {
        printf("Entry %d:\n", i+1);
        printf("Name: ");
        scanf("%s", list[i].name);
        printf("Email: ");
        scanf("%s", list[i].email);
    }

    // Sort the list by name
    for (int i = 0; i < list_size-1; i++) {
        for (int j = i+1; j < list_size; j++) {
            if (strcmp(list[i].name, list[j].name) > 0) {
                struct mailing_list temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    // Print the sorted list
    printf("\nSorted Mailing List:\n");
    for (int i = 0; i < list_size; i++) {
        printf("%s - %s\n", list[i].name, list[i].email);
    }

    return 0;
}