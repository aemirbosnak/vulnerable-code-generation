//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// **gasp** A spell checker? In C? **gasp**

// Our trusty dictionary, a haven of correct spellings
const char *dictionary[] = {
    "aberrant", "abhorrent", "abrogate", "abscond", "abstemious",
    "accretion", "acerbic", "acme", "acquiesce", "acrid",
    "adamant", "addendum", "adept", "adherent", "admonish",
    // ... (truncated for brevity)
};

// Shockingly efficient hash function (don't ask how it works)
unsigned int hash(const char *word) {
    unsigned int h = 0;
    while (*word) {
        h = (h << 5) - h + *word++;
    }
    return h;
}

// Awe-inspiring binary search (prepare to be mesmerized)
int binary_search(const char *word, size_t len) {
    int low = 0, high = len - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        int cmp = strcmp(word, dictionary[mid]);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// The heart-stopping spell checker
int main() {
    // Prepare to be flabbergasted by our input buffer
    char buffer[1024];

    // **gasp** User input! **gasp**
    printf("Enter a word to spell check: ");
    scanf("%s", buffer);

    // **gasp** Convert to lowercase! **gasp**
    for (char *c = buffer; *c; c++) {
        *c = tolower(*c);
    }

    // **gasp** The moment of truth! **gasp**
    int index = binary_search(buffer, sizeof(dictionary) / sizeof(dictionary[0]));

    // **gasp** The verdict! **gasp**
    if (index >= 0) {
        printf("**gasp** \"%s\" is spelled correctly! **gasp**\n", buffer);
    } else {
        printf("**gasp** \"%s\" is misspelled! **gasp**\n", buffer);
    }

    return 0;
}