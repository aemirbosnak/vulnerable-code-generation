//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000

typedef struct {
    char *string;
    int length;
} string_t;

void initialize_string(string_t *str, char *input) {
    str->string = malloc(MAX_STRING_LEN * sizeof(char));
    str->length = strlen(input);
    strncpy(str->string, input, str->length);
    str->string[str->length] = '\0';
}

int compare_strings(string_t *str1, string_t *str2) {
    return strcmp(str1->string, str2->string);
}

void swap_strings(string_t *str1, string_t *str2) {
    string_t temp;
    temp.string = str1->string;
    temp.length = str1->length;
    str1->string = str2->string;
    str1->length = str2->length;
    str2->string = temp.string;
    str2->length = temp.length;
}

void quicksort_strings(string_t *array, int left, int right) {
    int i = left, j = right;
    string_t pivot = array[(left + right) / 2];
    while (i <= j) {
        while (compare_strings(&array[i], &pivot) < 0) {
            i++;
        }
        while (compare_strings(&array[j], &pivot) > 0) {
            j--;
        }
        if (i <= j) {
            swap_strings(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quicksort_strings(array, left, j);
    }
    if (i < right) {
        quicksort_strings(array, i, right);
    }
}

void print_strings(string_t *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", array[i].string);
    }
}

int main() {
    string_t strings[10];
    char input[MAX_STRING_LEN];
    int n = 0;

    printf("Enter strings (up to 10):\n");
    while (n < 10 && scanf("%s", input)!= EOF) {
        initialize_string(&strings[n], input);
        n++;
    }

    quicksort_strings(strings, 0, n - 1);
    printf("Sorted strings:\n");
    print_strings(strings, n);

    return 0;
}