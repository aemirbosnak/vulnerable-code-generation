//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char filename[MAX_LENGTH], line[MAX_LENGTH];
    FILE *fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file.");
        return 1;
    }

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        reverse_string(line);
        printf("Reversed line: %s\n", line);

        // Write reversed line back to file
        FILE *fp_write = fopen(filename, "a");
        if (fp_write == NULL) {
            perror("Error opening file for writing.");
            fclose(fp);
            return 1;
        }
        fprintf(fp_write, "%s\n", line);
        fclose(fp_write);
    }

    fclose(fp);
    printf("All lines reversed and written to file.\n");

    return 0;
}