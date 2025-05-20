//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 256

void writeLoveLetter(const char *filename);
void readLoveLetter(const char *filename);
void romanticDelight();

int main() {
    romanticDelight();
    return 0;
}

void romanticDelight() {
    printf("Welcome to the realm of eternal love!\n");
    printf("Let us weave our love stories through words written upon paper.\n");

    const char *filename = "love_letter.txt";
    int choice;

    do {
        printf("\nChoose an action:\n");
        printf("1. Write a love letter\n");
        printf("2. Read the love letter\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after entering the choice

        switch (choice) {
            case 1:
                writeLoveLetter(filename);
                break;
            case 2:
                readLoveLetter(filename);
                break;
            case 3:
                printf("Love is a journey that never ends. Farewell, dear heart!\n");
                break;
            default:
                printf("Invalid choice! Let the heart guide you to the right path.\n");
        }
    } while (choice != 3);
}

void writeLoveLetter(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Oh no! I could not open the file to pour my heart out.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("To whom do you wish to express your love? (Name): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character

    printf("Now, write your heartfelt message:\n");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove the newline character

    fprintf(file, "Dear %s,\n", name);
    fprintf(file, "%s\n", message);
    fprintf(file, "With endless love,\nYour Heart\n\n");
    
    fclose(file);
    printf("Your love letter has been inscribed in the pages of eternity.\n");
}

void readLoveLetter(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Oh darling! It seems the letter we cherish is lost in the void.\n");
        return;
    }

    char line[MAX_MESSAGE_LENGTH];
    printf("Here is your love letter:\n\n");
    
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    
    fclose(file);
    printf("\nThe sweet echoes of your words linger in the air, forever cherished.\n");
}