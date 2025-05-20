//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    size_t size;
} String;

/*
 * Allocate memory for a new string and initialize it with the given data
 */
String *string_new(const char *data)
{
    String *string = malloc(sizeof(String));
    if (string == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    string->data = strdup(data);
    string->size = strlen(data);

    return string;
}

/*
 * Free memory used by a string
 */
void string_free(String *string)
{
    free(string->data);
    free(string);
}

/*
 * Concatenate two strings and return the result
 */
String *string_concat(const String *a, const String *b)
{
    String *result = malloc(sizeof(String));
    if (result == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    result->size = a->size + b->size;
    result->data = malloc(result->size + 1);
    if (result->data == NULL) {
        free(result);
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    strcpy(result->data, a->data);
    strcat(result->data, b->data);

    return result;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    String *s1 = string_new(argv[1]);
    String *s2 = string_new(argv[2]);
    String *result = string_concat(s1, s2);

    printf("Concatenated string: %s\n", result->data);

    string_free(s1);
    string_free(s2);
    string_free(result);

    return 0;
}