#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    char data[1024] = "This is a large string that will cause a buffer overflow";

    printf("Enter a command: ");
    scanf("%s", buffer);

    if (strcmp(buffer, "sync") == 0) {
        FILE *file = fopen("myfile.txt", "w");
        fprintf(file, "%s", data);
        fclose(file);
    } else if (strcmp(buffer, "get") == 0) {
        FILE *file = fopen("myfile.txt", "r");
        fscanf(file, "%s", buffer);
        fclose(file);
        printf("%s", buffer);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
