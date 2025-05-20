//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char phone[15];
} Entry;

Entry phonebook[MAX_ENTRIES];
int num_entries = 0;
float avg_name_length = 0.0;
int longest_name_len = 0;

void add_entry(char *name, char *phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;
    avg_name_length += strlen(name) / (num_entries + 1.0);
    if (strlen(name) > longest_name_len) {
        longest_name_len = strlen(name);
    }
}

void delete_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(Entry) * (num_entries - i - 1));
            num_entries--;
            avg_name_length -= strlen(phonebook[i].name) / (num_entries + 1.0);
            break;
        }
    }
}

Entry *search_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            return &phonebook[i];
        }
    }
    return NULL;
}

void print_statistics() {
    printf("Number of entries: %d\n", num_entries);
    printf("Average name length: %.2f\n", avg_name_length);
    printf("Longest name length: %d\n", longest_name_len);
}

int main() {
    char name[NAME_LENGTH], phone[15];
    int choice, i;
    while (1) {
        printf("\nPhonebook Menu:\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Print statistics\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_entry(name, phone);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                if (search_entry(name) != NULL) {
                    printf("Name %s found. Phone number: %s\n", name, search_entry(name)->phone);
                } else {
                    printf("Name %s not found.\n", name);
                }
                break;
            case 4:
                print_statistics();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}