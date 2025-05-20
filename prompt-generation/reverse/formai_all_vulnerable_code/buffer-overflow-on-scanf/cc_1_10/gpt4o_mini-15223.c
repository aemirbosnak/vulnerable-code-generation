//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three values
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int **d = (int **)malloc((len_s + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s; i++) {
        d[i][0] = i; // deletion
    }

    for (int j = 0; j <= len_t; j++) {
        d[0][j] = j; // insertion
    }

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,       // deletion
                         d[i][j - 1] + 1,       // insertion
                         d[i - 1][j - 1] + cost); // substitution
        }
    }

    int distance = d[len_s][len_t];

    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

// Function to display the menu
void display_menu() {
    printf("Levenshtein Distance Calculator\n");
    printf("1. Calculate distance\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    char str1[100], str2[100];
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                int distance = levenshtein(str1, str2);
                printf("The Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);
                break;

            case 2:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}