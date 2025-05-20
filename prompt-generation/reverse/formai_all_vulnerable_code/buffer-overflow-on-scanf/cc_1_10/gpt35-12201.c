//FormAI DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum size for the buffer
#define MAX_BUFFER_SIZE 1024

// define the email structure
typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[MAX_BUFFER_SIZE];
} Email;

// function to read an email from the standard input
void read_email(Email *email) {
    printf("Enter sender email address: ");
    scanf("%s", email->sender);
    printf("Enter recipient email address: ");
    scanf("%s", email->recipient);
    getchar(); // consume the newline character
    printf("Enter the subject of the email: ");
    fgets(email->subject, sizeof(email->subject), stdin);
    printf("Enter the body of the email: ");
    fgets(email->body, sizeof(email->body), stdin);
}

// function to write an email to a file
void write_email_to_file(const Email *email, const char *filename) {
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    fprintf(fp, "Sender: %s\nRecipient: %s\nSubject: %s\nBody:\n%s\n", 
            email->sender, email->recipient, email->subject, email->body);
    fclose(fp);
}

// function to display the contents of a file
void display_file_contents(const char *filename) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
}

int main() {
    Email email;
    char filename[50];
    char display_choice;
    
    printf("Welcome to the C Email Client Program!\n");
    printf("Please enter the name of the file you wish to store your emails in: ");
    scanf("%s", filename);
    
    read_email(&email);
    write_email_to_file(&email, filename);
    
    printf("Email successfully stored in file!\n");
    printf("Would you like to display the contents of the file? (y/n): ");
    scanf(" %c", &display_choice);
    
    if (display_choice == 'y') {
        printf("Displaying contents of file...\n");
        display_file_contents(filename);
    } else {
        printf("Exiting program...\n");
    }
    
    return 0;
}