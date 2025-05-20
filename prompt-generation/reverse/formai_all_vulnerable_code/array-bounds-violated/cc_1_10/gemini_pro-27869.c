//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of spam words and emails
#define MAX_SPAM_WORDS 1000
#define MAX_EMAILS 10000

// Define the structure of a spam word
typedef struct {
    char *word;
    int count;
} SpamWord;

// Define the structure of an email
typedef struct {
    char *subject;
    char *body;
    int is_spam;
} Email;

// Create the global arrays of spam words and emails
SpamWord spam_words[MAX_SPAM_WORDS];
Email emails[MAX_EMAILS];

// Initialize the global variables
int num_spam_words = 0;
int num_emails = 0;

// Load the spam words from a file
void load_spam_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening spam words file");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Allocate memory for the spam word
        SpamWord *spam_word = malloc(sizeof(SpamWord));
        if (spam_word == NULL) {
            perror("Error allocating memory for spam word");
            exit(1);
        }

        // Copy the spam word into the structure
        spam_word->word = strdup(line);
        if (spam_word->word == NULL) {
            perror("Error copying spam word");
            exit(1);
        }

        // Set the spam word count to 0
        spam_word->count = 0;

        // Add the spam word to the array
        spam_words[num_spam_words++] = *spam_word;
    }

    fclose(file);
}

// Load the emails from a file
void load_emails(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening emails file");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Allocate memory for the email
        Email *email = malloc(sizeof(Email));
        if (email == NULL) {
            perror("Error allocating memory for email");
            exit(1);
        }

        // Parse the email subject and body
        char *subject = strtok(line, "\t");
        char *body = strtok(NULL, "\t");

        // Copy the email subject and body into the structure
        email->subject = strdup(subject);
        if (email->subject == NULL) {
            perror("Error copying email subject");
            exit(1);
        }

        email->body = strdup(body);
        if (email->body == NULL) {
            perror("Error copying email body");
            exit(1);
        }

        // Set the email is_spam flag to 0
        email->is_spam = 0;

        // Add the email to the array
        emails[num_emails++] = *email;
    }

    fclose(file);
}

// Check if an email is spam
int is_spam(Email *email) {
    // Count the number of spam words in the email
    int num_spam_words_in_email = 0;
    for (int i = 0; i < num_spam_words; i++) {
        if (strstr(email->subject, spam_words[i].word) != NULL || strstr(email->body, spam_words[i].word) != NULL) {
            num_spam_words_in_email++;
        }
    }

    // If the number of spam words in the email is greater than 0, then the email is spam
    if (num_spam_words_in_email > 0) {
        return 1;
    } else {
        return 0;
    }
}

// Print the results of the spam detection system
void print_results() {
    // Print the number of emails that were classified as spam
    int num_spam_emails = 0;
    for (int i = 0; i < num_emails; i++) {
        if (emails[i].is_spam) {
            num_spam_emails++;
        }
    }

    printf("Number of emails classified as spam: %d\n", num_spam_emails);

    // Print the list of spam words and their counts
    printf("Spam words and their counts:\n");
    for (int i = 0; i < num_spam_words; i++) {
        printf("%s: %d\n", spam_words[i].word, spam_words[i].count);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 3) {
        printf("Usage: %s <spam words file> <emails file>\n", argv[0]);
        exit(1);
    }

    // Load the spam words from the file
    load_spam_words(argv[1]);

    // Load the emails from the file
    load_emails(argv[2]);

    // Check each email for spam
    for (int i = 0; i < num_emails; i++) {
        emails[i].is_spam = is_spam(&emails[i]);
    }

    // Print the results of the spam detection system
    print_results();

    return 0;
}