//FormAI DATASET v1.0 Category: Phone Book ; Style: careful
#include <stdio.h>
#include <string.h>

struct phonebook_entry {
    char name[50];
    char phone_number[15];
    char email[50];
};

void display_menu() {
    printf("\n\nPhone Book Menu\n");
    printf("1. Add new entry\n");
    printf("2. Search by name\n");
    printf("3. Search by phone number\n");
    printf("4. Display all entries\n");
    printf("5. Exit\n\n");
}

void add_entry(struct phonebook_entry *pb, int *num_entries) {
    printf("\nEnter name: ");
    scanf("%s", pb[*num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", pb[*num_entries].phone_number);
    printf("Enter email: ");
    scanf("%s", pb[*num_entries].email);
    (*num_entries)++;
    printf("Entry added!\n");
}

void search_by_name(struct phonebook_entry *pb, int num_entries) {
    char name[50];
    printf("\nEnter name to search for: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(pb[i].name, name) == 0) {
            printf("Name: %s\n", pb[i].name);
            printf("Phone number: %s\n", pb[i].phone_number);
            printf("Email: %s\n", pb[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found.\n");
    }
}

void search_by_number(struct phonebook_entry *pb, int num_entries) {
    char number[15];
    printf("\nEnter phone number to search for: ");
    scanf("%s", number);
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(pb[i].phone_number, number) == 0) {
            printf("Name: %s\n", pb[i].name);
            printf("Phone number: %s\n", pb[i].phone_number);
            printf("Email: %s\n", pb[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found.\n");
    }
}

void display_entries(struct phonebook_entry *pb, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("\nEntry %d:\n", i+1);
        printf("Name: %s\n", pb[i].name);
        printf("Phone number: %s\n", pb[i].phone_number);
        printf("Email: %s\n", pb[i].email);
    }
}

int main() {
    struct phonebook_entry phonebook[100];
    int num_entries = 0;
    int choice;
    do {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(phonebook, &num_entries);
                break;
            case 2:
                search_by_name(phonebook, num_entries);
                break;
            case 3:
                search_by_number(phonebook, num_entries);
                break;
            case 4:
                display_entries(phonebook, num_entries);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}