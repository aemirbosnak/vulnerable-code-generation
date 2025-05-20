//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char* generate_string(int length) {
    char* string = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to check if two strings are equal
int compare_strings(char* string1, char* string2) {
    int length = strlen(string1);
    if (length!= strlen(string2)) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (string1[i]!= string2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    int length = 10;
    int attempts = 0;
    int correct_attempts = 0;

    while (1) {
        char* string_to_type = generate_string(length);
        printf("Type the following string: %s\n", string_to_type);

        char input_string[100];
        fgets(input_string, 100, stdin);

        if (compare_strings(string_to_type, input_string)) {
            correct_attempts++;
        }

        attempts++;

        if (attempts == 5) {
            break;
        }
    }

    printf("You got %d out of %d correct.\n", correct_attempts, attempts);

    return 0;
}