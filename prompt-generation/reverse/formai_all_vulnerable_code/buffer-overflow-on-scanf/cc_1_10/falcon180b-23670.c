//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_SIZE 100
#define MAX_STRING_SIZE 1000

typedef struct {
    char *text;
    int length;
} String;

String generateRandomString(int length) {
    String result = {0};
    result.length = length;
    result.text = malloc(length + 1);

    if (result.text == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result.text[i] = rand() % 26 + 'a';
    }
    result.text[length] = '\0';

    return result;
}

void printString(String str) {
    printf("%s\n", str.text);
}

int main() {
    int length;

    printf("Enter the desired length of the string: ");
    scanf("%d", &length);

    if (length <= 0 || length > MAX_INPUT_SIZE) {
        printf("Error: Invalid input!\n");
        return 1;
    }

    String str = generateRandomString(length);
    printString(str);

    return 0;
}