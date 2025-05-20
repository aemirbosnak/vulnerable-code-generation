//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 1000
char str[MAX_LENGTH];
int main() {
    srand(time(NULL));
    int len, i, j, flag = 0;
    printf("Enter a string to check for palindrome: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    if (len % 2 == 0) {
        for (i = 0, j = len - 1; i < len / 2; i++, j--) {
            if (str[i] != str[j]) {
                flag = 1;
                break;
            }
        }
    } else {
        for (i = 0, j = len - 1; i < len / 2; i++, j--) {
            if (str[i] != str[j]) {
                flag = 1;
                break;
            }
            if (i != len - 1 && str[i] != str[j]) {
                flag = 1;
                break;
            }
        }
    }
    if (flag) {
        printf("The given string is not a palindrome.\n");
    } else {
        printf("The given string is a palindrome.\n");
        int count[256] = {0};
        for (i = 0; str[i] != '\0'; i++) {
            count[(int)str[i]]++;
        }
        for (i = 0; i < 256; i++) {
            if (count[i] % 2 != 0) {
                if (isalpha(i) || isdigit(i)) {
                    int random_index = rand() % (len / 2);
                    if (str[random_index] != (char)i) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag) {
            printf("The given string is not a statistical palindrome.\n");
        } else {
            printf("The given string is a statistical palindrome.\n");
        }
    }
    return 0;
}