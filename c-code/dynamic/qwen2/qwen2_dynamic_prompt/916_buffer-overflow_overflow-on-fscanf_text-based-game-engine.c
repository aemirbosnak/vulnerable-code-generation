#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void loadGame(char* filename) {
    char buffer[10];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fscanf(file, "%s", buffer);
    fclose(file);
}

int main() {
    char input[20];
    printf("Enter the game file name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    loadGame(input);
    return 0;
}
