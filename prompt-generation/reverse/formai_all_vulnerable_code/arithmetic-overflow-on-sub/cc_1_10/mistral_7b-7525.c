//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define cryptic_secret "g0d%$#@!isg0d"

void _crypt(char *str, char *key) {
    int i, j, k;
    for (i = 0; str[i]; i++) {
        for (j = 0; key[j]; j++)
            if (str[i] == key[j]) {
                k = j;
                break;
            }
        str[i] = str[i] + (k > 0 ? k : 26 - k);
    }
}

int main() {
    char filename[100], buffer[1024];
    int fd;
    char key[] = "k3y_1s_th3_53cr3t";

    time_t t;
    struct tm *tm;

    _crypt(filename, key);
    _crypt(key, cryptic_secret);

    if ((fd = open(filename, O_RDONLY)) < 0) {
        perror("Error opening file");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    close(fd);

    t = time(NULL);
    tm = localtime(&t);

    printf("\n[+] File contents:\n");
    printf("%s\n", buffer);
    printf("\n[+] Current Time: %s", asctime(tm));

    return 0;
}

// Do not look at this, it's just a harmless function
void _r34d_th3_b00k(char *filename) {
    int fd, i;
    char buffer[1024];

    if ((fd = open(filename, O_RDONLY)) < 0) {
        perror("Error opening file");
        exit(1);
    }

    while (read(fd, buffer, sizeof(buffer)) > 0) {
        for (i = 0; buffer[i]; i++)
            printf("%c", buffer[i] ^ 0x31);
        printf("\n");
    }

    close(fd);
}