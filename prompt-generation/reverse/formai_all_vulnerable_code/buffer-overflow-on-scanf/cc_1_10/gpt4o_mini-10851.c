//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LETTERS 100
#define MAX_LENGTH 256

typedef struct {
    char sender[MAX_LENGTH];
    char receiver[MAX_LENGTH];
    char content[MAX_LENGTH];
} LoveLetter;

typedef struct {
    LoveLetter letters[MAX_LETTERS];
    int count;
} LoveDatabase;

void initializeDatabase(LoveDatabase *db) {
    db->count = 0;
}

void addLetter(LoveDatabase *db, const char *sender, const char *receiver, const char *content) {
    if (db->count < MAX_LETTERS) {
        snprintf(db->letters[db->count].sender, MAX_LENGTH, "%s", sender);
        snprintf(db->letters[db->count].receiver, MAX_LENGTH, "%s", receiver);
        snprintf(db->letters[db->count].content, MAX_LENGTH, "%s", content);
        db->count++;
        printf("A love letter has been crafted!\n");
    } else {
        printf("Oh no! The love letter database is full!\n");
    }
}

void viewLetters(LoveDatabase *db) {
    if (db->count == 0) {
        printf("No love letters have been written yet.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        printf("Love Letter %d:\n", i + 1);
        printf("From: %s\n", db->letters[i].sender);
        printf("To: %s\n", db->letters[i].receiver);
        printf("Content: %s\n\n", db->letters[i].content);
    }
}

void searchBySender(LoveDatabase *db, const char *sender) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->letters[i].sender, sender) == 0) {
            printf("Found a love letter from %s to %s:\n", db->letters[i].sender, db->letters[i].receiver);
            printf("Content: %s\n\n", db->letters[i].content);
            found = 1;
        }
    }
    if (!found) {
        printf("No letters found from %s.\n", sender);
    }
}

void romanticMenu() {
    printf("Welcome to the Love Letter Database!\n");
    printf("Let your emotions flow as you cherish the letters of love.\n\n");
}

int main() {
    LoveDatabase db;
    initializeDatabase(&db);
    
    romanticMenu();

    int choice;
    while (1) {
        printf("Choose an action:\n");
        printf("1. Write a love letter\n");
        printf("2. View all love letters\n");
        printf("3. Search love letters by sender\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline after scanf

        if (choice == 1) {
            char sender[MAX_LENGTH];
            char receiver[MAX_LENGTH];
            char content[MAX_LENGTH];
            printf("Enter sender's name: ");
            fgets(sender, MAX_LENGTH, stdin);
            sender[strcspn(sender, "\n")] = 0; // Remove trailing newline
            printf("Enter receiver's name: ");
            fgets(receiver, MAX_LENGTH, stdin);
            receiver[strcspn(receiver, "\n")] = 0; // Remove trailing newline
            printf("Write your love letter:\n");
            fgets(content, MAX_LENGTH, stdin);
            content[strcspn(content, "\n")] = 0; // Remove trailing newline
            addLetter(&db, sender, receiver, content);
        } else if (choice == 2) {
            viewLetters(&db);
        } else if (choice == 3) {
            char sender[MAX_LENGTH];
            printf("Enter the sender's name to search: ");
            fgets(sender, MAX_LENGTH, stdin);
            sender[strcspn(sender, "\n")] = 0; // Remove trailing newline
            searchBySender(&db, sender);
        } else if (choice == 4) {
            printf("Farewell, until love brings us together again!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}