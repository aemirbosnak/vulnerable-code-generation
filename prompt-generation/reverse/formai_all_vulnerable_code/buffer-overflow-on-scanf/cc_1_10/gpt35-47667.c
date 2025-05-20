//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void compress(char *str) {
    int len = strlen(str);
    int count[MAX_SIZE] = {0};
    int index = 0;
    for (int i = 0; i < len; i++) {
        count[str[i]]++;
        if (i < len - 1 && str[i] != str[i+1]) {
            str[index++] = str[i];
            char freq = '0' + count[str[i]];
            if (freq != '1')
                str[index++] = freq;
            count[str[i]] = 0;
        }
    }
    str[index++] = str[len-1];
    char freq = '0' + count[str[len-1]];
    if (freq != '1')
        str[index++] = freq;
    str[index] = '\0';
}

void decompress(char *str) {
    int len = strlen(str);
    char *temp = (char*) malloc(len * sizeof(char));
    int index1 = 0, index2 = 0;
    while (index1 < len) {
        temp[index2++] = str[index1++];
        if (str[index1] >= '2' && str[index1] <= '9') {
            int freq = str[index1] - '0';
            for (int i = 1; i < freq; i++) {
                temp[index2++] = str[index1-1];
            }
            index1++;
        }
    }
    temp[index2] = '\0';
    strcpy(str, temp);
    free(temp);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string to compress: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);

    compress(str);
    printf("Compressed string: %s\n", str);

    decompress(str);
    printf("Decompressed string: %s\n", str);

    return 0;
}