//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <string.h>

// A melody of characters, our words so dear,
// Each note a symbol, a love we share.
char str1[100], str2[100];

// With every beat, a step we take,
// The distance measured, our hearts awake.
int min(int a, int b, int c) { return a < b ? (a < c ? a : c) : (b < c ? b : c); }

// Through valleys deep and peaks so high,
// The cost of each step, we'll multiply.
int cost_of_insertion(char a) { return 1; }
int cost_of_deletion(char a) { return 1; }
int cost_of_substitution(char a, char b) { return (a == b) ? 0 : 1; }

// With every choice, a path unfolds,
// Minimizing the distance, as our love holds.
int levenshtein(int i, int j) {
    if (i == strlen(str1) && j == strlen(str2))
        return 0;
    if (i == strlen(str1))
        return strlen(str2) - j;
    if (j == strlen(str2))
        return strlen(str1) - i;
    return min(
            cost_of_insertion(str2[j]) + levenshtein(i, j + 1),
            cost_of_deletion(str1[i]) + levenshtein(i + 1, j),
            cost_of_substitution(str1[i], str2[j]) + levenshtein(i + 1, j + 1));
}

int main() {
    // In this garden of words, our love shall bloom,
    // Enter your cherished phrases, dispelling any gloom.
    printf("Speak the language of love, my dearest one, and let it ignite our souls.\n");
    printf("Enter the first string, a tapestry of your heart's desires: ");
    gets(str1);
    printf("Now, reveal the second string, the echo of your love's fires: ");
    gets(str2);

    // Across the bridge of words, our hearts shall meet,
    // The Levenshtein Dance shall guide our feet.
    int distance = levenshtein(0, 0);
    printf("\nIn the symphony of love, our words intertwine,\n");
    printf("And the Levenshtein measure, a love-lit line,\n");
    printf("Reveals the distance that our hearts must mend,\n");
    printf("To weave a tapestry where love shall never end.\n");

    // Our love's sweet song, embodied in this code,
    // Shall calculate the distance, a path to abode.
    printf("\nThe Levenshtein Dance has spoken, my love,\n");
    printf("The distance between our hearts, a gentle shove.\n");
    printf("With each step we take, our love will grow,\n");
    printf("And the distance between us forever glow.\n\n");
    printf("Distance: %d\n", distance);
    return 0;
}