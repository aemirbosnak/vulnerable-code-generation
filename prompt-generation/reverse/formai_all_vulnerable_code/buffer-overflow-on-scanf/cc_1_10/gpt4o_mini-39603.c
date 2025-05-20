//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

// Declare the characters, noble in nature, to be included in the password generation
const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";

// A sonnet of functions, for our secure password creation
void show_preamble() {
    printf("Enter fair password length, noble user (between %d and %d):\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
}

int get_valid_length() {
    int length;
    while (1) {
        printf("Length: ");
        scanf("%d", &length);
        if (length >= MIN_PASSWORD_LENGTH && length <= MAX_PASSWORD_LENGTH) {
            return length;
        } else {
            printf("A length too short or tall; choose once more, dear friend.\n");
        }
    }
}

char generate_character() {
    return characters[rand() % strlen(characters)];
}

void build_password(char *password, int length) {
    for (int i = 0; i < length; i++) {
        password[i] = generate_character();
    }
    password[length] = '\0'; // Add the null terminator
}

void display_password(const char *password) {
    printf("Your secure password, oh gentle soul, is: %s\n", password);
}

void tragedy_of_memory(char *password) {
    free(password); // Release memory, let it go, as Juliet did to her Romeo
}

int main() {
    srand(time(NULL)); // The fickle hand of fate guides our random number generators

    show_preamble();
    
    int length = get_valid_length(); // Length of our password fair
    char *password = (char *)malloc((length + 1) * sizeof(char)); // Memory allocation, as love requires space

    if (password == NULL) {
        fprintf(stderr, "Alas! Memory allocation failed. Love requires strength; such errors beg forgiveness.\n");
        return EXIT_FAILURE;
    }

    build_password(password, length); // Crafting the password from hidden characters of twilight and stars
    display_password(password); // Unveil the masterpiece to the world

    tragedy_of_memory(password); // Part ways with resources, lest they beAnchored too long
    return EXIT_SUCCESS; // In this tale, we find a sweet resolution
}