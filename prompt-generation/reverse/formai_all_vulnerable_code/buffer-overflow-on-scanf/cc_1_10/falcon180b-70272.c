//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <locale.h>

#define MAX_SIZE 1000

int main() {
    int i, j, n, k, m, c, flag;
    char str[MAX_SIZE], search[MAX_SIZE];
    char *token;
    char *delim = " ";
    FILE *file;

    printf("Enter the string to be searched: ");
    scanf("%s", str);

    printf("Enter the search string: ");
    scanf("%s", search);

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("File not found\n");
        exit(0);
    }

    while ((fgets(str, MAX_SIZE, file))!= NULL) {
        flag = 0;
        token = strtok(str, delim);
        while (token!= NULL) {
            if (strcasecmp(token, search) == 0) {
                flag = 1;
                break;
            }
            token = strtok(NULL, delim);
        }
        if (flag == 1) {
            printf("%s", str);
        }
    }

    fclose(file);

    return 0;
}