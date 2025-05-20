#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void analyze_text(char *text) {
    char buffer[50];
    int i = 0;
    while (text[i] != '\0' && i < 49) {
        buffer[i] = text[i];
        i++;
    }
    buffer[i] = '\0';
}

int main() {
    char input[100];
    printf("Enter some text: ");
    gets(input);
    analyze_text(input);
    return 0;
}
