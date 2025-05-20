//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char* data;
    int size;
} String;

int createString(String* str, char* data) {
    str->data = malloc(strlen(data) + 1);
    if (str->data == NULL) {
        return 0;
    }
    strcpy(str->data, data);
    str->size = strlen(data);
    return 1;
}

int deleteString(String* str) {
    free(str->data);
    str->data = NULL;
    str->size = 0;
    return 1;
}

int resizeString(String* str, int newsize) {
    if (newsize <= 0) {
        return 0;
    }
    char* newdata = realloc(str->data, newsize + 1);
    if (newdata == NULL) {
        return 0;
    }
    str->data = newdata;
    str->size = newsize;
    return 1;
}

int concatString(String* str1, String* str2) {
    int newsize = str1->size + str2->size + 1;
    if (newsize > MAX_SIZE) {
        return 0;
    }
    char* newdata = malloc(newsize);
    if (newdata == NULL) {
        return 0;
    }
    strcpy(newdata, str1->data);
    strcat(newdata, str2->data);
    free(str1->data);
    str1->data = newdata;
    str1->size = newsize;
    return 1;
}

int compareString(String* str1, String* str2) {
    if (str1->size!= str2->size) {
        return 1;
    }
    return strcmp(str1->data, str2->data);
}

int main() {
    String s1, s2, s3;
    createString(&s1, "Hello");
    createString(&s2, "World");
    concatString(&s1, &s2);
    printf("%s\n", s1.data); // HelloWorld
    resizeString(&s1, 5);
    printf("%s\n", s1.data); // Hello
    deleteString(&s1);
    return 0;
}