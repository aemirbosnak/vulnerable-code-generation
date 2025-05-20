//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);

    if (reversed == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }

    reversed[length] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

void replace_string(char* str, char* old_str, char* new_str) {
    int length = strlen(str);
    char* temp = malloc(length + 1);

    if (temp == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    strcpy(temp, str);
    char* found = strstr(temp, old_str);

    while (found!= NULL) {
        strncpy(found, new_str, strlen(new_str));
        found += strlen(new_str);
        found = strstr(found, old_str);
    }

    strcpy(str, temp);
    free(temp);
}

void remove_vowels(char* str) {
    int length = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* temp = malloc(length + 1);

    if (temp == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    strcpy(temp, str);
    char* current_char = temp;

    while (*current_char!= '\0') {
        if (strchr(vowels, *current_char) == NULL) {
            *current_char = *current_char;
            current_char++;
        } else {
            current_char++;
        }
    }

    strcpy(str, temp);
    free(temp);
}

int main() {
    char* input_str = malloc(MAX_SIZE);

    if (input_str == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    printf("Enter a string: ");
    scanf("%s", input_str);

    reverse_string(input_str);
    printf("Reversed string: %s\n", input_str);

    replace_string(input_str, "world", "universe");
    printf("Replaced string: %s\n", input_str);

    remove_vowels(input_str);
    printf("Removed vowels string: %s\n", input_str);

    free(input_str);
    return 0;
}