//FormAI DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_ENTRIES 100

struct EmailEntry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int menu() {
    int option;

    printf("====== Mailing List Manager ======\n");
    printf("1. Add email\n");
    printf("2. View mailing list\n");
    printf("3. Save mailing list to file\n");
    printf("4. Load mailing list from file\n");
    printf("5. Exit\n");

    printf("Enter option: ");
    scanf("%d", &option);

    return option;
}

bool isValidEmail(char *email) {
    // Dummy email validation function, change as needed
    return true;
}

bool addEmail(struct EmailEntry *mailingList, int *mailingCount) {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter email: ");
    scanf("%s", email);

    if (!isValidEmail(email)) {
        printf("Invalid email\n");
        return false;
    }

    struct EmailEntry entry;
    strcpy(entry.name, name);
    strcpy(entry.email, email);

    mailingList[(*mailingCount)++] = entry;

    printf("Email added successfully\n");

    return true;
}

void viewMailingList(struct EmailEntry *mailingList, int *mailingCount) {
    printf("====== Mailing List ======\n");
    for (int i = 0; i < *mailingCount; i++) {
        printf("%s - %s\n", mailingList[i].name, mailingList[i].email);
    }
}

bool saveMailingList(struct EmailEntry *mailingList, int *mailingCount, char *filename) {
    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Unable to open file\n");
        return false;
    }

    for (int i = 0; i < *mailingCount; i++) {
        fprintf(file, "%s,%s\n", mailingList[i].name, mailingList[i].email);
    }

    fclose(file);

    printf("Mailing list saved to %s\n", filename);

    return true;
}

bool loadMailingList(struct EmailEntry *mailingList, int *mailingCount, char *filename) {
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Unable to open file\n");
        return false;
    }

    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");

        if (!name || !email) {
            printf("Error parsing line\n");
            return false;
        }

        struct EmailEntry entry;
        strcpy(entry.name, name);
        strcpy(entry.email, email);

        mailingList[(*mailingCount)++] = entry;
    }

    fclose(file);

    printf("Mailing list loaded from %s\n", filename);

    return true;
}

void clearScreen() {
    system("cls" /* on Windows */);
    system("clear" /* on Linux, macOS */);
}

int main() {
    struct EmailEntry *mailingList = malloc(MAX_ENTRIES * sizeof(struct EmailEntry));
    int mailingCount = 0;

    while (true) {
        int option = menu();

        clearScreen();

        switch (option) {
            case 1:
                addEmail(mailingList, &mailingCount);
                break;
            case 2:
                viewMailingList(mailingList, &mailingCount);
                break;
            case 3:
                saveMailingList(mailingList, &mailingCount, "mailinglist.csv");
                break;
            case 4:
                loadMailingList(mailingList, &mailingCount, "mailinglist.csv");
                break;
            case 5:
                free(mailingList);
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }
}