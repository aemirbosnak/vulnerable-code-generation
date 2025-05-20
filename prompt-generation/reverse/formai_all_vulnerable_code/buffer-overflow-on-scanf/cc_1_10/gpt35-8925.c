//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Define variables
    int i, j, k, n = 0, length = 0;

    // User input
    printf("Enter the password length: ");
    scanf("%d", &length);

    // Seed the random number generator with current time
    srand(time(NULL));

    // Define and initialize arrays
    char password[length + 1];
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special[] = "!@#$%^&*()_+-=[]{}|;':\"<>,.?/~`";

    // Generate password with secure random numbers
    while (n < length) {
        i = rand() % 4;
        switch (i) {
            case 0:
                j = rand() % 26;
                password[n] = lowercase[j];
                break;
            case 1:
                j = rand() % 26;
                password[n] = uppercase[j];
                break;
            case 2:
                j = rand() % 10;
                password[n] = numbers[j];
                break;
            case 3:
                j = rand() % 31;
                password[n] = special[j];
                break;
        }
        n++;
    }

    // Shuffle the password array
    for (i = 0; i < length; i++) {
        j = rand() % length;
        k = password[i];
        password[i] = password[j];
        password[j] = k;
    }

    // Print the password
    printf("Your secure password is: %s\n", password);
    return 0;
}