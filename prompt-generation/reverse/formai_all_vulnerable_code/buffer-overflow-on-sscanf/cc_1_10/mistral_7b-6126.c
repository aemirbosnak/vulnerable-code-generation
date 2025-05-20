//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_MESSAGE_LENGTH 500
#define NUM_KEYWORDS 5

typedef struct {
    char subject[MAX_MESSAGE_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int is_spam;
} Email;

const char *keywords[NUM_KEYWORDS] = {
    "viagra", "cialis", "levitra", "priapism", "penis"
};

int contains_keyword(const char *message, int num_keywords, const char *keywords[]) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        size_t keyword_len = strlen(keywords[i]);
        size_t message_len = strlen(message);
        for (size_t j = 0; j < message_len - keyword_len + 1; j++) {
            if (strncmp(&message[j], keywords[i], keyword_len) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void process_email(const char *filename, Email *emails, int *num_emails) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[MAX_MESSAGE_LENGTH];
    int email_index = 0;
    while (fgets(line, sizeof(line), file)) {
        if (email_index >= MAX_EMAILS) {
            printf("Error: Too many emails in file\n");
            fclose(file);
            return;
        }

        Email *email = &emails[email_index];
        sscanf(line, "%s %s", email->subject, email->message);
        email->is_spam = contains_keyword(email->message, NUM_KEYWORDS, keywords);

        email_index++;
    }

    fclose(file);
    *num_emails = email_index;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Email emails[MAX_EMAILS];
    int num_emails;
    process_email(argv[1], emails, &num_emails);

    for (int i = 0; i < num_emails; i++) {
        printf("%s: %s (spam: %s)\n", emails[i].subject, emails[i].message,
            emails[i].is_spam ? "yes" : "no");
    }

    return 0;
}