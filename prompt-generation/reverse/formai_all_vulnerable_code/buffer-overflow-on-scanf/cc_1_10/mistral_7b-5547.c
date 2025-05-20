//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 12
#define MAX_LEN 20
#define LOWER 97
#define UPPER 65
#define NUM 48
#define SYMBOL 33
#define TOTAL_CHAR 26 + 26 + 10

// Function to generate random number
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate random character
char rand_char(int type) {
    if (type == 0) {
        return (char) (rand_int(LOWER, UPPER) + LOWER);
    } else if (type == 1) {
        return (char) (rand_int(UPPER, UPPER) + LOWER);
    } else if (type == 2) {
        return (char) (rand_int(NUM, NUM) + 48);
    } else {
        return (char) (rand_int(SYMBOL, SYMBOL) + 32);
    }
}

// Function to generate a random password
void generate_password(char *password, int len) {
    int i;
    for (i = 0; i < len; i++) {
        password[i] = rand_char(rand() % 4);
    }
    password[len] = '\0';
}

int main() {
    srand(time(NULL));
    int len;
    char password[MAX_LEN + 1];
    printf("Enter the length of password: ");
    scanf("%d", &len);
    if (len < MIN_LEN || len > MAX_LEN) {
        printf("Invalid length! Expected length between %d and %d.\n", MIN_LEN, MAX_LEN);
        return 1;
    }
    generate_password(password, len);
    printf("Generated Password: %s\n", password);
    return 0;
}