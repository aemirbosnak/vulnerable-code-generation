#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void edit(char* buffer) {
    printf("Edit:\n%s\n\nCommand (save/exit/append): ", buffer);
    char command[32];
    scanf("%s", command);

    if (strcmp(command, "save") == 0) {
        FILE *file;
        file = fopen("file.txt", "w");
        fprintf(file, "%s", buffer);
        fclose(file);
        printf("File saved.\n");
    } else if (strcmp(command, "append") == 0) {
        char append[BUFFER_SIZE];
        printf("Enter text to append: ");
        scanf("%s", append);
        strcat(buffer, append);
        printf("Text appended.\n");
    } else if (strcmp(command, "exit") != 0) {
        printf("Invalid command. Try again.\n");
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    FILE *file;
    file = fopen("file.txt", "r");
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);

    while (1) {
        edit(buffer);
    }

    return 0;
}
