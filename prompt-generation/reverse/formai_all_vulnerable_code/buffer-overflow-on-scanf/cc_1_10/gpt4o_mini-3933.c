//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define NUM_OF_PASSWORDS 5

const char *upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *lower_case = "abcdefghijklmnopqrstuvwxyz";
const char *numbers = "0123456789";
const char *special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

void generate_password(char *password) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Ensure the password contains at least one character of each type
    password[0] = upper_case[rand() % strlen(upper_case)];
    password[1] = lower_case[rand() % strlen(lower_case)];
    password[2] = numbers[rand() % strlen(numbers)];
    password[3] = special_chars[rand() % strlen(special_chars)];

    // Fill the rest of the password with random characters from all categories
    const char *all_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        password[i] = all_chars[rand() % strlen(all_chars)];
    }

    // Shuffle the password to avoid any predictable patterns
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string
    password[PASSWORD_LENGTH] = '\0';
}

void print_passwords(int count) {
    printf("\nGenerated Passwords:\n");
    for (int i = 0; i < count; i++) {
        char password[PASSWORD_LENGTH + 1]; // +1 for null-terminator
        generate_password(password);
        printf("%s\n", password);
    }
}

void save_passwords_to_file(int count) {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        char password[PASSWORD_LENGTH + 1]; // +1 for null-terminator
        generate_password(password);
        fprintf(file, "%s\n", password);
    }

    fclose(file);
    printf("Generated passwords saved to 'passwords.txt'.\n");
}

int main() {
    int choice;
    printf("Secure Password Generator\n");
    printf("-------------------------\n");
    printf("1. Generate Passwords\n");
    printf("2. Save Passwords to File\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_passwords(NUM_OF_PASSWORDS);
                break;
            case 2:
                save_passwords_to_file(NUM_OF_PASSWORDS);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}