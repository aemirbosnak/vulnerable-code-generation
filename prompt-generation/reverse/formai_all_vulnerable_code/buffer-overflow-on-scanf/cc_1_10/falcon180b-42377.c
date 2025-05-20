//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
} string_t;

void init_string(string_t *str) {
    str->data = malloc(MAX_SIZE);
    str->size = 0;
}

void append_string(string_t *str, char *data, int size) {
    str->data = realloc(str->data, str->size + size);
    memcpy(str->data + str->size, data, size);
    str->size += size;
}

void free_string(string_t *str) {
    free(str->data);
    str->size = 0;
}

void print_string(string_t *str) {
    printf("%s", str->data);
}

int main() {
    char input_file[100];
    char output_file[100];
    FILE *in, *out;
    char c;
    string_t str = {0};

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    in = fopen(input_file, "r");
    if (in == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    out = fopen(output_file, "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    init_string(&str);
    while ((c = fgetc(in))!= EOF) {
        if (str.size >= MAX_SIZE) {
            append_string(&str, " ", 1);
            str.size = 0;
        }
        append_string(&str, &c, 1);
    }
    free_string(&str);

    fclose(in);
    fclose(out);

    return 0;
}