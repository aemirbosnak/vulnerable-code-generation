//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SURREAL_STRING_LENGTH 100

typedef struct {
    char str[SURREAL_STRING_LENGTH];
} SurrealString;

void randomizeString(SurrealString *ss) {
    int i, j, len;
    len = strlen(ss->str);

    srand(time(NULL));

    for (i = 0; i < len; i++) {
        j = rand() % len;
        if (i == j) {
            continue;
        }
        char temp = ss->str[i];
        ss->str[i] = ss->str[j];
        ss->str[j] = temp;
    }
}

void printSurrealString(SurrealString *ss) {
    printf("Surreal String: %s\n", ss->str);
}

void reverseSubstring(char *str, int start, int end) {
    int i, j;
    for (i = start, j = end; i < end && j > start; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

SurrealString generateSurrealString() {
    SurrealString ss;
    int i, length;

    printf("Generating Surreal String...\n");

    scanf("%d", &length);

    for (i = 0; i < length; i++) {
        ss.str[i] = (char) (rand() % 26 + 'a');
    }

    ss.str[length] = '\0';

    randomizeString(&ss);

    return ss;
}

int main() {
    SurrealString ss1, ss2;
    int i, j;
    char temp[SURREAL_STRING_LENGTH];

    ss1 = generateSurrealString();
    printSurrealString(&ss1);

    printf("Creating another Surreal String...\n");
    ss2 = generateSurrealString();
    printSurrealString(&ss2);

    printf("Combining Surreal Strings...\n");
    strcat(ss1.str, ss2.str);

    printf("Printing combined Surreal String...\n");
    printSurrealString(&ss1);

    printf("Reversing a substring of Surreal String 1...\n");
    reverseSubstring(ss1.str, 5, 15);

    printf("Printing reversed substring of Surreal String 1...\n");
    printSurrealString(&ss1);

    printf("Swapping Surreal Strings...\n");
    strcpy(temp, ss1.str);
    strcpy(ss1.str, ss2.str);
    strcpy(ss2.str, temp);

    printf("Printing swapped Surreal Strings...\n");
    printSurrealString(&ss1);
    printSurrealString(&ss2);

    return 0;
}