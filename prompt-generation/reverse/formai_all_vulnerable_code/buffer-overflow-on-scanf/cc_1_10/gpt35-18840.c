//FormAI DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD "p4ssw0rd"

struct DiaryEntry {
    char date[11];
    char content[1001];
    struct DiaryEntry *next;
};

void encrypt(char str[], int key);
void decrypt(char str[], int key);
void addEntry(struct DiaryEntry **head);
void viewEntries(struct DiaryEntry *head);
void deleteEntry(struct DiaryEntry **head);
void saveEntriesToFile(struct DiaryEntry *head);
void readEntriesFromFile(struct DiaryEntry **head);

int main() {
    struct DiaryEntry *head = NULL;
    char password[21], choice;

    printf("Enter password: ");
    scanf("%s", password);
    if (strcmp(password, PASSWORD) != 0) {
        encrypt(password, 5);
        printf("\nIncorrect password. Encrypted password: %s", password);
        exit(1);
    }

    readEntriesFromFile(&head);

    while (1) {
        printf("\n\nChoose an option:\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Save entries to file\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addEntry(&head);
                break;
            case '2':
                viewEntries(head);
                break;
            case '3':
                deleteEntry(&head);
                break;
            case '4':
                saveEntriesToFile(head);
                break;
            case '5':
                saveEntriesToFile(head);
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    }

    return 0;
}

void encrypt(char str[], int key) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] += key;
    }
}

void decrypt(char str[], int key) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] -= key;
    }
}

void addEntry(struct DiaryEntry **head) {
    char date[11], content[1001];
    struct DiaryEntry *newNode, *curr;

    newNode = malloc(sizeof(struct DiaryEntry));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.");
        return;
    }

    printf("Enter the date (in MM/DD/YYYY format): ");
    scanf("%s", date);
    printf("Enter the content:\n");
    scanf(" %[^\n]s", content);

    encrypt(date, 2);
    encrypt(content, 3);

    strcpy(newNode->date, date);
    strcpy(newNode->content, content);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Entry added successfully.");
        return;
    }

    curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;

    printf("Entry added successfully.");
}

void viewEntries(struct DiaryEntry *head) {
    struct DiaryEntry *curr = head;
    int count = 0;

    if (curr == NULL) {
        printf("No entries found.");
        return;
    }

    printf("\n\nDate       Content\n");
    printf("--------------------------------------\n");

    while (curr != NULL) {
        decrypt(curr->date, 2);
        decrypt(curr->content, 3);
        printf("%s  %s\n", curr->date, curr->content);
        encrypt(curr->date, 2);
        encrypt(curr->content, 3);
        curr = curr->next;
        count++;
    }

    printf("--------------------------------------\n");
    printf("Total entries: %d", count);
}

void deleteEntry(struct DiaryEntry **head) {
    char date[11];
    struct DiaryEntry *prev, *curr;

    if (*head == NULL) {
        printf("No entries found.");
        return;
    }

    printf("Enter the date of the entry to be deleted (in MM/DD/YYYY format): ");
    scanf("%s", date);

    encrypt(date, 2);

    prev = NULL;
    curr = *head;

    while (curr != NULL && strcmp(curr->date, date) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Entry not found.");
        return;
    }

    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);

    printf("Entry deleted successfully.");
}

void saveEntriesToFile(struct DiaryEntry *head) {
    struct DiaryEntry *curr;
    FILE *fptr;

    if (head == NULL) {
        printf("No entries found.");
        return;
    }

    fptr = fopen("diary.txt", "w");
    if (fptr == NULL) {
        printf("Error: File could not be opened.");
        return;
    }

    curr = head;
    while (curr != NULL) {
        decrypt(curr->date, 2);
        decrypt(curr->content, 3);
        fprintf(fptr, "%s|%s\n", curr->date, curr->content);
        encrypt(curr->date, 2);
        encrypt(curr->content, 3);
        curr = curr->next;
    }

    fclose(fptr);

    printf("Entries saved to file successfully.");
}

void readEntriesFromFile(struct DiaryEntry **head) {
    struct DiaryEntry *newNode, *curr;
    char date[11], content[1001], line[1012];
    FILE *fptr;

    fptr = fopen("diary.txt", "r");
    if (fptr == NULL) {
        printf("File does not exist or could not be opened.");
        return;
    }

    while (fgets(line, 1012, fptr) != NULL) {
        sscanf(line, "%[^|]|%[^\n]", date, content);

        encrypt(date, 2);
        encrypt(content, 3);

        newNode = malloc(sizeof(struct DiaryEntry));
        if (newNode == NULL) {
            printf("Error: Memory allocation failed.");
            return;
        }
        strcpy(newNode->date, date);
        strcpy(newNode->content, content);
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            curr = *head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }

        encrypt(date, 2);
        encrypt(content, 3);
    }

    fclose(fptr);
}