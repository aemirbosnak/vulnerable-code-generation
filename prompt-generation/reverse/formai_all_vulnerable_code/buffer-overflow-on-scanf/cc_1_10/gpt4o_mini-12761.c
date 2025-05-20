//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int min_val = a < b ? a : b;
    return min_val < c ? min_val : c;
}

// Function to compute the Levenshtein distance
int levenshtein(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** distance = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // distance from str1 to empty str2
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // distance from empty str1 to str2
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,      // deletion
                                 distance[i][j - 1] + 1,      // insertion
                                 distance[i - 1][j - 1] + cost); // substitution
        }
    }

    int result = distance[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to display the menu
void display_menu() {
    printf("=== Levenshtein Distance Calculator ===\n");
    printf("1. Calculate Distance\n");
    printf("2. Exit\n");
    printf("=========================================\n");
}

// Function to get the user's input strings
void get_input(char** str1, char** str2) {
    *str1 = (char*)malloc(256 * sizeof(char));
    *str2 = (char*)malloc(256 * sizeof(char));

    printf("Enter the first string: ");
    fgets(*str1, 256, stdin);
    strtok(*str1, "\n"); // Remove the newline character

    printf("Enter the second string: ");
    fgets(*str2, 256, stdin);
    strtok(*str2, "\n"); // Remove the newline character
}

int main() {
    int choice;
    char *str1 = NULL, *str2 = NULL;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character from buffer

        switch (choice) {
            case 1:
                get_input(&str1, &str2);
                int distance = levenshtein(str1, str2);
                printf("Levenshtein Distance: %d\n", distance);
                free(str1);
                free(str2);
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 2);

    return 0;
}