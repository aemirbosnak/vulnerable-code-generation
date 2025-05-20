//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define SPAM_THRESHOLD 5

// Function to count keywords in a message
int count_keywords(const char *message, const char **keywords, int num_keywords) {
    int count = 0;
    for (int i = 0; i < num_keywords; i++) {
        const char *pos = message;
        while ((pos = strstr(pos, keywords[i])) != NULL) {
            count++;
            pos += strlen(keywords[i]);
        }
    }
    return count;
}

// Function to determine if the message is spam
bool is_spam(const char *message, const char **keywords, int num_keywords) {
    int keyword_count = count_keywords(message, keywords, num_keywords);
    return keyword_count >= SPAM_THRESHOLD;
}

// Function to read messages from a file
void read_messages(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    const char *spam_keywords[] = {
        "free", 
        "click", 
        "subscribe", 
        "prize", 
        "offer"
    };
    int num_keywords = sizeof(spam_keywords) / sizeof(spam_keywords[0]);

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        if (is_spam(buffer, spam_keywords, num_keywords)) {
            printf("Spam detected: %s\n", buffer);
        } else {
            printf("Not Spam: %s\n", buffer);
        }
    }

    fclose(file);
}

// Function to add a message to the log file
void add_message(const char *filename, const char *message) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char filename[100];
    printf("Enter the filename to read messages from: ");
    scanf("%s", filename);

    read_messages(filename);

    char message[BUFFER_SIZE];
    printf("Enter a message to save to log (type 'exit' to quit): ");
    
    while (true) {
        fgets(message, BUFFER_SIZE, stdin); // fetch new line after scanf
        fgets(message, BUFFER_SIZE, stdin); // read again for message input
        
        // Remove newline character
        message[strcspn(message, "\n")] = 0;

        if (strcmp(message, "exit") == 0) {
            break;
        }

        add_message(filename, message);
        printf("Message saved: %s\n", message);
    }

    return 0;
}