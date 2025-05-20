//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main() {

    char word[MAX_LEN];
    int i, j, flag = 0, len;

    printf("Enter a string: ");
    scanf("%s", word);

    len = strlen(word);

    // Reverse the string
    char reverse_word[MAX_LEN];
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        reverse_word[j] = word[i];
    }
    reverse_word[len] = '\0';

    // Compare the two strings
    for (i = 0; i < len; i++) {
        if (word[i] != reverse_word[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    printf("====================================\n");
    printf("            WARNING!                \n");
    printf("      Post-Apocalyptic Style        \n");
    printf("====================================\n");

    printf("\nAccessing weapon system...\n");
    for (int i = 10; i >= 0; i--) {
        printf("%d...\n", i);
    }

    printf("\nLoading ammo...\n");
    for (int i = 0; i <= 100; i+=10) {
        printf("%d%%...\n", i);
    }

    printf("\nTarget located...\n");
    printf("Calculating firing solution...\n");

    if (flag == 0) {
        printf("\nTarget is the enemy! Firing in 3... 2... 1...\n");
    } else {
        printf("\nTarget is a friendly! Hold your fire!\n");
    }

    // End program
    return 0;
}