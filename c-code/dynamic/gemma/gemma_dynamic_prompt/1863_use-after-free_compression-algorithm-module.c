#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = "This is a string that I will compress";
    int str_len = strlen(str);
    int compressed_size = compress(str, str_len);
    char *compressed_str = (char *)malloc(compressed_size);
    compress(str, str_len, compressed_str);
    printf("Compressed size: %d\n", compressed_size);
    printf("Compressed string: %s\n", compressed_str);
    free(compressed_str);
    return 0;
}

int compress(char *str, int str_len, char *compressed_str) {
    int compressed_size = str_len * 2;
    int i = 0;
    for (i = 0; i < str_len; i++) {
        int count = 1;
        char current_char = str[i];
        while (i + 1 < str_len && str[i + 1] == current_char) {
            count++;
            i++;
        }
        compressed_str[i] = current_char;
        compressed_str[i + 1] = count;
    }
    return compressed_size;
}
