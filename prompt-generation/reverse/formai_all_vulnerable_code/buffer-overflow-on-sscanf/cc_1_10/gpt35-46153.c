//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct phonebook_entry {
    char name[20];
    char phone[15];
} phonebook_entry;

int main() {
    phonebook_entry phonebook[MAX_ENTRIES];
    int num_entries = 0;
    char input[20], command[10], name[20], phone[15];

    printf("============================\n");
    printf("= C PHONE BOOK APPLICATION =\n");
    printf("============================\n");

    while (1) {
        printf("\nEnter command (add, search, quit): ");
        fflush(stdout);
        fgets(input, 20, stdin);
        sscanf(input, "%s", command);

        if (strcmp(command, "add") == 0) {
            if (num_entries == MAX_ENTRIES) {
                printf("Error: phonebook is full.\n");
                continue;
            }
            printf("Enter name: ");
            fflush(stdout);
            fgets(input, 20, stdin);
            sscanf(input, "%s", name);

            printf("Enter phone number: ");
            fflush(stdout);
            fgets(input, 15, stdin);
            sscanf(input, "%s", phone);

            phonebook_entry new_entry;
            strcpy(new_entry.name, name);
            strcpy(new_entry.phone, phone);
            phonebook[num_entries] = new_entry;

            printf("Entry added.\n");
            num_entries++;
        } else if (strcmp(command, "search") == 0) {
            printf("Enter name: ");
            fflush(stdout);
            fgets(input, 20, stdin);
            sscanf(input, "%s", name);

            int entry_found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(phonebook[i].name, name) == 0) {
                    printf("Phone number for %s: %s\n", phonebook[i].name, phonebook[i].phone);
                    entry_found = 1;
                    break;
                }
            }

            if (!entry_found) {
                printf("No entry found for %s.\n", name);
            }
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting phonebook application.\n");
            break;
        } else {
            printf("Error: invalid command.\n");
        }
    }

    return 0;
}