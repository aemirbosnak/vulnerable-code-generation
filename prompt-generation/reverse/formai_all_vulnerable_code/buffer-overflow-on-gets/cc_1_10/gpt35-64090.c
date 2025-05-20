//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int lev_distance(char *s1, char *s2, int m, int n) {
    int arr[m+1][n+1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {

            if(i == 0) {
                arr[i][j] = j;
            } else if(j == 0) {
                arr[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                arr[i][j] = arr[i-1][j-1];
            } else {
                arr[i][j] = min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1]) + 1;
            }
        }
    }

    return arr[m][n];
}

int main() {
    char s1[100], s2[100];
    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);

    int m = strlen(s1);
    int n = strlen(s2);

    int dist = lev_distance(s1, s2, m, n);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, dist);

    printf("Wow, I'm surprised that this program actually runs without any errors. \n");
    printf("Being a chatbot, I was not sure if I could write a C Levenshtein Distance Calculator program. \n");
    printf("But this code looks promising and should work for most cases. \n");
    printf("I guess I still have a lot to learn, but thanks for giving me this opportunity to write some code!\n");

    return 0;
}