//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct database_entry {
    int id;
    char name[30];
    char address[50];
    float salary;
};

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct database_entry database[100];
    int num_entries = 0;
    char operation[10];

    while (1) {
        printf("\nEnter operation (ADD/REMOVE/SEARCH/DISPLAY/EXIT): ");
        scanf("%s", operation);

        if (strcmp(operation, "ADD") == 0) {
            flush_input();
            struct database_entry entry;
            printf("\nEnter ID: ");
            scanf("%d", &entry.id);
            flush_input();

            printf("\nEnter Name: ");
            fgets(entry.name, 30, stdin);
            entry.name[strcspn(entry.name, "\n")] = 0;

            printf("\nEnter Address: ");
            fgets(entry.address, 50, stdin);
            entry.address[strcspn(entry.address, "\n")] = 0;

            printf("\nEnter Salary: ");
            scanf("%f", &entry.salary);

            database[num_entries] = entry;
            num_entries++;
        } else if (strcmp(operation, "REMOVE") == 0) {
            int id_to_remove;
            printf("\nEnter ID to remove: ");
            scanf("%d", &id_to_remove);

            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (database[i].id == id_to_remove) {
                    found = 1;
                    for (int j = i; j < num_entries - 1; j++) {
                        database[j] = database[j + 1];
                    }
                    num_entries--;
                    printf("\nEntry with ID %d removed.", id_to_remove);
                    break;
                }
            }

            if (!found) {
                printf("\nEntry with ID %d not found.", id_to_remove);
            }
        } else if (strcmp(operation, "SEARCH") == 0) {
            int id_to_search;
            printf("\nEnter ID to search: ");
            scanf("%d", &id_to_search);

            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (database[i].id == id_to_search) {
                    found = 1;
                    printf("\nID: %d\nName: %s\nAddress: %s\nSalary: %.2f",
                           database[i].id, database[i].name, database[i].address, database[i].salary);
                    break;
                }
            }

            if (!found) {
                printf("\nEntry with ID %d not found.", id_to_search);
            }
        } else if (strcmp(operation, "DISPLAY") == 0) {
            printf("\nTotal Number of Entries: %d", num_entries);
            printf("\n------------------------------------------\n");
            for (int i = 0; i < num_entries; i++) {
                printf("\nID: %d\nName: %s\nAddress: %s\nSalary: %.2f",
                       database[i].id, database[i].name, database[i].address, database[i].salary);
                printf("\n------------------------------------------\n");
            }
        } else if (strcmp(operation, "EXIT") == 0) {
            printf("\nExiting Database...");
            exit(0);
        } else {
            printf("\nInvalid Operation. Please try again.");
        }
    }
    return 0;
}