//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char *string;
    int length;
} String;

void generateRandomString(String *string) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for (i = 0; i < MAX_STRING_LENGTH; i++) {
        string->string[i] = charset[rand() % strlen(charset)];
    }

    string->length = strlen(string->string);
}

int compareStrings(const void *a, const void *b) {
    const String *stringA = (const String *)a;
    const String *stringB = (const String *)b;

    return strcmp(stringA->string, stringB->string);
}

int main() {
    int numStrings;
    int i;
    String strings[100];

    printf("Enter the number of strings to generate: ");
    scanf("%d", &numStrings);

    srand(time(NULL));

    for (i = 0; i < numStrings; i++) {
        generateRandomString(&strings[i]);
    }

    qsort(strings, numStrings, sizeof(String), compareStrings);

    for (i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i].string);
    }

    return 0;
}