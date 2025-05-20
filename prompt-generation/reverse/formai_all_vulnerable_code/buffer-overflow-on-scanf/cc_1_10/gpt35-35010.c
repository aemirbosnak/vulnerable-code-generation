//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold relevant mailing list data
typedef struct {
    char name[20];
    char email[50];
} mailing_list;

// Function to add an entry to the mailing list
void add_entry(mailing_list* list, int* size) {
    // Dynamically allocate more memory for the list
    *size += 1;
    list = (mailing_list*)realloc(list, *size * sizeof(mailing_list));

    // Get input for the new entry
    printf("Enter name: ");
    scanf("%s", list[*size - 1].name);
    printf("Enter email: ");
    scanf("%s", list[*size - 1].email);

    printf("Entry added!\n");
}

// Function to remove an entry from the mailing list
void remove_entry(mailing_list* list, int* size, char* email) {
    // Lookup the email and remove the entry
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            *size -= 1;
            list = (mailing_list*)realloc(list, *size * sizeof(mailing_list));
            printf("Entry removed!\n");
            return;
        }
    }
    printf("Email not found. Entry not removed.\n");
}

// Function to print all entries in the mailing list
void print_list(mailing_list* list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", list[i].name, list[i].email);
    }
}

// Main driver function
int main() {
    mailing_list* list = NULL; // Initialize list to NULL
    int size = 0;

    // Menu-driven program loop
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(list, &size);
                break;
            case 2:
                printf("Enter email of entry to remove: ");
                char email[50];
                scanf("%s", email);
                remove_entry(list, &size, email);
                break;
            case 3:
                print_list(list, size);
                break;
            case 4:
                // Free allocated memory and exit program
                free(list);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}