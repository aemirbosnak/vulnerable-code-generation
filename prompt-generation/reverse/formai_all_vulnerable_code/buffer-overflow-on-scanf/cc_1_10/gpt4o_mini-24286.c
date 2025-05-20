//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUOTES 100
#define MAX_LENGTH 256

void writeQuotesToFile(FILE *file, char quotes[MAX_QUOTES][MAX_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", quotes[i]);
    }
    printf("🎉 Your fantastic quotes have been written to the file! 🎉\n");
}

void readQuotesFromFile(FILE *file) {
    char quote[MAX_LENGTH];
    printf("\n📜 Here are the quotes from your file:\n");
    while (fgets(quote, sizeof(quote), file) != NULL) {
        printf("✨ %s", quote);
    }
    printf("🚀 That's a wonderful collection of wisdom! 🚀\n");
}

int main() {
    char quotes[MAX_QUOTES][MAX_LENGTH];
    int quoteCount = 0;
    char filename[50];
    FILE *file;

    // Get file name from user
    printf("🎈 Welcome to the Quote Manager! 🎈\n");
    printf("Please enter the filename to save your quotes (e.g., quotes.txt): ");
    scanf("%s", filename);

    // Open file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "😱 Error opening file for writing!\n");
        exit(1);
    }

    // Get quotes from user
    printf("📖 Please enter your quotes (type 'exit' to finish):\n");
    while (quoteCount < MAX_QUOTES) {
        printf("Quote %d: ", quoteCount + 1);
        getchar();  // To consume the newline character from previous input
        fgets(quotes[quoteCount], MAX_LENGTH, stdin);
        // Remove the newline character
        quotes[quoteCount][strcspn(quotes[quoteCount], "\n")] = 0;

        // Check for exit condition
        if (strcmp(quotes[quoteCount], "exit") == 0) {
            break;
        }
        quoteCount++;
    }

    // Write quotes to file
    writeQuotesToFile(file, quotes, quoteCount);
    fclose(file); // Close the file after writing

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "😱 Error opening file for reading!\n");
        exit(1);
    }

    // Read quotes from file
    readQuotesFromFile(file);
    fclose(file); // Close the file after reading

    // End of the program
    printf("Thank you for using Quote Manager! Goodbye! 👋🏼\n");
    return 0;
}