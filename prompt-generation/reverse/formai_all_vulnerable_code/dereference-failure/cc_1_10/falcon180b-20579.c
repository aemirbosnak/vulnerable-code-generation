//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {
    int i, j, n, m, k, l, p, q, r, s, t;
    float x, y, z;
    char ch;
    FILE *fp;
    struct tm *tm;
    time_t t1;
    char *str;
    int len;

    srand(time(NULL));
    n = rand() % 10 + 1;
    m = rand() % 10 + 1;
    k = rand() % 10 + 1;
    l = rand() % 10 + 1;
    p = rand() % 10 + 1;
    q = rand() % 10 + 1;
    r = rand() % 10 + 1;
    s = rand() % 10 + 1;
    t = rand() % 10 + 1;
    x = rand() % 100;
    y = rand() % 100;
    z = rand() % 100;
    ch = rand() % 26 + 'a';

    fp = fopen("random.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(fp, "Random numbers:\n");
    fprintf(fp, "n = %d\nm = %d\nk = %d\nl = %d\np = %d\nq = %d\nr = %d\ns = %d\nt = %d\n", n, m, k, l, p, q, r, s, t);

    fprintf(fp, "\nRandom float numbers:\n");
    fprintf(fp, "x = %.2f\ny = %.2f\nz = %.2f\n", x, y, z);

    fprintf(fp, "\nRandom character:\n");
    fprintf(fp, "ch = %c\n", ch);

    fclose(fp);

    t1 = time(NULL);
    tm = localtime(&t1);
    str = asctime(tm);
    len = strlen(str);
    printf("Current date and time: %s\n", str);

    return 0;
}