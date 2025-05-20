//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10
#define MAX_LENGTH 256

typedef struct {
    char recipient[MAX_LENGTH];
    char subject[MAX_LENGTH];
    char body[MAX_LENGTH * 2];
} Email;

void sendLoveLetter(Email email) {
    printf("\n💌 Sending Love Letter... 💌\n");
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("\nMy Dearest,\n\n");
    printf("%s\n", email.body);
    printf("\nForever Yours,\n");
    printf("----\n\n");
}

void composeEmail(Email *email) {
    printf("Who is the lucky recipient of your love? ");
    fgets(email->recipient, MAX_LENGTH, stdin);
    email->recipient[strcspn(email->recipient, "\n")] = 0; // Remove newline

    printf("What sweet subject will you give this letter? ");
    fgets(email->subject, MAX_LENGTH, stdin);
    email->subject[strcspn(email->subject, "\n")] = 0; // Remove newline

    printf("Write your heartfelt words below:\n");
    printf("Type 'END' when you want to finish your love letter.\n");
    
    char line[MAX_LENGTH];
    strcpy(email->body, "");  // Initialize body as empty

    while (1) {
        fgets(line, MAX_LENGTH, stdin);
        if (strncmp(line, "END", 3) == 0) {
            break;
        }
        strcat(email->body, line);
    }
}

int main() {
    Email loveLetters[MAX_MESSAGES];
    int count = 0;
    char choice;

    printf("💖 Welcome to the Romantic Email Client! 💖\n");

    while (count < MAX_MESSAGES) {
        printf("\nWould you like to compose a love letter? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume the newline character after scanf

        if (choice == 'y' || choice == 'Y') {
            composeEmail(&loveLetters[count]);
            sendLoveLetter(loveLetters[count]);
            count++;
        } else if (choice == 'n' || choice == 'N') {
            printf("Oh, I see. Love can be complicated. 💔\n");
            break;
        } else {
            printf("Aren't we full of surprises! Please choose 'y' or 'n'.\n");
        }
    }

    if (count > 0) {
        printf("\nYou have sent %d love letter(s) today!\n", count);
        printf("Each word shall linger in their heart, like a beautiful melody.\n");
    } else {
        printf("\nYour heart remains quiet... until we meet again. 🌹\n");
    }

    printf("Thank you for using our Romantic Email Client! Until next time...\n");
    return 0;
}