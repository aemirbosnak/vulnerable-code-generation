//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char *str;
    int len;
} string;

string *create_string(const char *str) {
    string *s = malloc(sizeof(string));
    s->str = malloc(strlen(str) + 1);
    strcpy(s->str, str);
    s->len = strlen(str);
    return s;
}

void free_string(string *s) {
    free(s->str);
    free(s);
}

int compare_strings(const void *a, const void *b) {
    string *sa = (string *)a;
    string *sb = (string *)b;
    return strcmp(sa->str, sb->str);
}

int main() {
    // Get the input string from the user.
    char input_str[MAX_STR_LEN];
    printf("Enter the string to be compressed: ");
    scanf("%s", input_str);

    // Create a string object for the input string.
    string *input = create_string(input_str);

    // Sort the string in ascending order.
    qsort(input, input->len, sizeof(string), compare_strings);

    // Create a new string to store the compressed string.
    string *compressed = create_string("");

    // Iterate over the input string and append each character to the compressed string.
    // If the current character is the same as the previous character, increment the
    // count of the previous character. Otherwise, append the current character to
    // the compressed string and set the count to 1.
    int count = 1;
    for (int i = 0; i < input->len; i++) {
        if (i > 0 && input->str[i] == input->str[i - 1]) {
            count++;
        } else {
            char str[MAX_STR_LEN];
            sprintf(str, "%c%d", input->str[i], count);
            strcat(compressed->str, str);
            count = 1;
        }
    }

    // Print the compressed string.
    printf("Compressed string: %s\n", compressed->str);

    // Free the allocated memory.
    free_string(input);
    free_string(compressed);

    return 0;
}