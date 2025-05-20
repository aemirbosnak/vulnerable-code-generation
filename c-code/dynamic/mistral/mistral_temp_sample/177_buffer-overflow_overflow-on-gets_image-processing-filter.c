#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void process_image(char *input) {
    char buffer[10];
    strcpy(buffer, input);
    gets(buffer);
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    printf("Enter the path of the image file to process:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    process_image(input);
    return 0;
}
