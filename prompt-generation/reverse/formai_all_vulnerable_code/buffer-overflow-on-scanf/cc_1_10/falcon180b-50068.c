//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100
#define MIN_SIZE 3

// Function to generate a random string of given length
char* generate_random_string(int length) {
    char *random_string = (char*) malloc((length + 1) * sizeof(char));
    if (random_string == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++) {
        int random_char = rand() % 26 + 65; // Generate a random uppercase letter
        random_string[i] = random_char;
    }
    random_string[length] = '\0'; // Add null terminator
    return random_string;
}

// Function to check if a given string is a palindrome
int is_palindrome(char* string) {
    int length = strlen(string);
    int i;
    for (i = 0; i < length / 2; i++) {
        if (tolower(string[i])!= tolower(string[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int length;
    printf("Enter the length of the random string: ");
    scanf("%d", &length);
    if (length < MIN_SIZE || length > MAX_SIZE) {
        printf("Invalid length\n");
        exit(1);
    }
    char* random_string = generate_random_string(length);
    printf("Random string: %s\n", random_string);
    if (is_palindrome(random_string)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }
    free(random_string);
    return 0;
}