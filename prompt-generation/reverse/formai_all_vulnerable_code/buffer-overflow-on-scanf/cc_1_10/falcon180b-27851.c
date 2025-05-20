//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

void add_contact(contact *list, int *size) {
    printf("Enter name: ");
    scanf("%s", list[*size].name);
    printf("Enter email: ");
    scanf("%s", list[*size].email);
    (*size)++;
}

void display_contacts(contact *list, int size) {
    printf("\nName\tEmail\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\n", list[i].name, list[i].email);
    }
}

void sort_contacts(contact *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(list[i].name, list[j].name) > 0) {
                contact temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void search_contact(contact *list, int size, char *name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            printf("\nName: %s\nEmail: %s\n", list[i].name, list[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    contact list[100];
    int size = 0;

    add_contact(list, &size);
    add_contact(list, &size);
    add_contact(list, &size);

    display_contacts(list, size);
    sort_contacts(list, size);
    search_contact(list, size, "John");

    return 0;
}