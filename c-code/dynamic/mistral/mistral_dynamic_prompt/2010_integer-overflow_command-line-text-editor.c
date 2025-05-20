#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define BUFFER_SIZE 8192

void read_line(char *buf, int *ptr) {
    char c;
    while ((c = getchar()) != EOF && *ptr < MAX_LINE) {
        buf[*ptr++] = c;
    }
    buf[*ptr] = '\0';
}

void edit_line(char *buf) {
    int len = strlen(buf);
    char input[BUFFER_SIZE];
    int input_ptr = 0;

    printf("Edit line (%d characters): ", len);
    read_line(input, &input_ptr);

    // Integer overflow vulnerability occurs here when the length of the input is larger than MAX_LINE
    strcpy(buf, input);
}

int main() {
    char buffer[MAX_LINE];

    while (1) {
        edit_line(buffer);
        printf("\nDisplaying your edited line:\n%s\n", buffer);
    }

    return 0;
}
