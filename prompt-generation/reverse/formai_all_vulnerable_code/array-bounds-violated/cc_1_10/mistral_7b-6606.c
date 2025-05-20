//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRY 100

typedef struct {
    char name[30];
    char phone[15];
    int status;
} Entry;

Entry phonebook[MAX_ENTRY];
int count = 0;

void displayMenu() {
    printf("\n-------------------\n");
    printf("| Phonebook Menu   |\n");
    printf("-------------------\n");
    printf("| 1. Add Entry    |\n");
    printf("| 2. Edit Entry   |\n");
    printf("| 3. Delete Entry |\n");
    printf("| 4. Search Entry |\n");
    printf("| 5. Exit        |\n");
    printf("-------------------\n");
}

void addEntry() {
    if (count >= MAX_ENTRY) {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter Name: ");
    fgets(phonebook[count].name, sizeof(phonebook[count].name), stdin);
    phonebook[count].name[strlen(phonebook[count].name) - 1] = '\0';

    printf("Enter Phone: ");
    fgets(phonebook[count].phone, sizeof(phonebook[count].phone), stdin);
    phonebook[count].phone[strlen(phonebook[count].phone) - 1] = '\0';

    phonebook[count].status = 1;
    count++;
}

void editEntry() {
    int index;
    printf("Enter index: ");
    scanf("%d", &index);

    if (index >= 0 && index < count) {
        printf("Enter New Name: ");
        fgets(phonebook[index].name, sizeof(phonebook[index].name), stdin);
        phonebook[index].name[strlen(phonebook[index].name) - 1] = '\0';

        printf("Enter New Phone: ");
        fgets(phonebook[index].phone, sizeof(phonebook[index].phone), stdin);
        phonebook[index].phone[strlen(phonebook[index].phone) - 1] = '\0';

        printf("Entry updated.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void deleteEntry() {
    int index;
    printf("Enter index: ");
    scanf("%d", &index);

    if (index >= 0 && index < count) {
        phonebook[index].status = 0;
        printf("Entry deleted.\n");
    } else {
        printf("Invalid index.\n");
    }
}

void searchEntry() {
    char name[30];
    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0 && phonebook[i].status == 1) {
            printf("Name: %s, Phone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Name not found.\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                editEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                searchEntry();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}