#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int *dist = (int *)malloc((len1 + 1) * sizeof(int));
    
    for (int i = 0; i <= len1; i++) {
        dist[i] = i;
    }
    
    for (int j = 1; j <= len2; j++) {
        int prev = dist[0];
        dist[0] = j;
        
        for (int i = 1; i <= len1; i++) {
            int temp = dist[i];
            if (s1[i - 1] == s2[j - 1]) {
                dist[i] = prev;
            } else {
                dist[i] = MIN(MIN(dist[i - 1], dist[i]), prev) + 1;
            }
            prev = temp;
        }
    }
    
    int result = dist[len1];
    free(dist);
    return result;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    int distance = levenshtein_distance(str1, str2);
    
    printf("Levenshtein Distance: %d\n", distance);
    
    return 0;
}
