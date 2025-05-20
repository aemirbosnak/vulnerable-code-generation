#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_LENGTH 256

void summarizeText() {
    char sentences[MAX_SENTENCES][MAX_LENGTH];
    int count = 0;

    printf("Enter text (type 'exit' to finish):\n");
    while (count < MAX_SENTENCES) {
        fgets(sentences[count], MAX_LENGTH, stdin);
        if (strcmp(sentences[count], "exit\n") == 0) break;
        count++;
    }

    printf("\nSummary:\n");
    for (int i = 0; i < count; i++) {
        printf("%s", sentences[i]);
    }
}

int main() {
    summarizeText();
    return 0;
}
