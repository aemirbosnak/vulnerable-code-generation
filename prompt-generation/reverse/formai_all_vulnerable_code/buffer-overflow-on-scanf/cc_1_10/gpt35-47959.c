//FormAI DATASET v1.0 Category: String manipulation ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int get_input(char input[]) {
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    int length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }
    return length - 1;
}

void display_menu() {
    printf("\n---- MENU ----\n");
    printf("1. Display string length\n");
    printf("2. Count vowels\n");
    printf("3. Reverse string\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int count_vowels(char input[], int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        switch (input[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;
            default:
                break;
        }
    }
    return count;
}

void reverse_string(char input[], int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = input[start];
        input[start] = input[end];
        input[end] = temp;

        start++;
        end--;
    }

    printf("Reversed string: %s\n", input);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int length = get_input(input);

    int option;
    do {
        display_menu();
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                printf("String length: %d\n", length);
                break;
            case 2:
                printf("Number of vowels: %d\n", count_vowels(input, length));
                break;
            case 3:
                reverse_string(input, length);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}