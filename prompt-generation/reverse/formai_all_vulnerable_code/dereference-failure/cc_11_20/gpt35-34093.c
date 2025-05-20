//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    char keyword[10];
    char identifier[10];
    char operator[10];
    char value[10];
};

int main() {
    int count = 0, i = 0;
    char input[100];
    char *token;

    struct Data data[100];

    printf("Enter your C syntax: ");
    fgets(input, 100, stdin);

    token = strtok(input, " ");

    while (token != NULL) {

        if (strstr(token, "int") != NULL ||
            strstr(token, "char") != NULL ||
            strstr(token, "float") != NULL ||
            strstr(token, "double") != NULL)
        {
            strcpy(data[i].keyword, token);
            count++;
        }

        else if (strchr(token, '=') != NULL) {

            char *temp = strtok(token, "=");

            if (strstr(temp, "++") != NULL ||
                strstr(temp, "--") != NULL)
            {
                strcpy(data[i].operator, temp);
            }

            else {

                strcpy(data[i].identifier, temp);
                strcpy(data[i].operator, "=");

                temp = strtok(NULL, "=");

                if (strchr(temp, ';') != NULL) {
                    temp[strlen(temp)-1] = '\0';
                }

                strcpy(data[i].value, temp);
            }

            count++;
        }

        token = strtok(NULL, " ");
        i++;
    }

    printf("Parsed C syntax:\n");
    for (int j=0; j<count; j++) {

        if (strlen(data[j].keyword) > 0) {
            printf("Keyword: %s\n", data[j].keyword);
        }

        if (strlen(data[j].identifier) > 0) {
            printf("Identifier: %s\n", data[j].identifier);
        }

        if (strlen(data[j].operator) > 0) {
            printf("Operator: %s\n", data[j].operator);
        }

        if (strlen(data[j].value) > 0) {
            printf("Value: %s\n", data[j].value);
        }

    }

    return 0;
}