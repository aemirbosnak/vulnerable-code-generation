//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

char input_line[MAX_LINE_LENGTH];
char tokens[MAX_TOKENS][MAX_LINE_LENGTH];
int num_tokens = 0;

void tokenize(char line[]) {
    char *token = strtok(line, " ");
    int i = 0;

    while (token!= NULL) {
        strcpy(tokens[i], token);
        i++;
        num_tokens++;
        token = strtok(NULL, " ");
    }
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(input_line, MAX_LINE_LENGTH, file)!= NULL) {
        tokenize(input_line);
        for (int i = 0; i < num_tokens; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
        num_tokens = 0;
    }

    fclose(file);

    return 0;
}