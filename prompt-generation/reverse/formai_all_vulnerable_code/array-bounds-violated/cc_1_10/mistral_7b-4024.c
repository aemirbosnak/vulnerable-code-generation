//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LEN 100
#define NUM_STRINGS 10
#define SECRET_STRING "the quick brown fox jumps over the lazy dog"
typedef struct {
    char str[MAX_LEN];
    int len;
} String;
String strings[NUM_STRINGS];
void shuffle(String arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        j = rand() % (n - i) + i;
        temp = arr[i].len;
        strcpy(arr[i].str, arr[j].str);
        arr[i].len = arr[j].len;
        arr[j].len = temp;
        strncpy(arr[i].str + arr[i].len, arr[j].str, MAX_LEN - arr[i].len);
    }
}
int main() {
    int i, j, k;
    srand(time(NULL));
    for (i = 0; i < NUM_STRINGS; i++) {
        strings[i].len = rand() % MAX_LEN + 1;
        strings[i].str[strings[i].len] = '\0';
        strncpy(strings[i].str, SECRET_STRING, strings[i].len);
        memmove(strings[i].str + strings[i].len, SECRET_STRING, MAX_LEN - strings[i].len);
    }
    shuffle(strings, NUM_STRINGS);
    printf("Shuffled strings:\n");
    for (i = 0; i < NUM_STRINGS; i++) {
        printf("%s\n", strings[i].str);
    }
    printf("\nFinding the secret string...\n");
    for (i = 0; i < NUM_STRINGS; i++) {
        for (j = i + 1; j < NUM_STRINGS; j++) {
            if (strcmp(strings[i].str, strings[j].str) == 0) {
                printf("Found it! Strings %d and %d contain the secret string.\n", i + 1, j + 1);
                for (k = 0; k < NUM_STRINGS; k++) {
                    if (k != i && k != j) {
                        if (strlen(strings[k].str) == strlen(SECRET_STRING)) {
                            printf("Another instance of the secret string found in string %d.\n", k + 1);
                        }
                    }
                }
                break;
            }
        }
        if (strcmp(strings[i].str, strings[j].str) != 0) {
            continue;
        }
    }
    return 0;
}