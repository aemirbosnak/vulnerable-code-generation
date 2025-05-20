//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Ada Lovelace's Enchanted Mirror: Palindrome Reflector

typedef struct {
    char mirrored_symbol;
    bool is_alive;
} symbol_t;

void init_symbols(symbol_t symbols[], char chars[]) {
    for (int i = 0; chars[i] != '\0'; ++i) {
        symbols[chars[i] - 'a'] = (symbol_t) {
            .mirrored_symbol = chars[i],
            .is_alive = true
        };
    }
}

bool check_palindrome(char input[], symbol_t symbols[]) {
    int left = 0, right = strlen(input) - 1;
    while (left < right) {
        if (symbols[input[left] - 'a'].is_alive == false ||
            symbols[input[right] - 'a'].mirrored_symbol != input[left]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    char input[101];
    bool is_palindrome;
    symbol_t symbols[26];

    printf("Enter a palindrome or a string to check: ");
    scanf("%s", input);

    init_symbols(symbols, "aeiouAEIOU");

    is_palindrome = check_palindrome(input, symbols);

    if (is_palindrome) {
        printf("Enchanted mirror whispers: '%s' is a palindrome!\n", input);
    } else {
        printf("Enchanted mirror sighs: '%s' is not a palindrome.\n", input);
    }

    return 0;
}