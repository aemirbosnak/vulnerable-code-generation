//FormAI DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct detective {
    char name[20];
    char phone[15];
    int age;
};

void add_contact(struct detective arr[], int *len) {
    printf("Enter the name of the detective: ");
    scanf(" %[^\n]s", arr[*len].name);

    printf("Enter the phone number of the detective: ");
    scanf(" %[^\n]s", arr[*len].phone);

    printf("Enter the age of the detective: ");
    scanf("%d", &arr[*len].age);

    printf("\nContact added successfully!\n");
    (*len)++;
}

void view_contacts(struct detective arr[], int len) {
    if (len == 0) {
        printf("The phone book is empty.\n");
    } else {
        printf("Phone Book:\n");
        printf("Name\tPhone Number\tAge\n");
        for (int i = 0; i < len; i++) {
            printf("%s\t%s\t%d\n", arr[i].name, arr[i].phone, arr[i].age);
        }
    }
}

void search_contact(struct detective arr[], int len) {
    char name[20];
    printf("Enter the name of the detective: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < len; i++) {
        if (strcmp(name, arr[i].name) == 0) {
            printf("\nName: %s\nPhone Number: %s\nAge: %d\n", arr[i].name, arr[i].phone, arr[i].age);
            return;
        }
    }

    printf("\nContact not found.\n");
}

void delete_contact(struct detective arr[], int *len) {
    char name[20];
    printf("Enter the name of the detective: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < *len; i++) {
        if (strcmp(name, arr[i].name) == 0) {
            for (int j = i; j < *len - 1; j++) {
                arr[j] = arr[j + 1];
            }
            printf("\nContact deleted successfully!\n");
            (*len)--;
            return;
        }
    }

    printf("\nContact not found.\n");
}

int main() {
    int opt = 0, len = 0;
    struct detective arr[50];

    printf("Welcome, Mr. Holmes. What shall we do today?\n");

    while (opt != 5) {
        printf("\n1. Add a new contact\n2. View all contacts\n3. Search for a contact\n4. Delete a contact\n5. Exit the program\n\nYour choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                add_contact(arr, &len);
                break;
            case 2:
                view_contacts(arr, len);
                break;
            case 3:
                search_contact(arr, len);
                break;
            case 4:
                delete_contact(arr, &len);
                break;
            case 5:
                printf("\nThank you for using the Sherlock Holmes Phone Book.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}