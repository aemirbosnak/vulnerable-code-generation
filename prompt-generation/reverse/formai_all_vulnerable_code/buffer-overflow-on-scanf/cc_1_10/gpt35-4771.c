//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include<stdio.h>
#include<string.h>

void clearInput() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    char name[20], password[20];
    int age;

    printf("Welcome to Retro-Style Input Sanitizer!\n");

    // Get Name
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    // Get Age
    printf("What is your age? ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid Input! Please enter numerical value only.\n");
        clearInput(); // Clear Input Buffer
        return 0;
    }
    clearInput();

    // Get Password
    printf("Enter password (maximum 10 characters): ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    // Sanitize Password
    if (strlen(password) > 10) {
        printf("Invalid Input! Password should not exceed 10 characters!\n");
        return 0;
    }
    for (int i=0; i<strlen(password); i++) {
        if (password[i] == '\\' || password[i] == '\'' || password[i] == '\"') {
            printf("Invalid Input! Password should not contain backslash or quotes character!\n");
            return 0;
        }
    }

    // Valid Input
    printf("\nHello, %s!\n", name);
    printf("Your age is %d.\n", age);
    printf("Your password is %s.\n", password);

    return 0;
}