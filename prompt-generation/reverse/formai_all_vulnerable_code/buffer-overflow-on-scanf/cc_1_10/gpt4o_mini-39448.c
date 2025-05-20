//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maximum size for each quote
#define MAX_QUOTE_SIZE 256
// Maximum number of quotes
#define MAX_QUOTES 100

void createQuoteFile();
void addQuote(const char *quote);
void displayQuotes();
void getRandomQuote();

int main() {
    int choice;

    printf("Welcome to the Wisdom Quotes Vault\n");
    printf("1. Add a quote\n");
    printf("2. Display all quotes\n");
    printf("3. Get a random quote\n");
    printf("4. Exit\n");

    // Create the file if it doesn't exist
    createQuoteFile();

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To capture newline from previous input

        switch (choice) {
            case 1: {
                char quote[MAX_QUOTE_SIZE];
                printf("Enter your quote: ");
                fgets(quote, MAX_QUOTE_SIZE, stdin);
                // Remove newline character at the end
                quote[strcspn(quote, "\n")] = 0;
                addQuote(quote);
                break;
            }
            case 2:
                displayQuotes();
                break;
            case 3:
                getRandomQuote();
                break;
            case 4:
                printf("Exiting the Wisdom Quotes Vault. Keep spreading wisdom!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void createQuoteFile() {
    FILE *file = fopen("wisdom_quotes.txt", "a"); // Open for appending
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fclose(file); // Close file immediately
}

void addQuote(const char *quote) {
    FILE *file = fopen("wisdom_quotes.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", quote);
    fclose(file);
    printf("Your quote has been added to the vault!\n");
}

void displayQuotes() {
    FILE *file = fopen("wisdom_quotes.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char quote[MAX_QUOTE_SIZE];
    printf("\n--- Wisdom Quotes ---\n");
    while (fgets(quote, sizeof(quote), file)) {
        printf("%s", quote);
    }
    fclose(file);
}

void getRandomQuote() {
    FILE *file = fopen("wisdom_quotes.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char quotes[MAX_QUOTES][MAX_QUOTE_SIZE];
    int count = 0;

    // Read all quotes into memory
    while (fgets(quotes[count], sizeof(quotes[count]), file) && count < MAX_QUOTES) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No quotes found in the vault!\n");
        return;
    }

    // Seed the random number generator and pick a random quote
    srand(time(NULL));
    int randomIndex = rand() % count;
    printf("\n--- Random Wisdom Quote ---\n%s\n", quotes[randomIndex]);
}