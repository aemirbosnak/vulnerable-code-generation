//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LENGTH 32
#define MAX_BIN_LENGTH (MAX_NUM_LENGTH * 8 + 1)

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    char *binary = NULL;
    int line_num = 0;
    int num_len = 0;
    int bin_len = 0;
    int i;
    int j;

    printf("Enter a line of text:\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        line_num++;
        binary = realloc(binary, strlen(line) * MAX_BIN_LENGTH + 1);
        if (binary == NULL) {
            printf("Error: Out of memory.\n");
            exit(EXIT_FAILURE);
        }
        for (i = 0; line[i]!= '\0'; i++) {
            if (isalnum(line[i])) {
                num_len = 0;
                while (isalnum(line[i])) {
                    if (isdigit(line[i])) {
                        num_len++;
                    } else {
                        break;
                    }
                    i++;
                }
                bin_len = num_len * 8;
                for (j = 0; j < num_len; j++) {
                    if (isdigit(line[i - j])) {
                        binary[bin_len - 8 + j] = '1';
                    } else {
                        binary[bin_len - 8 + j] = '0';
                    }
                }
                binary[bin_len - 1] = '\0';
                strcat(binary, " ");
            } else {
                strcat(binary, &line[i]);
            }
        }
        printf("Line %d: %s\n", line_num, binary);
    }

    free(binary);
    return 0;
}