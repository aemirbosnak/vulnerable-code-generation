//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    char *str, *src, *dest, *token, *temp;
    size_t src_len, dest_len, i;

    if (argc != 3) {
        printf("Usage: %s <source_string> <destination_string>\n", argv[0]);
        exit(1);
    }

    str = malloc(strlen(argv[1]) + strlen(argv[2]) + 1);
    src = argv[1];
    dest = argv[2];

    src_len = strlen(src);
    dest_len = strlen(dest);

    for (i = 0; i < src_len; i++) {
        if (src[i] == 'a' || src[i] == 'e' || src[i] == 'i' || src[i] == 'o' || src[i] == 'u') {
            for (int j = 0; dest[j] != '\0'; j++) {
                if (dest[j] == src[i]) {
                    dest[j] = src[i + 1];
                    break;
                }
            }
            i++;
            strcpy(str, dest);
            dest = malloc(strlen(str) + 1);
            strcat(dest, str + i);
            i += strlen(str + i);
            free(str);
            str = malloc(strlen(dest) + 1);
            strcpy(str, dest);
            temp = malloc(strlen(src) + strlen(dest) + 2);
            strcat(temp, src);
            strcat(temp, dest);
            src = temp;
            temp = str;
            temp += i;
            free(temp);
            break;
        }
        strcpy(str, dest);
        dest = malloc(strlen(str) + 1);
        strcat(dest, str);
        free(str);
        str = malloc(strlen(src) + strlen(dest) + 1);
        strcpy(str, src);
        strcat(str, dest);
        temp = malloc(strlen(str) + 1);
        strcpy(temp, str);
        for (int j = 0; temp[j] != '\0'; j++) {
            if (temp[j] == src[i]) {
                temp[j] = src[i + 1];
                break;
            }
        }
        free(str);
        src += i + 1;
        dest = temp;
        i = -1;
    }

    printf("%s\n", dest);

    free(dest);
    free(src);
    free(str);
}