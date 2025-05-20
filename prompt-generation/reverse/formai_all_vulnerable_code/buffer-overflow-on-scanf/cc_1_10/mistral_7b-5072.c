//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

// Function to calculate the love score based on names
int calculate_love_score(char *name1, char *name2) {
    int love_score = 0;

    // Calculate score based on number of common letters between names
    for (int i = 0; name1[i] != '\0'; i++) {
        for (int j = 0; name2[j] != '\0'; j++) {
            if (tolower(name1[i]) == tolower(name2[j])) {
                love_score += 1;
                break;
            }
        }
    }

    // Calculate score based on the position of each letter in the names
    for (int i = 0; name1[i] != '\0'; i++) {
        love_score += name1[i] * (i + 1);
        love_score += tolower(name1[i]) - 'a' + 1;
    }

    for (int i = 0; name2[i] != '\0'; i++) {
        love_score += name2[i] * (i + 1);
        love_score += tolower(name2[i]) - 'a' + 1;
    }

    return love_score;
}

int main() {
    char name1[MAX_NAME_LENGTH];
    char name2[MAX_NAME_LENGTH];
    int love_score;

    printf("Welcome to the Romantic Arithmetic Love Calculator!\n");
    printf("Enter the name of the first person: ");
    scanf("%s", name1);
    printf("Enter the name of the second person: ");
    scanf("%s", name2);

    // Remove newline character from input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        continue;
    }

    love_score = calculate_love_score(name1, name2);

    // Generate a romantic message based on the love score
    if (love_score > 100) {
        printf("Your love score is %d. You two are deeply in love!\n", love_score);
    } else if (love_score > 50) {
        printf("Your love score is %d. You have a strong connection.\n", love_score);
    } else {
        printf("Your love score is %d. You might want to spend more time together.\n", love_score);
    }

    return 0;
}