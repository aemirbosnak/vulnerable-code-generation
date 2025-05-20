#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidAscii(char *data) {
    while (*data) {
        if (*data < 32 || *data > 126) return 0;
        data++;
    }
    return 1;
}

void cleanData(char *data) {
    char *cleaned = malloc(strlen(data) + 1);
    int j = 0;
    for (int i = 0; data[i]; i++) {
        if (data[i] != ' ' && data[i] != '\0') {
            cleaned[j++] = data[i];
        }
    }
    cleaned[j] = '\0';
    strcpy(data, cleaned);
    free(cleaned);
}

int main() {
    FILE *file;
    char filename[256], buffer[1024];

    printf("Enter the filename to read: ");
    scanf("%255s", filename);

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        cleanData(buffer);
        if (!isValidAscii(buffer)) {
            fprintf(stderr, "Non-ASCII character found in the file.\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        // Process the cleaned data here
        printf("%s", buffer);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
