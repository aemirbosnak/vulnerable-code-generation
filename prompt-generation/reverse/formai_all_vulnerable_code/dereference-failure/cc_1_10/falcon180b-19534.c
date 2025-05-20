//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_key(char *key, int key_size) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int i = 0;
    while (i < key_size) {
        key[i] = 'a' + tm->tm_sec % 26;
        i++;
    }
    key[key_size] = '\0';
}

void encrypt(char *file_name, char *key) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = 'a' + (ch - 'a' + 26 - (int) key[0] - 1) % 26;
        }
        fprintf(stdout, "%c", ch);
    }
    fclose(file);
}

void decrypt(char *file_name, char *key) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = 'a' + (ch - 'a' + 26 - (int) key[0] - 1) % 26;
        }
        fprintf(stdout, "%c", ch);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] [file_name] [key]\n", argv[0]);
        exit(1);
    }
    char *mode = argv[1];
    char *file_name = argv[2];
    char *key = argv[3];
    char key_buf[100];
    int key_size;
    if (strcmp(mode, "encrypt") == 0) {
        generate_key(key_buf, 100);
        strncpy(key, key_buf, strlen(key_buf));
        key_size = strlen(key);
        encrypt(file_name, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        key_size = strlen(key);
        decrypt(file_name, key);
    } else {
        printf("Invalid mode.\n");
        exit(1);
    }
    return 0;
}