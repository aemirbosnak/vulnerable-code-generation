//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int x, int y, int z) {
    return (x < y ? (x < z ? x : z) : (y < z ? y : z));
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    if (len1 == 0)
        return len2;

    if (len2 == 0)
        return len1;

    if (str1[len1 - 1] == str2[len2 - 1])
        return levenshtein_distance(str1, str2, len1 - 1, len2 - 1);

    int cost = (str1[len1 - 1] == str2[len2 - 1] ? 0 : 1);

    int delete_cost = levenshtein_distance(str1, str2, len1, len2 - 1);
    int insert_cost = levenshtein_distance(str1, str2, len1 - 1, len2);
    int substitute_cost = levenshtein_distance(str1, str2, len1 - 1, len2 - 1);

    return 1 + min(delete_cost, insert_cost, substitute_cost);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int len1, len2;

    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    len1 = strlen(str1);

    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    len2 = strlen(str2);

    if (len1 > MAX_LENGTH || len2 > MAX_LENGTH) {
        printf("Error: String length exceeds maximum limit.\n");
        return 1;
    }

    str1[len1 - 1] = '\0';
    str2[len2 - 1] = '\0';

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}