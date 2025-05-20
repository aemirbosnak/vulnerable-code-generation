#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 1024

void edit(char *filename) {
    char buffer[MAX_BUFFER];
    int number;

    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fgets(buffer, MAX_BUFFER, file);
    fclose(file);

    printf("Content: %s\n", buffer);

    printf("Enter the number of lines to append: ");
    scanf("%d", &number);

    for (int i = 0; i < number; ++i) {
        printf("Line %d: ", i + 1);
        fgets(buffer, MAX_BUFFER, stdin);
        strcat(buffer, "\n");
    }

    file = fopen(filename, "w");
    fputs(buffer, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./editor <filename>\n");
        return 1;
    }

    edit(argv[1]);
    return 0;
}
