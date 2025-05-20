//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *str;
    int length;
} string_t;

void init_string(string_t *str) {
    str->str = NULL;
    str->length = 0;
}

void destroy_string(string_t *str) {
    if (str->str!= NULL) {
        free(str->str);
        str->str = NULL;
        str->length = 0;
    }
}

void append_string(string_t *str, char c) {
    if (str->str == NULL) {
        str->str = malloc(str->length + 2);
        str->str[0] = c;
        str->length++;
    } else {
        char *new_str = malloc(str->length + 2);
        strcpy(new_str, str->str);
        new_str[str->length] = c;
        new_str[str->length + 1] = '\0';
        free(str->str);
        str->str = new_str;
        str->length++;
    }
}

int main() {
    string_t input_str;
    init_string(&input_str);

    char c;
    while ((c = getchar())!= '\n') {
        append_string(&input_str, c);
    }

    char *search_str = malloc(strlen(input_str.str) + 1);
    strcpy(search_str, input_str.str);

    int *result = malloc(MAX_SIZE * sizeof(int));
    int count = 0;

    char *str = strtok(input_str.str, " ");
    while (str!= NULL) {
        int len = strlen(str);
        int i;
        for (i = 0; i < len - strlen(search_str) + 1; i++) {
            if (strncmp(str + i, search_str, strlen(search_str)) == 0) {
                result[count++] = i + 1;
            }
        }
        str = strtok(NULL, " ");
    }

    printf("Occurrences of \"%s\" at positions: ", search_str);
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }

    destroy_string(&input_str);
    free(search_str);
    free(result);

    return 0;
}