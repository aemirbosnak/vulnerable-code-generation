//FormAI DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

// Struct representing an email
typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char sender[MAX_SUBJECT_LEN];
    char recipients[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

// Function to create a new email
Email *create_email(char *subject, char *sender, char *recipients, char *body) {
    Email *email = malloc(sizeof(Email));
    if (email == NULL) {
        printf("Failed to allocate memory for email\n");
        return NULL;
    }

    strncpy(email->subject, subject, MAX_SUBJECT_LEN);
    strncpy(email->sender, sender, MAX_SUBJECT_LEN);
    strncpy(email->recipients, recipients, MAX_SUBJECT_LEN);
    strncpy(email->body, body, MAX_BODY_LEN);

    return email;
}

// Function to print an email
void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("Sender: %s\n", email->sender);
    printf("Recipients: %s\n", email->recipients);
    printf("Body: %s\n", email->body);
}

// Function to read in a new email from the user
Email *read_email() {
    char subject[MAX_SUBJECT_LEN];
    char sender[MAX_SUBJECT_LEN];
    char recipients[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];

    printf("Enter the subject of your email: ");
    fgets(subject, MAX_SUBJECT_LEN, stdin);
    printf("Enter your email address: ");
    fgets(sender, MAX_SUBJECT_LEN, stdin);
    printf("Enter the recipients of your email (comma-separated): ");
    fgets(recipients, MAX_SUBJECT_LEN, stdin);
    printf("Enter the body of your email: ");
    fgets(body, MAX_BODY_LEN, stdin);

    // Remove any \n characters at the end of the strings
    strtok(subject, "\n");
    strtok(sender, "\n");
    strtok(recipients, "\n");
    strtok(body, "\n");

    return create_email(subject, sender, recipients, body);
}

// Function to save an email to a file
void save_email(Email *email, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    fprintf(file, "Subject: %s\n", email->subject);
    fprintf(file, "Sender: %s\n", email->sender);
    fprintf(file, "Recipients: %s\n", email->recipients);
    fprintf(file, "Body: %s\n", email->body);

    fclose(file);
}

// Function to load an email from a file
Email *load_email(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return NULL;
    }

    char subject[MAX_SUBJECT_LEN];
    char sender[MAX_SUBJECT_LEN];
    char recipients[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];

    while (!feof(file)) {
        char line[MAX_SUBJECT_LEN + MAX_BODY_LEN];
        fgets(line, MAX_SUBJECT_LEN + MAX_BODY_LEN, file);
        char *colon_pos = strchr(line, ':');
        if (colon_pos == NULL) {
            continue;
        }
        char *value = colon_pos + 2;
        if (strncmp(line, "Subject", strlen("Subject")) == 0) {
            strncpy(subject, value, MAX_SUBJECT_LEN);
        } else if (strncmp(line, "Sender", strlen("Sender")) == 0) {
            strncpy(sender, value, MAX_SUBJECT_LEN);
        } else if (strncmp(line, "Recipients", strlen("Recipients")) == 0) {
            strncpy(recipients, value, MAX_SUBJECT_LEN);
        } else if (strncmp(line, "Body", strlen("Body")) == 0) {
            strncpy(body, value, MAX_BODY_LEN);
        }
    }

    fclose(file);

    return create_email(subject, sender, recipients, body);
}

int main() {
    printf("Welcome to the C Email Client!\n");

    while (true) {
        printf("\nMenu Options:\n");
        printf("1. Compose a new email\n");
        printf("2. Load an existing email from file\n");
        printf("3. Save an email to a file\n");
        printf("4. Exit the program\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from input

        if (choice == 1) {
            Email *email = read_email();
            printf("\nYour email:\n");
            print_email(email);
            free(email);
        } else if (choice == 2) {
            char filename[MAX_SUBJECT_LEN];
            printf("Enter the name of the file to load the email from: ");
            fgets(filename, MAX_SUBJECT_LEN, stdin);
            strtok(filename, "\n"); // remove newline character at end of filename
            Email *email = load_email(filename);
            if (email != NULL) {
                printf("\nLoaded email:\n");
                print_email(email);
            }
            free(email);
        } else if (choice == 3) {
            Email *email = read_email();
            char filename[MAX_SUBJECT_LEN];
            printf("Enter the name of the file to save the email to: ");
            fgets(filename, MAX_SUBJECT_LEN, stdin);
            strtok(filename, "\n"); // remove newline character at end of filename
            save_email(email, filename);
            printf("\nEmail saved to file %s\n", filename);
            free(email);
        } else if (choice == 4) {
            printf("Exiting the program...\n");
            break;
        } else {
            printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}