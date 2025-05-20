//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256

typedef struct {
    char user_id[20];
    int level;
} Hacker;

void clear_stdin() {
    while (getchar() != '\n');
}

void display_futuristic_art() {
    printf("\n=======================\n");
    printf("  .*  * -  -  * .\n");
    printf(" *        WASTELAND       *\n");
    printf("    *    *    . *  *\n");
    printf("=======================\n");
}

int is_palindrome(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; // Not a palindrome
        }
        
        left++;
        right--;
    }

    return 1; // Is a palindrome
}

void hack_into_system(Hacker user) {
    printf("Hacker ID: %s\n", user.user_id);
    printf("Hacking Level: %d\n", user.level);
    printf("Accessing System...\n\n");
    display_futuristic_art();
}

int main() {
    Hacker user;
    char input[MAX_INPUT_SIZE];
    
    printf("Welcome to the Neon District Palindrome Checker\n");
    printf("Enter your Hacker ID: ");
    fgets(user.user_id, sizeof(user.user_id), stdin);
    user.user_id[strcspn(user.user_id, "\n")] = ' ';

    printf("Enter your Hacking Level (1-100): ");
    scanf("%d", &user.level);
    clear_stdin();

    hack_into_system(user);

    while (1) {
        printf("Enter a phrase to check for palindromic properties (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcasecmp(input, "exit") == 0) {
            printf("Disconnecting from the Neon District...\n");
            break;
        }

        if (is_palindrome(input)) {
            printf("** PALINDROME DETECTED! **\n");
        } else {
            printf("No palindromic properties found. Rerouting...\n");
        }
        
        printf("------------------------------\n");
    }

    return 0;
}