//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[15];
};

int compare(const void *a, const void *b) {
    struct entry *entry1 = (struct entry *)a;
    struct entry *entry2 = (struct entry *)b;

    return strcmp(entry1->name, entry2->name);
}

int main() {
    FILE *file;
    char filename[50];
    int choice, search;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to the Phone Book!\n");
    printf("Please choose an option:\n");
    printf("1. Add a new entry\n");
    printf("2. Search for an entry\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the name: ");
            scanf("%s", entries[num_entries].name);
            printf("Enter the phone number: ");
            scanf("%s", entries[num_entries].phone);
            num_entries++;
            break;
        case 2:
            printf("Enter the name to search for: ");
            scanf("%s", filename);
            file = fopen(filename, "r");

            if(file == NULL) {
                printf("File not found.\n");
            } else {
                fclose(file);

                printf("Enter 1 to sort the entries alphabetically by name:\n");
                scanf("%d", &search);

                if(search == 1) {
                    qsort(entries, num_entries, sizeof(struct entry), compare);
                }

                printf("The entries in the phone book are:\n");
                for(int i = 0; i < num_entries; i++) {
                    printf("%s - %s\n", entries[i].name, entries[i].phone);
                }
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}