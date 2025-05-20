//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <string.h>

// Function to reverse the string
void reverseString(char* str, int start, int end) {
    char temp;
    for(; start < end; ++start, --end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

// Function to find the length of the longest common substring
int lcsLength(char* str1, char* str2, int m, int n) {
    int lcs[m+1][n+1];
    int i, j;

    // Initialize the matrix with zeros
    for(i = 0; i <= m; ++i) {
        for(j = 0; j <= n; ++j) {
            lcs[i][j] = 0;
        }
    }

    // Fill in the matrix recursively
    for(i = 1; i <= m; ++i) {
        for(j = 1; j <= n; ++j) {
            if(str1[i-1] == str2[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = 0;
            }
        }
    }

    return lcs[m][n];
}

int main() {
    char str1[100], str2[100];
    int m, n;

    // Input two strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Find the length of both strings
    m = strlen(str1);
    n = strlen(str2);

    // Print the longest common substring
    printf("Longest Common Substring Length: %d\n", lcsLength(str1, str2, m, n));

    // Reverse the first string and print it
    reverseString(str1, 0, m-1);
    printf("Reversed first string: %s\n", str1);

    // Check if the reversed first string is a substring of the second string
    if(strstr(str2, str1) != NULL) {
        printf("%s is a substring of %s.\n", str1, str2);
    }
    else {
        printf("%s is not a substring of %s.\n", str1, str2);
    }

    return 0;
}