//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50

// Function to reverse a string
void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to print a string in a retro style
void print_retro_str(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i % 2 == 0) {
            printf("%c ", str[i]);
        } else {
            printf("%c%c", str[i], ' ');
        }
    }
    printf("\n");
}

int main() {
    char str[MAX_STR_LEN];
    char *str_ptr;

    // Ask the user for a string
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    // Reverse the string
    reverse_str(str);

    // Print the string in a retro style
    print_retro_str(str);

    // Ask the user if they want to reverse the string again
    printf("Do you want to reverse the string again? (y/n): ");
    char again;
    scanf(" %c", &again);

    if (again == 'y') {
        // Reverse the string again
        reverse_str(str);
        // Print the string in a retro style again
        print_retro_str(str);
    }

    return 0;
}