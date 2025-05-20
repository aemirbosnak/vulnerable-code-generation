//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
    char name[50];
    char number[15];
};

void addEntry(struct PhoneBook *pb, char *name, char *number) {
    if (strlen(name) > 0 && strlen(number) > 0) {
        pb->name[0] = '\0';
        strcpy(pb->name, name);
        pb->number[0] = '\0';
        strcpy(pb->number, number);
        printf("Entry added successfully.\n");
    } else {
        printf("Invalid entry.\n");
    }
}

void displayEntries(struct PhoneBook *pb) {
    printf("Name\tNumber\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\t%s\n", pb[i].name, pb[i].number);
    }
}

int main() {
    struct PhoneBook entries[10];

    printf("Welcome to the Mind-Bending Phone Book!\n");

    while (1) {
        printf("Enter 'A' to add an entry:\n");
        char choice;
        scanf("%c", &choice);

        if (choice == 'A') {
            printf("Enter the name:\n");
            char name[50];
            scanf("%s", name);

            printf("Enter the phone number:\n");
            char number[15];
            scanf("%s", number);

            addEntry(entries, name, number);
        } else if (choice == 'D') {
            displayEntries(entries);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}