//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define MIN_ENTROPY 4.0

// Function to calculate entropy of a string
double entropy(char *str, int length) {
    int freq[128];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < length; i++) {
        freq[(int)str[i]]++;
    }

    double sum = 0;
    for (int i = 0; i < 128; i++) {
        double p = (double)freq[i] / length;
        sum += p * log2(p);
    }

    return sum;
}

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    double entropy_value = entropy(password, length);

    srand(time(NULL));
    double random_number = (double)rand() / RAND_MAX;

    if (length < MIN_LENGTH) {
        return 0;
    }

    if (entropy_value < MIN_ENTROPY) {
        return 0;
    }

    if (random_number < pow(0.5, (entropy_value - MIN_ENTROPY))) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (check_password_strength(password)) {
        printf("Strong password!\n");
    } else {
        printf("Weak password. Try a longer and more complex one.\n");
    }

    return 0;
}