//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    char *data;
} String;

String *create_string(int size) {
    String *new_string = (String *) malloc(sizeof(String));
    if (new_string == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_string->size = size;
    new_string->data = (char *) malloc(size * sizeof(char));
    if (new_string->data == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    memset(new_string->data, '\0', size);
    return new_string;
}

void delete_string(String *string) {
    free(string->data);
    free(string);
}

void print_string(String *string) {
    printf("%s", string->data);
}

int main() {
    String *string1 = create_string(20);
    strcpy(string1->data, "Hello, world!");
    printf("String 1: ");
    print_string(string1);

    String *string2 = create_string(30);
    strcpy(string2->data, "This is a longer string.");
    printf("\nString 2: ");
    print_string(string2);

    delete_string(string1);
    delete_string(string2);

    return 0;
}