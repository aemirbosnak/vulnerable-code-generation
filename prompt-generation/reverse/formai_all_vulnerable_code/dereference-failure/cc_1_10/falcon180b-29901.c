//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <openssl/md5.h>

typedef struct {
    char *str;
    int len;
} string;

string *createString(char *str) {
    string *newString = (string *)malloc(sizeof(string));
    newString->str = str;
    newString->len = strlen(str);
    return newString;
}

void printString(string *str) {
    printf("%s\n", str->str);
}

int compareStrings(string *str1, string *str2) {
    if(str1->len!= str2->len) {
        return 0;
    }
    for(int i = 0; i < str1->len; i++) {
        if(tolower(str1->str[i])!= tolower(str2->str[i])) {
            return 0;
        }
    }
    return 1;
}

string *hashString(string *str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)str->str, str->len, digest);
    string *newString = createString((char *)digest);
    return newString;
}

int main() {
    string *inputString = createString("Hello, World!");
    string *hashedString = hashString(inputString);
    printf("Input String: ");
    printString(inputString);
    printf("Hashed String: ");
    printString(hashedString);
    return 0;
}