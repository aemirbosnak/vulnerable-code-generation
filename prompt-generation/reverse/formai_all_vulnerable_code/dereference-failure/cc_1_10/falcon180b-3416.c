//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int len;
} String;

int compare_strings(const void *a, const void *b) {
    String *s1 = (String *) a;
    String *s2 = (String *) b;
    return strcmp(s1->str, s2->str);
}

void delete_strings(String *strings, int n) {
    for (int i = 0; i < n; i++) {
        free(strings[i].str);
    }
    free(strings);
}

String *read_strings(FILE *fp, int n) {
    String *strings = (String *) malloc(n * sizeof(String));
    for (int i = 0; i < n; i++) {
        char line[MAX_SIZE];
        if (fgets(line, MAX_SIZE, fp) == NULL) {
            printf("Error reading string.\n");
            exit(1);
        }
        strings[i].str = strdup(line);
        strings[i].len = strlen(strings[i].str);
    }
    return strings;
}

void print_strings(String *strings, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i].str);
    }
}

int main() {
    FILE *fp;
    String *strings;
    int n;

    fp = fopen("strings.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    n = 0;
    while (fgetc(fp)!= EOF) {
        n++;
    }
    rewind(fp);

    strings = read_strings(fp, n);
    qsort(strings, n, sizeof(String), compare_strings);
    print_strings(strings, n);

    delete_strings(strings, n);
    fclose(fp);

    return 0;
}