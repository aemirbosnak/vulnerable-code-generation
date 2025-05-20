//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} Entry;

int main() {
    FILE *fp;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    fp = fopen("phonebook.txt", "r");
    if (fp == NULL) {
        printf("Error: Phonebook file not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s\n", entries[num_entries].name, entries[num_entries].phone)!= EOF) {
        num_entries++;
    }

    fclose(fp);

    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s %s\n", entries[i].name, entries[i].phone);
    }

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Save changes\n");
        printf("5. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf(" %s", entries[num_entries].name);
                printf("Enter phone number: ");
                scanf(" %s", entries[num_entries].phone);
                num_entries++;
                break;

            case '2':
                printf("Enter name to delete: ");
                scanf(" %s", entries[num_entries - 1].name);
                num_entries--;
                break;

            case '3':
                printf("Enter name to search: ");
                scanf(" %s", entries[num_entries - 1].name);
                i = 0;
                while (i < num_entries) {
                    if (strcmp(entries[i].name, entries[num_entries - 1].name) == 0) {
                        printf("%s %s\n", entries[i].name, entries[i].phone);
                        break;
                    }
                    i++;
                }
                break;

            case '4':
                fp = fopen("phonebook.txt", "w");
                if (fp == NULL) {
                    printf("Error: Could not save changes.\n");
                } else {
                    int j;
                    for (j = 0; j < num_entries; j++) {
                        fprintf(fp, "%s %s\n", entries[j].name, entries[j].phone);
                    }
                    fclose(fp);
                }
                break;

            case '5':
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}