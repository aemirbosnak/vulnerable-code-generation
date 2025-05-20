//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void print_string(char *str) {
    printf("The given string is: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void capitalize_first_letter(char *str) {
    if (strlen(str) > 0) {
        str[0] = toupper(str[0]);
    }
}

int main() {
    char input_string[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_string);

    capitalize_first_letter(input_string);
    print_string(input_string);

    reverse_string(input_string);
    printf("Reversed string: ");
    print_string(input_string);

    int position;
    char find_char;
    printf("Enter the position and character to find in the string: ");
    scanf("%d %c", &position, &find_char);

    if (position < 0 || position > strlen(input_string)) {
        printf("Invalid position.\n");
    } else if (input_string[position] != find_char) {
        printf("Character not found.\n");
    } else {
        printf("Character found at position %d.\n", position);
    }

    int count = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == find_char) {
            count++;
        }
    }

    printf("Number of occurrences of %c in the string: %d.\n", find_char, count);

    int length_without_space = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] != ' ') {
            length_without_space++;
        }
    }

    char output_string[length_without_space + 1];
    int j = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] != ' ') {
            output_string[j] = input_string[i];
            j++;
        }
    }
    output_string[j] = '\0';

    printf("String without spaces: %s\n", output_string);

    int compare_result = strcmp(input_string, output_string);
    if (compare_result == 0) {
        printf("Both strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }

    return 0;
}