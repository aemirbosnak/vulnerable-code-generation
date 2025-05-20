//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 8
#define MAX_LEN 32
#define CHAR_SET_SIZE 52

// Function to generate random numbers
int rand_range(int start, int end) {
    return rand() % (end - start + 1) + start;
}

// Function to generate random character from character set
char rand_char() {
    int index = rand_range(0, CHAR_SET_SIZE - 1);
    return (char)(index < 26 ? 'a' + index : (index < 36 ? '0' + index - 26 : (index < 52 ? 'A' + index - 36 : '!')));
}

// Function to generate random password
void generate_password(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand_char();
    }
    password[length] = '\0';
}

// Function to print password
void print_password(char *password) {
    int i;
    printf("Your new password is: ");
    for (i = 0; password[i] != '\0'; i++) {
        printf("%c", password[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL) + getpid()); // Seed the random number generator with current time and process ID

    int password_length;
    printf("Enter the desired length of your password (min %d, max %d): ", MIN_LEN, MAX_LEN);
    scanf("%d", &password_length);

    if (password_length < MIN_LEN || password_length > MAX_LEN) {
        printf("Invalid length. Exiting...\n");
        return 1;
    }

    char password[MAX_LEN + 1];
    generate_password(password, password_length);
    print_password(password);

    return 0;
}