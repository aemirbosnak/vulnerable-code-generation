//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_PW_LENGTH 20

void view_passwords(char *filename);
void add_password(char *filename);
int check_password_strength(char *password);
void encrypt_password(char *password, int key);
void decrypt_password(char *password, int key);
void generate_password(char *password);

int main()
{
    char choice;
    char filename[MAX_LENGTH] = "passwords.txt";

    do {
        printf("\n\nPassword Management Menu\n\n");
        printf("1. View passwords\n");
        printf("2. Add password\n");
        printf("3. Generate Strong Password\n");
        printf("4. Exit\n\n");
        printf("Enter your choice (1/2/3/4): ");

        scanf("%c", &choice);
        getchar();

        switch (choice) {
            case '1':
                view_passwords(filename);
                break;
            case '2':
                add_password(filename);
                break;
            case '3':
                generate_password(NULL);
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    } while (choice != '4');

    return 0;
}

void view_passwords(char *filename)
{
    FILE *fp = fopen(filename, "r");
    char line[MAX_PW_LENGTH];

    if (fp == NULL) {
        printf("\nError: File %s not found.\n", filename);
        return;
    }

    printf("\nPasswords:\n\n");
    while (fgets(line, MAX_PW_LENGTH, fp) != NULL) {
        printf("%s\n", line);
    }

    fclose(fp);
}

void add_password(char *filename)
{
    char password[MAX_PW_LENGTH];
    int strength;
    int key = 5; // Key for encryption

    printf("\nEnter your password: ");
    fgets(password, MAX_PW_LENGTH, stdin);

    // Remove trailing newline character
    password[strcspn(password, "\n")] = 0;

    strength = check_password_strength(password);
    if (strength < 3) {
        printf("\nPassword is not strong enough. Please try again.\n");
        return;
    }

    encrypt_password(password, key);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("\nError: Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(fp, "%s\n", password);
    fclose(fp);

    printf("\nPassword added successfully!\n");
}

int check_password_strength(char *password)
{
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_number = 1;
        } else {
            has_special = 1;
        }
    }

    return has_uppercase + has_lowercase + has_number + has_special;
}

void encrypt_password(char *password, int key)
{
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        password[i] += key;
    }
}

void decrypt_password(char *password, int key)
{
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        password[i] -= key;
    }
}

void generate_password(char *password)
{
    if (password == NULL) {
        password = malloc((MAX_PW_LENGTH + 1) * sizeof(char));
    }

    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=";

    int num_uppercase = rand() % 4 + 1;
    int num_lowercase = rand() % 4 + 1;
    int num_numbers = rand() % 4 + 1;
    int num_symbols = rand() % 4 + 1;

    int length = num_uppercase + num_lowercase + num_numbers + num_symbols;

    for (int i = 0; i < length; i++) {
        if (num_uppercase > 0) {
            password[i] = uppercase_letters[rand() % strlen(uppercase_letters)];
            num_uppercase--;
        } else if (num_lowercase > 0) {
            password[i] = lowercase_letters[rand() % strlen(lowercase_letters)];
            num_lowercase--;
        } else if (num_numbers > 0) {
            password[i] = numbers[rand() % strlen(numbers)];
            num_numbers--;
        } else if (num_symbols > 0) {
            password[i] = symbols[rand() % strlen(symbols)];
            num_symbols--;
        }
    }

    password[length] = '\0';

    printf("\nYour generated password is: %s\n", password);
}