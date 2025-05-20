//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void generate_case(char* target, int target_len, char* suspect, int suspect_len);
int compare_strings(char* str1, char* str2);

int main() {
    char target[100], suspect[100];
    int target_len, suspect_len;

    // Get user input for target string
    printf("Enter the target string: ");
    scanf("%s", target);
    target_len = strlen(target);

    // Generate a random suspect string
    srand(time(0));
    for (int i = 0; i < target_len; i++) {
        suspect[i] = rand() % 26 + 'a';
    }
    suspect[target_len] = '\0';

    // Compare the two strings
    int match_count = 0;
    for (int i = 0; i < target_len; i++) {
        if (target[i] == suspect[i]) {
            match_count++;
        }
    }

    // Output the results
    if (match_count == target_len) {
        printf("Suspect is an exact match!\n");
    } else {
        printf("Suspect has %d matching characters.\n", match_count);
    }

    return 0;
}

// Function to generate a random string of given length
void generate_case(char* target, int target_len, char* suspect, int suspect_len) {
    for (int i = 0; i < target_len; i++) {
        suspect[i] = rand() % 26 + 'a';
    }
    suspect[target_len] = '\0';
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
    }

    return 1;
}