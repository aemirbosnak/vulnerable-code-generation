//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encode_morse(char* str, int len) {
    int i, j, k;
    char temp[100], temp2[100];
    char morse_table[100][100];
    char output[100];

    for (i = 0; i < 100; i++) {
        strcpy(temp, "");
        for (j = 0; j < 100; j++) {
            strcat(temp, "-");
            strcat(temp, " ");
        }
        strcpy(morse_table[i], temp);
    }

    for (i = 0; i < len; i++) {
        temp[0] = str[i];
        temp[1] = '\0';
        k = toupper(temp[0]);
        strcpy(temp2, morse_table[k]);
        for (j = 0; temp2[j]!= '\0'; j++) {
            strcat(output, temp2[j]);
        }
        strcat(output, " ");
    }

    printf("%s\n", output);
}

void decode_morse(char* str, int len) {
    int i, j, k;
    char temp[100], temp2[100];
    char morse_table[100][100];
    char output[100];

    for (i = 0; i < 100; i++) {
        strcpy(temp, "");
        for (j = 0; j < 100; j++) {
            strcat(temp, "-");
            strcat(temp, " ");
        }
        strcpy(morse_table[i], temp);
    }

    for (i = 0; i < len; i++) {
        temp[0] = str[i];
        temp[1] = '\0';
        k = toupper(temp[0]);
        strcpy(temp2, morse_table[k]);
        for (j = 0; temp2[j]!= '\0'; j++) {
            strcat(output, temp2[j]);
        }
        strcat(output, " ");
    }

    printf("%s\n", output);
}

int main() {
    char str[100];
    int len;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    len = strlen(str);
    printf("Enter a number (1 for encode, 2 for decode): ");
    scanf("%d", &len);
    if (len == 1) {
        if (str[0] == '1') {
            encode_morse(str, len);
        } else if (str[0] == '2') {
            decode_morse(str, len);
        } else {
            printf("Invalid input.\n");
        }
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}