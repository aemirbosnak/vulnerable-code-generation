//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
// The Adventure of the Levenshtein Distance Calculator

#include<stdio.h>
#include<string.h>

int levenshtein_distance(char* str1, char* str2);
void print_case(int count, char* str1, char* str2, int distance);

int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);
    print_case(1, str1, str2, distance);

    return 0;
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1), len2 = strlen(str2), i, j;
    int dp[len1+1][len2+1];

    for(i=0; i<=len1; i++) { dp[i][0] = i; }
    for(j=0; j<=len2; j++) { dp[0][j] = j; }

    for(i=1; i<=len1; i++) {
        for(j=1; j<=len2; j++) {
            if(str1[i-1] ==  str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

void print_case(int count, char* str1, char* str2, int distance) {
    printf("The Adventure of the Levenshtein Distance Calculator\n\n");
    printf("Case #%d: '%s' and '%s' --> %d\n\n", count, str1, str2, distance);
    printf("Mr. Sherlock Holmes sat in his armchair with a thoughtful expression on his face,\n"
           "while a visit from Dr. Watson brought him out of his reverie.\n\n");

    printf("\"Good morning, Watson,\" said Holmes. \"I have just been working on a little problem\n"
           "concerning the distance between two strings, and I believe I have arrived at a solution.\n"
           "I have calculated the Levenshtein Distance between the two strings, '%s', and '%s',\n"
           "and the result is %d.\"\n\n", str1, str2, distance);

    printf("Dr. Watson, always eager to learn, asked Holmes how he had made the calculation.\n\n");
    printf("\"Ah,\" said Holmes, \"I simply used a dynamic programming algorithm to find the\n"
           "minimum number of operations required to transform one string into another.\"\n\n");

    printf("\"But how does it work?\" asked Watson.\n"
           "Holmes replied, \"Well, you see, we first initialize a two-dimensional array to\n"
           "store the minimum number of operations required to transform prefixes of the two strings.\n"
           "Then, we compute the minimum number for each cell by taking into account the operations\n"
           "required to transform the prefixes that lead to that cell. Finally, we return the last\n"
           "element in the array, which corresponds to the minimum number of operations to transform\n"
           "the complete strings.\"\n\n");

    printf("Dr. Watson looked impressed. It was as if Holmes had worked a miracle, something that\n"
           "he had made a habit of doing. His admiration for the great detective knew no bounds.\n\n");
}

int minimum(int a, int b, int c) {
    if(a < b && a < c) { return a; }
    else if(b < a && b < c) { return b; }
    else { return c; }
}