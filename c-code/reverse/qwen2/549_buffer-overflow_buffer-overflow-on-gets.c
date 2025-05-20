#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b ? a : b) < c ? (a < b ? a : b) : c;
}

int levenshtein_distance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int *dist = (int *)malloc((len2 + 1) * sizeof(int));
    for (size_t i = 0; i <= len2; ++i) dist[i] = i;

    for (size_t i = 1; i <= len1; ++i) {
        int prev = dist[0];
        dist[0] = i;
        for (size_t j = 1; j <= len2; ++j) {
            int temp = dist[j];
            dist[j] = min(prev + (s1[i - 1] == s2[j - 1] ? 0 : 1),
                          dist[j - 1] + 1,
                          dist[j] + 1);
            prev = temp;
        }
    }

    int result = dist[len2];
    free(dist);
    return result;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Levenshtein Distance: %d\n", levenshtein_distance(str1, str2));
    return 0;
}
