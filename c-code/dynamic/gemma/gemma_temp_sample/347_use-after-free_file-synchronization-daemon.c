#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    FILE* file_a = fopen("/home/user/filea.txt", "w");
    FILE* file_b = fopen("/home/user/fileb.txt", "w");

    fprintf(file_a, "Hello, world!");
    fprintf(file_b, "Goodbye, world!");

    fclose(file_a);
    fclose(file_b);

    return 0;
}
