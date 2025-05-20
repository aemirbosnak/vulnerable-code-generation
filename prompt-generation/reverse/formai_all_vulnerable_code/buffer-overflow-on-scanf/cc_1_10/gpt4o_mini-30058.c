//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUOTES 100
#define MAX_LENGTH 256
#define QUOTE_FILE "quotes.txt"

void addQuote();
void displayQuotes();
void surpriseQuote();

int main() {
    int choice;

    while (1) {
        printf("\n--- Surprise Quote Manager ---\n");
        printf("1. Add a new quote\n");
        printf("2. Display all quotes\n");
        printf("3. Get a surprise quote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); //consume newline character left by scanf

        switch (choice) {
            case 1:
                addQuote();
                break;
            case 2:
                displayQuotes();
                break;
            case 3:
                surpriseQuote();
                break;
            case 4:
                printf("Goodbye! Stay inspired!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addQuote() {
    FILE *file = fopen(QUOTE_FILE, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char quote[MAX_LENGTH];
    printf("Enter your quote (up to 255 characters): ");
    fgets(quote, MAX_LENGTH, stdin);
    quote[strcspn(quote, "\n")] = 0; // removes the newline character

    fprintf(file, "%s\n", quote);
    fclose(file);
    printf("Your quote has been added!\n");
}

void displayQuotes() {
    FILE *file = fopen(QUOTE_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char quote[MAX_LENGTH];
    printf("\n--- All Quotes ---\n");
    while (fgets(quote, MAX_LENGTH, file) != NULL) {
        printf("-> %s", quote);
    }
    fclose(file);
}

void surpriseQuote() {
    FILE *file = fopen(QUOTE_FILE, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    srand(time(0));
    int totalQuotes = 0;
    char quotes[MAX_QUOTES][MAX_LENGTH];

    // Read quotes into memory
    while (fgets(quotes[totalQuotes], MAX_LENGTH, file) != NULL) {
        quotes[totalQuotes][strcspn(quotes[totalQuotes], "\n")] = 0; // Clean \n
        totalQuotes++;
    }
    fclose(file);

    if (totalQuotes == 0) {
        printf("No quotes available for surprise!\n");
        return;
    }

    int randomIndex = rand() % totalQuotes;
    printf("Surprise Quote: %s\n", quotes[randomIndex]);
}