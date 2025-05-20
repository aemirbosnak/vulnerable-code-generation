//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void compress(char *s, int n, char *c) {
    int i, j, k;
    int cnt;
    char tmp[8];

    for (i = 0, k = 0; i < n; ) {
        cnt = 1;
        for (j = i+1; j < n && s[j] == s[i]; ++j, ++cnt);

        if (cnt > 1) {
            sprintf(tmp, "%d%c", cnt, s[i]);
            for (j = 0; tmp[j]; ++j, ++k)
                c[k] = tmp[j];
        } else {
            c[k++] = s[i];
        }
        i += cnt;
    }
    c[k] = '\0';
}

void decompress(char *s, int n, char *d) {
    int i, j, cnt;
    char tmp[MAX_LEN];
    char *p;

    for (i = 0, j = 0; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt = s[i] - '0';
            while (s[i+1] >= '0' && s[i+1] <= '9')
                cnt = cnt*10 + s[++i]-'0';
            p = strchr(s, s[i+1]);
            strncpy(tmp, p, cnt);
            tmp[cnt] = '\0';
            strcat(d, tmp);
        } else {
            d[j++] = s[i];
            d[j] = '\0';
        }
    }
}

int main(void) {
    char src[MAX_LEN], cmp[MAX_LEN], dec[MAX_LEN];
    printf("Enter a string with length < %d: ", MAX_LEN);
    fgets(src, MAX_LEN, stdin);
    src[strlen(src)-1] = '\0';

    compress(src, strlen(src), cmp);
    printf("Compressed string: %s\n", cmp);

    decompress(cmp, strlen(cmp), dec);
    printf("Decompressed string: %s\n", dec);

    return EXIT_SUCCESS;
}