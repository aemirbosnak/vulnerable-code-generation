//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int i, j, k, n, m, c, d, t;
    char str[100];
    FILE *fp;
    time_t now;

    printf("Enter the size of the file: ");
    scanf("%d", &n);

    printf("Enter the number of lines to be displayed: ");
    scanf("%d", &m);

    printf("Enter the name of the file: ");
    scanf("%s", str);

    fp = fopen(str, "r");

    if (fp == NULL) {
        printf("Error! File not found.\n");
        exit(0);
    }

    t = 0;
    for (i = 1; i <= n; i++) {
        fseek(fp, 0L, SEEK_END);
        t += ftell(fp);
        rewind(fp);
    }

    printf("Total number of characters in the file: %d\n", t);

    printf("Enter the starting line number: ");
    scanf("%d", &c);

    printf("Enter the ending line number: ");
    scanf("%d", &d);

    rewind(fp);

    for (i = 1; i <= m; i++) {
        if ((c <= i) && (i <= d)) {
            fgets(str, 100, fp);
            printf("%s", str);
        } else {
            for (j = 1; j <= 80; j++) {
                printf(" ");
            }
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}