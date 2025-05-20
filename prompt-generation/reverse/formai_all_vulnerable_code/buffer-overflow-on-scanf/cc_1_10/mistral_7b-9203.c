//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK_THRESHOLD 3

typedef struct {
    int upper;
    int lower;
    int digits;
    int symbols;
} password_quality;

int check_password_quality(const char *password) {
    password_quality pq = {0, 0, 0, 0};
    int length = strlen(password);

    for (int i = 0; password[i] != '\0'; ++i) {
        if (isalpha(password[i])) {
            if (isupper(password[i]))
                pq.upper++;
            else
                pq.lower++;
        } else if (isdigit(password[i]))
            pq.digits++;
        else
            pq.symbols++;
    }

    return length >= MIN_LENGTH && (pq.upper + pq.lower + pq.digits + pq.symbols) >= WEAK_THRESHOLD;
}

int main(void) {
    char input[128];
    int quality;

    printf("Welcome traveler, to the ruins of what was once a thriving civilization. You have reached the guarded entrance to the last known library.\n");
    printf("To prove your worthiness, you must provide a password, a sequence of characters that will unlock the ancient knowledge contained within.\n");
    printf("Enter your password: ");
    scanf("%s", input);

    quality = check_password_quality(input);

    if (quality) {
        printf("The password is of acceptable strength.\n");
        printf("Enter the ancient code to unlock the library:\n");
        // Here you can add a function to open the library based on the input
    } else {
        printf("The password is weak. You shall not pass.\n");
    }

    return 0;
}