//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32

int main(int argc, char *argv[]) {
    int password_length = MAX_PASSWORD_LENGTH;
    int use_uppercase = 1;
    int use_lowercase = 1;
    int use_numbers = 1;
    int use_special_chars = 0;

    srand(time(NULL));

    // Parse command line arguments
    if (argc >= 2) {
        password_length = atoi(argv[1]);
    }

    if (argc >= 3) {
        use_uppercase = atoi(argv[2]);
    }

    if (argc >= 4) {
        use_lowercase = atoi(argv[3]);
    }

    if (argc >= 5) {
        use_numbers = atoi(argv[4]);
    }

    if (argc >= 6) {
        use_special_chars = atoi(argv[5]);
    }

    char password[MAX_PASSWORD_LENGTH + 1] = {0};
    char charset[256] = {0};

    // Build charset based on user preferences
    if (use_uppercase) {
        strcat(charset, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    }

    if (use_lowercase) {
        strcat(charset, "abcdefghijklmnopqrstuvwxyz");
    }

    if (use_numbers) {
        strcat(charset, "0123456789");
    }

    if (use_special_chars) {
        strcat(charset, "!@#$%^&*()_+-=[]{}|;:,.<>?");
    }

    // Generate password
    for (int i = 0; i < password_length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    printf("Generated password: %s\n", password);

    return 0;
}