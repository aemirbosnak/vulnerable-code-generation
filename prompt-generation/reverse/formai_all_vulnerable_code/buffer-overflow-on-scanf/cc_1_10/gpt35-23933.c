//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOWER_CASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPER_CASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define SPECIAL_CHARS "!@#$%^&*()_-+={}[]|;’:,.<>/?`~"
#define NUMBERS "0123456789"

char* generate_password(int length) {
    char* password = malloc(length + 1);
    if (!password) {
        perror("Memory allocation failed");
        exit(1);
    }

    char* all_chars = malloc(strlen(LOWER_CASE_CHARS) + strlen(UPPER_CASE_CHARS) + strlen(SPECIAL_CHARS) + strlen(NUMBERS) + 1);
    if (!all_chars) {
        perror("Memory allocation failed");
        exit(1);
    }

    strcpy(all_chars, LOWER_CASE_CHARS);
    strcat(all_chars, UPPER_CASE_CHARS);
    strcat(all_chars, SPECIAL_CHARS);
    strcat(all_chars, NUMBERS);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int random_index = rand() % strlen(all_chars);
        password[i] = all_chars[random_index];
    }

    password[length] = '\0';

    free(all_chars);

    return password;
}

int main() {
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    char* password = generate_password(length);

    printf("Generated password: %s\n", password);

    free(password);

    return 0;
}