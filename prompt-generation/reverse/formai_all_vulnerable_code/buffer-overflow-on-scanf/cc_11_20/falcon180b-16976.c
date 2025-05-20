//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH + 1] = {0};
    int length = 0;
    int i;

    // Prompt user for password length
    printf("Enter password length (between 1 and %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    // Check if password length is valid
    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    // Initialize with random seed
    srand(time(NULL));

    // Add lowercase letters
    for (i = 0; i < length; i++) {
        int random = rand() % 26;
        password[i] = 'a' + random;
    }

    // Add uppercase letters
    for (i = 0; i < length; i++) {
        int random = rand() % 26;
        password[i + length / 2] = 'A' + random;
    }

    // Add digits
    for (i = 0; i < length; i++) {
        int random = rand() % 10;
        password[i + length / 2 * 2] = '0' + random;
    }

    // Add special characters
    for (i = 0; i < length; i++) {
        int random = rand() % 6;
        if (random == 0) {
            password[i + length / 2 * 3] = '!';
        } else if (random == 1) {
            password[i + length / 2 * 3] = '@';
        } else if (random == 2) {
            password[i + length / 2 * 3] = '#';
        } else if (random == 3) {
            password[i + length / 2 * 3] = '$';
        } else if (random == 4) {
            password[i + length / 2 * 3] = '%';
        } else {
            password[i + length / 2 * 3] = '&';
        }
    }

    // Print the generated password
    printf("Generated password: %s\n", password);

    return 0;
}