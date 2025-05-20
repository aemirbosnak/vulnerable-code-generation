//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

void create_string(String *string, char *cstring) {
    string->string = (char *) malloc(strlen(cstring) + 1);
    strcpy(string->string, cstring);
    string->length = strlen(cstring);
}

void destroy_string(String *string) {
    free(string->string);
}

int compare_strings(String *string1, String *string2) {
    return strcmp(string1->string, string2->string);
}

int binary_search(String *strings, int n, String target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = compare_strings(strings + mid, &target);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    String strings[10];
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char cstring[MAX_STRING_LENGTH];
        printf("Enter string %d: ", i + 1);
        scanf("%s", cstring);
        create_string(strings + i, cstring);
    }

    String target;
    printf("Enter the target string: ");
    scanf("%s", target.string);
    target.length = strlen(target.string);

    int index = binary_search(strings, n, target);

    if (index == -1) {
        printf("Target string not found.\n");
    } else {
        printf("Target string found at index %d.\n", index);
    }

    for (int i = 0; i < n; i++) {
        destroy_string(strings + i);
    }

    return 0;
}