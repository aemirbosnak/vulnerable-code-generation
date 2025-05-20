//FormAI DATASET v1.0 Category: Email Client ; Style: retro
#include <stdio.h>
#include <string.h>

void login(char username[], char password[]);
void menu(char username[]);
void readEmail(char username[]);
void writeEmail(char username[]);
void logout(char username[]);

int main() {
    char username[20], password[20];
    printf("Welcome to the Retro Email Client!\n");
    printf("Please enter your username and password:\n");
    login(username, password);
    menu(username);
    logout(username);

    return 0;
}

void login(char username[], char password[]) {
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
}

void menu(char username[]) {
    char choice;
    do {
        printf("\nWelcome, %s!\n", username);
        printf("What would you like to do?\n");
        printf("1. Read email\n");
        printf("2. Write email\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                readEmail(username);
                break;
            case '2':
                writeEmail(username);
                break;
            case '3':
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');
}

void readEmail(char username[]) {
    char filename[30];
    printf("Enter the filename of the email you want to read: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Email not found!\n");
    } else {
        printf("From: %s\nSubject: %s\n", strtok(filename, "_"), strtok(NULL, "_"));
        printf("------------------------------\n");
        char c;
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }
        printf("\n------------------------------\n");
        fclose(fp);
    }
}

void writeEmail(char username[]) {
    char recipient[20], subject[50], filename[30], line[100];
    printf("Enter the recipient's username: ");
    scanf("%s", recipient);
    printf("Enter the subject of your email: ");
    scanf(" %[^\n]", subject);
    printf("Enter your message (type 'end' on a new line to finish):\n");
    sprintf(filename, "%s_%s.txt", recipient, subject);
    FILE *fp = fopen(filename, "w");
    fputs(username, fp);
    fputc('\n', fp);
    fputs(subject, fp);
    fputc('\n', fp);
    do {
        fgets(line, 100, stdin);
        fputs(line, fp);
    } while (strncmp(line, "end\n", 4) != 0);
    fclose(fp);
    printf("Email sent!\n");
}

void logout(char username[]) {
    printf("Goodbye, %s!\n", username);
}